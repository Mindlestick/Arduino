

byte armsDown[8]={
0b00100,
0b01010,
0b00100,
0b00100,
0b01110,
0b10101,
0b00100,
0b01010
};

byte armsUp[8]={
0b00100,
0b01010,
0b00100,
0b10101,
0b01110,
0b00100,
0b00100,
0b01010
};

void setup()
  {
    lcd.begin(16,2);
    lcd.print("Arduino!");
    lcd.createChar(3,armsDown);
    lcd.createChar(4,armsUp);
  }
void loop(){
  for(int i=0;i<3;i++){
    lcd.scrollDisplayRight();
    delay(1000);
  }
    for(int i=0;i<3;i++){
      lcd.scrollDisplayLeft();
      delay(1000);
    }
   for(int i=0;i<3;i++){
    lcd.setCursor(6,1);
    lcd.write(3);
    delay(1000);
    lcd.write(4);
    delay(1000);     
   }
   lcd.cursor();
   lcd.blink();
   delay(5000);
   lcd.noBlink();
   lcd.noCursor();
     }

 
