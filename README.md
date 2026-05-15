# CCP020 - DIGITAL EXPERIENCE ULTIMATE

## Projeto - Reprodutor de Músicas com Arduino

Esse projeto foi desenvolvido utilizando um Arduino Uno com a proposta de criar um pequeno reprodutor de músicas utilizando componentes eletrônicos básicos.

A ideia principal era montar um sistema simples, mas interativo, onde o usuário pudesse escolher músicas através de um menu no display LCD e controlar a reprodução usando botões físicos.

O sistema conta com:
- Display LCD 16x2
- Buzzer
- LEDs de status
- Botões de controle
- Menu de navegação

---

# Integrantes

- Kaike Frentzel De Oliveira
- Pedro Cembrone De Sá

---

# Objetivo do Projeto

O projeto foi criado para colocar em prática conteúdos vistos durante as aulas, principalmente conceitos relacionados a:

- Programação embarcada
- Entradas e saídas digitais
- Organização de código
- Funções
- Vetores
- Lógica de programação
- Controle de hardware utilizando Arduino

Além disso, o projeto também ajudou bastante na parte de integração entre software e componentes eletrônicos.

---

# Componentes Utilizados

| Componente | Quantidade |
|---|---|
| Arduino Uno | 1 |
| Display LCD 16x2 | 1 |
| Protoboard | 2 |
| Buzzer | 1 |
| LEDs | 2 |
| Resistores | 3 |
| Botões | 4 |
| Jumpers | Vários |

---

# Funcionamento do Sistema

Quando o Arduino é ligado, o LCD mostra um menu para seleção das músicas disponíveis.

Exemplo:

```text
Escolher musica:
> Mario
```

Os botões permitem navegar entre as músicas e controlar a reprodução.

## Função dos Botões

| Botão | Função |
|---|---|
| CIMA | Próxima música |
| BAIXO | Música anterior |
| PLAY | Tocar ou pausar |
| STOP | Parar música |

---

# LEDs de Status

| LED | Função |
|---|---|
| Verde | Música tocando |
| Vermelho | Sistema parado ou pausado |

---

# Músicas Disponíveis

As músicas cadastradas no projeto são:

- Mario
- Harry Potter
- Star Wars
- Darth Vader
- Pac-Man
- Tetris
- Zelda
- Sonic

---

# Como as músicas funcionam

Cada música foi criada utilizando dois vetores:
- um vetor para armazenar as notas
- outro vetor para armazenar o tempo de duração

Exemplo:

```cpp
static int n[] = {659,659,0,659};
static int d[] = {150,150,100,150};
```

O vetor `n[]` guarda as frequências das notas e o vetor `d[]` guarda o tempo de duração de cada nota.

Quando aparece `0`, significa uma pausa na música.

---

# Organização do Código

O código foi separado em funções para deixar a estrutura mais organizada e facilitar o entendimento.

| Função | O que faz |
|---|---|
| `mostrar_menu()` | Mostra o menu no LCD |
| `ler_botoes()` | Faz a leitura dos botões |
| `iniciar_musica()` | Inicia a reprodução |
| `rodar_pausa()` | Pausa ou continua a música |
| `parar_tudo()` | Para a reprodução |
| `tocar_som()` | Executa as notas musicais |
| `buscar_dados()` | Carrega os dados das músicas |

---

# Ligações Utilizadas

## LCD

| LCD | Arduino |
|---|---|
| RS | Pino 12 |
| E | Pino 11 |
| D4 | Pino 9 |
| D5 | Pino 8 |
| D6 | Pino 7 |
| D7 | Pino 6 |

---

## Botões

| Botão | Pino |
|---|---|
| CIMA | Pino 2 |
| BAIXO | Pino 3 |
| PLAY | Pino 4 |
| STOP | Pino 5 |

---

## Saídas

| Componente | Pino |
|---|---|
| Buzzer | Pino 10 |
| LED Verde | Pino 13 |
| LED Vermelho | Pino A0 |

---

# Conceitos Utilizados

Durante o desenvolvimento do projeto foram utilizados vários conceitos importantes, como:

- Variáveis
- Vetores
- Funções
- Estruturas condicionais
- Repetição
- Ponteiros
- Máquina de estados
- Biblioteca LiquidCrystal

---

# Como Executar

1. Abrir o código na IDE Arduino  
2. Conectar o Arduino Uno no computador  
3. Fazer o upload do código  
4. Montar o circuito corretamente  
5. Utilizar os botões para controlar as músicas  

---

# Resultado Final

O projeto conseguiu reproduzir diferentes músicas utilizando buzzer e fornecer interação através do LCD e dos botões.

Além da parte funcional, o desenvolvimento ajudou bastante na prática de programação, organização do código e integração entre hardware e software.

---

# Imagem do Projeto

![Projeto](Arduino.png)

---

# Vídeo do Projeto

Clique no link abaixo para assistir ao funcionamento do projeto:

[Assistir vídeo no YouTube](https://youtube.com/shorts/e8fbsYHyTJE?si=T8x5NMm9kxQhim_A)

---
