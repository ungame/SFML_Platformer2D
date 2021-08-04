# Jogo de Plataforma 2D com C++ e SFML no Visual Studio

### Criar um diretório de desenvolvimento

- Exemplo:

```cmd
	mkdir Game-Projects
```

### Baixar SFML

https://www.sfml-dev.org/

- Descompatar os arquivos dentro do diretório de desenvolvimento.

- Renomear a pasta do SFML apenas para `SFML`.


### Criar uma solução do Visual Studio

- Criar a solução no diretório de desenvolvimento onde está a biblioteca do SFML.

- Criar um projeto C++ vazio.

### Configurações do Projeto

- Copiar todos os arquivos em `SFML\bin` para a raiz do diretório do projeto.

- Clicar em __Projeto__.

- Selecionar a opção `Propriedades de <Nome do Projeto>`.

- Em `Configuração` selecionar `Todas as Configurações`.

- Selecionar a opção `C++`.

- Selecionar a opção `Diretórios de inclusão Adicionais`.

- Clicar em __Editar__.

- Digitar a linha: `$(SolutionDir)..\SFML\include`.

- Clicar em __OK__.

- Selecionar a opção `Vinculador`.

- Selecionar a opção `Diretórios de biblioteca Adicionais`.

- Clicar em __Editar__.

- Digitar a linha: `$(SolutionDir)..\SFML\lib`.

- Clicar em __OK__.

- Clicar em __Aplicar__.

- Em `Configuração` alterar para `Release`.

- Selecionar `Vinculador`.

- Selecionar `Entrada`.

- Selecionar `Dependências Adicionais`.

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

- Em `Configuração` selecionar `Debug`.

- Selecionar `Vinculador`.

- Selecionar `Entrada`.

- Selecionar `Dependências Adicionais`.

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

- Crie um arquivo `main.cpp` em `Arquivos de Origem` e adicione o código a seguir:

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