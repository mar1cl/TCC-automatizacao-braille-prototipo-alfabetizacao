# Automatização do Sistema Braille com ESP32

Este projeto foi desenvolvido para o Trabalho de Conclusão de Curso (TCC), e teve como o objetivo a automatização do sistema Braille, ou seja, automatizar a representação de caracteres do sistema Braille utilizando microcontrolador ESP32 e micro servomotores.

Projeto aprovado com nota máxima – 2025.

** Este repositório ainda esta sendo alimentado e atualizado com todos os documentos!
---

## Sobre o Projeto
O projeto propõe o desenvolvimento de um protótipo que seja capaz de fazer a representação física de uma célula Braille através de uma placa controladora e seis micro servomotores.
O circuito recebe via Bluetooth ou serial os dados enviados por um aplicativo e o código-fonte faz a conversão dos caracteres dos Português para a sua representação no sistema Braille. 

A proposta deste trabalho é auxiliar o processo da alfabetização de deficiêntes visuais no sistema Braille através do protótipo desenvolvido, utilizando tecnologia acessível e de vaixo custo.


## Objetivo

- Modelar o display para a impressão 3D;
- Desenvolver um circuito de automação funcional utilizando ESP32 e servomotores;
- Desenvolver o código-fonte para fazer a conversão correta dos caracteres para a represetação em Braille;
- Desenvolver um aplicativo mobile acessivel que faça o envio dos caracteres para a tradução;
- Fazer a integração dos componentes e garantir o funcionamento.



## Tecnologias Utilizadas

- ESP32
- Linguagem Python/ C++
- Biblioteca ESP32Servo
- Biblioteca BluetoothSerial
- Comunicação Bluetooth (SPP)
- Thinkercad e Wokwi (simulação)



## Funcionamento do Sistema

1. O usuário envia um caractere via Bluetooth ou Serial.
2. O ESP32 identifica o padrão Braille correspondente.
3. Os servomotores associados aos pontos ativos são acionados.
4. A representação permanece ativa por 2 segundos.
5. O sistema retorna automaticamente à posição inicial.

Cada servomotor representa um dos seis pontos da célula Braille, dessa forma, quando feito uma *combinação de pontos*,
representa-se um caractere do Braille na célula.

---

## Estrutura do Repositório
documentacao/
├── componentes-hardware.md
├── esquema-eletrico.png
├── prototipo-fisico.jp

codigo/
├── braille-esp32.ino

---

## Imagens do Projeto

### Simulação no Thinkercad
<img width="947" height="529" alt="arduinotg" src="https://github.com/user-attachments/assets/16ba17f1-fade-496f-999f-3739705a4108" />

### Protótipo Físico com ESP32
<img width="344" height="459" alt="image" src="https://github.com/user-attachments/assets/f8a97546-5471-4f54-a982-bea3f185efec" />


## Documentação Completa

A documentação detalhada do projeto pode ser encontrada na pasta `documentacao`, incluindo:

- Explicação do hardware
- Explicação do software
- Esquema elétrico

---

## Autoria

Maria Clara de Andrade  
Hanela Ribeiro  
Orientador: Prof Me. André Giovanni Castaldini

Trabalho de Conclusão de Curso – 2025

Integrando automação, tecnologia assistiva e programação embarcada este projeto traz o desenvolviemnto de uma opção viável para subrir as necessidades de materias do sistema Braille. Este repositório tem fins acadêmicos e demonstrativos.
