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

<img width="1256" height="329" alt="image" src="https://github.com/user-attachments/assets/65cce211-eb97-4a87-9666-46efa0f154d2" />

**Caso de uso: Escolher elemento**
Um combo box que permite selecionar entre os quatro elementos

**Caso de uso: Escolher tipo de conjuração**
Um combo box que permite selecionar entre os quatro tipos de conjurações

**Caso de uso: Conjurar**
Checa ambas boxes do elemento e do tipo de conjuração e a utiliza para definir qual habilidade será conjurada. O sistema pega a velocidade do jogador e do inimigo e checa se a do jogador é igual ou maior que a do inimigo para dedicidir qual habilidade será conjurada primeiro.
Caso a habilidade selecionada seja:
1. Disparo: pega o ataque e calcula o dano base da habilidade, aumenta a barra elemental, e ao acertar o inimgo, aplica o elemento nele, e se o inimigo já possuir um elemento, checa se aquele elemento é diferente do elemento aplicado, se sim, causa a reação elemental, e então aplica estes efeito e depois atualiza os labels necessários após isso. Também salva numa variável quantas vezes aquele elemento específico foi usado
2. Escudo: dá um escudo ao jogador do elemento especificado e aumenta a barra elemental.
3. Técnica: Aplica buff/efeito no jogador
4. Ultimate: por padrão desativada, quando a a barra elemental chegar a 100%, o botão fica disponível. O elemento da ultimate é definido com base no elemento mais usado dos ultimos conjuramentos (esses conjuramentos não ficam a mostra). Caso os dois maiores elementos possuam a mesma quantidade de casts, há uma prioridade dos elementos: Fogo > agua > terra > vento. Ao utilizar a ultimate a barra elemental cai para 0% e os contadores são resetados para não influenciarem numa possível segunda ultimate, então é aplicado o elemento da ultimate no alvo, e detecta reações elementais caso ela possa acontecer.

## Diagrama de Domínio do problema

<img width="961" height="710" alt="image" src="https://github.com/user-attachments/assets/0b35c129-79cc-41a4-819d-07b14c3fc0b1" />

<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
