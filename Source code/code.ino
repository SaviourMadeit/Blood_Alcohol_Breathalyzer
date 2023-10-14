/#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD I2C address and size (16x2)

// MQ-3 gas sensor pins
const int analogPin = A0;

// LED pins
const int led1 = 2; // Red
const int led2 = 3; // Yellow
const int led3 = 4; // Yellow
const int led4 = 5; // Green
const int led5 = 6; // Green

// Buzzer pin
const int buzzerPin = 7;

int ledState = LOW;
unsigned long previousMillis = 0;
long blinkInterval = 250;

int TIME_UNTIL_WARMUP = 900; // warm up for 15 minutes!
unsigned long time;

void setup() {
  pinMode(analogPin, INPUT)
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  Serial.begin(9600);
  lcd.begin(16, 2);  // Initialize the LCD
  lcd.clear();  // Clear the LCD screen
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= blinkInterval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }

  delay(100);

  int val = readAlcohol();
  printTitle();
  printWarming();

  time = millis() / 1000;

  if (time <= TIME_UNTIL_WARMUP) {
    time = map(time, 0, TIME_UNTIL_WARMUP, 0, 100);
    lcd.setCursor(0, 1);
    lcd.print("Warming up: ");
    lcd.print(time);
    lcd.print("%");
  } else {
    printTitle();
    printAlcohol(val);
    printAlcoholLevel(val);
  }
}

void printTitle() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Breathalyzer");
}

void printWarming() {
  lcd.setCursor(0, 1);
  lcd.print("Warming up...");
}

void printAlcohol(int value) {
  lcd.setCursor(2, 1);
  lcd.print("Alcohol: ");
  lcd.print(value);
}

void printAlcoholLevel(int value) {
  lcd.setCursor(0, 1);

  if (value < 250) {
    lcd.print("You are sober.");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    noTone(buzzerPin);
  }
  else if (value >= 250 && value < 300) {
    lcd.print("One beer.");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    noTone(buzzerPin);
  }
  else if (value >= 300 && value < 350) {
    blinkInterval = 750; // blinking slow
    lcd.print("2+ beers.");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, ledState); // blinking yellow LED
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    noTone(buzzerPin);
  }
  else if (value >= 350 && value < 550) {
    blinkInterval = 250; // blinking faster
    lcd.print("Many beers!");
    digitalWrite(led1, LOW);
    digitalWrite(led2, ledState); // blinking yellow LED
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    noTone(buzzerPin);
  }
  else if (value > 450) {
    blinkInterval = 25; // blinking fast
    lcd.print("You are drunk!");
    digitalWrite(led1, ledState); // blinking red LED
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    tone(buzzerPin, 1000);
  }
}

int readAlcohol() {
  int val = 0;
  int val1;
  int val2;
  int val3;

  val1 = analogRead(analogPin);
  delay(10);
  val2 = analogRead(analogPin);
  delay(10);
  val3 = analogRead(analogPin);

  val = (val1 + val2 + val3) / 3;
  return val;
}
