#ifndef METEORO_H
#define METEORO_H

#include "estruturas.h"

void gerar_meteoro(Meteoro **lista, Placar *p, int nivel);
void atualizar_meteoros(Meteoro **lista, Placar *p, Nave *n);
void desenhar_meteoros(Meteoro *m);
void liberar_meteoros(Meteoro *lista);
int verificar_colisao_nave_meteoro(Nave *n, Meteoro *lista);

#endif
