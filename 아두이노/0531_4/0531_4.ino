#include<LiquidCrystal.h>
#include<SHT1x.h>
LiquidCrystal lcd(12,11,5,4,3,2);

unsigned long time1,time2;

int Keypadpin=31;
byte FND_SEL[6]={14,15,16,17,18,19};
byte FND_DB[8]={22,23,24,25,26,27,28,29};
byte FND_DATA[]={0x3F,0x06,0x5B,0x4F,
0x66,0x6D,0x7D,0x27,
0x7F,0x67,0x77,0x7C,
0x39,0x5E,0x79,0x71};

int OpampInputPin=A0;
int val=0;

int CdsSensorValue=0;

int PsdSensorValue=0;

int BuzzerPin=8;

int DataPin=14;
int ClockPin=15;
int MT_P=8;
int MT_N=9;
SHT1x sht1x(DataPin,ClockPin);
float g_fTempC=0;
float g_fHumidity=0;

void setup(){
  pinMode(BuzzerPin,OUTPUT);
  lcd.begin(16,2);
  lcd.print ("SYSTEM START");

  Serial.begin(9600);

  for(int i=0;i<8;i++){
    pinMode(FND_DB[i],OUTPUT);
  }

  for(int i=0;i<6;i++){
    pinMode(FND_SEL[i],OUTPUT);
    digitalWrite(FND_SEL[i],HIGH);
  }

  pinMode(Keypadpin,INPUT);
  
  pinMode(1,OUTPUT);
  pinMode(3,OUTPUT);
  time1=time2=millis();
  }

void FndDisplay(byte Position,byte Data){
  for(int i=0;i<6;i++){
    if(i==Position){
      digitalWrite(FND_SEL[i],LOW);
     }
    else{
      digitalWrite(FND_SEL[i],HIGH);
    }
    for(int j=0;j<8;j++){
      digitalWrite(FND_DB[j],bitRead(Data,j));
    }
  }
}


/*
void SensorRead(){
  g_fTempC = sht1x.readTemperatureC()-5;
  g_fHumidity = sht1x.readHumidity();
  Serial.print ("TEMP:");
  Serial.println(g_fTempC);
  Serial.print ("HUMI:");
  Serial.println(g_fHumidity);
}
*/

void LEDblink(){
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
  }
void LEDoff(){
    digitalWrite(3,LOW);
    delay(1000);
    }

void FanON(){
    digitalWrite(MT_P,HIGH);
    digitalWrite(MT_N,LOW);
   }

void FanOFF(){
    digitalWrite(MT_P,LOW);
    digitalWrite(MT_N,LOW);
   }

void loop(){

  lcd.setCursor(0,1);

/*소리값 val*/
  val=analogRead(OpampInputPin);
  delay(10);
  if(digitalRead(Keypadpin)!=0){
    
    }

  
/*소리가 55보다 클때부터 작동*/
  if(val>=55){
    
   while(1){
  
     lcd.clear();

     if(digitalRead(Keypadpin)==0){
      lcd.clear();
      lcd.print ("SYSTEM START");
      break;
      }
  
     lcd.setCursor(0,0);
     CdsSensorValue=analogRead(A1);
     lcd.print(CdsSensorValue);
     
     lcd.setCursor(0,1);
     PsdSensorValue=analogRead(A2);
     PsdSensorValue=(6762/(PsdSensorValue-9))-4;
     if(PsdSensorValue<7&&PsdSensorValue>=0){
        PsdSensorValue=7;
     }
     if(PsdSensorValue>100||PsdSensorValue<0){
        PsdSensorValue=100;
     }
     lcd.print(PsdSensorValue);

     
/*거리가 20cm 이하면 소리 삑삑*/
      if(PsdSensorValue<=20){
        tone(BuzzerPin,262,50);
      }


     lcd.setCursor(7,0);
     g_fTempC = sht1x.readTemperatureC()-5; 
     lcd.print(g_fTempC);

     lcd.setCursor(7,1);
     g_fHumidity = sht1x.readHumidity();
     lcd.print(g_fHumidity);


/*온도가 27도 이상이면 FAN ON*/
      if(g_fTempC>=27){
        FanON();
      }
      else{
      FanOFF();
      }

/*습도가 50이하면 LED 깜박깜박*/

  if(g_fHumidity<=50){
  LEDblink();
  }
  else{
    LEDoff();
  }

     delay(500);


  }

/*습도가 50도 이하면*/


/* 7-SEG에 50을 출력하려고 하면 습,온도 센서가 이상하게 나옴.
     if(g_fHumidity>=42){
       for(int i=0;i<2;i++){
       FndDisplay(i,FND_DATA[i*5]);
       delay(10);
       }
     }
*/

 

  }

}

  
