#include "jogo.h"

void inicializar_jogo(Nave *n, Placar *p) {
    n->x = MAXX / 2;
    n->y = MAXY - 2;
    p->pontos = 0;
    p->recorde = 0;
}

void mover_nave(Nave *n, char tecla) {
    if (tecla == 'a' && n->x > 1)
        n->x--;
    if (tecla == 'd' && n->x < MAXX - 2)
        n->x++;
}

void desenhar_jogo(Nave *n, Meteoro *m, Placar p) {
    screenClear();

    screenGotoxy(n->x, n->y);
    printf("^"); // desenha a nave

    screenGotoxy(0, 0);
    printf("Pontuação: %d  Recorde: %d", p.pontos, p.recorde);

    screenUpdate();
}

// Funções vazias por enquanto (vamos preencher depois)
void atualizar_meteoros(Meteoro **lista, Placar *p) {}
void gerar_meteoro(Meteoro **lista) {}
int verificar_colisao(Nave n, Meteoro *lista) { return 0; }
void liberar_meteoros(Meteoro *lista) {}
void carregar_recorde(Placar *p) {}
void salvar_recorde(Placar p) {}
