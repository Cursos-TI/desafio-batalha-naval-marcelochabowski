// Desafio Batalha Naval - MarceloCaboski
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10 // usando um macro para define o tabulheiro
const char agua = 'a'; 
const char NAVIO_JOGADOR = 'j';
const char NAVIO_CPU = 'c';
const char TIRO_AGUA = 'O';
const char TIRO_NAVIO = 'X';
// usando const char para deixa o codigo mais limpo e manter os caracteres do jogo

void imprimirCelula(char c){
    if ( c == NAVIO_JOGADOR || c == NAVIO_CPU)
     printf("[A]");
    else
     printf("[%c]", c);
    // variavel void para nao retorna e para esconder o navio
}
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  ");
    for (int j = 0; j < TAMANHO; j++)
       printf("%2d ",j);
    printf("\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("%2d ",i);
        for (int j = 0; j < TAMANHO; j++) {
          imprimirCelula(tabuleiro[i][j]);
        }
    printf("\n");    
    }
}
// usando funcao imprimircelular/tabuleiro e variavel para deixa o jogo visual
void posicionarNavio(char tabuleiro[TAM][TAM], char navio, int *x, int *y){
    do{
        *x = rand() % TAM;
        *y = rand() % TAM;
    }
     while (tabuleiro[*x][*y] != AGUA);
      tabuleiro[*x][*y] = navio;
}
// usando funcao posicionar para colocar os navios, usando rando para colocar dentro do limite.
// while para colocar aleatrorio
int main(){
    char tabuleiro[TAM][TAM];
    int xJog,yJog,xCPU,yCPU;
    int acertouJogador = 0, acertouCPU = 0;
    int tentativasJogador = 0, tentativasCPU = 0;
    srand(time(NULL));
}
// usando a funcao int main cria pontuacao e usar o tabuleiro unico para ambos jogadores e srand para gerar jogo aleatorios
 for (int i =0; i < TAMANHO; i++)
     for (int j = 0, j < TAMANHO; j++)
     tabuleiro[i][j] = AGUA;
    posicionarNavio(tabuleiro, NAVIO_JOGADOR, &xJog,&yJog);
    posicionarNavio(tabuleiro, NAVIO_CPU,&xCPU,&yJog);
 // variavel para posicionar navios
 printf("Bem-vindo a batalha naval\n');
    while (!acertouJOGADOR && !acertouCPU)

                               







    return 0;
}
