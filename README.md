CCP020 - DIGITAL EXPERIENCE ULTIMATE
Projeto - Reprodutor de Músicas
Sobre o projeto

Esse projeto foi desenvolvido utilizando um Arduino Uno com a ideia de criar um pequeno reprodutor de músicas usando alguns componentes eletrônicos básicos.

O sistema possui um display LCD 16x2, buzzer, LEDs e botões para controle das funções. Pelo menu mostrado no LCD, o usuário consegue escolher a música, tocar, pausar ou parar a reprodução.

Os LEDs servem para mostrar o estado do sistema:

LED verde ligado = música tocando
LED vermelho ligado = sistema parado ou pausado
Objetivo

O objetivo principal do projeto foi colocar em prática conteúdos vistos durante as aulas, principalmente programação embarcada e lógica utilizando Arduino.

Durante o desenvolvimento foram utilizados conceitos como:

entradas e saídas digitais
funções
vetores
lógica de programação
controle de menu
reprodução de sons utilizando frequências
Componentes utilizados
Componente	Quantidade
Arduino Uno	1
Display LCD 16x2	1
Protoboard	2
Buzzer	1
LEDs	2
Resistores	3
Botões	4
Jumpers	Vários
Funcionamento

Quando o sistema é iniciado, o LCD mostra um menu para escolher as músicas disponíveis.

Exemplo:

Escolher musica:
> Mario

Os botões permitem navegar pelo menu e controlar a música.

Função dos botões
Botão	Função
CIMA	Passa para a próxima música
BAIXO	Volta para a música anterior
PLAY	Toca ou pausa
STOP	Para a música
Músicas disponíveis

As músicas cadastradas no projeto são:

Mario
Harry Potter
Star Wars
Darth Vader
Pac-Man
Tetris
Zelda
Sonic
Como as músicas funcionam

Cada música foi feita usando dois vetores:

um para armazenar as notas
outro para armazenar o tempo de cada nota

Exemplo:

static int n[] = {659,659,0,659};
static int d[] = {150,150,100,150};

O vetor n[] guarda as frequências das notas e o vetor d[] guarda o tempo de duração.

Quando aparece 0, significa uma pausa na música.

Organização do código

O código foi separado em funções para facilitar o entendimento e a organização.

Função	O que faz
mostrar_menu()	Mostra o menu no LCD
ler_botoes()	Faz a leitura dos botões
iniciar_musica()	Inicia a reprodução
rodar_pausa()	Pausa ou continua a música
parar_tudo()	Para tudo
tocar_som()	Reproduz as notas
buscar_dados()	Carrega os dados das músicas
Ligações principais
LCD
RS → Pino 12
E → Pino 11
D4 → Pino 9
D5 → Pino 8
D6 → Pino 7
D7 → Pino 6
Botões
CIMA → Pino 2
BAIXO → Pino 3
PLAY → Pino 4
STOP → Pino 5
Saídas
Buzzer → Pino 10
LED Verde → Pino 13
LED Vermelho → Pino A0
Conceitos utilizados

Durante o projeto foram utilizados vários conceitos importantes, como:

variáveis
vetores
funções
estruturas condicionais
repetição
ponteiros
máquina de estados
biblioteca LiquidCrystal
Como executar
Abrir o código na IDE Arduino
Conectar o Arduino Uno no computador
Fazer o upload do código
Montar o circuito
Utilizar os botões para navegar pelas músicas
Resultado final

No final, o projeto conseguiu reproduzir músicas utilizando buzzer e permitir interação pelo LCD e pelos botões.

Além da parte funcional, o projeto ajudou bastante na prática de programação, organização do código e integração entre hardware e software.
