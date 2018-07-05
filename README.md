# LIFE
LIFE é uma aplicação do jogo da vida de John Conway

## Author

Judson Cabral de Melo

## Sobre:
LIFE é uma aplicação do jogo da vida de John Conway

## Como funciona?
O programa vai criar uma matriz(por dimensões escolhidas pelo jogador) e posicionar as celulas vivas e então simula o jogo onde
o jogador pode parar quando quiser ou quando uma das regras de parada for alcançada de acordo com as regras do jogo da vida.

## Compilação:
Para compilar, abra o terminal na pasta LIFE e screva o seguinte comando no terminal:

g++ -Wall -std=c++17 -pedantic src/main.cpp src/life.cpp -o life_game


## Durante a execução:
Pode se fornecer um arquivo com configurações para fazer uma simulão direta:

10 10

v

..........

..........

..........

..vv......

..v.......

..........

..........

..........

..........

..........

..........

..........


Onde os primeiros números seriam a linha e coluna.

O caractere que representa a celula viva(v).

A criação do mapa com as celulas vivas já posicionada.

E depois ira ficar aplicando as regras enquanto o jogo não tiver estabilizado ou todas as celulas se tornado extintas ou o jogador tenha desejado parar

Ou caso não forneça um arquivo:

Primeiro ira pedir o quantidade de colunas e de linha:

no qual você deve fornecer primeiro a coluna e depois a linha consecutivamente

Depois ira perguntar quantidade de celulas vivas deseja posiciona:

Depois ira pedir pra posicionar essas celulas vivas

Depois ira ficar aplicando as regras enquanto o jogo não tiver estabilizado ou todas as celulas se tornado extintas ou o jogador tenha desejado parar

## Execução:
Para executar, abra o terminal na pasta LIFE e screva o seguinte comando no terminal:
./life_game
ou
./life_game arquivo.txt
