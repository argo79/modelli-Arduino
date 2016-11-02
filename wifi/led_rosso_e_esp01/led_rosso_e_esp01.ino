void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);    // accende il led (HIGH è il livello logico alto)
  delay(1000);                  // attende un secondo
  digitalWrite(2, LOW);     // spegne il led (LOW è il livello logico basso)
  delay(1000);                  // attende un secondo
}
