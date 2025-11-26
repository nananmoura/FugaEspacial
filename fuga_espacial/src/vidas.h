#ifndef VIDAS_H
#define VIDAS_H

#include "estruturas.h"
#include "screen.h"
#include <unistd.h>

void diminuir_vida(Nave *n);
void desenhar_vidas(Nave *n);
int acabou_vidas(Nave *n);

#endif
