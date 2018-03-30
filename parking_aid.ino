const int sensorPin = A5;

#include <LiquidCrystal.h>
LiquidCrystal lcd( 7, 2, 3 , 4, 5, 6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Welcome!");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = analogRead(sensorPin);
  Serial.print ("Sensor Value: ");
  Serial.print (sensorVal);

  float v = (sensorVal / 1024.0) * 5.0;

  Serial.print (" , Volts: ");
  Serial.print (v);

  if (v >= 0.35 and v < 1.0)  {
    Serial.print (" , Distance cm: ");
    float distance = (555.60 * (v * v * v * v) - 1846.55 * (v * v * v) + 2357.23 * (v * v) - 1417.42 * (v) + 380.56);
    Serial.println(distance);
    if (distance >= 15.0 and distance < 30.0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }
    if (distance >= 30.0 and distance < 45.0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }
    if (distance >= 45.0 and distance < 60.0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }
    if (distance >= 60.0 and distance < 80.0 ) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }
  }
  else if (v >= 1.0 and v < 2.625) {
    Serial.print (" , Distance cm: ");
    float distance = (3.3162 * (v * v * v * v) - 29.2683 * (v * v * v) + 98.9855 * (v * v) - 157.6901 * (v) + 113.7012);
    Serial.println(distance);
    if (distance >= 10.0 and distance < 15.0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }
    else if (distance >= 15.0 and distance < 30.0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);

      lcd.clear();
      lcd.print("Distance(cm):");
      lcd.setCursor(0, 1);
      lcd.print(distance);

    }

  }
  else if (v < 0.35)  {
    Serial.println (" , out of range");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);

    lcd.clear();
    lcd.print("Distance(cm):");
    lcd.setCursor(0,1);
    lcd.print("out of range!");

  }
  delay (100);
}
