#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"  // <-- Inclui o arquivo estruturas.h aqui!

int main() {
    // Testando a criação da nave
    Nave jogador;
    jogador.x = 20;
    jogador.y = 18;
    
    printf("Nave criada na posicao: (%d, %d)\n", jogador.x, jogador.y);
    
    // Testando a criação de um meteoro
    Meteoro *meteoro1 = (Meteoro*)malloc(sizeof(Meteoro));
    meteoro1->x = 10;
    meteoro1->y = 0;
    meteoro1->ativo = 1;
    meteoro1->prox = NULL;
    
    printf("Meteoro criado na posicao: (%d, %d)\n", meteoro1->x, meteoro1->y);
    
    free(meteoro1);
    
    return 0;
}
//testando oq fiz 