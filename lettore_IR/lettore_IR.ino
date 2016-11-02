/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * Rileva sulla seriale i codici dei pulsanti premuti (da uno a 10)
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;
char* canali[]={"uno","due","tre","quattro","cinque","sei","sette","otto","nove","zero",};
long codice[10];
int c=0;
int k=1;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
   
}

void loop() {
 
   int lettura;
   unsigned long tempMillis;//serve per il timeout sulla ricezione del valore di PWM
   byte caratteri; //contiene il numero di caratteri ricevuti
   byte tempChar; //contiene il carattere letto
Serial.print("Scrivi il nome pulsante: \t");
int data=Serial.read();

    if (irrecv.decode(&results)) {
      codice[c]=results.value;
      dump(&results);
      irrecv.resume(); // Receive the next value
    }
}
void dump(decode_results *results) {    
  
   if (codice[c]==16757325){
        Serial.println("RESET");
        for (int i=0;i<c;i++) {
        Serial.print("Tasto: \t");
        Serial.print(canali[i]);
        Serial.print("\t");
        Serial.println(codice[i]);
        }
        c=0;
        k=1;
        return;
   }
      Serial.print("Tasto: \t");
      Serial.print(canali[c]);
      Serial.print("\t");
      Serial.print(codice[c]); //decimale
      Serial.print("\t");
      Serial.print(results->value, HEX);
      Serial.print("\t");
      Serial.print(c);
      Serial.print("\t");
      Serial.println(k);
      c++;
      k++;
      if (c>9) {
        c=0;
      }
      delay(250);
      
       }
     
/*
  Serial.println("Tasto source"); 
    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    canali[1]=results.value;
    delay(2500);
    irrecv.resume();
    }

    Serial.print(canali[0]);
    Serial.print(canali[1]);
    
    Serial.println("Tasto source");
    irrecv.decode(&results);
    int source=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto muto");
    irrecv.decode(&results);
    int muto=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto record");
    irrecv.decode(&results);
    int record=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto chp");
    irrecv.decode(&results);
    int chp=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto times");
    irrecv.decode(&results);
    int times=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto volm");
    irrecv.decode(&results);
    int volm=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto full");
    irrecv.decode(&results);
    int full=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto volp");
    irrecv.decode(&results);
    int volp=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto 0");
    irrecv.decode(&results);
    int zero=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto chm");
    irrecv.decode(&results);
    int chm=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto recall");
    irrecv.decode(&results);
    int recall=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto uno");
    irrecv.decode(&results);
    int uno=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto due");
    irrecv.decode(&results);
    int due=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto tre");
    irrecv.decode(&results);
    int tre=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto quattro");
    irrecv.decode(&results);
    int quattro=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto cinque");
    irrecv.decode(&results);
    int cinque=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto sei");
    irrecv.decode(&results);
    int sei=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto sette");
    irrecv.decode(&results);
    int sette=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto otto");
    irrecv.decode(&results);
    int otto=(results.value, HEX);
    delay(250);
    irrecv.resume();
    Serial.println("Tasto nove");
    irrecv.decode(&results);
    int nove=(results.value, HEX);
    delay(250);
    irrecv.resume();
  Serial.print(uno);
  */
 


