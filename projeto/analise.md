# Análise orientada a objeto

## Descrição Geral do domínio do problema

Neste jogos iremos precisar de duas classes principais, o jogador e o monstro controlado pelo programa. O jogador possuí três principais ações: Atacar, defender e usar habilidade, o monstro não possuí um padrão de habilidades, ele fara uma ação aleatória ou a mais benéfica para ele, dependendo da dificuldade do monstro

## Diagrama de Casos de Uso

Aqui vemos que a parte principal é o turno do jogador, onde ele pode escolher qual ação ele fará. O jogo dispõe para o jogador a próxima ação do inimigo, assim ele pode escolher melhor o que ele fará a seguir (alguns inimigos não mostram a próxima ação). Após isto, esta ação é executada, em seguida o monstro executa sua ação, e então entram os eventos secundários, que acontecem fora de turno, como dano por sangramento/veneno, buffs, etc

<img width="726" height="701" alt="image" src="https://github.com/user-attachments/assets/7d7a37cb-0b26-4e97-a68d-85518d5d8718" />

## Diagrama de Domínio do problema

<img width="1099" height="511" alt="image" src="https://github.com/user-attachments/assets/496279a5-9122-48a5-bcfe-15a2ffded199" />

<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
