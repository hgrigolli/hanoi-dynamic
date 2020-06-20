#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/**
Torre de Hanoi com programação dinâmica

Henrique Nóbrega Grigolli - 41821661
Kleber Takashi Yoshida - 41843533


Analisando o quebra-cabeça da torre de Hanoi

O quebra-cabeça da torre de Hanoi, possui apenas 6 movimentos (e enumeramos cada movimento deste de 1 a 6):

* de A para B [1]
* de A para C [2]
* de B para C [3]
* de C para A [4]
* de C para B [5]
* de B para A [6]


Então, a solução para o problema com 1,2,3,4 e 5 discos é:

* 1 disco:
  - 1
* 2 discos:
  - 215
* 3 discos:
  - 123 145 1
* 4 discos:
  - 215 263 215 465 215
* 5 discos:
  - 123 145 123 643 123 145 143 645 123 145 1

Neste exemplo vemos que há um padrão entre as soluções com um número par e impar de discos.

Para mapear dentro da chamada recursiva do problema (pois envolve o movimento entre os tres pilares),
sendo o pilar A equivalente a 0, o pilar B equivalente a 1 e o pilar 3 equivalente 2.

Então, os movimentos:

* de A para B [1] equivale a chamada hanoi(0,1,2);
* de A para C [2] equivale a chamada hanoi(0,2,1);
* de B para C [3] equivale a chamada hanoi(1,2,0);
* de C para A [4] equivale a chamada hanoi(1,0,2);
* de C para B [5] equivale a chamada hanoi(2,0,1);
* de B para A [6] equivale a chamada hanoi(2,1,0);



Como há um padrão entre as soluções, armazenamos em memória as soluções já computadas, tornando o acesso a elas mais rapido.
Então a ideia é utilizar uma matriz, com n linhas e 6 colunas, em uma matriz de char* e a solução é calculada concatenando com as strings anteriores.

Isso faz com que o tempo de execução diminua pois já houve o calculo anteriormente, porém, ao ganharmos a solução em tempo,
perdemos em espaço, que agora a cada solução, o espaço que deve ser armazenado se torna exponencial devido a caracteristica do problema.


*/
void imprimeMatriz(char ***hm, int n){
    printf(" n 012 021 120 102 201 210\n");
    for(int i = n; i >= 0; i--){
        if(i < 10){
            printf(" %d ", i);
        } else {
        printf("%d ", i);
        }
        for(int j = 0; j < 6; j++){
            if(hm[i][j] != "0"){
                printf(" X  ");
            } else {
                printf(" 0  ");
            }
        }
        printf("\n");
    }

}

//Verifica em qual posição da matriz deve ser acessada para encontrar a solução.
int traduzMapa(int a, int b, int c){
    if(a == 0){
        if(b == 1 && c == 2){
            return 0;
        }
        else if (b == 2 && c == 1){
            return 1;
        }
    } else if (a == 1){
        if(b == 2 && c == 0){
            return 2;
        }
        else if (b == 0 && c == 2){
            return 3;
        }
    } else if (a == 2){
        if(b == 0 && c == 1){
            return 4;
        }
        else if (b == 1 && c == 0){
            return 5;
        }
    }
    return -1;
}


char * hanoiDyn(char ***hm, int k, int a, int b, int c){

    int j = traduzMapa(a,b,c);
    //Se a posição ja foi calculada, retorna a solução.
    if(hm[k-1][j] != "0"){
        return hm[k-1][j];
    } else {
        //Calcula as soluções
        char * x = hanoiDyn(hm, k-1, a, c, b);

        char * y = hanoiDyn(hm, 1, a, b, c);

        char * z = hanoiDyn(hm, k-1, c, b, a);

        //Calcula o tamanho da string que será armazenada
        int tempSize = (strlen(x)+strlen(y)+strlen(z)+1);

        //Aloca na memoria o tamanho da string
        hm[k-1][j] = (char *) malloc( tempSize * sizeof(char) );

        hm[k-1][j][0] = '\0';

        //Concatena em hm[k-1][j] o resultado das string x,y e z
        strncat(hm[k-1][j], x, tempSize);
        strncat(hm[k-1][j], y, tempSize);
        strncat(hm[k-1][j], z, tempSize);
     }

     return hm[k-1][j];
}

int main () {


    //Quantidade de blocos
    int n = 26;

    //Inicializa a matriz que irá armazenar os resultados
    char ***hanoiMatrix;

    //Aloca espaço inicial da matriz
    hanoiMatrix = (char ***) calloc(n, sizeof(char **));

    //Aloca espaço inicial da matriz
    for(int i = 0; i <= n; i++){

        hanoiMatrix[i] = (char **) calloc(6, sizeof(char *));

        for(int j = 0; j < 6; j++){
            //Inicializa a matriz n x 6 com "0"
            hanoiMatrix[i][j] = "0";
        }
    }

    //A primeira linha da matriz contem todos os movimentos possiveis para a solução do quebra-cabeça
    hanoiMatrix[0][0] = "1";
    hanoiMatrix[0][1] = "2";
    hanoiMatrix[0][2] = "3";
    hanoiMatrix[0][3] = "4";
    hanoiMatrix[0][4] = "5";
    hanoiMatrix[0][5] = "6";

    //Calcula o tempo em que leva para calcular a solução.
    clock_t t;
    t = clock();

    char* fim = hanoiDyn(hanoiMatrix, n, 0,1,2);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
    printf("A execucao levou %f segundos\n", time_taken);

    //free(hanoiMatrix);

    return 0;
}
