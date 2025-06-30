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

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posiciona os navios
    posicionarNavio(tabuleiro, NAVIO_JOGADOR, &xJog, &yJog);
    posicionarNavio(tabuleiro, NAVIO_CPU, &xCPU, &yCPU);

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
        // Aqui você pode implementar a jogada da CPU se desejar
    }

    printf("Fim de jogo!\n");
    return 0;
}
