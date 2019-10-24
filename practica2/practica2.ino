// 2400 off
// 600 on
const int LED = 13;
const float semiCicloBajo = 0.8;
const float semiCicloAlto = 0.2;

float f = 0.3333f;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  
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
