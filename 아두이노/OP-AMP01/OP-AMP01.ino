int LedPin[16]={22,23,24,25,26,27,28,29,14,15,16,17,18,19,20,21};
const int LedLevelTable[16]={100,120,140,160,180,200,220,240,260,280,300,320,340,360,400,420};
unsigned int g_unAmpValue=0;


byte FND_SEL[6]={8,9,10,11,12,13};
byte FND_DB[8]={0,1,2,3,4,5,6,7};
byte FND_DATA[]={0x3F,0x06,0x5B,0x4F,
0x66,0x6D,0x7D,0x27,
0x7F,0x67,0x77,0x7C,
0x39,0x5E,0x79,0x71};

void setup()
  {
    for(int i=0;i<16;i++)
    {
      pinMode(LedPin[i],OUTPUT);
    }
  }
void LedControl(int Num){
  for(int i=0;i<16;i++)
  {
    if(i<=Num)
    {
      digitalWrite(LedPin[i],HIGH);
    }
    else
    {
      digitalWrite(LedPin[i],LOW);
    }
  }
}

void PrintLed(unsigned int AmpValue){
  if(LedLevelTable[0]>AmpValue)
  {
    for(int i=0;i<16;i++)
    {
      digitalWrite(LedPin[i],LOW);
    }
  }
  else if((LedLevelTable[0]<=AmpValue)&&(LedLevelTable[1]>AmpValue))
  {
    LedControl(0);
  }
  else if((LedLevelTable[1]<=AmpValue)&&(LedLevelTable[2]>AmpValue))
  {
    LedControl(1);
  }
  else if((LedLevelTable[2]<= AmpValue) && (LedLevelTable[3] > AmpValue))
  {
    LedControl(2);
  }
  else if((LedLevelTable[3]<= AmpValue) && (LedLevelTable[4] > AmpValue))
  {
    LedControl(3);
  }
  else if((LedLevelTable[4]<= AmpValue) && (LedLevelTable[5] > AmpValue))
  {
    LedControl(4);
  }
  else if((LedLevelTable[5]<= AmpValue) && (LedLevelTable[6] > AmpValue))
  {
    LedControl(5);
  }
  else if((LedLevelTable[6]<= AmpValue) && (LedLevelTable[7] > AmpValue))
  {
    LedControl(6);
  }
  else if((LedLevelTable[7]<= AmpValue) && (LedLevelTable[8] > AmpValue))
  {
    LedControl(7);
  }
  else if((LedLevelTable[8]<= AmpValue) && (LedLevelTable[9] > AmpValue))
  {
    LedControl(8);
  }
  else if((LedLevelTable[9]<= AmpValue) && (LedLevelTable[10] > AmpValue))
  {
    LedControl(9);
  }
  else if((LedLevelTable[10]<=AmpValue)&&(LedLevelTable[11]>AmpValue))
  {
    LedControl(10);
  }
  else if((LedLevelTable[11]<=AmpValue)&&(LedLevelTable[12]>AmpValue))
  {
    LedControl(11);
  }
  else if((LedLevelTable[12]<=AmpValue)&&(LedLevelTable[13]>AmpValue))
  {
    LedControl(12);
  }
  else if((LedLevelTable[13]<=AmpValue)&&(LedLevelTable[14]>AmpValue))
  {
    LedControl(13);
  }
  else if((LedLevelTable[14]<=AmpValue)&&(LedLevelTable[15]>AmpValue))
  {
    LedControl(14);
  }
  else if(LedLevelTable[15]<AmpValue)
  {
    LedControl(15);
  }
}
void loop()
  {
    g_unAmpValue=analogRead(A0);
    PrintLed(g_unAmpValue);
  }
