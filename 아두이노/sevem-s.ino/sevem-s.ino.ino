/*millis() 함수*/
byte FND_SEL[6]={14,15,16,17,18,19};
byte FND_DB[8]={22,23,24,25,26,27,28,29};
byte FND_DATA[]={0x3F,0x06,0x5B,0x4F,
0x66,0x6D,0x7D,0x27,
0x7F,0x67,0x77,0x7C,
0x39,0x5E,0x79,0x71};

void setup(){
    for(int i=0;i<8;i++){
    pinMode(FND_DB[i],OUTPUT);
  }

  for(int i=0;i<6;i++){
    pinMode(FND_SEL[i],OUTPUT);
    digitalWrite(FND_SEL[i],HIGH);
  }
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

void loop(){
 for(int i=0;i<2;i++){
    FndDisplay(i,FND_DATA[i*5]);
    delay(10);
  }
}
