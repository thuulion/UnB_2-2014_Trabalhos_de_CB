# UnB_2-2014_Trabalhos_de_CB
Aqui está meu trabalho final de Computação Básica em 2/2014 na UnB, da turma da prof Carla Koike.
Obs: trabalho feito no 1º semestre do curso, e nunca alterado depois de entregue.



README original do trabalho:



Universidade de Brasília
Departamento de Ciências da Computação - CIC
Computação Básica
Turma: C
Professora: Carla Maria Chagas e Cavalcante Koike
Programador: Thúlio Noslen Silva Santos
Matrícula: 14/0164090
Trabalho 2: Jogo v2.0 -> Qual é a música?

/*	DESCRIÇÃO	*/

O programa incialmente exibe uma mensagem de boas vindas e solicita ao usuário que se identifique.
Depois de inserido um identificador válido, o menu principal aparece e é pedido ao usuário que selecione uma das opções disponíveis.
Quando o usuário escolhe jogar, um laço de repetição se inicia e o programa exibe um trecho de uma música aleatória do gênero musical escolhido. 

DINÂMICA DO JOGO:
Ao usuário somente é perguntado "Qual é a música?" e ele tem no máximo 2 tentativas para acertar. 
Quando ele acerta o nome da música, uma próxima música aleatória diferente da música anterior é mostrada. 
As músicas são buscadas dentro de um arquivo texto com o nome do estilo, como "mpb.txt" ou "rock.txt".
As músicas param de ser mostradas ao usuário quando ele acertar as todas as músicas do gênero em sequência ou quando ele errar duas vezes em qualquer uma das músicas.

CONTAGEM DOS PONTOS:
Sempre que o usuário seleciona a opção 'jogar', uma partida é iniciada. 
Quando o usuário erra o nome de uma música, ele perde 1 ponto. Quando ele acerta, ganha 10 pontos. 
Cada estilo musical tem uma contagem de pontos individual. 
O jogador pode fazer no máximo N * 10 pontos por estilo, em que N é o número de músicas disponíveis no arquivo texto, já que são no máximo 10 pontos por música.
Os pontos se somam enquanto o jogador estiver dentro de uma partida e o total de pontos feitos pelo usuário é mostrado no final da partida.
Quando o usuário joga em um mesmo estilo musical novamente, a contagem de pontos do estilo escolhido é reiniciada.
A pontuação da partida anterior é substituída pela nova pontuação feita nesta nova partida.
A pontuação atual do usuário é mostrada no topo do menu principal.
No final do programa, quando o usuário seleciona a opção de saída do menu, a pontuação é mostrada ao usuário e o usuário atual é registrado no arquivo binário que contém a classificação dos dez últimos usuário que jogaram.

CONFIGURAÇÕES:
O jogador também pode ir ao menu de configurações e alterar a opção de gênero musical. 
O gênero musical padrão é o rock, e a opção escolhida pelo usuário é realçada no menu.

CLASSIFICAÇÃO:
Existe a opção de ver o ranking no menu principal, em que o usuário escolhe um estilo e os dez últimos usuário que jogaram o jogo são exibidos. Caso ninguém tenha jogado, uma mensagem informa que o ranking não existe ao usuário. O usuário atual só é colocado na classificação quando ele finaliza sua sessão e seleciona a opção de saída do jogo no menu principal.

VALIDAÇÃO DE ENTRADAS:
Todas as entradas passam por uma verificação antes de o programa executar alguma coisa. 
Caso uma entrada não seja válida, o programa exibe uma mensagem de erro e pede para o usuário digitar uma opção dentre as que o programa exibe. 

/* 	COMPILAÇÃO E EXECUÇÃO		*/

Para que este programa possa ser compilado pelo GCC e executado no Linux, são necessárias estas duas linhas de comando no terminal:
	gcc -ansi -Wall trabalho.c -o trabalho
	./trabalho
	
/* 	DADOS DE TESTE		*/

