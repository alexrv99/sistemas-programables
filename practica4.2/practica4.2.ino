#include <Servo.h>

Servo sg90;

unsigned long tiempoApagado;
unsigned long tiempoEncendido;

const float f = 0.3333f;
const int LED = 13;
float semiCicloBajo = 0.8;
float semiCicloAlto = 0.2;


void setup() {
  Serial.begin(115200);
  sg90.attach(9);
  pinMode(LED, OUTPUT);

  Serial.println("Inserta el período (T en milisegundos)");
  esperarDato();
  long intervalo = leerString().toInt();
  Serial.print("Intervalo: ");
  Serial.println(intervalo);


  Serial.println("Teclee el semiciclo en alto de 0 a 100");
  esperarDato();
  int porcentaje = leerString().toInt();


  Serial.print("Porcentaje: ");
  Serial.println(porcentaje);



  tiempoEncendido = intervalo * porcentaje / 100;
  tiempoApagado = intervalo - tiempoEncendido;

  Serial.print("tiempoEncendido: ");
  Serial.println(tiempoEncendido);

  Serial.print("tiempoApagado: ");
  Serial.println(tiempoApagado);

}

void loop() {
  readSerial();

  sg90.write(90);
  digitalWrite(LED, HIGH);
  Serial.println("Encendido");
  asyncDelay(tiempoEncendido);

  sg90.write(120);
  digitalWrite(LED, LOW);
  Serial.println("Apagado");
  asyncDelay(tiempoApagado);


}

void asyncDelay(unsigned long interval) {
  unsigned long currentTime = millis();
  while (millis() < currentTime + interval) {
    readSerial();
  }
}

void readSerial() {
  if (Serial.available()) {
    char letra = Serial.read();
    if (letra == 'a') {
      Serial.println("--------------------");
      Serial.println("Modo uno");
      semiCicloBajo = 0.8;
      semiCicloAlto = 0.2;
    } else if (letra == 'b') {
      Serial.println("--------------------");
      Serial.println("Modo dos");
      semiCicloBajo = 0.2;
      semiCicloAlto = 0.8;
    } else
      return;
  }
}

String leerString() // lee mas de un caracter y lo retorna
{
  String cadena = "";
  while (Serial.available() > 0)
  {
    cadena = cadena + (char) Serial.read();
    delay(10);
  }
  return cadena;
}

void esperarDato() // funcion que espera hasta que se reciba un dato para continuar con la ejecucion
{
  limpiarSerial();
  while (Serial.available() == 0) {}
}

void limpiarSerial() // lee todo lo que hay en el monitor serial para recibir nuevos datos
{
  while (Serial.available()) Serial.read();
}
