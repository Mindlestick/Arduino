#include<LiquidCrystal.h>
#include<SHT1x.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int LED=29;
int LED1=28;
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

  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1,LOW);
  
  pinMode(BuzzerPin,OUTPUT);
  lcd.begin(16,2);
  lcd.print ("SYSTEM START");

  for(int i=0;i<8;i++){
    pinMode(FND_DB[i],OUTPUT);
  }

  for(int i=0;i<6;i++){
    pinMode(FND_SEL[i],OUTPUT);
    digitalWrite(FND_SEL[i],HIGH);
  }

  pinMode(Keypadpin,INPUT);

  }

/*사용자 생성 함수*/

/*LED를 깜빡거리는 함수*/
void LEDblink(){
  digitalWrite(LED,HIGH);
  digitalWrite(LED1,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  digitalWrite(LED1,LOW);
}

/*소리가 나는 함수*/
void Sound(){
  tone(BuzzerPin,262,300);
  }

/*Fan을 가동시키는 함수*/
void FanON(){
    digitalWrite(MT_P,HIGH);
    digitalWrite(MT_N,LOW);
   }

/*Fan 가동을 중지하는 함수*/
void FanOFF(){
    digitalWrite(MT_P,LOW);
    digitalWrite(MT_N,LOW);
   }


void loop(){
  lcd.setCursor(0,1);

/*소리값 val*/
  val=analogRead(OpampInputPin);
  delay(5);
  if(digitalRead(Keypadpin)!=0){
    /*키패드 안눌렸을 때*/
    }

  
/*소리가 60보다 클때부터 작동*/
  if(val>=60){
    
   while(1){
     lcd.clear();
/*키패드 PR10번이 눌리면 모두 멈추고 SYSTEM START화면*/
     if(digitalRead(Keypadpin)==0){
      lcd.clear();
      lcd.print ("SYSTEM START");
      break;
      }
/*빛의 밝기 LCD 출력*/
     lcd.setCursor(0,0);
     CdsSensorValue=analogRead(A1);
     lcd.print(CdsSensorValue);

/*거리 LCD 출력*/
     lcd.setCursor(0,1);
     PsdSensorValue=analogRead(A2);
     /*적외선 거리 센서의 출력은 10~60cm 거리에서, 2.2V~0.5V로 반비례 값을 출력한다.
     10cm 이하의 거리는 검출하지 못한다.*/
     PsdSensorValue=(6762/(PsdSensorValue-9))-4;
     /*거리가 7cm 이내면 7cm로 인식한다.*/
     if(PsdSensorValue<7&&PsdSensorValue>=0){
        PsdSensorValue=7;
     }
     /*거리가 150cm 이상이면 150cm로 인식한다.*/
     if(PsdSensorValue>150||PsdSensorValue<0){
        PsdSensorValue=150;
     }
     lcd.print(PsdSensorValue);

     
/*거리가 20cm 이하면 소리 삑삑*/
      if(PsdSensorValue<=20){
        Sound();
      }

/*온습도 LCD화면 출력*/
     lcd.setCursor(7,0);
     g_fTempC = sht1x.readTemperatureC()-5; 
     lcd.print(g_fTempC);

     lcd.setCursor(7,1);
     g_fHumidity = sht1x.readHumidity();
     lcd.print(g_fHumidity);

/*온도가 30도 이상이면 FAN ON*/
      if(g_fTempC>=30){
        FanON();
      }
      else{
      FanOFF();
      }

/*습도가 50이하면 LED 깜박깜박*/
  if(g_fHumidity<=50){
    LEDblink();
  }

     delay(250);
  }

/*습도가 50도 이하면 7-SEG 50 출력*/

/* 7-SEG에 50을 출력하려고 하면 습,온도 센서가 이상하게 나옴.
     if(g_fHumidity<=50){
       for(int i=0;i<2;i++){
       FndDisplay(i,FND_DATA[i*5]);
       delay(10);
       }
     }
*/

 

  }

}

  
