#include <TrueRandom.h>

void setup() {
  Serial.begin(9600);

  Serial.print("I threw a random die and got ");
  Serial.print(random(1,7));

  Serial.print(". Then I threw a TrueRandom die and got ");
  Serial.println(TrueRandom.random(1,7));

}

void loop() {
  ; // Do nothing
}
