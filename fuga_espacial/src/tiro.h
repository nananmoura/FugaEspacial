#ifndef TIRO_H
#define TIRO_H

#include "estruturas.h"
#include "screen.h"
#include <stdlib.h>

void disparar_tiro(Tiro **lista, Nave *n, int nivel);
void atualizar_tiros(Tiro **lista);
void desenhar_tiros(Tiro *lista);
int tiro_acertou_meteoro(Tiro *t, Meteoro *m);

#endif

