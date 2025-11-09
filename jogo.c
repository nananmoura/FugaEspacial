#include "jogo.h"

void inicializar_jogo(Nave *nave, Placar *placar) {
    nave->x = LARGURA_TELA / 2;
    nave->y = ALTURA_TELA - 3;
    nave->vidas = 3;
    nave->invencivel = 0;
    nave->piscar = 0;
    
    placar->pontos = 0;
    placar->recorde = carregar_recorde();
}

void mover_nave(Nave *nave, char tecla) {
    if (tecla == 'a' || tecla == 'A') {
        if (nave->x > 2) nave->x--;
    }
    if (tecla == 'd' || tecla == 'D') {
        if (nave->x < LARGURA_TELA - 2) nave->x++;
    }
    if (tecla == 'w' || tecla == 'W') {
        if (nave->y > 2) nave->y--;
    }
    if (tecla == 's' || tecla == 'S') {
        if (nave->y < ALTURA_TELA - 2) nave->y++;
    }
}

void gerar_meteoro(Meteoro **meteoritos) {
    Meteoro *novo = (Meteoro *)malloc(sizeof(Meteoro));
    if (novo == NULL) return;
    
    novo->x = (rand() % (LARGURA_TELA - 4)) + 2;
    novo->y = 2;
    novo->proximo = *meteoritos;
    *meteoritos = novo;
}

void atualizar_meteoros(Meteoro **meteoritos, Placar *placar) {
    Meteoro *atual = *meteoritos;
    Meteoro *anterior = NULL;
    
    while (atual != NULL) {
        atual->y++;
        
        if (atual->y >= ALTURA_TELA - 1) {
            placar->pontos += 10;
            
            if (anterior == NULL) {
                *meteoritos = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            
            Meteoro *temp = atual;
            atual = atual->proximo;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

int verificar_colisao(Nave *nave, Meteoro *meteoritos) {
    if (nave->invencivel > 0) {
        nave->invencivel--;
        return 0;
    }
    
    Meteoro *atual = meteoritos;
    while (atual != NULL) {
        int distX = atual->x - nave->x;
        int distY = atual->y - nave->y;
        
        if (distX >= -1 && distX <= 1 && distY >= -1 && distY <= 1) {
            nave->vidas--;
            nave->invencivel = 30;
            nave->piscar = 30;
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void desenhar_jogo(Nave *nave, Meteoro *meteoritos, Placar placar) {
    screenClear();
    screenDrawBorders();
    
    screenGotoxy(2, 1);
    printf("VIDAS: ");
    for (int i = 0; i < nave->vidas; i++) {
        printf("<3 ");
    }
    
    screenGotoxy(20, 1);
    printf("PONTOS: %d", placar.pontos);
    
    screenGotoxy(50, 1);
    printf("RECORDE: %d", placar.recorde);
    
    Meteoro *atual = meteoritos;
    while (atual != NULL) {
        screenGotoxy(atual->x, atual->y);
        printf("*");
        atual = atual->proximo;
    }
    
    if (nave->invencivel == 0 || nave->piscar % 4 < 2) {
        screenGotoxy(nave->x, nave->y);
        printf("A");
    }
    
    if (nave->piscar > 0) {
        nave->piscar--;
    }
    
    screenUpdate();
}

void liberar_meteoros(Meteoro *meteoritos) {
    while (meteoritos != NULL) {
        Meteoro *temp = meteoritos;
        meteoritos = meteoritos->proximo;
        free(temp);
    }
}

void salvar_recorde(Placar placar) {
    if (placar.pontos > placar.recorde) {
        FILE *arquivo = fopen("recorde.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%d", placar.pontos);
            fclose(arquivo);
        }
    }
}

int carregar_recorde() {
    FILE *arquivo = fopen("recorde.txt", "r");
    int recorde = 0;
    
    if (arquivo != NULL) {
        fscanf(arquivo, "%d", &recorde);
        fclose(arquivo);
    }
    
    return recorde;
}