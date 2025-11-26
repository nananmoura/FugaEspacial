#include "vidas.h"
#include "screen.h"
#include <stdio.h>
#include <unistd.h>

void diminuir_vida(Nave *n) {
    n->vidas--;
    screenGotoxy(MAXX / 2 - 6, MAXY / 2);
    printf("DANO RECEBIDO!");
    screenUpdate();
}

void desenhar_vidas(Nave *n) {
    screenGotoxy(2, 2);
    for (int i = 0; i < MAXX - 4; i++) printf(" ");

    screenGotoxy(2, 2);
    printf("VIDAS: ");

    for (int i = 0; i < n->vidas; i++) {
        printf("♥ ");
    }
}


int acabou_vidas(Nave *n) {
    return n->vidas <= 0;
}
