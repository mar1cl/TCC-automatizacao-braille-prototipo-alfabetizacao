Projeto: Automatização do Sistema Braille  
Autoras: Maria Clara de Andrade e Hanela Ribeiro  
Orientador: Prof. Me. André Giovanni Castaldini

Ano: 2025  

---

# Componentes de Hardware

Este documento descreve o funcionamento do circuito e apresenta os componentes de hardware utilizados no desenvolvimento do projeto.

---

## 🧠 ESP32

O ESP32 é uma placa microcontroladora de baixo consumo de energia, amplamente utilizada em projetos de automação e IoT (Internet of Things).

O ESP32 é o controlador principal do projeto, sendo responsável pelo envio dos sinais de controle aos micro servomotores.

**Funcionalidades:**
- Realizar a conexão Bluetooth com o aplicativo;
- Processar os dados recebidos;
- Controlar os servomotores por meio de sinais elétricos;
- Executar a lógica implementada no código-fonte.

A escolha do ESP32 se deve à sua conectividade integrada, permitindo o uso de Bluetooth sem a necessidade de conexão com rede Wi-Fi.



## ⚙️ 2. Micro servomotores

Foram utilizados 6 micro servomotores para representar os pontos da célula Braille.

Os seis atuam conjuntamente para possibilitar a representação de uma única célula Braille, pois cada servomotor corresponde a um ponto da célula.

**Funcionalidades:**
- Levantar ou abaixar os pinos físicos do dispositivo;
- Representar letras por meio da combinação dos 6 pontos do sistema Braille.



## 📡 3. Módulo Bluetooth (integrado ao ESP32)

O Bluetooth, integrado ao ESP32, permite a comunicação entre o dispositivo e outro equipamento, como celular ou computador.

**Funcionalidades:**
- Receber caracteres enviados pelo aplicativo;
- Acionar os servomotores de acordo com o caractere recebido.



## 🔌 4. Fonte de Alimentação

A alimentação do sistema é realizada por meio de uma fonte conectada à tomada que gera rede elétrica.

Ela é responsável por fornecer energia para:
- ESP32;
- Servomotores.

É fundamental que a fonte possua corrente suficiente para alimentar todos os servomotores simultaneamente, garantindo o funcionamento estável do sistema.



## 🧩 5. Protoboard e Jumpers

A protoboard e os cabos jumper foram utilizados para realizar as conexões entre os componentes de forma organizada, segura e sem a necessidade de soldagem.



# 🖼 Esquema Elétrico

O esquema elétrico completo do projeto pode ser visualizado no arquivo:

`esquema-eletrico.png`

O esquema apresentado foi desenvolvido na plataforma Thinkercad, onde a simulação foi realizada utilizando uma placa Arduino.

Após análise técnica do projeto, optou-se pela utilização da placa ESP32 no protótipo físico, por apresentar maior conectividade, melhor desempenho e 
integração nativa com Bluetooth, além de oferecer maior portabilidade ao sistema.

Apesar da substituição da placa microcontroladora, a estrutura do circuito permaneceu a mesma, conforme representado na imagem. A principal alteração ocorreu 
no código-fonte (sketch), que precisou ser adaptado para o ESP32, devido à utilização de bibliotecas específicas e diferenças na configuração dos pinos.

---

🌟Portanto, o esquema elétrico apresentado serve como base estrutural para a implementação do protótipo, garantindo a correta interligação dos componentes e 
o funcionamento adequado do sistema automatizado de representação Braille.

---
