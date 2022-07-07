int PsdSensorValue=0;
int BuzzerPin=8;
long mi=330;
long delaytime[10]={50,40,30,20,10,5,4,3,2,1};

void setup(){
Serial.begin(9600);
Serial.println("PSDSensorReadStart");

}

void loop(){
  PsdSensorValue=analogRead(A0);
  PsdSensorValue=(6762/PsdSensorValue-9)-4;
  if(PsdSensorValue<7&&PsdSensorValue>=0){
  PsdSensorValue=7;
  }
  if(PsdSensorValue>100||PsdSensorValue<0)
  {
    PsdSensorValue=100;
  }



  tone(BuzzerPin,mi,100);
  delay(PsdSensorValue*10);
  
}
