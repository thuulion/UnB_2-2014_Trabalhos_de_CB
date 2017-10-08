/* Universidade de Brasília
 * Departamento de Ciências da Computação - CIC
 * Computação Básica
 * Turma C
 * Professora: Carla Maria Chagas e Cavalcante Koike
 * Programador: Thúlio Noslen Silva Santos
 * Matrícula: 14/0164090
 * Trabalho 3: Jogo v3.0 -> "Qual é a música?"
 */










/* 		INÍCIO DAS BIBLIOTECAS		*/

#include <stdio.h>

#include <stdlib.h>	/* system("clear"); 	srand();	rand(); 	malloc(); 	free();	*/

#include <time.h>	/* time(NULL); */

/* 		FIM DAS BIBLIOTECAS		*/










/*		TYPEDEF STRUCT		*/


/*	USUARIO: este tipo de STRUCT vai armanezar as informações do usuário durante a execução do programa.	*/
typedef struct {
	
	char	user[100];	/* Esta variável guarda o nickname que o usuário escolhe durante a execução do programa. */
	
	int 	ptsrock,
		ptsfunk,	/* Estas quatro variáveis guardam a contagem dos pontos para cada gênero separadamente. */ 
		ptsmpb,
		ptspop;
		
} usuario;


/* 	USUARIOTEMP: este tipo de STRUCT servirá para ler e escrever nos arquivos binários individuais de cada estilo.	*/
typedef struct {
	
	char	user[100];	/* Guarda o nickname de um usuário qualquer. */
	
	int 	pontos;		/* Guarda os pontos de um usuário qualquer em um estilo específico que será determinado durante a execução das funções do programa. */
		
} usuariotemp;


/* 	MUSICA: este tipo de STRUCT servirá mais para frente. Vetores de MUSICA serão criados durante a execução do jogo com tamanho definido somente depois da leitura dos arquivos de texto.	*/
typedef struct {
	
	char	titulo[210],	/* Máximo de 200 caracteres. (200) + (10). O 10 extra é só uma medida de segurança. */
		trecho[650];	/* Máximo de 70 caracteres por verso e e máximo de 9 versos. (9 * 70) + (20). Aqui o 20 também é somente uma medida de segurança. */
		
} musica;


/*		FIM DO TYPEDEF STRUCT		*/










/*		INÍCIO DOS CABEÇALHOS		*/

void agradecimento (usuario*);

void boas_vindas (void);

int comparar_string (char*, char*);

void concatenar_string (char*, char*);

void config (int*);

int confirma_id (char*);

void conforme_seja_op_inicial (int, int*, usuario*);

void copiar_string (char*, char*);

void genrandom (int*, int);

void identificador (char*);

void jogar (int, usuario*);

void jogar_funk (int*, int*);

void jogar_mpb (int*, int*);

void jogar_pop (int*, int*);

void jogar_rock (int*, int*);

int le_id (char*);

int ler_op_inicial (void);

void limpar_tela (void);

void limpar_tela_noenter (void);

char menu_inicial (usuario);

void mostrar_ops_config (int);

void mostrar_ops_inicial (usuario);

void mudar_classificacao (usuario);

void op_invalida (void);

int partida_funk (char*);

int partida_mpb (char*);

int partida_pop (char*);

int partida_rock (char*);

void ranking (void);

int tamanho_string (char*);

int testador (char*, char*, int*, int*, int*);

void ver_classificacao (int);

/*		FIM DOS CABEÇALHOS		*/










/*		FUNÇÃO MAIN	 	*/

int main () {
	
	int 	op;	/* A variável OP armazena a opção escolhida pelo usuário no menu inicial. */
	
	int	opm = 1;	/* OPM guarda o gênero musical escolhido pelo usuário. O gênero padrão é rock, e então OPM vale inicialmente 1. */
	
	boas_vindas ();	 	/* Esta função mostra a mensagem de boas-vindas ao usuário no começo do programa. */
	
	usuario	jogador;	/* JOGADOR é uma STRUCT que guardará o nickname do usuário e seus pontos durante o programa. */
	
	jogador.ptsrock = 0;
	jogador.ptsfunk = 0;	/* Aqui os pontos são inicializados com 0 para qualquer novo usuário. */
	jogador.ptsmpb = 0;	
	jogador.ptspop = 0;
	
	identificador (jogador.user);	
	/* Aqui a função IDENTIFICADOR é chamada para mostrar ao usuário a interface de identificação. O nickname escolhido será salvo em JOGADOR.USER. */
	
	while (op != 4) {	/* Este WHILE é encerrado quando o usuário selecionar a opção 4, a de saída do jogo. */
		
		limpar_tela_noenter ();		/* Limpa a tela sem esperar que o usuário pressione ENTER. */
		
		op = menu_inicial (jogador);	/* A função MENU_INICIAL mostra a interface do menu inicial e é responsável por retornar o valor da opção escolhida pelo usuário, que foi lida dentro de MENU_INICIAL. */
		
		conforme_seja_op_inicial (op, &opm, &jogador);	
		/* O valor de OP escolhido pelo usuário é então passado junto ao gênero musical escolhido para CONFORME_SEJA_OP_INICIAL, que redirecionará o usuário para a ação escolhida. */
		
	}
	
	return 0;
}

/* 		FIM DA FUNÇÃO MAIN		*/











/* 		FUNÇÕES EM ORDEM ALFABÉTICA 		*/


/* 	FUNÇÃO AGRADECIMENTO: esta função mostra a mensagem final do jogo ao usuário quando ele pressionar 4. Ela mostra o total de pontos que o usuário fez e o agradece por jogar. 	*/
void agradecimento (usuario *jogador) {
	
	limpar_tela_noenter ();
	printf("\nObrigado por jogar, %s! Eis seu placar:\n\nRock: %d pontos\tFunk: %d pontos\nMPB: %d pontos\tPOP: %d pontos\n\nVolte novamente mais tarde!\n", jogador->user, jogador->ptsrock, jogador->ptsfunk, jogador->ptsmpb, jogador->ptspop);
	limpar_tela ();

}


/* 	FUNÇÃO BOAS_VINDAS: esta função mostra a mensagem inicial do jogo. 	*/
void boas_vindas (void) {

	printf("\nSeja bem vindo ao jogo: Qual eh a musica? v3.0\n");
	limpar_tela ();
	
}


/* 	FUNÇÃO COMPARAR_STRING: esta função torna todas as letras de duas strings minúsculas e as compara. 	*/
int comparar_string (char string1[], char string2[]) {
	
	int	i,	/* Servirá como índice nas iterações. */
		result;	/* Esta variável guardará o resultado de uma subtração. */
		
	/* Aqui a função checa se as duas strings tem o mesmo tamanho. */
	if (tamanho_string(string1) != tamanho_string(string2))
		return -1;	/* Se não tiverem, não poderão ser iguais e a função retorna -1. */
		
	/* Aqui e no loop FOR seguinte a função torna as letras das duas strings minúsculas. */
	for (i = 0; string1[i] != '\0'; i++)
		if ((string1[i] >= 'A')&&(string1[i] <= 'Z'))	/* Caso a letra esteja entre o A e o Z... */
			string1[i] += 0x20;	/* A função torna a letra minúscula somando 0x20 no caracter (por causa da tabela ASCII e tals). */
			
	for (i = 0; string2[i] != '\0'; i++)
		if ((string2[i] >= 'A')&&(string2[i] <= 'Z'))
			string2[i] += 0x20;
	
	/* Aqui neste FOR a comparação acontece para todos os caracteres das strings. */
	for (i = 0; string1[i] != '\0'; i++) {
	
		/* Cada caracter é subtraído do caracter da mesma posição da outra string. */
		result = string1[i] - string2[i];
			
		if (result)	/* Se a subtração der qualquer valor que não seja 0... */
			return result;	/* As strings são diferentes e a função retorna a diferença da subtração feita. */
	}
	
	/* Se as strings tiverem passado por todos os testes sem que a função retornasse -1 ou o valor da diferença na comparação, a função retorna 0, que indica que as strings são iguais. */
	return result;	
	
}


