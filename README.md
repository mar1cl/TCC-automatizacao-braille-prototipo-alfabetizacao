# Automatização do Sistema Braille com ESP32

Projeto desenvolvido como Trabalho de Conclusão de Curso (TCC) com o objetivo de automatizar a representação de caracteres do sistema Braille utilizando microcontrolador ESP32 e micro servomotores.

Projeto aprovado com nota máxima – 2025.

** Este repositório ainda esta sendo alimentado e atualizado com todos os documentos!
---

## 📖 Sobre o Projeto

Este projeto propõe o desenvolvimento de um dispositivo automatizado capaz de representar fisicamente uma célula Braille por meio da movimentação de seis micro servomotores.

O sistema recebe caracteres via comunicação Serial ou Bluetooth e converte cada letra ou número em sua respectiva combinação de pontos no padrão Braille Grau 1.

A proposta busca contribuir como ferramenta auxiliar no processo de alfabetização de pessoas com deficiência visual, utilizando tecnologia acessível e de baixo custo.

---

## 🎯 Objetivo

Desenvolver um protótipo funcional capaz de:

- Receber caracteres via Bluetooth;
- Converter caracteres para o padrão Braille;
- Acionar mecanicamente os pontos da célula Braille;
- Retornar automaticamente à posição inicial após a leitura tátil.

---

## 🛠 Tecnologias Utilizadas

- ESP32
- Linguagem Python/ C++
- Biblioteca ESP32Servo
- Biblioteca BluetoothSerial
- Comunicação Bluetooth (SPP)
- Thinkercad (simulação inicial)

---

## 🔧 Componentes de Hardware

- 1x ESP32  
- 6x Micro servomotores  
- Protoboard  
- Cabos jumper  
- Fonte de alimentação  

---

## ⚙️ Funcionamento do Sistema

1. O usuário envia um caractere via Bluetooth ou Serial.
2. O ESP32 identifica o padrão Braille correspondente.
3. Os servomotores associados aos pontos ativos são acionados.
4. A representação permanece ativa por 2 segundos.
5. O sistema retorna automaticamente à posição inicial.

Cada servomotor representa um dos seis pontos da célula Braille, dessa forma, quando feito uma *combinação de pontos*,
representa-se um caractere do Braille na célula.

---

## 📁 Estrutura do Repositório
documentacao/
├── componentes-hardware.md
├── esquema-eletrico.png
├── prototipo-fisico.jp

codigo/
├── braille-esp32.ino

---

## 🖼 Imagens do Projeto

### Simulação no Thinkercad
<img width="947" height="529" alt="arduinotg" src="https://github.com/user-attachments/assets/16ba17f1-fade-496f-999f-3739705a4108" />

### Protótipo Físico com ESP32
<img width="344" height="459" alt="image" src="https://github.com/user-attachments/assets/f8a97546-5471-4f54-a982-bea3f185efec" />

---

## 📚 Documentação Completa

A documentação detalhada do projeto pode ser encontrada na pasta `documentacao`, incluindo:

- Explicação do hardware
- Explicação do software
- Esquema elétrico

---

## 👩‍💻 Autoras

Maria Clara de Andrade  
Hanela Ribeiro  

Trabalho de Conclusão de Curso – 2025

---

## 🚀 Considerações Finais

O protótipo integra automação, programação embarcada e tecnologia assistiva, demonstrando a aplicação prática de sistemas embarcados no desenvolvimento de soluções inclusivas.
Este repositório tem fins acadêmicos e demonstrativos.
