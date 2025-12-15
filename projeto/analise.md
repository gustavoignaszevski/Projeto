# Análise orientada a objeto

## Descrição Geral do domínio do problema

# Principal

Um jogo de turnos que você controla um mago e luta contra criaturas mágicas. O mago possúi quatro elementos, sendo eles: Fogo, água, terra e vento. As magias tem o mesmo comportamento, apenas mudando seu elemento. Tambem ha as ultimates, que podem aplicar ou elemento ou não, assim como tabmém serem buff, para utilizar a ultimate você precisa carregar uma barra elemental utilizando magias e causando reações elementais, utilizar uma habilidade aumenta em 5 a barra, e uma reação aumenta em mais 10, até uma maximo de 100.

**O jogador**

Tem os status de ataque e vida, ele pode escolher a magia para conjurar ou a ultimate caso a barra elemental esteja carregada o suficiente.
(Status base: 200 hp, 20 ataque, 10 defesa)

**Batalhas**

A batalha acontece em turnos, e o jogador sempre começa.

**Reações elementais**

Habilidades e algumas ultimate aplicam elemento no inimigo, e caso esse elemento seja diferente da habilidade utilizada uma reação elemental é aplicada, isso causa um efeito dependendo dos dois elementos misturado e deixa e limpa os elementos do alvo

**Reações**

Cada reação precisa de um efeito especial para justificar usar ela, algumas reações podem ser melhores contra inimigos especificos, ou melhores no final da luta, ou o contrário, melhor no começo, etc

🔥 + 💧	Vaporizar			    		Aumenta seu ataque em 5

🌱 + 🔥	Queimadura		 		    Reduz a defesa do alvo em 5

🌪️ + 🌱 Folhas Cortantes	  	O ataque ignora a defesa

🔥 + 🌪️	Explosão			    		Reduz o ataque do alvo em 5

💧 + 🌱	Lama		  	    			O conjurador cura 10 + 10% da vida perdida

💧 + 🌪️	Névoa		  	  	  		Aumenta a defesa do conjurador em 5

**Ultimates**

As ultimates são desbloqueadas até houve pontos suficientes na barra elemental, quando isso acontece. Ao utilizar a ultimate, a barra é reduzida o quanto aquela ultimate custa.

☄️ Meteoro do Fulgor (60)
- Causa 250% do ataque como dano
- Aplica elemento Fogo

🐉 Corrente do Leviatã (40)
- Cura 30 + 20% da vida perdida
- Remove o elemento aplicado em si

⛰️ Terra Primordial (50)
- Defesa +15 para si
- Defesa -5 para o inimigo

🌀️ Vendaval Uivante (70)
- Causa 200% do ataque como dano
- Aplica Vento
- Se causar reação, mantém o elemento Vento

🛰 Laser Orbital (100)
- Causa 300% do ataque como dano verdadeiro
- Ignora defesa
  
💠 Zoltrak (30)
- Causa 150% do ataque como dano
- Aplica um efeito aleatório:
  • +2 ATK (si mesmo)
  • -2 ATK (alvo)
  • +2 DEF (si mesmo)
  • -2 DEF (alvo)
  • Cura 5 + 5% da vida perdida

## Diagrama de Casos de Uso

<img width="921" height="448" alt="Desktop Screenshot 2025 12 15 - 19 16 35 76" src="https://github.com/user-attachments/assets/81ecb8db-0c81-4e69-a581-7c19dde4f694" />

**Caso de uso: Selecionar habilidade**
Quatro botöes, um para cada habilidade elemental

**Caso de uso: Selecionar Ultimate**
Um QComboBox onde o jogador pode selecionar a ultimate, caso ele tenha a quantidade de pontos requisitada o botäo de conjurar a ultimate é liberado

**Caso de uso: Detecta vitória/derrota**
Checa a vida o jogador e do inimigo para saber se o jogador ganhou ou perdeu

**Caso de uso: Reiniciar batalha*
Depois da derrota ou vitória é dado a opção de reseta a batalha para o inicio

**Caso de uso: Detecta Escolhe habilidade aleatória**
O sistema (oponente) escolhe uma habilidade aleatória das quatro e usa ela

## Diagrama de Domínio do problema (DESATUALIZADO)

<img width="961" height="710" alt="image" src="https://github.com/user-attachments/assets/0b35c129-79cc-41a4-819d-07b14c3fc0b1" />

<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
