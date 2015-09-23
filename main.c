/****
*
* Título: Torre de Hanoi
*
* Autor: Matheus Almeida
*
* Data de Criação: 14 de Agosto de 2015
* Última modificação: 17 de Setembro de 2015
*
* Descrição: O programa vai mostrar na tela todos os passos necessario para se resolver o problema da TORRE DE HANOI
*            com a quantidade de discos que o usuario vai determinar, não ultrapassando 10 discos, atravez do uso de
*            funções recursivas.
*
* Entrada: O usuario entra com um inteiro que ira determinar o numero de discos que a TORRE DE HANOI ira ter.
*
*   Exemplo: Será pedido ao usuario entrar com um numero de 1 a 10, e ele vai entrar com o numero 3.
*
*            Digite o numero de Discos da Torre, entre 1 e 10:
*            3
*
* Saída: O programa vai imprimir na tela todos os passos para resolver o problema separados por '*'.
*
*   Exemplo:
*             *
*            ***
*           *****
*   *******************************
*            ***
*           ***** 	      	   *
*   *******************************
*
*           ***** 	  ***  	   *
*   *******************************
*        	           *
*           ***** 	  ***
*   *******************************
*         	           *
*         	          ***  	 *****
*   *******************************
*
*             *   	  ***  	 *****
*   *******************************
*               	      	  ***
*             *   	      	 *****
*   *******************************
*         	            	   *
*         	            	  ***
*      	         	         *****
*   *******************************
*
****/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/****
*
* Título: imprimeDisco
*
* Autor: Matheus Almeida
*
* Data de Criação: 15 de Agosto de 2015
* Última modificação: 17 de Setembro de 2015
*
* Descrição: A função escreve na tela os Discos da Torre de Hanoi.
*
* Parâmetros:
*
*     Entrada:
*
*             int *mtz:         É um ponteiro que aponta para a matriz que foi alocada e definida na função main.
*             int pil:          Indica a quantidade de pilhas que a torre possui, que no caso sempre é 3.
*             int numD:         Indica o numero de Discos que a torre terá, o numD foi indicado pelo usuario na função main.
*             int tamDiscMaior: Indica o tamanho do maior disco que será a base da  Torre de Hanoi.
*
* Valor de retorno: A função não possui retorno. A propria função imprime na tela ' ' e '*' dependendo dos valores de entrada.
*
****/

void imprimeDisco( int* , int, int, int );

/****
*
* Título: moverDisco
*
* Autor: Matheus Almeida
*
* Data de Criação: 16 de Agosto de 2015
* Última modificação: 17 de Setembro de 2015
*
* Descrição: A função checa o disco na posição mais alta da pilha de origem dada pelo valor de entrada, depois checa
*            o disco na posição mais baixa da pilha de destino dada pelo valor de entrada. Copia o disco da origem para
*            uma posição acima da do disco do destino e apaga o disco da origem. Depois chama a função imprimeDisco
*            para reemprimir a nova formatação dos discos na tela.
*
* Parâmetros:
*
*     Entrada:
*
*             int *mtz:          É um ponteiro que aponta para a matriz que foi alocada e definida na função main.
*             int pil:           Indica a quantidade de pilhas que a torre possui, que no caso sempre é 3.
*             int numD:          Indica o numero de Discos que a torre terá, o numD foi indicado pelo usuario na função main.
*             int tamDiscMaior:  Indica o tamanho do maior disco que será a base da  Torre de Hanoi.
*             int pilOrig:       Indica a pilha de origem do disco a ser movido.
*             int pilDest:       Indica a pilha de destino do disco a ser movido.
*
* Valor de retorno: Ela retorna as novas posições dos discos que serão impressos na tela novamente.
*
****/

void moverDisco( int* , int , int , int , int , int );

/****
*
* Título: resolveHanoi
*
* Autor: Matheus Almeida
*
* Data de Criação: 14 de Agosto de 2015
* Última modificação: 17 de Setembro de 2015
*
* Descrição: Move o disco da posição mais alta da pilha de origem para a pilha de destino
*
* Parâmetros:
*
*     Entrada:
*
*             int *mtz:          É um ponteiro que aponta para a matriz que foi alocada e definida na função main.
*             int pil:           Indica a quantidade de pilhas que a torre possui, que no caso sempre é 3.
*             int numD:          Indica o numero de Discos que a torre terá, o numD foi indicado pelo usuario na função main.
*             int tamDiscMaior:  Indica o tamanho do maior disco que será a base da  Torre de Hanoi.
*             int O:             Indica o numero da pilha de origem do disco a ser movido.
*             int A:             Indica o numero da pilha que vai auxiliar a mover os discos de uma pilha pra outra.
*             int D:             Indica o numero da pilha de destino para onde sera movido o disco.
*
* Valor de retorno: Indica a nova pilha de Origem, Auxiliar e de Destino.
*
****/

