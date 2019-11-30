/*
 * 
 * All the resources for this project: http://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

#define RST_PIN1 4
#define SS_PIN1 5

MFRC522 mfrc522_1(SS_PIN1,RST_PIN1);
int present[4]={0,0,0,0};
int a =0;
int b=0;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  mfrc522_1.PCD_Init();  
  Serial.println();
  int count=1;
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}


void loop() 
{ 
  present[0]=0;
  present[1]=0;
  if (mfrc522_1.PICC_IsNewCardPresent())
  {
  present[0]=1;
  }
  if (mfrc522.PICC_IsNewCardPresent())
  {
  present[1]=1;
  }
  Serial.println(2*present[1]+present[0]);
  if ((present[1]==0) and (b==0))
  {
  digitalWrite(3,HIGH);
  }
  else
  {
  digitalWrite(3,LOW);
  }
  if (((present[0]==0) and (a==0)))
  {
  digitalWrite(2,HIGH);
  }
  else
  {
  digitalWrite(2,LOW);
  }
  a = present[0];
  b = present[1];
  delay(500);
 }
