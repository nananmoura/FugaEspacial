#ifndef NAVE_H
#define NAVE_H

#include "screen.h"
#include "estruturas.h"

void inicializar_nave(Nave *n);
void mover_nave(Nave *n, char tecla);
void desenhar_nave(Nave n);
void rotacionar_nave(Nave *n);

#endif