void resolveHanoi( int* , int , int , int , int , int , int , int );

/****
*
* Título: imprimeMenu
*
* Autor: Matheus Almeida
*
* Data de Criação: 20 de Setembro de 2015
* Última modificação: 20 de Setembro de 2015
*
* Descrição: Imprime o menu com as opções que o usuario pode escolher.
*
* Parâmetros:
*
*     Entrada:
*
*             int opcao: Informa qual opção do menu foi escolhida pelo usuario.
*
*     Saida:
*
*             A opção desejada pelo usuario e a poção de voltar para o menu ou começar a rodar o programa.
*
* Valor de retorno: Um inteiro que indica se o usuario voltou ao menu ou se foi direto ao programa.
*
****/

int imprimeMenu(int);

int main(){
    int numD; // Numero de Discos da Torre de Hanoi
    int *matriz; // Matriz onde ira ser armazenado a Torre de Hanoi
    int pilhas = 3; // Numero de astes, pilhas, da Torre de Hanoi
    int disco = 1; // Vai dizer o numero de discos a ser posto em cada linha x coluna da matriz
    int tamDiscMaior; // Armazena o tamanho do disco maior
    int i, j; // Contadores
    int opcao; // Opção do menu escolhida pelo usuario

    do {
        system("CLS");

        printf("Ol%c Bem vindo ao programa TABELA DE HANOI.\n", 160);
        printf("Neste programa voc%c vai entrar com o numero de discos que a torre ter%c\n", 136, 160);
        printf("E depois ir%c mostrar o passo a passo de como resolver o problema.\n", 160);
        printf("\nDesenvolvido por Matheus Almeida.\n");
        printf("\n");
        opcao = imprimeMenu(4);

        switch (opcao)
        {
            case 1:
                system("CLS");

                printf("Digite o numero de Discos da Torre, entre 1 e 10: ");
                scanf("%d", &numD);
                printf("\n");

                if (numD > 10){ // VERIFICAÇÃO DO NUMERO DE DISCOS 1
                    printf("N%co %c possivel utilizar mais de 10 discos na torre por conta de distor%c%co de tela.\n", 198, 130, 135, 198);
                    exit(-1);
                }
                else
                if (numD < 1) { // VERIFICAÇÃO DO NUMERO DE DISCOS 2
                    printf("N%co %c possivel utilizar menos de 1 disco na torre.\n", 198, 130);
                    exit(-1);
                }

                matriz = malloc(sizeof(int)*pilhas*numD); // ALOCA A MATRIZ ONDE OS DISCOS SERÃO DESENHADOS

                if(matriz == NULL){
                printf("FALTA DE MEMORIA!");
                exit(-1);
                } // FINAL DA VERIFICAÇÃO DA MATRIZ

                for(i=0; i< pilhas; i++)              // CRIA A TORRE NA PILHA 0 DA MATRIZ --- Número de Colunas
                    for(j=numD-1; j >= 0 ; j--)       // Número de Linhas
                        if(i==0){                     //
                            matriz[numD*i+j] = disco; // Define Tamanho
                            disco += 2;               // Do Disco Maior
                        }                             //
                        else{                         //
                            matriz[numD*i+j] = 0;     // Deixa todas as posições das pilhas 1 e 2 vazias
                        }

                tamDiscMaior = disco;

                imprimeDisco( matriz, pilhas, numD, tamDiscMaior); // Imprime na tela o passo 0 que são todos os discos empilhados na pilha 0

                printf("\n");
                for (i = 0; i <= (tamDiscMaior*3)+8; i++) {
                    printf("*");
                }
                printf("\n");

                resolveHanoi( matriz, pilhas, numD, numD, tamDiscMaior, 0, 1, 2); // Começa a Resolver a TORRE DE HANOI apartir da recursividade

                printf("\n\n%.0lf passos necessarios para resolver o problema.\n\n", pow(numD, 2)-1);

                free(matriz); // Libera a memoria usada para fazer a Matriz onde foi montada a TORRE DE HANOI

                system("pause");
            break;

            case 2:
                opcao = imprimeMenu(2);
            break;

            case 3:
                opcao = imprimeMenu(3);
            break;

            case 4:
                opcao = 4;
            break;

            default:
                printf("Opcaoo invalida\n");
        } //FINAL DO SWITCH CASE checar

    } while(opcao != 4);

    system("CLS && pause");

    return 0;
}

