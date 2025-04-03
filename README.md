# 🎮 so_long

**so_long** é um jogo 2D simples em que o objetivo é coletar todos os itens espalhados pelo cenário e encontrar a saída para completar o jogo. Focado na navegação e resolução de puzzles simples, o jogo oferece uma experiência acessível e envolvente com gráficos minimalistas.

---

## 📌 Índice

- [Objetivo do Projeto](#-objetivo-do-projeto)
- [Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [Como Jogar](#-como-jogar)
- [Instalação](#-instalação)
- [Funcionalidades](#-funcionalidades)
- [Testes](#-testes)
- [Contato](#-contato)

---

## 🎯 Objetivo do Projeto

O **so_long** foi criado para proporcionar uma experiência simples e divertida em um jogo 2D, onde o jogador explora um ambiente labiríntico, coleta itens e encontra a saída. O projeto prioriza jogabilidade clara e uma experiência leve.

**Destaques:**
- ✅ Navegação simples
- ✅ Labirinto desafiador
- ✅ Gráficos 2D minimalistas

---

## 🛠 Tecnologias Utilizadas

- **Linguagem:** C  
- **Compilador:** `cc` (ou GCC, Clang)  
- **Biblioteca:** MiniLibX  
- **Gráficos:** 2D minimalista  
- **Sistemas Operacionais:** Linux, macOS (Windows com configuração especial)  

---

## 🎮 Como Jogar

### 🎯 Objetivo:
Coletar todos os itens e encontrar a saída do labirinto.

### 🎛 Controles:
```
W - Cima
A - Esquerda
S - Baixo
D - Direita
```
### 🔓 Progresso:
- Ao coletar todos os itens, a saída do labirinto será desbloqueada, permitindo avanço.

### 🗺️ Mapa:
- O mapa do jogo deve estar no formato `.ber` e ser colocado na pasta `maps/`.
- Para rodar o jogo com um mapa específico:
  ```sh
  ./so_long maps/nome_do_mapa.ber
  ```
- Exemplo:
  ```sh
  ./so_long maps/mapa1.ber
  ```

---

## 🛠 Instalação

### 🔹 Passo 1: Clonar o repositório
```sh
git clone https://github.com/seu-usuario/so_long.git
```

### 🔹 Passo 2: Instalar dependências

**Linux:**
```sh
sudo apt-get install libmlx-dev
```
**macOS:**
```sh
brew install mlx
```
**Windows:**
Siga as instruções na documentação da MiniLibX.

### 🔹 Passo 3: Compilar o projeto
```sh
cd so_long
make
```

### 🔹 Passo 4: Rodar o jogo
```sh
./so_long maps/nome_do_mapa.ber
```

---

## 🚀 Funcionalidades

✔️ **Colete itens** - Pegue todos os itens do mapa.  
✔️ **Saída do labirinto** - Aparece após coletar todos os itens.  
✔️ **Gráficos minimalistas** - Design simples para foco na jogabilidade.  
✔️ **Controles intuitivos** - Movimentação com teclado (W, A, S, D).  

---

## 🧪 Testes

Atualmente, o jogo não possui testes automatizados. Os seguintes testes manuais podem ser realizados:

- ✅ Verificar se o personagem se move corretamente.
- ✅ Confirmar que todos os itens podem ser coletados.
- ✅ Testar se a saída aparece após coletar todos os itens.

---

## 📩 Contato

Se tiver alguma dúvida ou sugestão, entre em contato:
📧 **E-mail:** [asilvaperoba@gmail.com](mailto:asilvaperoba@gmail.com)

