#include "jogo.h"
#include "borda.h"
#include "nave.h"
#include "meteoro.h"
#include "tiro.h"
#include "vidas.h"
#include "placar.h"
#include "nivel.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    screenInit(1);
    keyboardInit();
    timerInit(100);

    screenClear();
    desenhar_borda();
    screenUpdate();

    char nome[50];
    screenGotoxy(MAXX / 2 - 15, MAXY / 2);
    printf("Digite seu nome: ");
    fflush(stdout);
    if (fgets(nome, sizeof(nome), stdin)) {
        size_t len = strlen(nome);
        if (len > 0 && nome[len - 1] == '\n') nome[len - 1] = '\0';
    } else {
        nome[0] = '\0';
    }

    Nave nave;
    Placar placar;
    Meteoro *meteoritos = NULL;
    inicializar_jogo(&nave, &placar);

    FILE *fRec = fopen("record.txt", "r");
    int recorde = 0;
    if (fRec) {
        fscanf(fRec, "%d", &recorde);
        fclose(fRec);
    }

    int rodando = 1;

    while (rodando) {
        int nivel;
        if (placar.pontos <= 30) nivel = 1;
        else if (placar.pontos <= 90) nivel = 2;
        else if (placar.pontos <= 150) nivel = 3;
        else nivel = 4;

        if (keyhit()) {
            char tecla = readch();
            if (tecla == 27) rodando = 0;
            else if (tecla == ' ') {
                disparar_tiro(&nave.tiros, &nave, nivel);
            } else {
                mover_nave(&nave, tecla);
            }
        }

        if (timerTimeOver()) {
            if (rand() % 100 < nivel * 10)
                gerar_meteoro(&meteoritos, &placar, nivel);

            atualizar_jogo(&nave, &meteoritos, &placar);
            desenhar_jogo(&nave, meteoritos, placar);

            screenGotoxy(MAXX / 2 - 10, 1);
            printf("RECORD: %d", recorde);

            if (acabou_vidas(&nave)) {
                rodando = 0;
                screenGotoxy(MAXX / 2 - 5, MAXY / 2);
                printf("GAMER OVER!");
                screenUpdate();
                usleep(1000000);
            }
        }
    }

    FILE *fPont = fopen("pontuacao.txt", "a");
    if (fPont) {
        fprintf(fPont, "%s %d\n", nome, placar.pontos);
        fclose(fPont);
    }

    if (placar.pontos > recorde) {
        FILE *fRecUp = fopen("record.txt", "w");
        if (fRecUp) {
            fprintf(fRecUp, "%d", placar.pontos);
            fclose(fRecUp);
        }
    }

    liberar_meteoros(meteoritos);
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
