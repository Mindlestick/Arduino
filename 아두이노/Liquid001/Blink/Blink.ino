#include <LiquidCrystal.h>
 LiquidCrystal lcd(12,11,5,4,3,2);

int PDSensorValue=0;
int CdsSensorValue=0;
void setup(){
  lcd.clear();
  lcd.begin(16,2);
}

void loop(){
  CdsSensorValue=analogRead(A0);
 PDSensorValue=analogRead(A1);

 lcd.setCursor(0,0);
//  lcd.clear();
  lcd.print(CdsSensorValue);
  delay(200);

 lcd.setCursor(0,1);
  // lcd.clear();  
    lcd.print( PDSensorValue);
  delay(500);
  }
