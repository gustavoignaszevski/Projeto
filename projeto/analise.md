# Análise orientada a objeto
> [!NOTE]
> A **análise** orientada a objeto consiste na descrição do problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema.

## Descrição Geral do domínio do problema

Descrever de forma geral o domínio do problema.

Possíveis requisitos funcionais e não-funcionais podem ser elencados aqui.

Neste jogos iremos precisar de duas classes principais, o jogador e o monstro controlado pelo programa. O jogador possuí três principais ações: Atacar, defender e usar habilidade, o monstro não possuí um padrão de habilidades, ele fara uma ação aleatória ou a mais benéfica para ele, dependendo da dificuldade do monstro

## Diagrama de Casos de Uso

Apresentar o diagram de casos de uso, identificando as funcionalidades do sistema assim como os atores envolvidos

Aqui vemos que a parte principal é o turno do jogador, onde ele pode escolher qual ação ele fará. O jogo dispõe para o jogador a próxima ação do inimigo, assim ele pode escolher melhor o que ele fará a seguir (alguns inimigos não mostram a próxima ação). Após isto, esta ação é executada, em seguida o monstro executa sua ação, e então entram os eventos secundários, que acontecem fora de turno, como dano por sangramento/veneno, buffs, etc
 
## Diagrama de Domínio do problema

Elaborar um diagrama conceitual do domínio do problema.


<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
