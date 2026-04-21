#include <LiquidCrystal.h>

// Configuração do LCD (Padrão 4 bits)
LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

// Definição dos pinos dos botões (Entradas)
#define BT_CIMA 2
#define BT_BAIXO 3
#define BT_PLAY 4
#define BT_PARAR 5

// Pinos de saída (Buzzer e LEDs)
#define PINO_SOM 10
#define LED_OK 13      // LED Verde/Azul (Reproduzindo)
#define LED_ESPERA A0  // LED Vermelho (Pausado/Menu)

// Variáveis de controle de estado (Máquina de Estados)
int qual_musica = 0; 
bool ta_tocando = false;
bool ta_pausado = false;

// Ponteiros para economia de RAM
int* notas;
int* tempos;
int total_notas = 0;

// Lista de faixas para o menu
String nomes[] = {"Mario", "Harry Potter", "Star Wars", "Darth Vader", "Pac-Man", "Tetris", "Zelda", "Sonic"};

void setup() {
  lcd.begin(16, 2);

  // Configuração dos botões com resistor interno PULL-UP
  pinMode(BT_CIMA, INPUT_PULLUP);
  pinMode(BT_BAIXO, INPUT_PULLUP);
  pinMode(BT_PLAY, INPUT_PULLUP);
  pinMode(BT_PARAR, INPUT_PULLUP);

  pinMode(PINO_SOM, OUTPUT);
  pinMode(LED_OK, OUTPUT);
  pinMode(LED_ESPERA, OUTPUT);

  // Estado Inicial: LED Vermelho aceso (Espera)
  digitalWrite(LED_OK, LOW);
  digitalWrite(LED_ESPERA, HIGH);

  mostrar_menu();
}

void loop() {
  ler_botoes();

  if (ta_tocando) {
    tocar_som();
  }
}

void ler_botoes() {
  // Navegação no menu (Apenas se não estiver tocando)
  if (digitalRead(BT_CIMA) == LOW && !ta_tocando) {
    qual_musica = (qual_musica + 1) % 8;
    mostrar_menu();
    delay(200); 
  }

  if (digitalRead(BT_BAIXO) == LOW && !ta_tocando) {
    qual_musica = (qual_musica - 1 + 8) % 8;
    mostrar_menu();
    delay(200);
  }

  // Lógica de Play / Pause
  if (digitalRead(BT_PLAY) == LOW) {
    if (!ta_tocando) {
      iniciar_musica();
    } else {
      rodar_pausa();
    }
    delay(300); 
  }

  // Lógica de Stop
  if (digitalRead(BT_PARAR) == LOW) {
    parar_tudo();
    delay(300);
  }
}

void iniciar_musica() {
  ta_tocando = true;
  ta_pausado = false;

  digitalWrite(LED_OK, HIGH);
  digitalWrite(LED_ESPERA, LOW);

  lcd.clear();
  lcd.print("Tocando:");
  lcd.setCursor(0, 1);
  lcd.print(nomes[qual_musica]);

  buscar_dados(); 
}

void parar_tudo() {
  ta_tocando = false;
  ta_pausado = false;
  noTone(PINO_SOM);

  digitalWrite(LED_OK, LOW);
  digitalWrite(LED_ESPERA, HIGH);

  lcd.clear();
  lcd.print("Musica parada");
  delay(500);
  mostrar_menu();
}

void rodar_pausa() {
  ta_pausado = !ta_pausado;

  if (ta_pausado) {
    noTone(PINO_SOM);
    digitalWrite(LED_OK, LOW);
    digitalWrite(LED_ESPERA, HIGH);
    
    // Atualiza o LCD para indicar pausa conforme solicitado
    lcd.setCursor(0, 0);
    lcd.print("Musica parada   "); 
  } else {
    digitalWrite(LED_OK, HIGH);
    digitalWrite(LED_ESPERA, LOW);
    
    // Retorna o status para "Tocando" ao despausar
    lcd.setCursor(0, 0);
    lcd.print("Tocando:        ");
  }
}

void tocar_som() {
  for (int i = 0; i < total_notas; i++) {
    if (!ta_tocando) return;

    int f = notas[i];
    int t = tempos[i];

    if (f != 0 && !ta_pausado) tone(PINO_SOM, f);

    int t_passado = 0;
    while (t_passado < t) {
      if (digitalRead(BT_PARAR) == LOW) {
        parar_tudo();
        return;
      }
      
      if (digitalRead(BT_PLAY) == LOW) {
        rodar_pausa();
        delay(300);
      }

      if (!ta_pausado) {
        t_passado += 10;
        delay(10);
      } else {
        noTone(PINO_SOM); 
        delay(10); 
      }
    }

    noTone(PINO_SOM);
    delay(t * 0.15); 
  }
  parar_tudo();
}

void mostrar_menu() {
  lcd.clear();
  lcd.print("Escolher musica:");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(nomes[qual_musica]);
}

void buscar_dados() {
  switch(qual_musica) {
    case 0: { // Mario
      static int n[] = {659,659,0,659,0,523,659,0,784,0,784,0,659,0,523,0,587,0,494};
      static int d[] = {150,150,100,150,100,150,150,100,300,150,300,150,150,150,150,150,150,150,350};
      notas = n; tempos = d; total_notas = 19;
    } break;

    case 1: { // Harry Potter
      static int n[] = {294,392,466,440,392,587,523,466,440,392,349,440};
      static int d[] = {250,250,250,250,250,300,350,250,250,250,250,350};
      notas = n; tempos = d; total_notas = 12;
    } break;

    case 2: { // Star Wars
      static int n[] = {440,440,440,349,523,440,349,523,440};
      static int d[] = {300,300,300,200,350,300,200,350,400};
      notas = n; tempos = d; total_notas = 9;
    } break;

    case 3: { // Darth Vader
      static int n[] = {392,392,392,311,466,392,311,466,392};
      static int d[] = {300,300,300,200,350,300,200,350,450};
      notas = n; tempos = d; total_notas = 9;
    } break;

    case 4: { // Pac-Man
      static int n[] = {988,988,784,659,784,988};
      static int d[] = {150,150,150,150,150,300};
      notas = n; tempos = d; total_notas = 6;
    } break;

    case 5: { // Tetris
      static int n[] = {659,494,523,587,523,494,440};
      static int d[] = {250,250,250,250,250,250,350};
      notas = n; tempos = d; total_notas = 7;
    } break;

    case 6: { // Zelda
      static int n[] = {392,440,494,523,494,440};
      static int d[] = {300,300,300,350,300,300};
      notas = n; tempos = d; total_notas = 6;
    } break;

    case 7: { // Sonic
      static int n[] = {659,784,880,784,659,523,659,784};
      static int d[] = {150,150,150,150,250,150,150,250};
      notas = n; tempos = d; total_notas = 8;
    } break;
  }
}