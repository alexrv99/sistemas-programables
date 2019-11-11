/**
   El estacionamiento consiste en una entrada y salida
   accionadas por un sensor PIR. Solo hay 10 lugares para
   carros.
   Cuando un carro quiere entrar y no hay lugar, el led debe parpadear.
   Los servos se usan para simular las plumas.
   Si esta lleno, se mantiene el LED rojo. Si queda un lugar, parpadea el rojo.
   Si no esta lleno y hay menos de 9 lugares, se mantiene en verde.
*/

#include <Servo.h>

Servo servoEntrada;
Servo servoSalida;

byte carros = 0;
byte pinServoEntrada = 2;
byte pinServoSalida = 3;
byte pinPirEntrada = 4;
byte pinPirSalida = 5;
byte pinLedEntrada = 6;
byte pinLedSalida = 7;

byte limiteCarros = 10;

void setup() {

  Serial.begin(9600);
  servoEntrada.attach(9);
  servoEntrada.attach(10);

  pinMode(pinServoEntrada, OUTPUT);
  pinMode(pinServoSalida, OUTPUT);
  pinMode(pinPirEntrada, INPUT);
  pinMode(pinPirSalida, INPUT);
  pinMode(pinLedEntrada, OUTPUT);
  pinMode(pinLedSalida, OUTPUT);

}


void loop() {

  if (digitalRead(pinServoEntrada)) {
    Serial.println("CARRO EN ENTRADA");

    if (carros == limiteCarros) {
      Serial.println("Entrada negada!");

    } else {
      // ABRIR
      servoEntrada.write(0);
      delay(1000);
      servoEntrada.write(180);
      carros++;
    }
  }


  if (digitalRead(pinServoSalida)) {
    Serial.println("CARRO EN SALIDA");

    // CERRAR
    servoSalida.write(0);
    delay(1000);
    servoSalida.write(180);
    carros--;
  }

}
