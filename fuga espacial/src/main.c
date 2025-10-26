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
            if (tecla == 27) // ESC pra sair
            rodando = 0;
            if (tecla == 'a' || tecla == 'd')
            mover_nave(&nave, tecla);
        }

        if (timerTimeOver()) {
            contador++;
            if (contador % 5 == 0) gerar_meteoro(&meteoritos);
            atualizar_meteoros(&meteoritos, &placar);
            if (verificar_colisao(nave, meteoritos)) rodando = 0;
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
