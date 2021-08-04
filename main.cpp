#include <SFML/Graphics.hpp>

using namespace sf;

float offsetX = 0;
float offsetY = 0;

const int H = 15;
const int W = 80;

String TileMap[H] = {
	"B                                                                             B",
	"B                                                                             B",
	"B                                                                             B",
	"B                                    000                                      B",
	"B                                                                             B",
	"B                                                                             B",
	"B                                                                             B",
	"B     0                         BB                                            B",
	"B                             BB  BB                                          B",
	"B                           BB      BB                                        B",
	"B            BB           BB          BB                                      B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};


class PLAYER
{

public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(250, 0, 50, 85);
		dx = dy = 0.1;
		currentFrame = 0;
	}

	void update(float time)
	{
		rect.left += dx * time;
		Collision(0);

		if (!onGround) dy = dy + 0.0005 * time;

		rect.top += dy * time;
		onGround = false;
		Collision(1);

		currentFrame += 0.005 * time;
		if (currentFrame > 4) currentFrame -= 4;

		int startFrame = 250 + 53 * int(currentFrame);
		if (dx > 0) sprite.setTextureRect(IntRect(startFrame, 0, 53, 100)); // caminhar para a direita
		if (dx < 0) sprite.setTextureRect(IntRect(startFrame + 53, 0, -53, 100)); // caminhar para a esquerda

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}

	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
		{
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'B')
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
					
					if ((dy > 0) && (dir == 1))
					{
						rect.top = i * 32 - rect.height;
						dy = 0;
						onGround = true;
					}

					if ((dy < 0) && (dir == 1))
					{
						rect.top = i * 32 + 32;
						dy = 0;
					}
				}

				if (TileMap[i][j] == '0')
				{
					TileMap[i][j] = ' ';
				}
			}
		}
	}
};


int main()
{
	RenderWindow window(VideoMode(600, 400), "Jogo de Plataforma");

	Texture playerTex, groundTex;
	playerTex.loadFromFile("resources/assets/SaraOGATransparent.PNG");
	groundTex.loadFromFile("resources/assets/Ground.png");

	float currentFrame = 0;

	PLAYER player(playerTex);

	Clock clock;

	IntRect rect(0, 0, 32, 32);
	Sprite ground(groundTex, rect);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700; // deixa o pulo mais suave

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.dx = -0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.dx = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (player.onGround)
			{
				player.dy = -0.35;
				player.onGround = false;
			}
		}

		player.update(time);

		if (player.rect.left > 300)
		{
			offsetX = player.rect.left - 300;
		}

		offsetY = player.rect.top - 200;

		window.clear(Color::Black);
		window.draw(player.sprite);

		for(int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B') ground.setTextureRect(IntRect(0, 0, 32, 32)); // posição do pixel da grama
				if (TileMap[i][j] == '0') ground.setTextureRect(IntRect(530, 0, 32, 32)); // posição do pixel do coração
				if (TileMap[i][j] == ' ') continue;

				ground.setPosition(j * 32 - offsetX, i * 32 - offsetY);
				window.draw(ground);
			}
		}

		window.display();
	}

	return EXIT_SUCCESS;
}