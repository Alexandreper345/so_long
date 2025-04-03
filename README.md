so_long

so_long é um jogo 2D simples em que o objetivo é coletar todos os itens espalhados pelo cenário e encontrar a saída para completar o jogo. Focado na navegação e resolução de puzzles simples, o jogo oferece uma experiência acessível e envolvente com gráficos minimalistas.
Índice

    Objetivo do Projeto

    Tecnologias Utilizadas

    Como Jogar

    Instalação

    Estrutura do Projeto

    Funcionalidades

    Testes

    Contribuições

    Licença

    Contato

Objetivo do Projeto

O so_long foi criado com o objetivo de proporcionar uma experiência simples e divertida de jogo 2D, onde o jogador deve explorar um ambiente labiríntico para coletar itens e, ao final, encontrar a saída. O projeto foi desenvolvido com foco na clareza da jogabilidade e na leveza da experiência.

O jogo tem como principal característica a navegação simples através de um labirinto, sem mecânicas complexas. Ele é ideal para jogadores que buscam uma experiência descontraída e rápida, sem a necessidade de um aprendizado complexo.
Tecnologias Utilizadas

    Linguagem: C

    Compilador: cc (ou GCC, Clang)

    Biblioteca: MiniLibX

    Gráficos: 2D com estilo minimalista

    Sistema Operacional: Linux, macOS (e possivelmente Windows com a instalação adequada da MiniLibX)

Como Jogar

    Objetivo: O objetivo do jogo é simples: coletar todos os itens espalhados pelo cenário e sair do labirinto.

    Controle: Use as seguintes teclas para movimentar o personagem:

        W para cima

        A para a esquerda

        S para baixo

        D para a direita

    Progresso: Ao coletar todos os itens, a saída do labirinto será desbloqueada, permitindo que o jogador avance.

    Dificuldade: O jogo não possui níveis de dificuldade, sendo uma experiência mais relaxante e direta.

    Mapa: O mapa do jogo pode ser passado como argumento ao rodar o jogo. O arquivo de mapa deve estar no formato .ber e pode ser colocado na pasta maps/.

Rodando o Jogo

Para rodar o jogo com um mapa específico, use o comando abaixo, onde maps/nome_do_mapa.ber é o arquivo do mapa desejado:

./so_long maps/nome_do_mapa.ber

Exemplo

Se você tiver um mapa chamado mapa1.ber dentro da pasta maps/, o comando seria:

./so_long maps/mapa1.ber

Instalação
Passo 1: Clonar o repositório

Clone o repositório do so_long no seu computador utilizando Git:

git clone https://github.com/seu-usuario/so_long.git

Passo 2: Instalar dependências

Dependendo das bibliotecas utilizadas, você pode precisar instalar algumas dependências. Aqui estão as instruções para as dependências mais comuns.

No Linux:

sudo apt-get install libmlx-dev

No macOS:

brew install mlx

No Windows:

Siga as instruções na documentação da MiniLibX.
Passo 3: Compilar o projeto

Navegue até o diretório do projeto e compile:

cd so_long
make

Passo 4: Rodar o jogo

Após a compilação, execute o jogo com o comando:

./so_long maps/nome_do_mapa.ber

Funcionalidades

    Colete itens: O jogador deve coletar todos os itens espalhados no mapa.

    Saída do labirinto: Após coletar todos os itens, a saída do jogo é desbloqueada.

    Gráficos minimalistas: O design gráfico é simples, mas claro, com o objetivo de focar na jogabilidade.

    Controles intuitivos: O controle é feito através do teclado, utilizando as teclas W, A, S, D para movimentação.

Testes

O jogo não possui testes automatizados no momento, mas pode ser testado manualmente.
Testes Manuais

    Verifique se o personagem consegue se mover pelo mapa corretamente.

    Confirme se todos os itens podem ser coletados sem falhas.

    Teste se a saída aparece corretamente após a coleta de todos os itens.

Contato

Se tiver alguma dúvida ou quiser entrar em contato, me envie um e-mail para [asilvaperoba@gmail.com].
