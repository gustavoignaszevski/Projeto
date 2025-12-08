# Análise orientada a objeto

## Descrição Geral do domínio do problema

# Principal

Um jogo de turnos que você controla um mago e luta contra criaturas mágicas. O mago possúi quatro elementos e quatro tipos de conjuramento, sendo eles: Fogo, água, terra e vento, e disparo, escudo, técnica e ultimate. Os disparos tem o mesmo comportamento, apenas mudando seu elemento. Já a técnica é especifica para cada elemento, e a ultimate também. Para utilizar a ultimate você precisa carregar uma barra elemental utilizando magias e causando reações elementais, o elemento da magia mais usada é o que define ela. 

**O jogador**

Tem os status de ataque e vida, ele pode escolher o elemento da magia e o tipo de conjuramento.
(Status base: 200 hp, 20 ataque, 10 velocidade)

**Batalhas**

A batalha acontece em turnos, e quem possuír mais velocidade age antes. Caso a velocidade dos dois seja a mesma, o jogador começa.

**Reações elementais**

Habilidades de disparo e algumas ultimate aplicam elemento no inimigo, e caso esse elemento seja diferente da habilidade utilizada uma reação elemental é aplicada, isso causa um efeito dependendo dos dois elementos misturado e deixa e limpa os elementos do alvo

**Reações**

Cada reação precisa de um efeito especial para justificar usar ela, algumas reações podem ser melhores contra inimigos especificos, ou melhores no final da luta, ou o contrário, melhor no começo, etc

🔥 + 💧	Vaporizar			    		Causa 50% mais dano

🌱 + 🔥	Queimadura		 		    Causa 25% do dano ao longo de 3 turnos (75% no total)

🌪️ + 🌱 Folhas Cortantes	  	Reduz a cura em 75% por dois turnos

🔥 + 🌪️	Explosão			    		Causa dano adicional baseado em 50% do escudo

💧 + 🌱	Lama		  	    			Diminui a barra elemental em 40%

💧 + 🌪️	Névoa		  	  	  		Reduz a velocidade em 3 por um turno

**Escudos Técnicas**

Os escudos defendem completamente contra o mesmo elemento, apenas a reação explosão consegue ignorar escudos

As técnicas tem o objetivo de manter o jogador vivo ou ganhar buff, deixando a batalha mais estratégica

🔥 Foco flamejante            Aumenta o ataque em 5

💧 Maré calma                 Remove debuffs e o elemento aplicado

🌱 Herbalismo                 Cura 15 + 20% da vida perdida

🌪️ Tufão                      Aumenta a velocidade em 2

## Diagrama de Casos de Uso

<img width="1256" height="329" alt="image" src="https://github.com/user-attachments/assets/65cce211-eb97-4a87-9666-46efa0f154d2" />

## Diagrama de Domínio do problema

<img width="961" height="710" alt="image" src="https://github.com/user-attachments/assets/0b35c129-79cc-41a4-819d-07b14c3fc0b1" />

<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
