#include <dht.h>

#define dht_dpin A1
int led = 7;
int speakerPin = 8;

dht DHT; //H

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 156 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(speakerPin, OUTPUT);
Serial.begin(9600);
for (int i=0; i<10; i++) {
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);
}
delay(5000);
digitalWrite(led, HIGH);
delay (5000);
digitalWrite(led, LOW);
playTone(notes[2], 500);
}

void loop() {
  // put your main code here, to run repeatedly:
DHT.read11(dht_dpin);  //H

int sensore=analogRead(A0);
//int sensored=digitalRead(8);
float vol=(float)sensore/1024*5.0;
digitalWrite(led, LOW);
Serial.print("Misura analogica: ");
Serial.print(sensore, DEC);
//Serial.print(" digitale: ");
//Serial.print(sensored);
Serial.print(" Voltaggio: ");
Serial.print(vol);
Serial.print(" Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
if (sensore>50) {
  digitalWrite(led, HIGH);
  
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
   
    }

    // pause between notes
    delay(tempo / 2);
  }
  delay(250);
  digitalWrite(led, LOW);
  delay(250);
  digitalWrite(led, HIGH);
  delay(250);
  if (sensore <=150) {
    noTone(speakerPin);
}
}
delay(1000);

}
