#include <LiquidCrystal_I2C.h>

//#include <LiquidCrystal.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
#define mq3Pin 0
#define ledPin 8
//const int rs =13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorVal;
void setup()
{
  //Serial.begin(9600);
  //lcd.begin(16,2);
  lcd.init();
  pinMode(ledPin, OUTPUT);
  pinMode(mq3Pin,INPUT);
}

void loop ()
{
  sensorVal = analogRead(mq3Pin);
  //Serial.println(sensorVal);
  lcd.setCursor(0,1);
  lcd.print("SensorVal: ");
  lcd.print(sensorVal);
  delay(1000);
}
