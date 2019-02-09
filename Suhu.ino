#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,9,10,11,12);

float C;
int panas = 40;
int dingin = 23;
void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Alif Maulana");
  lcd.setCursor(1,1);
  lcd.print("18116016");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Suhu C: ");
  lcd.setCursor(0,1);
}

void loop() {
    C = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    lcd.setCursor(11, 0);
    lcd.print(C);
    if (C < dingin) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);   
    }
    else if (C > panas) {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);   
    }
    else {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);   
    }
    delay(1000);
}