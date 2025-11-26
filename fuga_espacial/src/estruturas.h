
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAXX 80
#define MAXY 24

typedef struct Tiro {
    int x, y;
    struct Tiro *prox;
} Tiro;

typedef struct Nave {
    int x, y;
    int vidas; 
    struct Tiro *tiros;
} Nave;

typedef struct Meteoro {
    int x, y;
    int direcao;
    int tamanho;
    int vida;
    struct Meteoro *prox;
} Meteoro;

typedef struct {
    int pontos;
    int recorde;
} Placar;

#endif
