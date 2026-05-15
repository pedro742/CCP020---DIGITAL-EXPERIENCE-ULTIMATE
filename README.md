CCP020 - DIGITAL EXPERIENCE ULTIMATE
Projeto - Reprodutor de Músicas
Sobre o Projeto

Este projeto foi desenvolvido utilizando um Arduino Uno com a proposta de criar um reprodutor de músicas simples e interativo utilizando componentes eletrônicos básicos.

O sistema conta com um display LCD 16x2, buzzer, LEDs e botões para controle das funções. Através do menu exibido no LCD, o usuário pode escolher entre diferentes músicas, iniciar a reprodução, pausar ou parar a execução.

Os LEDs ajudam a indicar o estado atual do sistema:

LED verde: música em reprodução
LED vermelho: sistema pausado ou parado
Objetivos

O principal objetivo do projeto foi aplicar conceitos de programação embarcada e eletrônica utilizando Arduino.

Durante o desenvolvimento foram trabalhados:

entradas e saídas digitais
utilização de funções
vetores
lógica de programação
controle de menu em LCD
reprodução de sons por frequência
Componentes Utilizados
Componente	Quantidade
Arduino Uno	1
Display LCD 16x2	1
Protoboard	2
Buzzer	1
LEDs	2
Resistores	3
Botões	4
Jumpers	Vários
Funcionamento do Sistema

Ao iniciar o sistema, o LCD exibe um menu para seleção das músicas disponíveis.

Exemplo:

Escolher musica:
> Mario

Os botões permitem navegar entre as opções e controlar a reprodução.

Função dos Botões
Botão	Função
CIMA	Próxima música
BAIXO	Música anterior
PLAY	Tocar ou pausar
STOP	Parar música
Músicas Disponíveis

O projeto possui 8 músicas cadastradas no sistema:

Mario
Harry Potter
Star Wars
Darth Vader
Pac-Man
Tetris
Zelda
Sonic
Funcionamento Interno

Cada música foi armazenada utilizando dois vetores:

um vetor para as notas
um vetor para o tempo de duração de cada nota

Exemplo:

static int n[] = {659,659,0,659};
static int d[] = {150,150,100,150};

Onde:

n[] representa as frequências das notas
d[] representa o tempo de duração
0 representa pausa ou silêncio
Estrutura do Código

O código foi dividido em funções para facilitar a organização e manutenção do projeto.

Função	Objetivo
mostrar_menu()	Exibe o menu no LCD
ler_botoes()	Faz a leitura dos botões
iniciar_musica()	Inicia a reprodução
rodar_pausa()	Pausa ou continua a música
parar_tudo()	Para a reprodução
tocar_som()	Executa as notas musicais
buscar_dados()	Carrega os dados das músicas
Ligações Principais
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
Conceitos Aplicados

Durante o desenvolvimento do projeto foram utilizados conceitos importantes de programação e eletrônica, como:

variáveis
vetores
funções
estruturas condicionais
laços de repetição
ponteiros
máquina de estados
entradas e saídas digitais
biblioteca LiquidCrystal
Como Executar
Abrir o código na IDE Arduino
Conectar o Arduino Uno ao computador
Fazer o upload do código
Montar o circuito conforme o esquema do projeto
Utilizar os botões para navegar e controlar as músicas
Resultado Final

O projeto conseguiu reproduzir diferentes músicas utilizando buzzer e fornecer interação ao usuário através do display LCD e dos botões.

Além da parte funcional, o desenvolvimento permitiu colocar em prática conceitos de programação embarcada, organização de código e integração entre hardware e software.
