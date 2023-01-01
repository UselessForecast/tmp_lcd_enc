#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define ONE_WIRE_BUS 2
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int A = 12;
int B = 13;
int counter = 0;
int aState;
int aLastState;
void setup(void) {
  Serial.begin(9600);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  aLastState = digitalRead(A);
  sensors.begin();
  lcd.begin();
  lcd.backlight();

}
void loop(void) {
  aState = digitalRead(A);
  if (aState != aLastState){
    if (digitalRead(B) != aState){
      counter ++;
    }else {
      counter --;
    }
    Serial.println(counter);
    lcd.clear();
    lcd.print("Counter:");
    lcd.setCursor(0,1);
    lcd.print(counter);
    lcd.setCursor(0,2);
    lcd.print("Tmp:");
    lcd.setCursor(4,2);
    lcd.print(sensors.getTempCByIndex(0));
   
  }
  aLastState = aState;
  
}  
