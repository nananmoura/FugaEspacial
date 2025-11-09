#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int HN;//se H for 10 a nave ta na coluna 10, anda para os lados 
    int VN;// se V for 5 a nave ta na coluna 5, anda p cima e p baixo
} Nave;

typedef struct Meteoro {
    int HM;// mesma coisa so q pra meteoro
    int VM;
    int ativo;// 1 = está caindo, 0 = já saiu da tela se ja tiver sido destruido 
    struct Meteoro *prox;
} Meteoro;

#endif