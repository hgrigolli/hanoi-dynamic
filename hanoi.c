#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void imprimeMatriz(char ***hm, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            printf("%s ", hm[i][j]);
        }
        printf("\n");
    }

}
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
            return 5;
        }
    } else if (a == 2){
        if(b == 0 && c == 1){
            return 3;
        }
        else if (b == 1 && c == 0){
            return 4;
        }
    }
    return -1;
}


char * hanoiDyn(char ***hm, int k, int a, int b, int c){
//    printf("inicio hanoi\n");
    int j = traduzMapa(a,b,c);
    if(hm[k-1][j] != "0"){
//        printf("ret [%d, %d]->%s\n", k-1, j, hm[k-1][j]);

        return hm[k-1][j];
    } else {

//        printf("antes x %d %d %d\n", a, c ,b);
        char * x = hanoiDyn(hm, k-1, a, c, b);
//        printf("antes y %d %d %d\n", a, b ,c);
        char * y = hanoiDyn(hm, 1, a, b, c);
//        printf("antes z %d %d %d\n", c, b ,a);
        char * z = hanoiDyn(hm, k-1, c, b, a);
        int tempSize = (strlen(x)+strlen(y)+strlen(z)+1);
//        printf("tempSize %d\n", tempSize);
        char *temp = malloc(tempSize * sizeof(char));
        temp[0] = '\0';
//        printf("temp0 %s\n", temp);
//        printf("concat x\n");
        strncat(temp, x, tempSize);

//        printf("tempx %s\n", temp);
//        printf("concat y\n");
        strncat(temp, y, tempSize);
//        printf("tempxy %s\n", temp);
//        printf("concat z\n");
        strncat(temp, z, tempSize);
//        printf("tempxyz %s\n", temp);

//        printf("x: %s->%p\n", x, &x);
//        printf("y: %s->%p\n", y, &y);
//        printf("z: %s->%p\n", z, &z);
//        printf("hm[k-1][j] %s\n", hm[k-1][j]);
//        printf("aloca para hm\n");
        hm[k-1][j] = (char *) malloc( tempSize * sizeof(char) );
//        printf("realocado %d\n", strlen(hm[k-1][j]));
//        printf("copia De temp para  hm\n");
        strncpy(hm[k-1][j], temp, tempSize);

//        free(temp);
//        printf("fim hanoi %d %d\n", k-1, j);

     }
     return hm[k-1][j];
}

int main () {

//    int n;
//    printf("Digite a quantidade de blocos: ");
//    scanf("%d", &n);
    int n = 30;

//    printf("n\n");
    char ***hanoiMatrix;
//    printf("xaloca n linhas matrix\n");
    hanoiMatrix = (char ***) calloc(n, sizeof(char **));
//    printf("fim linhas aloca\n");


//    printf("aloca colunas\n");
    for(int i = 0; i < n; i++){
//        printf("linha i=%d\n", i);
        hanoiMatrix[i] = (char **) calloc(6, sizeof(char *));
//     printf("linha i fim");
        for(int j = 0; j < 6; j++){
            hanoiMatrix[i][j] = "0";
        }
    }

//    printf("matriz inicializada");
    hanoiMatrix[0][0] = "1";
    hanoiMatrix[0][1] = "2";
    hanoiMatrix[0][2] = "3";
    hanoiMatrix[0][3] = "4";
    hanoiMatrix[0][4] = "5";
    hanoiMatrix[0][5] = "6";

//    printf("entrando hanoi dyn");
    char* fim = hanoiDyn(hanoiMatrix, n, 0,1,2);
//    printf("saindo da recursao -> %s\n", fim);
//    imprimeMatriz(hanoiMatrix, n);

    printf("Done.");
//   free(hanoiMatrix);

    return 0;
}
