#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "estruturas.h"
#include "nave.h"
#include "meteoro.h"

void inicializar_jogo(Nave *n, Placar *p);
void desenhar_jogo(Nave *n, Meteoro *m, Placar p);
void atualizar_jogo(Nave *n, Meteoro **lista, Placar *p);
void salvar_recorde(Placar p);
void carregar_recorde(Placar *p);

#endif


