#include "borda.h"
#include "screen.h"
#include <stdio.h>

void desenhar_borda() {
    int largura = MAXX;
    int altura  = MAXY;

    screenGotoxy(1, 1);
    printf("+");

    for (int i = 2; i < largura; i++) {
        screenGotoxy(i, 1);
        printf("-");
    }

    screenGotoxy(largura, 1);
    printf("+");

    for (int y = 2; y < altura; y++) {
        screenGotoxy(1, y);
        printf("|");

        screenGotoxy(largura, y);
        printf("|");
    }

    screenGotoxy(1, altura);
    printf("+");

    for (int i = 2; i < largura; i++) {
        screenGotoxy(i, altura);
        printf("-");
    }

    screenGotoxy(largura, altura);
    printf("+");
}
