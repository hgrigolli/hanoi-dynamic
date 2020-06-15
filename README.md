# Torrei de Hanoi com programação dinâmica

## Descrição do Problema
  O jogo da torre de Hanoi consiste em mover n discos de tamanhos diferentes, em ordem crescente, da coluna A para a coluna B, utilizando a coluna C como auxiliar, sendo que um disco maior não pode ficar acima de um disco menor.
  Este é um quebra-cabeça conhecido e é possível resolver com, no mínimo, 2^n - 1 passos.
  Devido a natureza do problema, a solução recursiva do problema possui um tempo exponencial. Será que é possível resolver este quebra-cabeça em um tempo menor?

## Analisando o quebra-cabeça
O quebra-cabeça da torre de Hanoi, possui apenas 6 movimentos (e enumeramos cada movimento deste de 1 a 6):

* de A para B \[1]
* de A para C \[2]
* de B para C \[3]
* de C para A \[4]
* de C para B \[5]
* de B para A \[6]

Então, a solução para o problema com 1,2,3,4 e 5 discos é:
(Nesta [planilha](hanoi.xlsx) é possível encontrar todas as soluções de 1 a 10 discos.)

* 1 disco:
  - 1
* 2 discos:
  - 215
* 3 discos:
  - 1231451
* 4 discos:
  - 215263215465215
* 5 discos:
  - 1231451236431231451436451231451

Neste exemplo vemos que há um padrão entre as soluções com um número par e impar de discos. 


## Tentativa de solução

Como há um padrão entre as soluções, poderíamos armazenar em memória as soluções já computadas, tornando o acesso a elas mais rapido.
Então a ideia é utilizar uma matriz, com n linhas e 6 colunas
