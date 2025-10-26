#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#define MAXX 80
#define MAXY 25

typedef struct {
    int x, y;
} Nave;

typedef struct meteoro {
    int x, y;
    struct meteoro *prox;
} Meteoro;

typedef struct {
    int pontos;
    int recorde;
} Placar;

#endif
