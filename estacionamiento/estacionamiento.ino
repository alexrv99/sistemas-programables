/**
   El estacionamiento consiste en una entrada y salida
   accionadas por un sensor PIR. Solo hay 10 lugares para
   carros.
   Cuando un carro quiere entrar y no hay lugar, el led debe parpadear.
   Los servos se usan para simular las plumas.
   Si esta lleno, se mantiene el LED rojo. Si queda un lugar, parpadea el verde.
   Si no esta lleno y hay menos de 9 lugares, se mantiene en verde.

*/

#include <Servo.h>
#include <Ultrasonic.h>


Ultrasonic ultraEntrada(2, 3, 400 * 58 ); // (Trig PIN,Echo PIN,DistMax*58)
Ultrasonic ultraSalida(4, 5, 400 * 58 ); // (Trig PIN,Echo PIN,DistMax*58)


Servo servoEntrada;
Servo servoSalida;

byte carros = 0;
byte pinServoEntrada = 9;
byte pinServoSalida = 10;
byte pinLedVerde = 6;
byte pinLedRojo = 7;

byte limiteCarros = 10;

void setup() {

  Serial.begin(115200);
  servoEntrada.attach(pinServoEntrada);
  servoSalida.attach(pinServoSalida);

  pinMode(pinServoEntrada, OUTPUT);
  pinMode(pinServoSalida, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedRojo, OUTPUT);

}


unsigned long tiempoDesdeUltimoBlink;

void loop() {
  //  Serial.println(digitalRead(pinPirSalida));
  digitalWrite(pinLedRojo, carros == limiteCarros);


  if (carros < 9) {
    digitalWrite(pinLedVerde, HIGH);
  } else if (carros == limiteCarros) {
    digitalWrite(pinLedVerde, LOW);
  }

  if (carros == 9 && tiempoDesdeUltimoBlink + 1000 < millis()) {
    digitalWrite(pinLedVerde, !digitalRead(pinLedVerde));
    tiempoDesdeUltimoBlink = millis();
  } 
  verificarPuertas();
}



void verificarPuertas() {
  int lecturaEntrada = ultraEntrada.Ranging(CM);
  int lecturaSalida = ultraSalida.Ranging(CM);
  //  Serial.print("Entrada: ");
  //  Serial.println(lecturaEntrada);
  //  Serial.print("Salida: ");
  //  Serial.println(lecturaSalida);

  if (lecturaEntrada < 10) {
    Serial.println("CARRO EN ENTRADA");
    if (carros == limiteCarros) {
      Serial.println("Entrada negada!");
    } else {
      carros++;
      Serial.print("Carros: ");
      Serial.println(carros);
      Serial.println("--------------------");
      // ABRIR
      servoEntrada.write(0);
      delay(2000);
      servoEntrada.write(180);
    }
  }


  if (lecturaSalida < 10) {
    Serial.println("CARRO EN SALIDA");
    if (carros > 0) {
      carros--;
      Serial.print("Carros: ");
      Serial.println(carros);
      Serial.println("--------------------");
      // CERRAR
      servoSalida.write(0);
      delay(2000);
      servoSalida.write(180);
    }
  }
}

void asyncDelay(unsigned long interval) {
  unsigned long currentTime = millis();
  while (millis() < currentTime + interval) {
    verificarPuertas();
  }
}