/* 	FUNÇÃO CONCATENAR_STRING: esta função junta o final da STRING1 (o '\0') com o começo da STRING2.	*/
void concatenar_string (char string1[], char string2[]) {
	
	int	i,
		k = 0;	/* K é inicializado com 0 para que STRING2 seja copiada de seu início. */
	
	/* Aqui o tamanho da STRING1 é descoberto. I, no final, receberá o valor do índice do '\0'. */
	for (i = 0; string1[i] != '\0'; i++);
	
	/* Aqui, enquanto a STRING2 não chegar ao final, ela é copiada para a STRING1. */
	for (k = 0; string2[k] != '\0'; i++, k++)
		string1[i] = string2[k];
		
	/* Por fim, STRING1 recebe '\0' para marcar seu final. */
	string1[i] = '\0';
			
}


/* 	FUNÇÃO CONFIG: esta função é responsável pela interface no menu de configurações e pela leitura do gênero musical escolhido. 	*/
void config (int *opm) {

	int 	opmbkp = *opm;	/* Esta variável aqui terá propósito mais pra frente nesta função. Explicarei seu funcionamento mais adiante. Spoiler alert: ela é um backup de OPM. */

	int 	lido;	/* Esta variável servirá para armazenar o valor de retorno da função SCANF. */

	/* Este WHILE é terminado quando é selecionada a opção 5, a opção de saída do menu de configurações. */
	while (*opm != 5) {
	
		limpar_tela_noenter ();
		
		mostrar_ops_config (*opm);	/* Aqui a função CONFIG chama a função MOSTRAR_OPS_CONFIG para mostrar o menu de configurações conforme o gênero musical atualmente selecionado. */
						
		lido = scanf("%d", opm);	/* Aqui se lê a opção musical. Como a opção de gênero musical é um inteiro, se forem inseridas letras ou outros caracteres que não são inteiros, a função SCANF descarta estes caracteres inválidos e retorna 0 para LIDO. */
		while(getchar() != '\n');
		
		while (lido == 0) {	/* O WHILE se mantém enquanto o usuário não digitar um número inteiro. */
		
			op_invalida ();	
			/* Enquanto o SCANF não tiver lido um valor inteiro, o usuário será avisado de que escolheu uma opção inválida. */		
		
			mostrar_ops_config (*opm);
		
			lido = scanf("%d", opm);
			while(getchar() != '\n');
			
		}
	
		/* Aqui a variável OPMBKP começa a ter uso. Já explico para que ela serve. */
		if ((*opm == 1)||(*opm == 2)||(*opm == 3)||(*opm == 4))		/* OPM = 1, 2, 3, 4 */
			opmbkp = *opm;
			/* Caso seja selecionada uma opção válida de gênero musical (a opção 5 é válida, mas não é opção de gênero musical), é feita uma cópia de segurança desta seleção na variável OPMBKP. */
			
		else	/* OPM = 5 e outros */
			if (*opm != 5) {	/* OPM = outros */
			
				*opm = opmbkp;
				/* Aqui OPMBKP começa a ter uso efetivo. Esta parte da crítica de dados é um complemento da crítica que envolve o valor de retorno do SCANF logo acima. Caso seja selecionada uma opção não válida de gênero, a variável OPM precisa ter seu valor anterior recuperado, já que agora ela está assumindo o valor inválido inserido pelo usuário. A variável OPMBKP é que fornece esta cópia de segurança do valor anterior de OPM. */
				
				op_invalida();
				/* E o usuário é avisado de que a opção selecionada era inválida. */
				
			}	/* E OPM = 5? */
			
		/* Por enquanto, o programa não faz nada quando se é selecionada a opção 5. */
		
	}	
	/* Aqui termina o WHILE que mantém o menu de configurações rodando. Isto significa que o usuário digitou 5. */		
					
	if (*opm == 5) 
		*opm = opmbkp;
		/* Aqui, mais uma vez, a variável OPMBKP entra em jogo. como foi selecionada a opção 5, a de saída do menu, o valor de OPM está "contaminado" com este novo valor e o valor do gênero musical previamente selecionado foi perdido. A variável OPMBKP, no entanto, pode nos fornecer uma cópia de segurança daquele valor, como anteriormente. */
		
	limpar_tela_noenter ();
	/* Por fim, esta função limpa a tela e volta ao menu principal */
}


/* 	FUNÇÃO CONFIRMA_ID: esta função é a que confirma que o identificador inserido é o que o usuário quer usar. 	*/
int confirma_id (char id[]) {
	
	char	op;	/* Esta variável armazenará o SIM ou o NÃO do usuário quando for pedido para que ele confirme se este é o identificador que ele quer usar. */
	
	printf("\nID: %s. Confirma? (S/N): ", id);	/* ID é a string que contém o nickname do usuário. */
	scanf("%c", &op);
	while (getchar() != '\n');
	
	switch (op) {	/* Aqui, o programa só toma o nick inserido como confirmado se o usuário disser SIM. */
		case 'S':
		case 's':
			/* Aqui a função retorna 0 e encerra o DO-WHILE que mantém a interface de confirmação rodando. */
			return (0);
			break;
		default:
			/* Aqui a função retorna 1 e o DO-WHILE não se encerra. A função só toma o nickname como confirmado se o usuário digitar S ou s. */
			limpar_tela_noenter ();
			return (1);
			break;
			
	}	
	
}


/* 	FUNÇÃO CONFORME_SEJA_OP_INICIAL: esta função realiza alguma ação com base no que o usuário escolheu como opção no menu inicial. 	*/
void conforme_seja_op_inicial (int op, int *opm, usuario *jogador) {
	
	switch (op) {
		case 1: 
			/* De forma resumida, JOGAR recebe três informações: o gênero musical escolhido, o nick do usuário e os pontos que ele já fez até agora. */
			jogar (*opm, jogador);
			break;
		case 2: 
			/* CONFIG mostra ao usuário o menu de configurações e com base em OPM alguma das opções é realçada. */
			config (opm);
			break;
		case 3:	
			/* RANKING mostra a classificação ao usuário. O usuário atual não entra para o ranking enquanto ele não encerrar o jogo. */ 
			ranking ();
			break;
		case 4: 
			/* Somente quando o usuário sai do programa seu nome de usuário é registrado na classificação. */
			mudar_classificacao (*jogador);
			agradecimento (jogador);
			/* Uma contagem dos pontos e uma mensagem de agradecimento é mostrada ao usuário. */
			break;
		default:
			/* Aqui o programa avisa ao usuário que foi inserida uma opção inválida. */
			op_invalida ();
			break;
	}
		
}


/*	FUNÇÃO COPIAR_STRING: copia STRING2 para STRING1.	*/
void copiar_string (char string1[], char string2[]) {
	
	int	i;
		
	/* Enquanto STRING2 não chegar ao fim, ela será copiada caracter por caracter para STRING1. */
	for (i = 0; string2[i] != '\0'; i++) 
		string1[i] = string2[i];
		
	/* Por fim, depois que STRING2 se esgotar, um '\0' é acrescentado no final de STRING1. */
	string1[i] = '\0';
	
}


