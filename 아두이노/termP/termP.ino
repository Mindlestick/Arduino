#include<LiquidCrystal.h>
#include<SHT1x.h>
LiquidCrystal lcd(12,11,5,4,3,2);

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

  val=analogRead(OpampInputPin);
  delay(10);


/* 없어도 되는 코드
  CdsSensorValue=analogRead(A1);
  Serial.print ("CDSSensor=");
  Serial.println(CdsSensorValue);
  delay(500);

  */
/*
  PsdSensorValue=analogRead(A2);
  PsdSensorValue=(6762/(PsdSensorValue-9))-4;
  if(PsdSensorValue<7&&PsdSensorValue>=0){
    PsdSensorValue=7;
    }
  if(PsdSensorValue>100||PsdSensorValue<0){
    PsdSensorValue=100;
    }
  Serial.print("Distance=");
  Serial.print(PsdSensorValue);
  Serial.println("CM");
  delay(500);
  */

  if(val>=55){
    
   while(1){
     lcd.clear();


  
     lcd.setCursor(0,0);
     CdsSensorValue=analogRead(A1);
     lcd.print(CdsSensorValue);
            delay(500);

     lcd.clear();
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
          delay(500);




  
       lcd.clear();

     lcd.setCursor(7,0);
     g_fTempC = sht1x.readTemperatureC()-5; 
     lcd.print(g_fTempC);
               delay(500);

          lcd.clear();
     lcd.setCursor(7,1);
     g_fHumidity = sht1x.readHumidity();
     lcd.print(g_fHumidity);
               delay(500);



      if(PsdSensorValue<=20){
      tone(BuzzerPin,262,100);
      }


      if(g_fTempC>=28){
        FanON();
      }
      else{
      FanOFF();
      }

      if(g_fHumidity<=50){
        
        }






      }   

  }

  

}
