int LED = 13;
int tiempo = 500;

// este es la configuracion
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(tiempo);
  digitalWrite(LED, LOW);
  delay(tiempo);
}