/* 	FUNÇÃO GENRANDOM: esta função é responsável por gerar uma sequência parcialmente aleatória de N números de 0 a N-1 sem repetição de números. Explicarei a importância desta sequência nas funções JOGAR mais adiante. Spoiler: são os índices dos vetores que contém o trecho e o título da música. 	*/
void genrandom (int random[], int nummus) {

	int	i,
		j,
		num,	/* Esta será a variável que abrigará o valor temporário dado pela função RAND. */
		existe;	/* EXISTE terá função bastante sugestiva que será explicada mais pra frente. */
	
	srand(time(NULL));
	/* Aqui a seed é resetada para que a cada execução do programa as sequências mudem. */
	
	for (i = 0; i < nummus; i++) {
		
		num = rand() % nummus;	
		/* Aqui NUM recebe um número pseudo-aleatório. */
		
		/* Aqui é feita um checagem: um novo número aleatório é gerado se for gerado um número que NUM já assumiu anteriormente. Na primeira execução, o teste não importa. Nas outras execuções, o teste é importante para que a sequência não tenha elementos iguais. Por isto chamei a sequência de pseudo-aleatória: uam vez que um número aparece dentre todas as possibilidades, ele não pode mais aparecer. */
		do {
		
			num = rand() % nummus;
			/* Um novo número NUM é gerado. */
			
			existe = 0;
			/* Aqui EXISTE começa a receber uma utilidade: o programa supõe que não exista nenhuma número igual a NUM na sequência e EXISTE recebe 0. O teste para saber se a suposição está correta acontece logo abaixo. */
			
			/* Aqui o programa varre o vetor RANDOM em busca de um número que seja igual ao número que acabou de ser gerado. */
			for (j = 0; (j < i)&&(!existe); j++) 
				if (num == random[j])	/* Se o número NUM já tiver sido gerado... */
					existe = 1;	/* EXISTE recebe 1, sinalizando que um número igual a NUM já foi gerado. O laço FOR se encerra e o laço DO-WHILE recomeça. */
		
		}
		
		while (existe);
		/* Este laço será executado enquanto o um número igual a NUM existir dentro do vetor que armazena os números gerados, o vetor RANDOM. */
		
		random[i] = num;
		/* Se NUM passar pelos testes e for considerada apto, ele entra para a sequência. */
	
	}
	
}


/* 	FUNÇÃO IDENTIFICADOR: esta função é responsável por ler mostrar a interface de leitura do nickname ao usuário. 	*/
void identificador (char id[]) {
	
	int 	tam,	/* TAM armazena o tamanho do nick inserido. */
		ok;	/* Esta variável é responsável por armazenar o retorno da função CONFIRMA_ID, que pede ao usuário que confirme se o nickname inserido é o que ele quer usar. A função retorna 1 se o usuário não confirmar e 0 se ele confirmar. */
	
	do {	/* Aqui a função entra num DO-WHILE e só sai dele quando CONFIRMA_ID retornar 0. */
	
		limpar_tela_noenter ();
		tam = le_id (id);	
		/* Aqui a função LE_ID lê o input do usuário e retorna o tamanho da string composta pelo nickname que o usuário inseriu. */
		
		while ((tam > 20) || (tam < 3)) {	/* Isto aqui pede ao usuário para que ele insira um nickname válido enquanto o nick inserido tiver menos de 3 ou mais de 20 caracteres. */
	
			printf("\nNumero de caracteres invalido!\n");
			
			limpar_tela ();
			
			tam = le_id (id);
			/* Novamente LE_ID lê o input do usuário e retorna o tamanho da string. */
		
		}
		
		ok = confirma_id (id);	/* Aqui a função CONFIRMA_ID mostra a interface de confirmação do nickname e retorna algum valor com base na confirmação ou não do nickname pelo usuário. */
		
	} while (ok);	
	/* A função só sairá deste loop quando o usuário inserir e confirmar um nickname válido. A função CONFIRMA_ID, neste caso, retornará 0, e o WHILE se encerrará. */
	
}


/* 	FUNÇÃO JOGAR: é ela que vai "invocar" as partidas conforme o gênero musical escolhido. 	*/
void jogar (int opm, usuario *jogador) {
	
	switch (opm) {	/* Note como cada um dos estilos musicais tem sua própria contagem de pontos. Fiz assim para que não se somem pontos a cada vez que se joga, e sim para que se substituam os pontos feitos anteriormente pelos pontos feitos na última rodada. */ 
		case 1:
			jogador->ptsrock = partida_rock (jogador->user);
			break;
		case 2:
			jogador->ptsfunk = partida_funk (jogador->user);
			break;
		case 3:
			jogador->ptsmpb = partida_mpb (jogador->user);
			break;
		case 4: 
			jogador->ptspop = partida_pop (jogador->user);
			break;
	}
	
	limpar_tela ();
		
}


