// ATENÇÃO: professor, o conteudo do desafio e o video que fizeram mostrando os resultado que vocês 
// Queriam com o codigo esta diferente, no desafio em texto tanbém devo mostrar os navios, mais no
// video, o professor so mostra as habilidades, fiquei meio confuso e decidi seguir com o exemplo
// Do video mesmo, por isso a diferença entre esse codigo e o ultimo do nivel aventureiro. :)  


#include <stdio.h>

int main(void) {
    // tabuleiro das habilidades
    // 0 = nada | 1 = cone | 2 = octaedro (losango) | 3 = cruz
    int tab[10][10];
    int i, j;

    // 1) zerar o tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tab[i][j] = 0;
        }
    }

    // 2) máscaras 5x5 (0/1) de cada habilidade 
    int cone[5][5];
    int cruz[5][5];
    int octa[5][5];
    int r, c;

    // CONE (apontando pra baixo): linhas com 1, 3 e 5 células
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            if (r <= 2 && c >= 2 - r && c <= 2 + r) cone[r][c] = 1;
            else cone[r][c] = 0;
        }
    }

    // CRUZ: linha central e coluna central
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            if (r == 2 || c == 2) cruz[r][c] = 1;
            else cruz[r][c] = 0;
        }
    }

    // OCTAEDRO (losango) pequeno: |dr| + |dc| <= 1
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            int dr = r - 2; if (dr < 0) dr = -dr;
            int dc = c - 2; if (dc < 0) dc = -dc;
            if (dr + dc <= 1) octa[r][c] = 1;
            else octa[r][c] = 0;
        }
    }

    // 3) posições (centros) onde vou desenhar no 10x10 (0..9)
    
    int cone_lin = 3, cone_col = 3;   // vai marcar 1
    int octa_lin = 4, octa_col = 6;   // vai marcar 2
    int cruz_lin = 6, cruz_col = 2;   // vai marcar 3

    // 4) aplicar CONE → 1
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            if (cone[r][c] == 1) {
                int ti = cone_lin + (r - 2);
                int tj = cone_col + (c - 2);
                if (ti >= 0 && ti < 10 && tj >= 0 && tj < 10) {
                    tab[ti][tj] = 1;
                }
            }
        }
    }

    // aplicar OCTAEDRO → 2
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            if (octa[r][c] == 1) {
                int ti = octa_lin + (r - 2);
                int tj = octa_col + (c - 2);
                if (ti >= 0 && ti < 10 && tj >= 0 && tj < 10) {
                    tab[ti][tj] = 2;
                }
            }
        }
    }

    // aplicar CRUZ → 3 (se sobrepor, a cruz “vence” por vir depois)
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            if (cruz[r][c] == 1) {
                int ti = cruz_lin + (r - 2);
                int tj = cruz_col + (c - 2);
                if (ti >= 0 && ti < 10 && tj >= 0 && tj < 10) {
                    tab[ti][tj] = 3;
                }
            }
        }
    }

    // 5) impressão 
    printf("TABULEIRO  BATALHA  NAVAL\n");
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);           
        for (j = 0; j < 10; j++) {
            printf(" %d", tab[i][j]);     
        }
        printf("\n");
    }

    return 0;
}
