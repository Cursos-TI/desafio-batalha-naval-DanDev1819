#include <stdio.h>

int main(void) {
    // meu tabuleiro 10x10 (0 = água, 3 = navio)
    int tab[10][10];
    int i, j;

    // 1) começo zerando tudo (tudo água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tab[i][j] = 0;
        }
    }

    // 2) navios como vetores (tamanho 3). cada posição vale 3
    int navio_h[3] = {3, 3, 3};  // horizontal
    int navio_v[3] = {3, 3, 3};  // vertical

    // 3) coordenadas (índice começa em 0)
    // horizontal: começa em (2,4) e vai pra direita
    // vertical:   começa em (5,7) e vai pra baixo
    int h_lin = 2, h_col = 4;
    int v_lin = 5, v_col = 7;

    // 4) checo se o navio horizontal cabe e não bate em nada
    int ok = 1;
    if (h_lin < 0 || h_lin >= 10 || h_col < 0 || (h_col + 3 - 1) >= 10) {
        ok = 0; // não cabe no limite
    } else {
        for (j = 0; j < 3; j++) {
            if (tab[h_lin][h_col + j] != 0) ok = 0; // já tem algo lá
        }
    }
    if (!ok) {
        printf("ERRO no navio horizontal em (%d,%d)\n", h_lin, h_col);
        return 0; // paro aqui
    }

    // 5) deu boa: coloco o horizontal no tabuleiro
    for (j = 0; j < 3; j++) {
        tab[h_lin][h_col + j] = navio_h[j];
    }

    // 6) agora valido o vertical (já considerando o horizontal que foi colocado)
    ok = 1;
    if (v_lin < 0 || (v_lin + 3 - 1) >= 10 || v_col < 0 || v_col >= 10) {
        ok = 0; // não cabe
    } else {
        for (i = 0; i < 3; i++) {
            if (tab[v_lin + i][v_col] != 0) ok = 0; // bateria no outro
        }
    }
    if (!ok) {
        printf("ERRO no navio vertical em (%d,%d)\n", v_lin, v_col);
        return 0;
    }

    // 7) tudo certo: coloco o vertical
    for (i = 0; i < 3; i++) {
        tab[v_lin + i][v_col] = navio_v[i];
    }

    // 8) Formato que o professor apresentou no video
    printf("TABULEIRO  BATALHA  NAVAL\n");
    printf("   A B C D E F G H I J\n");
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // numeração das linhas (1 a 10)
        for (j = 0; j < 10; j++) {
            printf(" %d", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
