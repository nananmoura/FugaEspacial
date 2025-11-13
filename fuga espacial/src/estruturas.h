#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAXX 80
#define MAXY 24

typedef struct {
    int x, y;        
    int rotacao;     
    int vidas;      
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


