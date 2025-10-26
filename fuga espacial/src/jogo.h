#ifndef JOGO_H
#define JOGO_H

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXX 80
#define MAXY 24

typedef struct {
    int x, y; // posição da nave
} Nave;

typedef struct Meteoro {
    int x, y; // posição do meteoro
    struct Meteoro *prox;
} Meteoro;

typedef struct {
    int pontos;
    int recorde;
} Placar;

// Funções
void inicializar_jogo(Nave *n, Placar *p);
void desenhar_jogo(Nave *n, Meteoro *m, Placar p);
void mover_nave(Nave *n, char tecla);
void atualizar_meteoros(Meteoro **lista, Placar *p);
void gerar_meteoro(Meteoro **lista);
int verificar_colisao(Nave n, Meteoro *lista);
void liberar_meteoros(Meteoro *lista);
void carregar_recorde(Placar *p);
void salvar_recorde(Placar p);

#endif
