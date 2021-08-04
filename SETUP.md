# Jogo de Plataforma 2D com C++ e SFML no Visual Studio

### Criar um diret�rio de desenvolvimento

- Exemplo:

```cmd
	mkdir Game-Projects
```

### Baixar SFML

https://www.sfml-dev.org/

- Descompatar os arquivos dentro do diret�rio de desenvolvimento.

- Renomear a pasta do SFML apenas para `SFML`.


### Criar uma solu��o do Visual Studio

- Criar a solu��o no diret�rio de desenvolvimento onde est� a biblioteca do SFML.

- Criar um projeto C++ vazio.

### Configura��es do Projeto

- Copiar todos os arquivos em `SFML\bin` para a raiz do diret�rio do projeto.

- Clicar em __Projeto__.

- Selecionar a op��o `Propriedades de <Nome do Projeto>`.

- Em `Configura��o` selecionar `Todas as Configura��es`.

- Selecionar a op��o `C++`.

- Selecionar a op��o `Diret�rios de inclus�o Adicionais`.

- Clicar em __Editar__.

- Digitar a linha: `$(SolutionDir)..\SFML\include`.

- Clicar em __OK__.

- Selecionar a op��o `Vinculador`.

- Selecionar a op��o `Diret�rios de biblioteca Adicionais`.

- Clicar em __Editar__.

- Digitar a linha: `$(SolutionDir)..\SFML\lib`.

- Clicar em __OK__.

- Clicar em __Aplicar__.

- Em `Configura��o` alterar para `Release`.

- Selecionar `Vinculador`.

- Selecionar `Entrada`.

- Selecionar `Depend�ncias Adicionais`.

- Clicar em __Editar__.

- Digitar as linhas abaixo:

```cmd
sfml-graphics.lib
sfml-network.lib
sfml-system.lib
sfml-window.lib
sfml-audio.lib
"opengl32.lib"
"glu32.lib"
```

- Clicar em __OK__.

- Clicar em __Aplicar__.

- Em `Configura��o` selecionar `Debug`.

- Selecionar `Vinculador`.

- Selecionar `Entrada`.

- Selecionar `Depend�ncias Adicionais`.

- Clicar em __Editar__.

- Digitar as linhas abaixo:

```cmd
sfml-graphics-d.lib
sfml-network-d.lib
sfml-system-d.lib
sfml-window-d.lib
sfml-audio-d.lib
```

- Clicar em __OK__.

- Clicar em __Aplicar__.


### Testando com SFML

Ref: https://www.sfml-dev.org/tutorials/2.5/start-vc.php

- Crie um arquivo `main.cpp` em `Arquivos de Origem` e adicione o c�digo a seguir:

```c++
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```