/*	FUNÇÃO JOGAR_FUNK: a família de funções JOGAR_ESTILO é chamada pela família de funções PARTIDA_ESTILO. As funções JOGAR_ESTILO são resposáveis por conectar a leitura de respostas, a seleção de músicas aleatórias e a contagem de pontos individuais dos estilos. 	*/ 
void jogar_funk (int *pontos, int *acertos) {

	int	tent,	/* TENT armazena o número de tentativas do usuário em uma rodada da partida. */
		ok = 1,	/* OK armazena o retorno da função TESTADOR (explicarei seu funcionamento mais adiante). TESTADOR retorna 0 se a resposta inserida pelo usuário não for correta e retorna 1 se for correta. Ela vale inicialmente 1 para que inicialmente a condição no FOR ali em baixo seja verdadeira. */
		nummus,		/* Armazenará o número de músicas lido no arquivo texto. */
		numversos,	/* Armazenará o número de versos lido no arquivo texto. */
		tam,	/* TAM receberá o tamanho de um trecho lido do arquivo texto. A aplicação disto será evidenciada mais pra frente na função. */
		*random,	/* *RANDOM armazenará o endereço de um vetor que será alocado dinâmicamente durante a execução da função. É a variável que armazenará a sequência de números pseudo-aleatórios gerados pelo gerador de números pseudo-aleatórios. Agora explico para que serve esta sequência: cada um dos elementos são índices das variáveis FUNK[].TITULO e FUNK[].TRECHO ali em baixo. Como será gerada uma sequência pseudo-aleatória (chamei-a assim porque os número não se repetem nunca uma vez que são gerados) a cada execução do programa, as músicas serão mostradas em ordem diferente para o usuário. */
		i,	/* I e J são somente variáveis de contagem. */
		j;

	FILE	*arq;	/* ARQ é a variável que usarei para acessar o arquivo texto contendo as músicas. */
		
	char	teste,	/* TESTE armazenará alguns '\n' durante a leitura do arquivo texto. O porquê disto será evidenciado daqui a pouco. */
		temp[100],	/* TEMP armazenará algum trecho imediatamente lido do arquivo texto. Você já deve estar cansado disto, mas o que porquê dele existir ficará mais claro mais para frente na função. */
		resp[250];	/* RESP armazena a resposta que o usuário inseriu. */
		
	arq = fopen("funk.txt", "r");
	/* Aqui o arquivo corresponde à opção musical FUNK é aberto para leitura. */
	
	fscanf(arq, "%d\n", &nummus);
	/* A primeira coisa que esta função JOGAR_FUNK precisa determinar é a quantidade de músicas no arquivo texto. Este valor está convenientemente localizado na primeira linha seguido de um '\n', que é "consumido" durante a leitura de NUMMUS. */
	
	musica	*funk;
	/* Aqui é criado um ponteiro de MUSICA chamado *FUNK que armazenará o endereço de um vetor de MUSICA que será dinamicamente alocado conforme o numéro de músicas no arquivo. */
	
	funk = (musica *) malloc (nummus * sizeof (musica));
	/* Aqui a alocação dinâmica mencionada logo acima acontece. */
	
	/* Aqui as músicas serão lidas do arquivo texto e devidamente armazenadas no vetor FUNK num loop FOR que é executado para cada música. */
	for (i = 0; i < nummus; i++) {
		
		fscanf(arq, "%200[^\n]", funk[i].titulo);
		/* Aqui o título da música é lido. O limite de caracteres no titulo da música é 200. */
		
		fscanf(arq, "%c", &teste);
		/* Aqui a função mais uma vez "consome" o '\n' que vem logo após o título da música. Como o título da música será a referência adotada pelo programa como a resposta correta, ele não pode ter um '\n' no final. */
		
		fscanf(arq, "%d\n", &numversos);
		/* Aqui o número de versos é lido do arquivo texto e o '\n' seguinte é devidamente consumido (usarei a palavra consumido desse jeito mesmo, sem aspas). */
		
		/* Dentro deste loop FOR serão lidos os versos da música em questão de acordo com o número de versos NUMVERSOS que foram lidos do arquivo texto. */
		for (j = 0; j < numversos; j++) {
		
			/* Os versos terão que ser lidos um por um e armazenados num vetor só. A cada leitura depois da primeira, os versos terão de ser concatenados uns nos outros. Aqui neste IF é o que acontece quando J é igual a 0. */
			if (!j) {
			
				fscanf(arq, "%70[^\n]", funk[i].trecho);
				/* O primeiro verso é lido. O limite de caracteres para cada verso é 70. */
				
				/* Aqui explico para que TAM serve: ele armazena o tamanho do trecho, que convenientemente tem o mesmo valor do índice do caracter '\0' no vetor. O que acontece então é que é adicionado um '\n' no fim do verso. Assim, mostrar a letra da música ao usuário é um pouco mais fácil .*/
				tam = tamanho_string (funk[i].trecho);
				funk[i].trecho[tam] = '\n';
				funk[i].trecho[tam+1] = '\0';
				
			} else { 
			
				fscanf(arq, "%70[^\n]", temp);
				/* Aqui os versos seguintes ao primeiro são lidos. */
				
				tam = tamanho_string (temp);
				/* Aqui algo parecido com o que aconteceu acima acontece: a função localiza o '\0' no vetor e acrescenta um '\n' antes dele. */
				
				temp[tam] = '\n';
				temp[tam+1] = '\0';
				/* Tive de usar esta variável TEMP para armazenar o verso e acrescentar o '\n' no final antes de ele ser concatenado no resto da letra da música. */ 
				
				/* Como neste ELSE estamos tratando dos versos seguintes ao primeiro, eles precisam ser emendados no primeiro. A função CONCATENAR_STRING faz exatamente o que ela sugere: concatena dois versos. */
				concatenar_string (funk[i].trecho, temp);
			}
			
			/* Aqui está a utilidade de TESTE: ele consome o '\n' ao final de cada verso lido para que o ponteiro do arquivo aponte para o começo do próximo verso. */
			fscanf(arq, "%c", &teste);
			
		}	/* Aqui, depois de todas as iterações, a leitura de versos de uma das músicas termina. A função então volta para o topo para ler a próxima música, quando houver. */	
			
	}	/* Aqui a leitura de cada música termina. */
	
	/* Aqui aquele vetor RANDOM entra em jogo: ele será dinamicamente alocado conforme o número de música. */
	random = (int *) malloc (nummus * sizeof(int));
	
	genrandom (random, nummus);
	/* Aqui a sequência pseudo-aleatória é gerada e armazenada em RANDOM. */	
	
	for (i = 0; ((i < nummus)&&(ok)); i++) {	/* As músicas serão mostradas enquanto todas não tiverem sido mostradas e enquanto o usuário não tiver errado duas vezes seguidas. Quando ele erra duas vezes seguidas, a contagem de pontos é mostrada e a partida se encerra. */
	
		tent = 0;
		/* Aqui o número de partidas é reiniciado para cada música. */
	
		/* Note como RANDOM[i] está servindo de índice para FUNK[].TRECHO. */
		printf("\nTente acertar o nome da musica:\n\n%s", funk[random[i]].trecho);	
		/* Aqui é mostrado o trecho da música selecionada pseudo-aleatoriamente ao usuário. (não sei se a palavra pseudo-aleatório existe mesmo, mas é a que torna o entendimento mais fácil, pelo menos pra mim rs) */
	
		while ((tent == 0)||(tent == 1)) { 	/* Aqui neste WHILE a função se mantém esperando uma resposta do usuário enquanto ele não acertar e não exceder o número de tentativas. */
		
			/* Aqui a resposta do usuário é lida. (com no máximo 200 caracteres, respeitando os limites do título da música. */
			printf(">>");
			scanf("%200[^\n]", resp);	
			while(getchar() != '\n');
	
			ok = testador (resp, funk[random[i]].titulo, &tent, pontos, acertos);
			/* Aqui, TESTADOR testa a resposta do usuário e manipula os valores dos pontos e dos acertos do usuário. A função retorna 0 se a resposta estiver errada e, caso o usuário erre duas vezes, o FOR lá de cima é encerrado. A função retorna 1 se a reposta estiver correta. */
			
		}	/* Aqui termina o WHILE que conta o número de tentativas. */
		
	}	/* Aqui termina o FOR que mostra todas as músicas ao usuário. */
	
	/* Aqui o arquivo texto é fechado e a memória ocupada pelo vetor RANDOM e pelo vetor de MUSICA FUNK é liberada. */
	fclose(arq);
	free(random);
	free(funk);
	
}


/*	FUNÇÃO JOGAR_MPB: as funções JOGAR_ESTILO estão no mesmo molde, as únicas coisas que variam são as músicas. Pouparei comentários nas próximas funções. 	*/
void jogar_mpb (int *pontos, int *acertos) {

	int	tent,
		ok = 1,
		nummus,
		numversos,
		tam,
		*random,
		i,
		j;

	FILE	*arq;
		
	char	teste,
		temp[100],
		resp[250];
		
	arq = fopen("mpb.txt", "r");
	
	fscanf(arq, "%d\n", &nummus);
	
	musica	*mpb;
	
	mpb = (musica *) malloc (nummus * sizeof (musica));
	
	for (i = 0; i < nummus; i++) {
	
		fscanf(arq, "%200[^\n]", mpb[i].titulo);
		fscanf(arq, "%c", &teste);
		fscanf(arq, "%d\n", &numversos);
		
		for (j = 0; j < numversos; j++) {
		
			if (!j) {
			
				fscanf(arq, "%70[^\n]", mpb[i].trecho);
				
				tam = tamanho_string (mpb[i].trecho);
				mpb[i].trecho[tam] = '\n';
				mpb[i].trecho[tam+1] = '\0';
				
			} else { 
			
				fscanf(arq, "%70[^\n]", temp);
				
				tam = tamanho_string (temp);
				temp[tam] = '\n';
				temp[tam+1] = '\0';
				concatenar_string (mpb[i].trecho, temp);
				
			}
			
			fscanf(arq, "%c", &teste);
				
		}	
	}
	
	random = (int *) malloc (nummus * sizeof(int));
	
	genrandom (random, nummus);
	
	for (i = 0; ((i < nummus)&&(ok)); i++) {
	
		tent = 0;
		
		printf("\nTente acertar o nome da musica:\n\n%s", mpb[random[i]].trecho);
		
		while ((tent == 0)||(tent == 1)) {
		
			printf(">>");
			scanf("%200[^\n]", resp);	
			while(getchar() != '\n');
			
			ok = testador (resp, mpb[random[i]].titulo, &tent, pontos, acertos);	
		}
	}

	fclose(arq);
	free(random);
	free(mpb);
	
}


