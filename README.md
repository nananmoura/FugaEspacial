# 🚀 Fuga Espacial

**Fuga Espacial** é um jogo em C, executado no terminal, desenvolvido como projeto acadêmico para praticar lógica de programação, estruturas, modularização, alocação dinâmica e uso de bibliotecas externas.  
O jogador controla uma nave que deve desviar de meteoros enquanto a dificuldade aumenta progressivamente.

---

## 🎯 Objetivo do Projeto

Este projeto foi desenvolvido com o intuito de praticar:

- ✅ Estruturas (`struct`)
- ✅ Modularização com múltiplos arquivos (`.c` e `.h`)
- ✅ Alocação dinâmica de memória
- ✅ Listas encadeadas (para os meteoros)
- ✅ Uso da biblioteca **CLI-LIB** para:
  - controle de teclado
  - renderização no terminal
  - gerenciamento de tempo (timer)

---

## 📁 Estrutura do Projeto

fuga espacial/
├── build/ # pasta de saída do executável

├── src/ # código-fonte principal

│ ├── main.c # loop principal do jogo

│ ├── jogo.c # lógica, desenho e mecânicas do jogo

│ ├── jogo.h # protótipos das funções e includes

│ └── estruturas.h # definição das structs

├── cli-lib/ # biblioteca auxiliar para CLI

│ ├── include/ # screen.h, keyboard.h, timer.h

│ └── src/ # implementações da biblioteca

└── Makefile # script de compilação


---

## 🧠 Mecânica do Jogo

### Controles

| Tecla | Ação                    |
|-------|--------------------------|
| `A`   | Mover para esquerda      |
| `D`   | Mover para direita       |
| `W`   | Mover para cima          |
| `S`   | Mover para baixo         |
| `ESC` | Encerrar o jogo          |

---

## ✅ Funcionalidades Implementadas

| Status | Funcionalidade |
|--------|----------------|
| ✅ | Nave controlável no terminal |
| ✅ | Meteoros caindo e se movendo pela tela |
| ✅ | Pontuação aumentando ao desviar dos meteoros |
| ✅ | Sistema de níveis baseado na pontuação |
| ✅ | Velocidade dos meteoros aumenta a cada nível |
| ✅ | Meteoros surgem de diferentes posições conforme o nível |
| ✅ | Colisão entre nave e meteoro encerra o jogo |
| ✅ | Animação de “LEVEL UP” com som |

---

## 🧪 Como Compilar e Executar

No terminal (Linux):

```bash
cd "fuga espacial"
make run
```