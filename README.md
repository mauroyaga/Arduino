Leitor de RFID
__________________________________________________________________________________________________________________________________________________________________________

Este código é um exemplo de como usar um leitor de RFID (Radio-Frequency Identification) com um Arduino. RFID é uma tecnologia que permite
a identificação de objetos ou pessoas por meio de sinais de rádio emitidos por um transmissor e recebidos por um leitor. O leitor de RFID usado
neste exemplo é o MFRC522.

As bibliotecas auxiliares incluídas no código são a SPI (para comunicação serial periférica) e a MFRC522 (para controle do leitor de RFID).
Em seguida, o código define o mapeamento do hardware, as variáveis globais e as configurações iniciais.

A função setup() inicia a comunicação serial, SPI e MFRC522. Em seguida, é exibida uma mensagem solicitando que o usuário aproxime seu cartão do leitor.

A função loop() é um loop infinito que verifica se há novos cartões. Se um novo cartão for detectado, o código seleciona o cartão e exibe o
UID (Identificador Único do Cartão) na serial. Em seguida, o código verifica se o UID corresponde a um dos cartões conhecidos 
(UID 1 - Chaveiro ou UID 2 - Cartão) e exibe uma mensagem na serial indicando qual cartão foi identificado.

O código também inclui um atraso de 3 segundos entre a identificação de cada cartão para evitar a detecção múltipla do mesmo cartão.
__________________________________________________________________________________________________________________________________________________________________________

Dependências
__________________________________________________________________________________________________________________________________________________________________________

A biblioteca SPI (Serial Peripheral Interface) é uma biblioteca auxiliar usada para a comunicação serial periférica em placas Arduino. 
A comunicação serial periférica é um protocolo de comunicação que permite a transferência de dados entre dispositivos periféricos e 
um controlador central (como o Arduino) por meio de um barramento de comunicação compartilhado.

A biblioteca SPI fornece uma interface para a comunicação serial periférica entre o Arduino e outros dispositivos, como sensores,
módulos de display e leitores de RFID. A biblioteca inclui funções que permitem a configuração dos pinos SPI do Arduino e a transferência 
de dados entre o Arduino e dispositivos periféricos.

A biblioteca MFRC522 é uma biblioteca auxiliar para o controle de leitores de RFID do tipo MFRC522. Esses leitores de RFID operam na faixa
de frequência de 13,56 MHz e são capazes de ler e escrever dados em cartões RFID.

A biblioteca MFRC522 fornece uma interface para controlar um leitor de RFID MFRC522 com um Arduino. A biblioteca inclui funções que permitem
a inicialização do leitor, a leitura do UID de um cartão RFID, a leitura e gravação de dados em um cartão RFID e a comunicação com o leitor
por meio de um protocolo de comunicação SPI. O código-fonte do exemplo apresentado usa as funções MFRC522.PCD_Init() para inicializar o 
leitor de RFID e MFRC522.PICC_ReadCardSerial() para ler o UID de um cartão RFID.

_______________________________________________________________________________________________________________________________________________________________________________________
Para dowload das bibliotecas com detalhamento sugiro: https://github.com/miguelbalboa