/* 	FUNÇÃO JOGAR_POP 	*/
void jogar_pop (int *pontos, int *acertos) {

	int	tent,
		ok = 1,
		nummus,
		numversos,
		tam,
		*random,
		i,
		j;

	FILE	*arq;
		
	char	teste,
		temp[100],
		resp[250];
		
	arq = fopen("pop.txt", "r");
	
	fscanf(arq, "%d\n", &nummus);
	
	musica	*pop;
	
	pop = (musica *) malloc (nummus * sizeof (musica));
	
	for (i = 0; i < nummus; i++) {
	
		fscanf(arq, "%200[^\n]", pop[i].titulo);
		fscanf(arq, "%c", &teste);
		fscanf(arq, "%d\n", &numversos);
		
		for (j = 0; j < numversos; j++) {
		
			if (!j) {
			
				fscanf(arq, "%70[^\n]", pop[i].trecho);
				
				tam = tamanho_string (pop[i].trecho);
				pop[i].trecho[tam] = '\n';
				pop[i].trecho[tam+1] = '\0';
				
			} else { 
			
				fscanf(arq, "%70[^\n]", temp);
				
				tam = tamanho_string (temp);
				temp[tam] = '\n';
				temp[tam+1] = '\0';
				concatenar_string (pop[i].trecho, temp);
				
			}
			
			fscanf(arq, "%c", &teste);
			
		}	
	}
	
	random = (int *) malloc (nummus * sizeof(int));
	
	genrandom (random, nummus);
	
	for (i = 0; ((i < nummus)&&(ok)); i++) {
	
		tent = 0;
		
		printf("\nTente acertar o nome da musica:\n\n%s", pop[random[i]].trecho);
		
		while ((tent == 0)||(tent == 1)) {
		
			printf(">>");
			scanf("%200[^\n]", resp);	
			while(getchar() != '\n');
			
			ok = testador (resp, pop[random[i]].titulo, &tent, pontos, acertos);	
		}
	}

	fclose(arq);
	free(random);
	free(pop);
	
}


/* 	FUNÇÃO JOGAR_ROCK 	*/
void jogar_rock (int *pontos, int *acertos) {

	int	tent,
		ok = 1,
		numversos,
		nummus,
		tam,
		*random,
		i,
		j;

	FILE	*arq;
		
	char	teste,
		temp[100],
		resp[250];
	
	arq = fopen("rock.txt", "r");
	
	fscanf(arq, "%d\n", &nummus);
		
	musica	*rock;
	
	rock = (musica *) malloc (nummus * sizeof (musica));
	
	for (i = 0; i < nummus; i++) {
	
		copiar_string (temp, "\0");
	
		fscanf(arq, "%200[^\n]", rock[i].titulo);
		fscanf(arq, "%c", &teste);
		fscanf(arq, "%d\n", &numversos);
		
		for (j = 0; j < numversos; j++) {
		
			if (j == 0) {
			
				fscanf(arq, "%70[^\n]", rock[i].trecho);
				
				tam = tamanho_string (rock[i].trecho);
				rock[i].trecho[tam] = '\n';
				rock[i].trecho[tam+1] = '\0';
							
			} else { 
			
				fscanf(arq, "%70[^\n]", temp);
				
				tam = tamanho_string (temp);
				temp[tam] = '\n';
				temp[tam+1] = '\0';
				concatenar_string (rock[i].trecho, temp);
				
			}
			
			fscanf(arq, "%c", &teste);
	
		}	
	}
	
	random = (int *) malloc (nummus * sizeof(int));
	
	genrandom (random, nummus);
	
	for (i = 0; (i < nummus)&&(ok); i++) {
	
		tent = 0;
		
		printf("\nTente acertar o nome da musica:\n\n%s", rock[random[i]].trecho);
		
		while ((tent == 0)||(tent == 1)) {
		
			printf(">>");
			scanf("%200[^\n]", resp);	
			while(getchar() != '\n');
			
			ok = testador (resp, rock[random[i]].titulo, &tent, pontos, acertos);	
		}
	}
	
	fclose(arq); 
	free(random);
	free(rock);
	
}


/* 	FUNÇÃO LE_ID: esta função efetivamente lê o nickname inserido pelo usuário. 	*/
int le_id (char id[]) {
	
	int	leu;	/* Esta variável guardará o valor de retorno do SCANF que lê o nickname. Se a função não conseguir ler nada, o programa pede ao usuário para que insira um nickname válido. */
	
	printf("\nDigite seu identificador (de 3 a 20 caracteres):");
	printf("\n>>");
	
	leu = scanf("%[^\n]", id); 	/* Só um recap: ID é a string onde será guardado o nickname inserido. No fundo, modificações nesta string são modificações na variável USER declarada na MAIN. */
	while (getchar() != '\n');
	
	return (leu)?(tamanho_string(id)):(-1);	
	/* LE_ID retorna o valor do tamanho do nickname para que o identificador possa tratar este dado. Se o SCANF não tiver conseguido ler coisa alguma, a função retorna -1, que é um valor inválido para o tamanho de uma cadeia de caracteres. */
	
}


/* 	FUNÇÃO LER_OP_INICIAL: esta função lê e retorna a opção que o usuário escolheu no menu inicial.	 */
int ler_op_inicial (void) {
	
	int	op = 0;	/* Aqui será guardada a opção escolhida pelo usuário. Caso o usuário insira um caracter que não seja um número inteir, a função SCANF não conseguirá atribuir nenhum valor a OP. Para indicar que o valor inserido era inválido, OP inicialmente vale 0, um valor inválido. */
	
	scanf("%d", &op);
	while(getchar() != '\n');
	
	return (op);	/* Aqui a função retorna a opção escolhida. */
	
}


/* 	FUNÇÃO LIMPAR_TELA: esta função é responsável por limpar a tela com um peculiaridade: ela espera o usuário pressionar ENTER para continuar. 	*/
void limpar_tela (void) {
	
	printf("\nPressione ENTER para continuar.\n");
	while(getchar() != '\n');
	
	system("clear");	/* Este é o comando base. É ele que realmente limpa o terminal. Este aqui só funciona em Linux, no entanto. */

}


/*	FUNÇÃO LIMPAR_TELA_NOENTER: é uma prima da função LIMPA_TELA. Esta, no entanto, limpa a tela sem esperar nenhum input do usuário.	 */
void limpar_tela_noenter (void) {
	
	system("clear");
	
}


/* 	FUNÇÃO MENU_INICIAL: esta função é a que é responsável pela interface do menu principal.	 */
char menu_inicial (usuario jogador) {
	
	mostrar_ops_inicial (jogador);	
	/* Aqui ela chama MOSTRAR_OPS_INICIAL, que mostra as opções disponíveis do menu para o usuário. */
	
	return (ler_op_inicial());
	/* Aqui MENU_INICIAL chama LER_OP_INICIAL. Esta última função lê e retorna a opção escolhida pelo usuário no menu inicial. MENU_INICIAL também retorna este valor, mas agora para a variável OP da função MAIN. */

}


/* 	FUNÇÃO MOSTRAR_OPS_INICIAL: esta função imprime as opções do menu inicial na tela e mostra a pontuação atual do usuário. 	*/
void mostrar_ops_inicial (usuario jogador) {

	/* A pontuação atual do usuário é mostrada no menu principal. */
	printf("\nPontuacao atual:");
	printf("\nRock: %d pontos", jogador.ptsrock);
	printf("\tFunk: %d pontos", jogador.ptsfunk);
	printf("\nMPB: %d pontos", jogador.ptsmpb);
	printf("\tPOP: %d pontos", jogador.ptspop);
	printf("\n\nEscolha uma opcao do menu:");
	printf("\n1. Jogar");
	printf("\n2. Configuracoes");
	printf("\n3. Ranking");
	printf("\n4. Sair do jogo");
	printf("\n>>");

}


