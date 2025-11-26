#ifndef PLACAR_H
#define PLACAR_H

#include "estruturas.h"
#include "screen.h"
#include <stdio.h>

void inicializar_placar(Placar *p);
void desenhar_placar(Placar p);
void adicionar_pontos(Placar *p, int qtd);
void salvar_recorde(Placar p);
void carregar_recorde(Placar *p);

#endif
