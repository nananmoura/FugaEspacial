#include "jogo.h"

int main() {
    screenInit(1);
    keyboardInit();
    timerInit(100);
    
    Nave nave;
    Placar placar;
    Meteoro *meteoritos = NULL;
    
    inicializar_jogo(&nave, &placar);
    
    int rodando = 1;
    int contador = 0;
    
    while (rodando) {
        if (keyhit()) {
            char tecla = readch();
            
            if (tecla == 27) {
                rodando = 0;
            }
            
            if (tecla == 'a' || tecla == 'd' || tecla == 'w' || tecla == 's' ||
                tecla == 'A' || tecla == 'D' || tecla == 'W' || tecla == 'S') {
                mover_nave(&nave, tecla);
            }
        }
        
        if (timerTimeOver()) {
            contador++;
            
            if (contador % 5 == 0) {
                gerar_meteoro(&meteoritos);
            }
            
            atualizar_meteoros(&meteoritos, &placar);
            
            if (verificar_colisao(&nave, meteoritos)) {
                if (nave.vidas <= 0) {
                    rodando = 0;
                }
            }
            
            desenhar_jogo(&nave, meteoritos, placar);
        }
    }
    
    screenClear();
    screenGotoxy(LARGURA_TELA / 2 - 5, ALTURA_TELA / 2);
    printf("GAME OVER!");
    screenGotoxy(LARGURA_TELA / 2 - 10, ALTURA_TELA / 2 + 2);
    printf("Pontuacao Final: %d", placar.pontos);
    
    if (placar.pontos > placar.recorde) {
        screenGotoxy(LARGURA_TELA / 2 - 8, ALTURA_TELA / 2 + 4);
        printf("NOVO RECORDE!");
    }
    
    screenUpdate();
    sleep(3);
    
    salvar_recorde(placar);
    liberar_meteoros(meteoritos);
    
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    
    return 0;
}