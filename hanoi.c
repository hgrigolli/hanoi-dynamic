#include<stdio.h>

int *mov;

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        printf("%c,%c\n", x, y);
        return;
    } else {
        hanoi(n-1,x,z,y);
        hanoi(1,x,y,z);
        hanoi(n-1,z,y,x);
    }

}

void hanoiImpar()
/**
Existem apenas 6 movimentos no problema da Torre de Hanoi
Da direta para esquerda:

A->B - mov 0
A->C - mov 1
B->C - mov 2

e da esquerda para direita:

C->A - mov 3
C->B - mov 4
B->A - mov 5

Existem 10 trios de movimentos, sendo que

Se n é par, os movimentos são

104
152
354
154
352

Se n é impar, sao

012
034
532
032
534


*/
int main () {

    mov = (int *)malloc(sizeof(int) * (6)); //Existem apenas 6 movimentos no hanoi
    for(int i = 1 ; i <= 10; i++){
        printf("Quantidade de blocos: %d\n", i);
        hanoi(i,'A','B','C');
    }
    return 0;
}
