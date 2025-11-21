#include "jogo.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void inicializar_jogo(Nave *n, Placar *p) {
    srand(time(NULL));
    inicializar_nave(n);
    n->vidas = 3;

    p->pontos = 0;
    p->recorde = 0;
    carregar_recorde(p);
}

void desenhar_jogo(Nave *n, Meteoro *m, Placar p) {
    screenClear();
    screenDrawBorders();

    screenGotoxy(2, 1);
    printf("VIDAS: ");
    for (int i = 0; i < n->vidas; i++) {
        printf("<3 ");
    }

    screenGotoxy(20, 1);
    printf("PONTOS: %d", p.pontos);

    screenGotoxy(50, 1);
    printf("RECORDE: %d", p.recorde);

    desenhar_nave(*n);
    desenhar_meteoros(m);

    screenUpdate();
}

void atualizar_jogo(Nave *n, Meteoro **lista, Placar *p) {
    atualizar_meteoros(lista, p, *n);

    if (verificar_colisao(*n, *lista)) {
        n->vidas--;

        if (n->vidas <= 0) {
            screenGotoxy(MAXX / 2 - 6, MAXY / 2);
            printf("GAME OVER!");
            screenUpdate();
            usleep(1200000);
            salvar_recorde(*p);
            keyboardDestroy();
            screenDestroy();
            timerDestroy();
            exit(0);
        }
    }
}

void salvar_recorde(Placar placar) {
    if (placar.pontos > placar.recorde) {
        FILE *arquivo = fopen("recorde.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%d", placar.pontos);
            fclose(arquivo);
        }
    }
}

void carregar_recorde(Placar *p) {
    FILE *f = fopen("recorde.txt", "r");
    if (f) {
        fscanf(f, "%d", &p->recorde);
        fclose(f);
    } else {
        p->recorde = 0;
    }
}
