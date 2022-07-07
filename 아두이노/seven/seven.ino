byte FND_SEL[6]={8,9,10,11,12,13};
byte FND_DB[8]={0,1,2,3,4,5,6,7};
byte FND_DATA[]={0x3F,0x06,0x5B,0x4F,
0x66,0x6D,0x7D,0x27,
0x7F,0x67,0x77,0x7C,
0x39,0x5E,0x79,0x71};

void setup(){
  for(int i=0;i<8;i++)
  {
    pinMode(FND_DB[i],OUTPUT);
  }
  for(int i=0;i<6;i++)
  {
    pinMode(FND_SEL[i],OUTPUT);
    digitalWrite(FND_SEL[i],HIGH);
  }
}
void FndDisplay(byte Position,byte Data){
  for(int i=0;i<6;i++)
  {
    if(i==Position)
    {
      digitalWrite(FND_SEL[i],LOW);
    }
    else
    {
    digitalWrite(FND_SEL[i],HIGH);
    }
      for(int j=0;j<8;j++)
      {
        digitalWrite(FND_DB[j],bitRead(Data,j));
      }
  }
}
void loop(){
  for(int i=0;i<12;i++)
   {
    FndDisplay(i%6,FND_DATA[i]);
    delay(1000);   
   Serial.begin(9600);
   Serial.print("7segment : ");
   Serial.println(i%6,i);
   }
}
