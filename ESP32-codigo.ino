#include <ESP32Servo.h>
#include "BluetoothSerial.h"

static const int NUM_SERVOS = 6;

// Pinos escolhidos (evitando 21 e 22):
int servoPins[NUM_SERVOS] = {13, 14, 16, 17, 18, 19};

// Posições iniciais por servo (0..5):
// Servos 0,1,2 -> 45°; Servos 3,4,5 -> 0°
int initialAngle[NUM_SERVOS] = {45, 45, 45, 0, 0, 0};

// DOT(1..6) -> índice de servo, conforme mapeamento pedido
// (0,0)->S2 (dot1), (1,0)->S1 (dot2), (2,0)->S0 (dot3),
// (0,1)->S3 (dot4), (1,1)->S4 (dot5), (2,1)->S5 (dot6)
int servoForDot[7] = {
  -1, // não usado
  2,  // dot1 -> servo 2
  1,  // dot2 -> servo 1
  0,  // dot3 -> servo 0
  3,  // dot4 -> servo 3
  4,  // dot5 -> servo 4
  5   // dot6 -> servo 5
};

Servo servos[NUM_SERVOS];
BluetoothSerial SerialBT;  // Bluetooth Classic SPP

// Retorna máscara (bits 0..5 correspondem aos pontos 1..6) para um caractere Braille Grau 1 básico
uint8_t brailleMaskForChar(char ch) {
  if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';

  switch (ch) {
    // Letras a..z (pontos 1..6)
    case 'a': return 0x01;               // 1
    case 'b': return 0x03;               // 1,2
    case 'c': return 0x09;               // 1,4
    case 'd': return 0x19;               // 1,4,5
    case 'e': return 0x11;               // 1,5
    case 'f': return 0x0B;               // 1,2,4
    case 'g': return 0x1B;               // 1,2,4,5
    case 'h': return 0x13;               // 1,2,5
    case 'i': return 0x0A;               // 2,4
    case 'j': return 0x1A;               // 2,4,5
    case 'k': return 0x05;               // 1,3
    case 'l': return 0x07;               // 1,2,3
    case 'm': return 0x0D;               // 1,3,4
    case 'n': return 0x1D;               // 1,3,4,5
    case 'o': return 0x15;               // 1,3,5
    case 'p': return 0x0F;               // 1,2,3,4
    case 'q': return 0x1F;               // 1,2,3,4,5
    case 'r': return 0x17;               // 1,2,3,5
    case 's': return 0x0E;               // 2,3,4
    case 't': return 0x1E;               // 2,3,4,5
    case 'u': return 0x25;               // 1,3,6
    case 'v': return 0x27;               // 1,2,3,6
    case 'w': return 0x3A;               // 2,4,5,6
    case 'x': return 0x2D;               // 1,3,4,6
    case 'y': return 0x3D;               // 1,3,4,5,6
    case 'z': return 0x35;               // 1,3,5,6

    // Dígitos (mapeados para a..j sem sinal numérico)
    case '1': return 0x01; // a
    case '2': return 0x03; // b
    case '3': return 0x09; // c
    case '4': return 0x19; // d
    case '5': return 0x11; // e
    case '6': return 0x0B; // f
    case '7': return 0x1B; // g
    case '8': return 0x13; // h
    case '9': return 0x0A; // i
    case '0': return 0x1A; // j

    // Espaço ou não suportado: sem pontos
    case ' ': default: return 0x00;
  }
}

// Alterna ângulo: se inicial = 45 -> 0; se inicial = 0 -> 45
int toggledAngleFromInitial(int initAng) {
  return (initAng == 45) ? 0 : 45;
}

void applyInitialPositions() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].write(initialAngle[i]);
    delay(20);
  }
}

// Lê um caractere tanto da Serial quanto do Bluetooth.
// Retorna true se leu um caractere válido em 'outChar'.
bool readAnyChar(char &outChar) {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    if (ch != '\r' && ch != '\n') { outChar = ch; return true; }
  }
  if (SerialBT.available() > 0) {
    char ch = SerialBT.read();
    if (ch != '\r' && ch != '\n') { outChar = ch; return true; }
  }
  return false;
}

void setup() {
  Serial.begin(115200);
  // Opcional: defina um PIN antes do begin (algumas versões exigem isso)
  SerialBT.setPin("1234",4);
  SerialBT.begin("ESP32-Braille"); // Nome visível para pareamento

  Serial.println("Braille-Servo ESP32: envie 1 caractere via Serial ou Bluetooth (SPP).");

  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].setPeriodHertz(50);
    bool ok = servos[i].attach(servoPins[i], 500, 2400);
    if (!ok) {
      Serial.print("Falha ao anexar servo no GPIO "); Serial.println(servoPins[i]);
    } else {
      Serial.print("Servo "); Serial.print(i);
      Serial.print(" no GPIO "); Serial.print(servoPins[i]);
      Serial.print(" (inicial = "); Serial.print(initialAngle[i]); Serial.println("°)");
    }
  }
  delay(200);
  applyInitialPositions();
}

void loop() {
  char ch;
  if (readAnyChar(ch)) {
    uint8_t mask = brailleMaskForChar(ch);

    // Logs para USB e Bluetooth
    Serial.print("Caractere recebido: '"); Serial.print(ch); Serial.println("'");
    Serial.print("Mascara Braille (bits 1..6): 0x"); Serial.println(mask, HEX);
    SerialBT.print("Recebido: '"); SerialBT.print(ch); SerialBT.println("'");

    // 1) Alterna os pontos ativos para o oposto da posição inicial
    for (int dot = 1; dot <= 6; dot++) {
      int si = servoForDot[dot];
      if (mask & (1 << (dot - 1))) {
        int target = toggledAngleFromInitial(initialAngle[si]);
        servos[si].write(target);
      } else {
        servos[si].write(initialAngle[si]);
      }
      delay(10);
    }

    // 2) Mantém por 2 segundos
    delay(2000);

    // 3) Retorna todos à posição inicial
    applyInitialPositions();
    Serial.println("Retorno às posições iniciais concluído.\n");
    SerialBT.println("OK: retorno ao inicial.");
  }

  // Pequeno atraso para reduzir uso de CPU
  delay(5);
}
