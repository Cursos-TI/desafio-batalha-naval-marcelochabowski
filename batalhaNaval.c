// Desafio Batalha Naval - MarceloCaboski
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10 // usando um macro para definir o tabuleiro
const char AGUA = 'a'; 
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
    for (int j = 0; j < TAM; j++)
       printf("%2d ",j);
    printf("\n");
    for(int i = 0; i < TAM; i++){
        printf("%2d ",i);
        for (int j = 0; j < TAM; j++) {
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
    int xJog, yJog, xCPU, yCPU;
    int acertouJogador = 0, acertouCPU = 0;
    int tentativasJogador = 0, tentativasCPU = 0;
    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    posicionarNavio(tabuleiro, NAVIO_JOGADOR, &xJog, &yJog);
    posicionarNavio(tabuleiro, NAVIO_CPU, &xCPU, &yCPU);
// posicionando os navio na agua, utilizando a função e variaveis
    printf("Bem-vindo a batalha naval\n");
    while (!acertouJogador && !acertouCPU) {
        imprimirTabuleiro(tabuleiro);
        int x, y;
        printf("\nSua vez!\n");
        printf("digite a linha (0-%d): ", TAM - 1);
        scanf("%d", &x);
        printf("digite a coluna (0-%d): ", TAM - 1);
        scanf("%d", &y);

        if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
            printf("Coordenadas invalidas. Tente novamente.\n");
        } else if (tabuleiro[x][y] == NAVIO_CPU) {
            printf("Acertou!\n");
            tabuleiro[x][y] = TIRO_NAVIO;
            acertouJogador++;
        } else if (tabuleiro[x][y] == AGUA) {
            printf("Tiro na agua.\n");
            tabuleiro[x][y] = TIRO_AGUA;
        } else {
            printf("Ja atirou aqui.\n");
        }
        if (acertouJogador) break;
        
        printf("\nVez da CPU\n")
        int cx, cy;
        do { 
            cx = rand() % TAM;
            cy = rand() % TAM;
        } while (tabuleiro[cx][cy] == TIRO_AGUA || tabuleiro[cx][cy] == TIRO_NAVIO);

        tentativasCPU++;
        printf("CPU atirou em (%d, %d)\n", cx, cy);
        if (tabuleiro[cx][cy] == NAVIO_JOGADOR) {
            printf("A CPU acertou voce!\n");
            acertouCPU = 1;
        } else if (tabuleiro[cx][cy] == NAVIO_CPU) {
            printf("A CPU fez fogo amigo!\n");
            tabuleiro[cx][cy] = TIRO_NAVIO;
        } else {
            printf("CPU acertou agua !\n");
            tabuleiro[cx][cy] = TIRO_AGUA;
        }
    }
    // usando loop com while para fica rodando o jogo
    // e usando as variaveis if e else criei coodernadas e regras
    printf("\nTabulheiro revelado:\n")
    for (int = 0; i <TAM; i++)
    for (int j = 0; j < TAM; j++)
if (tabuleiro[i][j] == NAVIO_JOGADOR || tabuleiro [i][j] == NAVIO_CPU)
 tabuleiro[i][j] = '*';
imprimirTabuleiro(tabuleiro);
if (acertouJogador)
 printf("\nParabens! voce ganhou em %d disparo.\n", tentativasJogador);
else
printf("\nA CPU venceu em %d disparo.\n", tentativasCPU);
    printf("Fim de jogo!\n");
    return 0;
}
