#ifndef JOGO_H
#define JOGO_H

#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "estruturas.h"

void inicializar_jogo(Nave *n, Placar *p);
void desenhar_jogo(Nave *n, Meteoro *m, Placar p);
int atualizar_jogo(Nave *n, Meteoro **lista, Placar *p); // retorna 1 se game over

#endif
