#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int potPin = A0;
const int motorPin = 9;
const int ledPin = 13;

void setup() {
 
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  lcd.print("Priject #16");
  lcd.setCursor(0, 1);
  lcd.print("Industrial Motor");
  lcd.setCursor(0, 2);
  lcd.print("Speed Controller");
  delay(3000);
  lcd.clear();

  // show students info 
  lcd.setCursor(0, 0);
  lcd.print("S1: Nada Alsaqqa");
  lcd.setCursor(0, 1);
  lcd.print("ID: 220212836");
  lcd.setCursor(0, 2);
  lcd.print("S2: Haneen Awad");
  lcd.setCursor(0, 3);
   lcd.print("ID: 220212135");
  delay(3000);
  lcd.clear();
}

void loop() {
  int potValue = analogRead(potPin); // read potentiometer
  // Map potentiometer value to PWM range (0-255) for motor speed
  int speedPWM = map(potValue, 0, 1023, 0, 255);
  // Map potentiometer value to simulated RPM range (0-470) for display
  int rpm = map(potValue, 0, 1023, 0, 470);
  // Send PWM signal to transistor to control motor speed
  analogWrite(motorPin, speedPWM);

  lcd.setCursor(0, 0);
  lcd.print("System Running ");

  // Row 2: Current RPM
  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(rpm);
  lcd.print(" RPM        ");

  // Row 3: LED indicator status
  lcd.setCursor(0, 2);
  if (rpm >= 230) {
    digitalWrite(ledPin, HIGH);
    lcd.print("LED: ON  (High Speed)");
  } else {
    digitalWrite(ledPin, LOW);
    lcd.print("LED: OFF (Low Speed) ");
  }

  delay(200);
}