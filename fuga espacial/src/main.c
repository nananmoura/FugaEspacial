#include "jogo.h"
#include <stdlib.h>

int main() {
    screenInit(1);
    keyboardInit();
    timerInit(100);

    Nave nave;
    Placar placar;
    Meteoro *meteoritos = NULL;

    inicializar_jogo(&nave, &placar);

    int rodando = 1;

    while (rodando) {
        if (keyhit()) {
            char tecla = readch();

            if (tecla == 27)
                rodando = 0;
            else
                mover_nave(&nave, tecla);
        }

        if (timerTimeOver()) {

            int nivel = placar.pontos / 10 + 1;

            if (rand() % 100 < nivel * 10) {
                gerar_meteoro(&meteoritos, &placar, nivel);
            }

            atualizar_jogo(&nave, &meteoritos, &placar);
            desenhar_jogo(&nave, meteoritos, placar);
        }
    }

    salvar_recorde(placar);
    liberar_meteoros(meteoritos);
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}

