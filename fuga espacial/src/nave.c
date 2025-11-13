#include "nave.h"
#include <stdio.h>
#include <unistd.h>

#define NAVE_ALTURA 4
#define NAVE_LARGURA 7

const char NAVE_FORMA[NAVE_ALTURA][NAVE_LARGURA + 1] = {
    "   *   ",
    "  ***  ",
    " ***** "
};

void inicializar_nave(Nave *n) {
    n->x = MAXX / 2;
    n->y = MAXY - NAVE_ALTURA - 1;
    n->rotacao = 0;
}

void desenhar_nave(Nave n) {
    int i, j;
    for (i = 0; i < NAVE_ALTURA; i++) {
        for (j = 0; j < NAVE_LARGURA; j++) {
            if (NAVE_FORMA[i][j] == '*') {
                int px = n.x + j - (NAVE_LARGURA / 2);
                int py = n.y + i;
                screenGotoxy(px, py);
                printf("*");
            }
        }
    }
}


void mover_nave(Nave *n, char tecla) {
    if ((tecla == 'a' || tecla == 'A') && n->x > 4)
        n->x--;
    else if ((tecla == 'd' || tecla == 'D') && n->x < MAXX - 4)
        n->x++;
    else if ((tecla == 'w' || tecla == 'W') && n->y > 1)
        n->y--;
    else if ((tecla == 's' || tecla == 'S') && n->y < MAXY - NAVE_ALTURA)
        n->y++;
    else if (tecla == 'r' || tecla == 'R')
        rotacionar_nave(n);
}


void rotacionar_nave(Nave *n) {
    const char *frames[] = {" ^ ", " / ", " > ", " \\ ", " v ", " / ", " < ", " \\ "};
    int total_frames = 8;

    for (int i = 0; i < total_frames; i++) {
        screenGotoxy(n->x, n->y);
        printf("%s", frames[i]);
        screenUpdate();
        usleep(40000);
        screenGotoxy(n->x, n->y);
        printf("   ");
    }

    n->rotacao = (n->rotacao + 1) % 4;
}



