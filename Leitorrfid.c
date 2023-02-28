/* 
Nome do Programa: Leito RFID
Descrição do Programa: Segue documentação README
Nome autor: Mauro 
Data: 28/02/23

*/

// Bibliotecas Auxiliares          O Programa depende destas bibliotecas

#include <SPI.h>
#include <MFRC522.h>


// Mapeamento de Hardware
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria instância com MFRC522
 

//  Variáveis Globais 
char st[20];


// Configurações Iniciais 
void setup() 
{
  Serial.begin(9600);   // Inicia comunicação Serial em 9600 baud rate
  SPI.begin();          // Inicia comunicação SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  
  Serial.println("Aproxime seu cartao ou tag do leitor...");
  Serial.println();
   
  
} 


// Loop Infinito
void loop() 
{
  // Verifica novos cartões
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Seleciona um dos cartões
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  // Mostra UID na serial
  Serial.print("UID: ");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  
  if (conteudo.substring(1) == "69 03 9A 6E") //UID 1 - Chaveiro
  {
    Serial.println("Chaveiro identificado!");
    Serial.println();
    delay(3000);
     
  }
 
  if (conteudo.substring(1) == "97 51 82 36") //UID 2 - Cartao
  {
    Serial.println("Cartao identificado");
    Serial.println();
    delay(3000);
    
  }
  
  
} //end loop
 
 
