const int pote_in = A0; // Entrada potenciometro
const int bt1 = 11; // Entrada botao 1
const int bt2 = 12; // Entrada botao 2
const int bt3 = 13; // Entrada botao 3

//Salva status dos botoes e potenciometro
int pote_val = 0;
int pote_val_last = 0;
int bt11 = 0;
int bt22 = 0;
int bt33 = 0;
int bt1_last = 0;
int bt2_last = 0;
int bt3_last = 0;

void setup() {

  pinMode(bt1 , INPUT);
  pinMode(bt2 , INPUT);
  pinMode(bt3 , INPUT);

  // inicializa a comunicacao serial:
  Serial.begin(9600);
}

void loop() {

  // faz a leitura da entrada analogica:
  pote_val = analogRead(pote_in) / 8; // divide por 8 para ter valores na escala 0 a 127
  bt11 = digitalRead(bt1);
  bt22 = digitalRead(bt2);
  bt33 = digitalRead(bt3);

  if (pote_val != pote_val_last)// Se houver diferença do valor anterior
  {
    msgMIDI(176, pote_val);// envia mensagem MIDI pela serial
    pote_val_last = pote_val;// Atualiza status do potenciometro
  }

  if (bt11 != bt1_last)// Se houver diferença do valor anterior
  {
    msgMIDI(177, bt11);// envia mensagem MIDI pela serial
    bt1_last = bt11;// Atualiza status do potenciometro
  }

  if (bt22 != bt2_last)// Se houver diferença do valor anterior
  {
    msgMIDI(178, bt22);// envia mensagem MIDI pela serial
    bt2_last = bt22;// Atualiza status do potenciometro
  }

  if (bt33 != bt3_last)// Se houver diferença do valor anterior
  {
    msgMIDI(179, bt33);// envia mensagem MIDI pela serial
    bt3_last = bt33;// Atualiza status do potenciometro
  }

  // Aguarda 2 milissegundos antes do proximo loop:
  delay(2);
}

void msgMIDI(byte comando, byte data)
{
  Serial.write(comando);
  Serial.write(1);
  Serial.write(data);
}
