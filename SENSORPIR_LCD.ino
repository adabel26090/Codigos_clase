#include <LiquidCrystal.h>

int sensorPIR = 8;  
int led = 13;        
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(sensorPIR, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);  
  lcd.print("Esperando deteccion");
  lcd.setCursor(0, 1);
  lcd.print("de movimiento...");
  delay(2000); 
}

void loop() {
  int estadoSensor = digitalRead(sensorPIR);
  lcd.clear();
 
  if (estadoSensor == HIGH) {
    digitalWrite(led, HIGH);  
    lcd.setCursor(0, 0);     
    lcd.print("Movimiento");
    lcd.setCursor(0, 1);     
    lcd.print("detectado!");
  } 
  else {
    digitalWrite(led, LOW);  
    lcd.setCursor(0, 0);      
    lcd.print("Sin movimiento");
    lcd.setCursor(0, 1);      
    lcd.print("detectado.");
  }
  delay(1000);  /
}