void imprimeDisco( int *mtz, int pil, int numD, int tamDiscMaior ){
    int i, j, k, espacoBranco;

    for(i=numD-1; i >= 0; i--){ // Linhas
        for(j=0; j < pil; j++){// Colunas
            espacoBranco = (tamDiscMaior - mtz[numD*j+i])/2;

            // Espaços em branco na Esquerda
            for(k=0; k < espacoBranco; k++)
                printf(" ");

            // Os asteriscos que formam o Disco
            for(k=0; k < mtz[numD*j+i]; k++)
                printf("*");

            // Espaços em branco na Esquerda
            for(k=0; k < espacoBranco; k++)
                printf(" ");

            printf("\t");

        }

        printf("\n");

    }
}

void moverDisco( int *mtz, int pil, int numD, int tamDiscMaior, int pilOrig, int pilDest ){
    int pO = numD-1, pD = numD-1;

    while(pO >= 0 && mtz[numD*pilOrig+pO] == 0)    // Encontra o Disco da camada mais alta da Pilha de Origem
        pO--;                                      //
    if(pO < 0)                                     // Corrige a localização da Matriz para impedir erro de memoria
        pO = 0;                                    //

    while(pD >= 0 && mtz[numD*pilDest+pD] == 0)    // Encontra o Disco da camada mais baixa da Pilha de Destino.
        pD--;                                      // Sempre ficando 1 posiçao abaixo do disco mais baixo.


    mtz[numD*pilDest+pD+1] = mtz[numD*pilOrig+pO]; // Copia o Disco mais alto da Origem pro mais baixo do Destino
    mtz[numD*pilOrig+pO] = 0;                      // Deixa o Disco mais alto da Origem em Branco


    imprimeDisco( mtz, pil, numD, tamDiscMaior);   // Imprime a Nova Posicao do Disco

}

void resolveHanoi( int *mtz, int pil, int numD, int disco, int tamDiscMaior, int O, int A, int D ){
    int i;

    if(disco == 1){
        moverDisco( mtz, pil, numD, tamDiscMaior, O, D);

        printf("\n");
        for (i = 0; i <= (tamDiscMaior*3)+8; i++) {
            printf("*");
        }
        printf("\n");

    }
    else{
        resolveHanoi(mtz, pil, numD, disco-1, tamDiscMaior, O, D, A);

        moverDisco(mtz, pil, numD, tamDiscMaior, O, D);

        printf("\n");
        for (i = 0; i <= (tamDiscMaior*3)+8; i++) {
            printf("*");
        }
        printf("\n\n");

        resolveHanoi(mtz, pil, numD, disco-1, tamDiscMaior, A, O, D);
    }

}

int imprimeMenu(int opcao){
    char numero[255];


    if(opcao == 2){
        system("CLS");
        printf("Sobre a entrada:\n\n");
        printf("Na inicializa%c%co do programa ser%c pedido o n%cmero de discos que voc%c quer que o\n", 135, 198, 160, 163, 136);
        printf("problema da TORRE DE HANOI tenha, para que o algoritimo resolva em seguida. Lembrando\n");
        printf("que o programa s%c aceita um numero maximo de 10 discos, por conta da distor%c%co da tela.\n", 162, 135, 198);
        printf("\nSobre a saida:\n\n");
        printf("Aparecer%c desenhado na tela o passo a passo de como resolver o problema da TORRE DE HANOI\n\n", 160);

        system("pause");
        return 5;
    }
    else
    if(opcao == 3){
        system("CLS");
        printf("Torre de Hanoi ou Torre de Lucas %c um \"quebra-cabe%ca\" que consiste em uma base contendo tr%cs pinos,\n", 130, 135, 136);
        printf("em um dos quais s%co dispostos alguns discos uns sobre os outros, em ordem crescente de di%cmetro,\n", 198, 131);
        printf("de cima para baixo. O problema consiste em passar todos os discos de um pino para outro qualquer,\n");
        printf("usando um dos pinos como auxiliar, de maneira que um disco maior nunca fique em cima de outro menor\n");
        printf("em nenhuma situa%c%co. O numero de discos pode variar sendo que o mais simples cont%cm apenas tr%cs.\n", 135, 198, 130, 136);
        printf("\nA Torre de Hanoi tem sido tradicionalmente considerada como um procedimento para avalia%c%co da\n", 135, 198);
        printf("capacidade de mem%cria de trabalho, e principalmente de planejamento e solu%c%co de problemas.\n\n", 162, 135, 198);
        printf("Fonte: https://pt.wikipedia.org/wiki/Torre_de_Hanoi\n\n");

        system("pause");
        return 5;
    }
    else
    if(opcao == 4){
        printf("(1) Para rodar o programa.\n");
        printf("(2) Para saber mais sobre o programa.\n");
        printf("(3) Para saber mais sobre a TORRE DE HANOI.\n");
        printf("(4) Para sair do programa.\n");
        gets(numero);

        return atoi(numero);
    }

}
