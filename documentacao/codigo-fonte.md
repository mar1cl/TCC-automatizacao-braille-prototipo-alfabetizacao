Projeto: Automatização do Sistema Braille  
Autoras: Maria Clara de Andrade 
Ano: 2025  

---

# 💻 Explicação do Código

Este documento apresenta uma explicação simplificada do funcionamento do código desenvolvido para controlar a célula Braille utilizando o ESP32.

---

## 📚 Bibliotecas Utilizadas

O código utiliza duas bibliotecas principais:

- **ESP32Servo.h** → Para controlar os micro servomotores.
- **BluetoothSerial.h** → Para permitir a comunicação via Bluetooth.

---

## ⚙ Funcionamento Geral

O sistema funciona da seguinte forma:

1. O ESP32 aguarda o recebimento de um caractere (letra ou número).
2. O caractere pode ser enviado via cabo USB (Serial) ou Bluetooth.
3. O código identifica quais pontos da célula Braille devem ser ativados.
4. Os servomotores correspondentes se movimentam.
5. Após 2 segundos, todos retornam à posição inicial.

---

## Controle dos Servomotores

Foram utilizados 6 micro servomotores, representando os 6 pontos da célula Braille.

Cada servo possui:
- Um pino específico definido no código;
- Um ângulo inicial;
- Um ângulo alternativo para representar o ponto levantado.

Quando um ponto precisa ser ativado, o servo correspondente altera seu ângulo.

---

## Conversão para Braille

A função `brailleMaskForChar()` é responsável por converter o caractere recebido em um padrão correspondente ao sistema Braille.

Cada letra ou número possui uma combinação específica de pontos (1 a 6), e o código identifica quais devem ser acionados.

---

## Comunicação Bluetooth

O Bluetooth é iniciado no `setup()` com o nome:

ESP32-Braille

Assim, o dispositivo pode ser pareado com celular ou computador para envio dos caracteres.

---

## Resumo

De maneira geral, o código:

- Recebe um caractere;
- Identifica o padrão Braille correspondente;
- Move os servomotores;
- Mantém a posição por alguns segundos;
- Retorna todos à posição inicial.

Esse processo permite a representação física e tátil das letras em Braille.
