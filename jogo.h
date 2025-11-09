#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#define LARGURA_TELA 80
#define ALTURA_TELA 24

typedef struct {
    int x;
    int y;
    int vidas;
    int invencivel;
    int piscar;
} Nave;

typedef struct {
    int pontos;
    int recorde;
} Placar;

typedef struct Meteoro {
    int x;
    int y;
    struct Meteoro *proximo;
} Meteoro;

void inicializar_jogo(Nave *nave, Placar *placar);
void mover_nave(Nave *nave, char tecla);
void gerar_meteoro(Meteoro **meteoritos);
void atualizar_meteoros(Meteoro **meteoritos, Placar *placar);
int verificar_colisao(Nave *nave, Meteoro *meteoritos);
void desenhar_jogo(Nave *nave, Meteoro *meteoritos, Placar placar);
void liberar_meteoros(Meteoro *meteoritos);
void salvar_recorde(Placar placar);
int carregar_recorde();

#endif