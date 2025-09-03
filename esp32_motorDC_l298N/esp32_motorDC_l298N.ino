// Definição dos pinos da ponte H
const int motorPin1 = 26; // Pino para controlar o sentido 1 do motor
const int motorPin2 = 27; // Pino para controlar o sentido 2 do motor

void setup() {
  // Configuração dos pinos como saída
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);


  // Inicializa a comunicação serial
  Serial.begin(9600);
  Serial.println("Controle do Motor DC via Serial");
  Serial.println("Comandos: A - Frente | B - Ré | C - Parar");
}

void loop() {
  // Verifica se há dados disponíveis na serial
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o comando enviado

    // Realiza a ação com base no comando
    if (comando == 'A' || comando == 'a') {
      // Girar o motor para frente
      digitalWrite(26, HIGH);
      digitalWrite(27, LOW);
      Serial.println("Motor girando para frente");
    } else if (comando == 'B' || comando == 'b') {
      // Girar o motor para trás
      digitalWrite(26, LOW);
      digitalWrite(27, HIGH);
      Serial.println("Motor girando para trás");
    } else if (comando == 'C' || comando == 'c') {
      // Parar o motor
      digitalWrite(26, LOW);
      digitalWrite(27, LOW);
      Serial.println("Motor parado");
    } else if (comando == 'L' || comando == 'l') {
      // Parar o motor
      digitalWrite(12, HIGH);
      digitalWrite(2, HIGH);
      delay(2000);
      digitalWrite(12, LOW);
      digitalWrite(2, LOW);

    } else {
      Serial.println("Comando inválido. Use A, B ou C.");
    }
    
  }
}