/* 	FUNÇÃO MOSTRAR_OPS_CONFIG: esta outra função é bem parecida com a de cima. Ela imprime o menu de configurações conforme a opção musical escolhida. 	*/
void mostrar_ops_config (int opm) {

	switch (opm) {
		case 1:	
			printf("\nEscolha o estilo de musica:\n");
			printf("1 - Rock <<\n");
			printf("2 - Funk\n");
			printf("3 - MPB\n");
			printf("4 - Pop\n");
			printf("5 - Voltar ao menu anterior\n>>");
			break;
		case 2:	
			printf("\nEscolha o estilo de musica:\n");
			printf("1 - Rock\n");
			printf("2 - Funk <<\n");
			printf("3 - MPB\n");
			printf("4 - Pop\n");
			printf("5 - Voltar ao menu anterior\n>>");
			break;
		case 3:	
			printf("\nEscolha o estilo de musica:\n");
			printf("1 - Rock\n");
			printf("2 - Funk\n");
			printf("3 - MPB <<\n");
			printf("4 - Pop\n");
			printf("5 - Voltar ao menu anterior\n>>");	
			break;
		case 4:	
			printf("\nEscolha o estilo de musica:\n");
			printf("1 - Rock\n");
			printf("2 - Funk\n");
			printf("3 - MPB\n");
			printf("4 - Pop <<\n");
			printf("5 - Voltar ao menu anterior\n>>");
			break;
		case 5:
			/* Esta opção "desnatada", sem setas, é usada pelo menu da função RANKING. */
			printf("\nEscolha o estilo de musica:\n");
			printf("1 - Rock\n");
			printf("2 - Funk\n");
			printf("3 - MPB\n");
			printf("4 - Pop\n");
			printf("5 - Voltar ao menu anterior\n>>");
			break;
	}
	
}


/* 	FUNÇÃO MUDAR_CLASSIFICACAO: esta função é responsável por alterar a classificação atual que está registrada num arquivo binário. Ela só é "sumonada" quando o usuário seleciona a opção de saída do jogo no menu principal.	*/
void mudar_classificacao (usuario playa) {
		
	FILE	*ranking;
	/* Este aqui será o ponteiro que usarei para acessar o arquivo binário. */
	
	int 	i,
		k,	/* Todas estas três são variáveis de contagem. */
		mus;
	
	char	nomearq[10],	/* NOMEARQ armanazenará o nome do arquivo conforme a opção musical escolhida. */
		estilo[4][10] = {"rock.bin", "funk.bin", "mpb.bin", "pop.bin"};
		/* Aqui em ESTILO estão armazenados os nomes dos arquivos binários que guardarão a classificação. */
	
	/* Este FOR percorre os quatro estilos musicais enquanto registra o o usuário atual na classificação. */
	for (mus = 0; mus < 4; mus++) {
	
		usuariotemp	jogador[10];
		/* Aqui um vetor de USUARIOTEMP JOGADOR é criado. Ele guardará, no máximo, os 10 últimos usuários que jogaram o jogo. O usuário atual será futuramente colocado neste vetor. */
	
		copiar_string (nomearq, estilo[mus]);
		/* Aqui o nome do arquivo será determinado pelo estilo musical. */
		
		ranking = fopen(nomearq, "rb");
		/* Aqui o arquivo é aberto para leitura. */
		
		if (ranking == NULL)
			ranking = fopen(nomearq, "w+b");
			/* Se ele não existir, ele será criado, mas somente será utilizado para leitura. */
	
		for (i = 0; (i < 10)&&(fread(&jogador[i], sizeof(usuariotemp), 1, ranking)); i++);
		/* Aqui a função lê o arquivo binário até que se chegue no fim do arquivo. I, no final, indicará quantos usuário foram lidos. */
		
		k = i;
		/* K guardará o número de usuários lidos. */
		
		/* Aqui o programa se comporta de maneiras diferentes conforme o número de usuário lidos. */
		if (k == 10)	/* Todos os jogadores com exceção do último no vetor são jogados uma posição para trás. As trocas acontecem do final ao começo do vetor. Quando K é 10, como JOGADOR[10] não existe, I começa em K-1. */
			for (i = (k-1); i > 0; i--)
				jogador[i] = jogador[i-1];
		else	/* Aqui, como K é menor do que 10 jogadores, I pode começar de K. */
			for (i = k; i > 0; i--)
				jogador[i] = jogador[i-1];
		
		copiar_string (jogador[0].user, playa.user);
		/* O usuário atual é copiado no primeiro elemento do vetor JOGADOR[]. Primeiramente seu nickname é copiado. */
		
		/* Aqui seus pontos são copiados para o primeiro elemento do vetor JOGADOR[] de acordo com a opção musical em questão. */
		switch (mus) {
			case 0:
				jogador[0].pontos = playa.ptsrock;
				break;
			case 1:
				jogador[0].pontos = playa.ptsfunk;
				break;
			case 2:
				jogador[0].pontos = playa.ptsmpb;
				break;
			case 3:
				jogador[0].pontos = playa.ptspop; 
				break;
		}
		
		fclose(ranking);
		/* Como as informações do arquivo binário já foram salvas, ele é fechado. */
		
		/* Depois que ele é fechado, ele é aberto novamente, mas é recriado. */
		ranking = fopen(nomearq, "w+b");
		
		/* Aqui a função copia o vetor para o arquivo binário. */
		if (k == 10) {	/* O índice de jogadores só precisa ir de 0 a K-1 quando K é 10. */
			for (i = 0; i < k; i++) {
				fwrite(&jogador[i], sizeof(usuariotemp), 1, ranking);
			}
		} else {	/* Quando K é menor do que 10, a regra muda um pouco. I talvez devesse ir de 0 a K-1 porque K é o número de jogadores que foram lidos do arquivo binário. Entretanto, o usuário atual precisa ser inserido na nova escrita, então I vai de 0 a K. */
			for (i = 0; i < (k+1); i++) {
				fwrite(&jogador[i], sizeof(usuariotemp), 1, ranking);
			}
		}
	
		fclose(ranking); /* Aqui o arquivo binário é finalmente fechado. */

	}
		
}


/* 	FUNÇÃO OP_INVALIDA: esta função exibe uma mensagem de erro quando o usuário digita alguma opção inválida.	 */
void op_invalida (void) {
	
	printf("\nErro! Digite uma das opcoes validas!\n");
	limpar_tela ();
	
}


