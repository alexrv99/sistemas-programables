#include <LiquidCrystal.h>

//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


const int pinA = 11;
const int pinB = 10;
const int pinC = 7;
const int pinD =  6;
const int pinMotor = 9;



void setup() {
  Serial.begin(9600);
//  lcd.begin(16, 2);

  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);
  analogWrite(pinMotor, 80);

}

void loop() {
  int suma = 0;
  if (digitalRead(pinA)) suma += 1;
  if (digitalRead(pinB)) suma += 2;
  if (digitalRead(pinC)) suma += 4;
  if (digitalRead(pinD)) suma += 8;
  //lcd.setCursor(0, 0);
  //lcd.print("Suma: ");
  //lcd.print(suma);

  //lcd.setCursor(0, 1);
//  lcd.print("Grados: ");
//  lcd.print(map(suma, 0, 15, 0, 360));

  Serial.print("Suma: ");
  Serial.println(suma);
  Serial.print("Grados: ");
  Serial.println(map(suma, 0, 15, 0, 360));


  delay(100);
}