O programa pode ser testado com os seguintes inputs (uma cópia de como o programa deve se comportar é mostrada para auxiliar):

	"Seja bem vindo ao jogo: Qual eh a musica? v3.0

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Digite seu identificador (de 3 a 20 caracteres):
	>>"
		Digite JORJINHO seguido de <ENTER>.
		
	"ID: JORJINHO. Confirma? (S/N): "
		Digite N seguido de <ENTER>.
		
	"Digite seu identificador (de 3 a 20 caracteres):
	>>"
		Digite JORJAO seguido de <ENTER>.
		
	"ID: JORJAO. Confirma? (S/N): "
		Digite S seguido de <ENTER>.
		
	"Pontuacao atual: 
	Rock: 0 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Digite 1 seguido de <ENTER>.

	As músicas aparecerão em uma ordem aleatória.
	
	Como são várias músicas, as repostas para cada uma terão de ser localizadas no arquivo texto do gênero.
	
	Digite a resposta correta usando letras maiúsculas e minúsculas misturadas para averiguar se o programa dará a resposta como correta.
	
	Na quarta música que aparecer, digite a seguinte sequência: 
	
		Digite LASANHA seguido de <ENTER>.

	"Voce errou! Tente novamente. -1 ponto
	>>"
		Digite BISCOITO seguido de <ENTER>.
		
	"Voce errou duas vezes! Fim de jogo! -1 ponto

	JORJAO acertou 3 musicas e fez 28 pontos!

	Pressione ENTER para continuar."
		Pressione <ENTER>.

	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 3 seguido de <ENTER>.
		
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 1 seguido de <ENTER>.
		
	"Ranking vazio!
	
	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 5 seguido de <ENTER>.
		
	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione B seguido de <ENTER>.
		
	"Erro! Digite uma das opcoes validas!

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 2 seguido de <ENTER>.

	"Escolha o estilo de musica:
	1 - Rock <<
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 4 seguido de <ENTER>.
	
	"Escolha o estilo de musica:
	1 - Rock 
	2 - Funk
	3 - MPB
	4 - Pop <<
	5 - Voltar ao menu anterior
	>>"
		Pressione 6 seguido de <ENTER>.
		
	"Erro! Digite uma das opcoes validas!

	Pressione ENTER para continuar."
		Pressione <ENTER>.		
		
	"Escolha o estilo de musica:
	1 - Rock 
	2 - Funk
	3 - MPB
	4 - Pop <<
	5 - Voltar ao menu anterior
	>>"
		Pressione 5 seguido de <ENTER>.
		
	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 1 seguido de <ENTER>.
		
	"Pop escolhido."
		
	Qualquer que seja a música mostrada, faça duas ações:
	
		Pressione <ENTER>.

	"Voce errou! Tente novamente. -1 ponto
	>>"
		Digite ABRASIVO seguido de <ENTER>.

	"Voce errou duas vezes! Fim de jogo. -1 ponto

	JORJAO acertou 0 musicas e fez -2 pontos!

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: -2 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 1 seguido de <ENTER>.
		
	Qualquer que seja a primeira música mostrada, digite a reposta correta. Já na segunda música que aparecer, digite uma resposta errada duas vezes. 
	
	"Parabens! Voce acertou. +10 pontos"

	Na segunda música mostrada faça:
	
		Digite ANDARILHO seguido de <ENTER>.
		
	"Voce errou! Tente novamente. -1 ponto
	>>"
		Digite aracaje seguido de <ENTER>.
		
	"Voce errou duas vezes! Fim de jogo. -1 ponto"

	"JORJAO acertou 1 musicas e fez 8 pontos!

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Pontuacao atual: 
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 8 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 4 seguido de <ENTER>.

	"Obrigado por jogar, JORJAO! Eis seu placar:
	
	Rock: 28 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 8 pontos
	
	Volte novamente mais tarde!

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	Agora, para checar se a pontuação de JORJAO ficou salva no ranking, entre novamente no programa com os seguintes comandos:
	
	"Seja bem vindo ao jogo: Qual eh a musica? v3.0

	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Digite seu identificador (de 3 a 20 caracteres):
	>>"
		Digite JORJINHO seguido de <ENTER>.
		
	"ID: JORJINHO. Confirma? (S/N): "
		Digite S seguido de <ENTER>.
		
	"Pontuacao atual: 
	Rock: 0 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 3 seguido de <ENTER>.
		
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 1 seguido de <ENTER>.
		
	"ID: JORJAO			Pontos: 28
	
	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 4 seguido de <ENTER>.
		
	"ID: JORJAO			Pontos: 8
	
	Pressione ENTER para continuar."
		Pressione <ENTER>.
		
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 2 seguido de <ENTER>.
		
	"ID: JORJAO			Pontos: 0
	
	Pressione ENTER para continuar."
		Pressione <ENTER>.
	
	"Escolha o estilo de musica:
	1 - Rock
	2 - Funk
	3 - MPB
	4 - Pop
	5 - Voltar ao menu anterior
	>>"
		Pressione 5 seguido de <ENTER>.
		
	"Pontuacao atual: 
	Rock: 0 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos

	Escolha uma opcao do menu:
	1. Jogar
	2. Configuracoes
	3. Ranking
	4. Sair do jogo
	>>"
		Pressione 4 seguido de <ENTER>.
		
	"Obrigado por jogar, JORJINHO! Eis seu placar:
	
	Rock: 0 pontos	Funk: 0 pontos
	MPB: 0 pontos	Pop: 0 pontos
	
	Volte novamente mais tarde!

	Pressione ENTER para continuar."
		Pressione <ENTER>.
