#include "jogo.h"
#include "borda.h"
#include "nave.h"
#include "meteoro.h"
#include "tiro.h"
#include "vidas.h"
#include "placar.h"
#include <unistd.h>
#include <time.h>

void inicializar_jogo(Nave *n, Placar *p) {
    srand(time(NULL));
    inicializar_nave(n);
    inicializar_placar(p);
}

void desenhar_jogo(Nave *n, Meteoro *m, Placar p) {
    screenClear();
    desenhar_borda();

    desenhar_vidas(n);
    desenhar_placar(p);

    desenhar_nave(*n);
    desenhar_meteoros(m);
    desenhar_tiros(n->tiros);

    screenUpdate();
}

int atualizar_jogo(Nave *n, Meteoro **lista, Placar *p) {
    atualizar_meteoros(lista, p, n);
    atualizar_tiros(&n->tiros);

    if (verificar_colisao_nave_meteoro(n, *lista)) {
        diminuir_vida(n);
    }

    return 0; 
}
