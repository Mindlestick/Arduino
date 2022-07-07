#include "NECIRrcv.h"

NECIRrcv IR_1(42);
int i=0;
void setup()
{
  Serial.begin(9600);
  IR_1.begin();
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(10, LOW);
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(3), stopp, RISING);
}

void loop() {
  while(IR_1.available())
  {
    Serial.println(IR_1.read());
  }
  // put your main code here, to run repeatedly:
  i++;
  Serial.println(i);
    delay(250);
  if(i==10)
  {
    i=0;
    digitalWrite(4, HIGH);
  }



}

void stopp()
{
  noInterrupts();
  Serial.println("Reset contador");
  digitalWrite(4, LOW);
  interrupts();
}

