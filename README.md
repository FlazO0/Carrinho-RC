# Carro RC Bluetooth

## Descrição
Este projeto demonstra como construir e controlar um carro RC utilizando comunicação Bluetooth e uma placa Arduino. Ele permite controlar o carro através de comandos enviados de um dispositivo com Bluetooth, como um smartphone. O carro opera com dois motores DC controlados por um driver H-Bridge, e a velocidade é regulada via PWM (modulação por largura de pulso).

## Funcionalidades
- **Controle Bluetooth**: Controle o carro usando comandos enviados via Bluetooth.
- **Ajuste de Velocidade**: Velocidade ajustável em incrementos com base nos comandos recebidos.
- **Controle Direcional**: Suporta movimentos para frente, para trás, para esquerda e para direita.
- **Função Parada**: Permite parar o carro imediatamente.
- **Regulação de Velocidade via PWM**: Controle suave da velocidade dos motores com PWM.

---

## Componentes Necessários
1. **Arduino (ex: ESP32 ou qualquer placa compatível)**
2. **Módulo Bluetooth (ex: HC-05 ou Bluetooth embutido no ESP32)**
3. **Driver H-Bridge (ex: L298N)**
4. **Dois Motores DC**
5. **Pacote de Bateria**
6. **Fios de Conexão**
7. **Chassi para o Carro**

---

## Como Funciona
1. **Comunicação Bluetooth**: O Arduino fica ouvindo comandos via Bluetooth, que são enviados de um dispositivo pareado, como um smartphone.
2. **Controle de Motores**: Os comandos são mapeados para ações específicas, como ajustar a velocidade, mudar de direção ou parar o carro.
3. **Controle de Velocidade via PWM**: A velocidade do carro é regulada através de sinais PWM nas entradas de habilitação do driver de motor.
4. **Comandos Direcionais**: Sinais altos e baixos nas entradas de controle de motor determinam a direção de rotação dos motores.

---

## Comandos
O carro RC responde aos seguintes sinais Bluetooth:

| Comando | Ação                    |
|---------|-------------------------|
| `F`     | Mover para frente        |
| `B`     | Mover para trás          |
| `L`     | Virar para a esquerda    |
| `R`     | Virar para a direita     |
| `S`     | Parar                    |
| `0`-`9` | Ajustar a velocidade     |
| `q`     | Velocidade máxima        |

---

## Diagrama do Circuito
- Conecte os pinos de habilitação do H-Bridge aos pinos PWM definidos no código (`enA` e `enB`).
- Conecte os pinos de controle de motor (`IN1`, `IN2`, `IN3`, e `IN4`) ao driver H-Bridge.
- Certifique-se de fornecer energia para os motores através do H-Bridge.
- Emparelhe o módulo Bluetooth com seu dispositivo e envie comandos através de um aplicativo de terminal Bluetooth.

---

## Visão Geral do Código
1. **Setup**: Inicializa a comunicação Bluetooth, configura os pinos PWM para controle de velocidade e define o estado inicial dos motores (parados).
2. **Loop Principal**: Verifica continuamente os sinais Bluetooth e executa as funções correspondentes.
3. **Funções**:
   - `forward()`: Move o carro para frente.
   - `backward()`: Move o carro para trás.
   - `turnLeft()`: Para o motor direito e faz o motor esquerdo girar para virar à esquerda.
   - `turnRight()`: Para o motor esquerdo e faz o motor direito girar para virar à direita.
   - `stop()`: Para ambos os motores.

---

## Configuração
- Modifique a variável `Speed` no código para ajustar a velocidade inicial do carro. A velocidade pode ser incrementada com os comandos (`0`-`9`) ou configurada para o valor máximo com o comando `q`.
- Certifique-se de que a frequência e a resolução do PWM estejam configuradas corretamente de acordo com o driver de motor utilizado.

---

## Exemplos de Uso
1. Emparelhe seu dispositivo com o módulo Bluetooth.
2. Abra um aplicativo de terminal Bluetooth.
3. Envie comandos (`F`, `B`, `L`, `R`, `S`, etc.) para controlar o carro.
4. Observe o carro respondendo aos comandos em tempo real.

---

## Resolução de Problemas
1. **Carro não se movendo**: Verifique as conexões dos motores e a alimentação.
2. **Bluetooth não emparelha**: Certifique-se de que o módulo Bluetooth está ligado e visível.
3. **Movimento incorreto**: Verifique se a fiação entre o driver de motor e o Arduino está de acordo com a configuração do código.

---
