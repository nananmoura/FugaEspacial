# Fuga Espacial

Um jogo simples em C, rodando no terminal, desenvolvido como projeto acadêmico para praticar estruturas, funções, alocação dinâmica e uso de bibliotecas externas.
O jogador controla uma nave tentando sobreviver no espaço, desviando de meteoros (fases futuras).

## Objetivo do Projeto

Implementar um jogo interativo em C utilizando:

Estruturas (struct)

Funções e modularização (.c e .h)

Alocação dinâmica

Biblioteca CLI-LIB para manipular tela, teclado e tempo

## Estrutura do Projeto

fuga espacial/

├── build/               # pasta de saída do executável

├── src/                 # código-fonte principal

│   ├── main.c           # função principal (loop do jogo)

│   ├── jogo.c           # funções de lógica e renderização

│   ├── jogo.h           # cabeçalhos e protótipos das funções

│   └── estruturas.h     # definição das structs

├── cli-lib/             # biblioteca auxiliar para CLI

│   ├── include/         # headers (screen.h, keyboard.h, timer.h)

│   └── src/             # implementações (.c)

└── Makefile             # script de compilação

## Como Compilar

No terminal (Linux):

cd "fuga espacial"
make run

O jogo será compilado dentro da pasta build/ e executado automaticamente.

Se quiser apenas compilar sem rodar:

make

Para limpar os arquivos compilados:

make clean

## Controles

| Tecla | Ação                |

| :---- | :------------------ |

| `A`   | Mover para esquerda |

| `D`   | Mover para direita  |

| `ESC` | Encerrar o jogo     |

## Funcionalidades Atuais

✅ Nave controlável no terminal
✅ Pontuação e recorde exibidos
✅ Estruturas de dados criadas (Nave, Meteoro, Placar)
✅ Organização modular (.c e .h)
✅ Uso da biblioteca cli-lib para interação

## Próximos Passos

🚧 Implementar geração e queda dos meteoros
🚧 Adicionar colisão entre nave e meteoro
🚧 Criar sistema de pontuação e recorde persistente
🚧 Melhorar a interface visual (ASCII ou Raylib no futuro)
