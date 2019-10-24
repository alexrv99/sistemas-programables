
const float f = 0.3333f;
const int LED = 13;
float semiCicloBajo = 0.8;
float semiCicloAlto = 0.2;

int boton1 = 4;
int boton2 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
}


bool sec1 = true;
void loop() {
  int valorBoton1 = digitalRead(boton1);
  int valorBoton2 = digitalRead(boton2);
  if (valorBoton1 == HIGH && valorBoton2 == HIGH) {
    Serial.println("AMBOS");
    return;
  } else if (valorBoton1 == HIGH) {
    sec1 = true;
  } else if (valorBoton2 == HIGH) {
    sec1 = false;
  } 

  if (sec1) {
    Serial.println("UNO");
    semiCicloBajo = 0.8;
    semiCicloAlto = 0.2;
  } else {
    Serial.println("DOS");
    semiCicloBajo = 0.2;
    semiCicloAlto = 0.8;
  }

  float tiempoTotal = 1 / f * 1000;
  float tiempoBajo = semiCicloBajo * tiempoTotal;
  float tiempoAlto = semiCicloAlto * tiempoTotal;

  digitalWrite(LED, HIGH);
  Serial.println("HIGH");
  delay(tiempoAlto);

  digitalWrite(LED, LOW);
  Serial.println("LOW");
  delay(tiempoBajo);
}
