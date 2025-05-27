#include <stdio.h>
//nivel novato
int main() {
    int tamanho = 10; // tamanho do tabuleiro
    int tabuleiro[10][10]; // matriz do tabuleiro

    // representando a agua do tabuleiro com 0 usando loop
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;}}

    // variaveis que representando os navios com o valor "3"
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // posicao inicial do navio horizontal(navio 1)
    int linha1 = 5;
    int coluna1 = 0;

    // verificacao para ver se o navio horizontal cabe no tabuleiro
    if (coluna1 + 3 <= tamanho) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha1][coluna1 + i] = navio_horizontal[i];}
    } else {
        printf("Navio horizontal não cabe no tabuleiro.\n"); // caso nao dê
        return 1;
    }

    // posicao inicial do navio vertical(navio 2)
    int linha2 = 5;
    int coluna2 = 4;

    // verificacao para ver se o navio vertical não sobrepoe o outro
    if (linha2 + 3 <= tamanho) {
       
        int sobreposicao = 0; // Verifica sobreposicao com o navio ja colocado
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha2 + i][coluna2] == 3) {
                sobreposicao = 1;
                break; }
        }

        if (!sobreposicao) {
            // Se nao ha sobreposicao, insere o navio vertical no tabuleiro
            for (int i = 0; i < 3; i++) {
                // coloca cada parte do navio vertical na matriz 'tabuleiro'
                tabuleiro[linha2 + i][coluna2] = navio_vertical[i];
            }
        } else {
            // se ha sobreposicao com outro navio, aparece mensagem de erro
            printf("Navio vertical sobrepõe o navio horizontal.\n");
            return 1; // finaliza o codigo de erro
        }
    } else {
        // se o navio vertical nao cabe no tabuleiro por nao caber
        printf("Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}