# Projeto orientado a objeto

>[!NOTE]
>O **Projeto orientado a objeto** é composto pelas documentação do projeto descrito em UML. Deve incluir um Diagrama de Classes do sistema projetado, e pelo menos um diagrama de interação de um dos casos de uso. Outros diagramas podem ser apresentados, caso julgue necessário.

# Principal

O jogo consiste em uma luta entre dois magos, ambos com quatro elementos cada: fogo, água, vento e terra. Quando utilizado um elemento no mago inimigo ele fica marcado com tal elemento, assim, ao aplicar um outro elemento nele, acontece uma reação elemental, causando um efeito especial e removendo ambos elementos do alvo.

Também havendo uma barra elemental para cada elemento, quanto mais você usa do mesmo elemento, mais a barra daquele elemento enche, e as outras esvaziam, isso elevaria o dano de algumas habilidades, habilitaria habilidades passivas, etc.

Logo, a ideia do jogo seria causar o máximo de reações elementais possíveis, ou focar em um elemento só, criando uma forma de jogar flexível e dinâmica.

# O jogador
Pode-se escolher entre alguns magos que possuém caracteristicas unicas, como causar mais dano, preencher as barras elementais mais rapido, curar, etc.

Cada mago possuí 6 magias, 4 delas sendo as magias principais: 🔥💧🌱🌪️, e duas unicas para cada personagem.

# Batalhas
Em batalha, o jogador irá batalhar contra a maquina, que utiliza ações baseadas em qual elemento está presente em ambos magos, vida, pontos elementais, etc.

Os turnos são simultâneos alternados, ou seja, ambas ações acontecem em ordem porém ao mesmo tempo. Isso é: no turno 1: A age, então B age. Agora no turno 2, B age primeiro, depois A, alternando todo turno.

# Barras elementais
Ambos os lados possuém 4 barras elementais, uma pra cada elemento. Ao utilizar uma habilidade elemental, o barra do mesmo ganha 1 ponto, e causar uma reação, aumenta 1 ponto pros elementos reagidos.

Cada ponto na barra aumenta o dano daquele elemento, até 5 pontos. Algumas habilidades e reações podem diminuira a barra inimiga.

# Magos

Cada mago precisa de sua caracteristica principal, para que tenha uma gameplay diferente no jogo, porém sem fugir muito da ideia de utilizar os elemento.

Mago: foco em preencher as barras, deixando o jogo simples e fácil de entender

⭐ Disparo mágico - Causa dano reduzido e aumenta todas as barras em 1

⭐ Escudo - Reduz o dano recebido em 50% do próximo ataque e aumenta todas as barras em 1


Feiticeiro: foco em uma barra só, focando em elementos especificos

⭐ Flecha instável - causa o mesmo tipo de dano da ultima habilide usada e aumenta a barra da mesma em 2. Não pode ser usado no primeiro turno

⭐ Raízes - cura 25% da vida e reduz o dano recebio em 50%, e aumenta em 1 a barra do ultimo elemento usado


Bruxa: foco em atrapalhar a estratégia inimiga

⭐ Caldeirão - Causa dano e aplica o elemento nela ao inimgo, aumenta em 2 pontos este elemento

⭐ Armadilha - Repele a magia caso ela faça uma reação elemental, aumenta em 2 pontos o elemento da magia utilizada

# Reações

Cada reação precisa de um efeito especial para justificar usar ela, algumas reações podem ser melhores contra inimigos especificos, ou melhores no final da luta, ou o contrário, melhor no começo, etc

🔥 + 💧	Vaporizar			    Ofensivo		Causa 50% mais dano

🌱 + 🔥	Cinzas		 		    Ofensivo		Aumenta o dano recebido em 75% no proximo turno

🌪️ + 🌱Folhas Cortantes	Ofensivo		Reduz a cura recebi, e ignora escudos

🔥 + 🌪️	Explosão			    Flexível		Diminui todas a barras em 1 ponto

💧 + 🌱	Lama		  	    	Flexível		Próxima habilide/reação não gera pontos

💧 + 🌪️	Névoa		  	  	  Flexível		Remove todos buff

[Retroceder](analise.md) | [Avançar](implementacao.md)

</div>