/* 	FUNÇÃO PARTIDA_FUNK: aqui chegamos à família de funções PARTIDA_ESTILO. Elas são responsáveis por administrar e imprimir os pontos e acertos feitos pelo usuário durante a partida.	*/
int partida_funk (char user[]) {	/* Este USER é o mesmo USER da MAIN e o mesmo ID de outras funções já vistas. */
	
	FILE	*arq;	/* Este será o ponteiro do arquivo. */
	
	int	pontos = 0,	/* Os pontos não são acumulados se o usuário já jogou neste gênero. Por isto a contagem de pontos é reiniciada. */
		acertos = 0,	/* Os acertos também não são acumulados. */
		num,	/* NUM armazena o número de músicas que será lido do começo do arquivo texto. */
		leu;	/* LEU guarda o valor de retorno de FSCANF. Se ele não conseguir ler coisa alguma na primeira linha do arquivo texto, algo está errado. */
	
	limpar_tela_noenter ();
	
	printf("\nFunk escolhido.\n");
	
	arq = fopen("funk.txt", "r");
	/* Aqui o arquivo texto contendo as músicas de funk é aberto para leitura. */
	
	if (arq == NULL)	
		printf("\nArquivo texto nao encontrado!\n");	/* Aqui, caso o arquivo não seja encontrado, uma mensagem é mostrada ao usuário. */
		
	else {
	
		leu = fscanf(arq, "%d\n", &num);
		/* Aqui LEU recebe o valor de retorno de FSCANF e NUM recebe o número lido na primeira linha. */
		
		fclose(arq);
		/* Aqui o arquivo é fechado já que JOGAR_FUNK terá que acessá-lo mais tarde. */
	
		/* Caso o primeiro número no arquivo texto não seja um número, o usuário é avisado de que há algo errado com o arquivo texto. */
		if (!leu)
			printf("\nO arquivo texto nao pode ser lido! (existem possiveis erros estruturais no arquivo)\n");	
		
		else {	
			if (num < 4) {
			
				/* Aqui a função JOGAR_FUNK não é nem chamada se o número de músicas for menor do que 4. */
				printf("\nHa somente %d ", num);
				(num == 1)?(printf("musica no arquivo! ")):(printf("musicas no arquivo! "));
				/* Mantendo a concordância gramatical. rs */
				printf("Este numero eh insuficiente. ");
				printf("\nPara jogar neste estilo musical, eh preciso que no arquivo texto ");
				printf("existam pelo menos 4 musicas disponiveis.\n");
				
			} else if ((num >= 4)&&(num < 10)) {
		
				/* Se o número de músicas for maior do que 4 porém menor do que 10, o usuário é avisado de que sua diversão não está garantida. */
				printf("\nATENCAO:"); 
				printf("\nO numero de musicas eh insuficiente para que sua diversao possa ser garantida!");
				printf("\nSao necessarias pelo menos 10 musicas para que a diversao seja completa!");
				printf("\nO jogo continuara, mas TEJE AVISADO, MELIANTE!\n");
				limpar_tela ();
		
				/* Aqui é chamada alguma função da família JOGAR_ESTILO para que ela mostre toda a interface da jogatina e manipule os pontos e acertos. */
				jogar_funk (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos);
				/* Aqui é mostrada no fim da rodada a contagem dos pontos e acertos. */
				
			} else if ((num >= 10)&&(num <= 50)) {	/* Aqui o programa se comporta normalmente caso o número de músicas esteja entre 10 e 50. */
		
				jogar_funk (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else 	/* Aqui o programa avisa o usuário que o programa não suporta mais de 50 músicas. */
				printf("\nMe parece que o arquivo texto tem mais de 50 musicas! O maximo suportado eh 50.\n");
			
		}
		
	}
	
	return pontos;
	/* Os pontos são retornados para que eles possam ser armazenados na família de variáveis PTSESTILO e assim eles integram a soma total dos pontos. */

}


/* 	FUNÇÃO PARTIDA_MPB: todas as funções da família PARTIDA_ESTILO seguem o mesmo padrão. Pouparei comentários.	 */
int partida_mpb (char user[]) {
	
	FILE	*arq;
	
	int	pontos = 0,	
		acertos = 0,
		num,
		leu;		
	
	limpar_tela_noenter ();
	
	printf("\nMPB escolhido.\n");
	
	arq = fopen("mpb.txt", "r");
	
	if (arq == NULL)	
		printf("\nArquivo texto nao encontrado!\n");
		
	else {
	
		leu = fscanf(arq, "%d\n", &num);
		
		fclose(arq);
	
		if (!leu)
			printf("\nO arquivo texto nao pode ser lido!\n");
		
		else {	
			if (num < 4) {
			
				printf("\nHa somente %d ", num);
				(num == 1)?(printf("musica no arquivo! ")):(printf("musicas no arquivo! "));
				printf("Este numero eh insuficiente. ");
				printf("\nPara jogar neste estilo musical, eh preciso que no arquivo texto ");
				printf("existam pelo menos 4 musicas disponiveis.\n");
				
			} else if ((num >= 4)&&(num < 10)) {
		
				printf("\nATENCAO:"); 
				printf("\nO numero de musicas eh insuficiente para que sua diversao possa ser garantida!");
				printf("\nSao necessarias pelo menos 10 musicas para que a diversao seja completa!");
				printf("\nO jogo continuara, mas TEJE AVISADO, MELIANTE!\n");
				limpar_tela ();
		
				jogar_mpb (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else if ((num >= 10)&&(num <= 50)) {
		
				jogar_mpb (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else
				printf("\nMe parece que o arquivo texto tem mais de 50 musicas! O maximo suportado eh 50.\n");
		}
		
	}
		
	return pontos;

}


/* 	FUNÇÃO PARTIDA_POP	 */
int partida_pop (char user[]) {
	
	FILE	*arq;
	
	int	pontos = 0,	
		acertos = 0,
		num,
		leu;		
	
	limpar_tela_noenter ();
	
	printf("\nPop escolhido.\n");
	
	arq = fopen("pop.txt", "r");
	
	if (arq == NULL)
		printf("\nArquivo texto nao encontrado!\n");
		
	else {
	
		leu = fscanf(arq, "%d\n", &num);
		
		fclose(arq);
	
		if (!leu)
			printf("\nO arquivo texto nao pode ser lido!\n");
		
		else {	
			if (num < 4) {
			
				printf("\nHa somente %d ", num);
				(num == 1)?(printf("musica no arquivo! ")):(printf("musicas no arquivo! "));
				printf("Este numero eh insuficiente. ");
				printf("\nPara jogar neste estilo musical, eh preciso que no arquivo texto ");
				printf("existam pelo menos 4 musicas disponiveis.\n");
				
			} else if ((num >= 4)&&(num < 10)) {
		
				printf("\nATENCAO:"); 
				printf("\nO numero de musicas eh insuficiente para que sua diversao possa ser garantida!");
				printf("\nSao necessarias pelo menos 10 musicas para que a diversao seja completa!");
				printf("\nO jogo continuara, mas TEJE AVISADO, MELIANTE!\n");
				limpar_tela ();
		
				jogar_pop (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else if ((num >= 10)&&(num <= 50)) {
		
				jogar_pop (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else
				printf("\nMe parece que o arquivo texto tem mais de 50 musicas! O maximo suportado eh 50.\n");
			
		}
		
	}
		
	return pontos;

}


/* 	FUNÇÃO PARTIDA_ROCK	 */
int partida_rock (char user[]) {
	
	FILE	*arq;
	
	int	pontos = 0,	
		acertos = 0,
		num,
		leu;	
	
	limpar_tela_noenter ();
	
	printf("\nRock escolhido.\n");
	
	arq = fopen("rock.txt", "r");
	
	if (arq == NULL)	
		printf("\nArquivo texto nao encontrado!\n");
		
	else {
	
		leu = fscanf(arq, "%d\n", &num);
		
		fclose(arq);
	
		if (!leu)
			printf("\nO arquivo texto nao pode ser lido!\n");
		
		else {	
			if (num < 4) {
			
				printf("\nHa somente %d ", num);
				(num == 1)?(printf("musica no arquivo! ")):(printf("musicas no arquivo! "));
				printf("Este numero eh insuficiente. ");
				printf("\nPara jogar neste estilo musical, eh preciso que no arquivo texto ");
				printf("existam pelo menos 4 musicas disponiveis.\n");
				
			} else if ((num >= 4)&&(num < 10)) {
		
				printf("\nATENCAO:"); 
				printf("\nO numero de musicas eh insuficiente para que sua diversao possa ser garantida!");
				printf("\nSao necessarias pelo menos 10 musicas para que a diversao seja completa!");
				printf("\nO jogo continuara, mas TEJE AVISADO, MELIANTE!\n");
				limpar_tela ();
		
				jogar_rock (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else if ((num >= 10)&&(num <= 50)) {
		
				jogar_rock (&pontos, &acertos);
				printf("\n%s acertou %d musicas e fez %d pontos!\n", user, acertos, pontos); 
				
			} else 
				printf("\nMe parece que o arquivo texto tem mais de 50 musicas! O maximo suportado eh 50.\n");
		}
		
	}
		
	return pontos;

}


/* 	FUNÇÃO RANKING: esta função mostra a interface de seleção de um gênero musical para a visualização do ranking.	  */
void ranking (void) {
	
	int 	opm,	/* OPM guardará o gênero musical escolhido pelo usuário. */
		lido;	/* LIDO receberá o valor de retorno do SCANF. */
	
	/* O menu será mostrado enquanto o usuário não escolher a opção sair do menu do ranking. */
	while (opm != 5) {
	
		limpar_tela_noenter ();
			
		mostrar_ops_config (5);
		/* As opções musicais são mostradas ao usuário. */
		
		/* A opção escolhida pelo usuário é lida. Caso ele não escolha uma opção válida, LIDO recebe 0. */
		lido = scanf("%d", &opm);
		while(getchar() != '\n');
		
		/* Caso LIDO seja igual a 0... */
		while (!lido) {
		
			/* A função continuará pedindo uma opção válida ao usuário. */
			op_invalida ();		
			mostrar_ops_config (5);
			lido = scanf("%d", &opm);
			while(getchar() != '\n');
			
		}
		
		switch (opm) {
			case 1:			
			case 2: 
			case 3: 
			case 4: 
				/* Caso o usuário escolha um estilo válido, a classificação é mostrada. */
				ver_classificacao (opm);
				break;
			case 5:
				break;
			default:
				/* Caso a opção seja inválida, o usuário é alertado. */
				op_invalida();
				break;
		}
		
	}
	
}


/*	FUNÇÃO TAMANHO_STRING: esta função é responsável por receber uma string e retornar seu tamanho. 	*/
int tamanho_string (char string[]) {
	
	int	i;	/* Serve de contador. */
	
	for (i = 0; string[i] != '\0'; i++);
	/* Neste FOR a variável I é incrementada até que se encontre o caracter '\0'. */
	
	return i;	
	/* Aqui a função retorna I, que é o tamanho da string. */
}


/* 	FUNÇÃO TESTADOR: esta função é responsável pelo mecanismo de teste de respostas e contagem efetiva de pontos e acertos do usuário. 	*/
int testador (char resp[], char respcorreta[], int *tent, int *pontos, int *acertos) {	/* RESP	é a resposta que o usuário inseriu. */

	int	ok,	/* Esta variável OK segue o mesmo padrão das outras. Ela, neste caso, tem duas serventias ao longo da função. Primeiramente ela armazena o valor de retorno de COMPARAR_STRING, que é 0 quando as strings são iguais. Nos IFS mais de dentro, OK sinaliza se o usuário errou duas vezes seguidas. */
		pontostmp = *pontos,	
		acertostmp = *acertos,	/* Aqui preferi trabalhar com valores temporários das variáveis e depois passar os  */ 
		tenttmp = *tent;	/* valores finais aos ponteiros ao invés de trabalhar diretamente com os ponteiros. */
	
	ok = comparar_string (resp, respcorreta);
	/* Aqui as respostas são comparadas com COMPARAR_STRING. Esta função tem a peculiaridade de ignorar a caixa alta ou baixa. */

	if (ok) {	/* Resposta incorreta. COMPARAR_STRING != 0 */
	
		if (tenttmp) {	/* Número de tentivas já gastas = 1 */
		
			printf("\nVoce errou duas vezes! Fim de jogo. -1 ponto\n");
			pontostmp--;
			/* Aqui o usuário sofreu a penalidade de -1 ponto pelo erro. */
			
			ok = 0;
			/* OK sinaliza que o usuário errou duas vezes e que o FOR que vai mostrar as três músicas ao usuário em JOGAR_ESTILO deve ser interrompido. */
			
		} else {	/* Número de tentativas já gastas = 0 */
		
			printf("\nVoce errou! Tente novamente. -1 ponto\n");
			pontostmp--;
			/* Aqui o usuário só é penalizado de -1 ponto pelo erro. */
			
			ok = 1;
			/* Aqui OK sinaliza com 1 que o FOR pode continuar sendo executado. */
			
		}
		
	} else {	/* Resposta correta. COMPARAR_STRING = 0 */
	
		tenttmp = 2;	
		/* O número de tentativas vai para 2 para garantir que se saia do WHILE que conta as tentativas. */
		
		printf("\nParabens! Voce acertou. +10 pontos\n");
		pontostmp+=10;	/* Aqui somam-se 10 pontos pelo acerto na pontuação do estilo. */
		acertostmp++;	/* Aqui soma-se 1 no contador de acertos. */
		
		ok = 1;
		/* Aqui OK sinaliza que o FOR de JOGAR_ESTILO pode continuar sendo executado. */
	}
		
	tenttmp++;	
	/* O número de tentativas é sempre acrescido de 1 quando se insere uma reposta e a função TESTADOR é chamada. */
	
	/* Aqui em baixo as devidas atribuições são feitas aos ponteiros. */
	*tent = tenttmp;
	*pontos = pontostmp;
	*acertos = acertostmp;
	
	return ok;
	/* Aqui a função retorna a sinalização de parada ou continuação do FOR de JOGAR_ESTILO. */

}


/*	FUNÇÃO VER_CLASSIFICAÇÃO: esta função é responsável por mostrar a classificação conforme o gênero musical ao usuário. 	*/
void ver_classificacao (int opm) {
	
	FILE	*ranking;
	/* Este será o ponteiro do arquivo binário. */
	
	int	tam,	/* TAM guardará o tamanho do nome do usuário. (questões estéticas mais pra frente) */ 	
		i,
		k;	/* Estas serão variáveis de contagem. */
	
	char	nomearq[10],	/* NOMEARQ receberá o nome do arquivo binário a ser aberto. */
		estilo[4][10] = {"rock.bin", "funk.bin", "mpb.bin", "pop.bin"};	/* Aqui estão os nomes. */
	
	usuariotemp	jogador[10];
	/* USUARIOTEMP é um tipo de STRUCT particular: é um caso reduzido de USUARIO. Neste tipo só existe uma variável de armazenagem de pontos, chamada PONTOS. JOGADOR[10] é um vetor deste de tipo. */
	
	copiar_string (nomearq, estilo[opm-1]);
	/* Aqui o nome do arquivo binário é copiado para NOMEARQ conforme gênero musical. */
	
	/* Aqui o arquivo é aberto para leitura. */
	ranking = fopen(nomearq, "rb");
	
	if (ranking == NULL)		
		printf("\nRanking vazio!\n");	/* Se o arquivo não existir, o usuário é avisado. */
		
	else {	/* Caso exista... */
		
		for (i = 0; (i < 10)&&(fread(&jogador[i], sizeof(usuariotemp), 1, ranking)); i++);
		/* Este FOR atualiza o valor de I até que ele seja igual ao número de jogadores existentes no arquivo binário. */
	
		k = i;
		/* K recebe o número de jogadores. */
		
		/* Este FOR mostra os jogadores de 0 a K-1. */
		for (i = 0; i < k; i++) {
			tam = tamanho_string (jogador[i].user);
			if (tam < 4)
				printf("\nID: %s\t\t\t\tPontos: %d", jogador[i].user, jogador[i].pontos);
			else if (tam < 12)
				printf("\nID: %s\t\t\tPontos: %d", jogador[i].user, jogador[i].pontos);
			else if (tam < 20)
				printf("\nID: %s\t\tPontos: %d", jogador[i].user, jogador[i].pontos);
			else 
				printf("\nID: %s\tPontos: %d", jogador[i].user, jogador[i].pontos);
		}
		
		printf("\n");
			
		/* Aqui o arquivo é fechado. */
		fclose(ranking);
	}
	
	limpar_tela ();
}

	
