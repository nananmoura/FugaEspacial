#ifndef NAVE_H
#define NAVE_H

#include "screen.h"
#include "estruturas.h"
#include "tiro.h"

#define NAVE_ALTURA 3
#define NAVE_LARGURA 10

extern const char *NAVE_FORMA[NAVE_ALTURA];

void inicializar_nave(Nave *n);
void mover_nave(Nave *n, char tecla);
void desenhar_nave(Nave n);

#endif
