#include <Servo.h>  

// Definir pines
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

// Crear objeto Servo
Servo myServo;

void setup() {
  
  Serial.begin(9600);

  // Configurar pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  myServo.attach(servoPin);
}

void loop() {
  
  long duration, distance;
  
  // Enviar pulso al Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
 
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration / 2) * 0.0343;
 
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mover el servo en función de la distancia
  if (distance < 10) {
    myServo.write(0);  
  } else if (distance < 20) {
    myServo.write(90);  
  } else {
    myServo.write(180); // Gira el servo a 180 grados si la distancia es mayor a 20 cm
  }

  
  delay(500);
}

