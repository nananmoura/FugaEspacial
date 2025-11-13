#ifndef METEORO_H
#define METEORO_H

#include "estruturas.h"
#include "screen.h"
#include <stdlib.h>
#include <time.h>

void gerar_meteoro(Meteoro **lista, Placar *p, int nivel);
void atualizar_meteoros(Meteoro **lista, Placar *p, Nave n);
void desenhar_meteoros(Meteoro *m);
void liberar_meteoros(Meteoro *lista);
int verificar_colisao(Nave n, Meteoro *lista);

#endif
