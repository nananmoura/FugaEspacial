#include "jogo.h"

void inicializar_jogo(Nave *n, Placar *p) {
    n->x = MAXX / 2;
    n->y = MAXY - 2;
    p->pontos = 0;
    p->recorde = 0;
}

void mover_nave(Nave *n, char tecla) {
    // Esquerda
    if ((tecla == 'a' || tecla == 'A') && n->x > 1)
        n->x--;

    // Direita
    else if ((tecla == 'd' || tecla == 'D') && n->x < MAXX - 2)
        n->x++;

    // Cima
    else if ((tecla == 'w' || tecla == 'W') && n->y > 1)
        n->y--;

    // Baixo
    else if ((tecla == 's' || tecla == 'S') && n->y < MAXY - 2)
        n->y++;
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
