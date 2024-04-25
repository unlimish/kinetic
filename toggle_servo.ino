#include <Servo.h>

Servo myservo1;
Servo myservo2;
int pos = 0;
int INPUT_PIN = 13;
int switch_status = 0;

void setup() {
  pinMode(INPUT_PIN, INPUT);
  myservo1.attach(9);
  myservo2.attach(10);
  Serial.begin(9600);

}

void loop() {
  Serial.print(INPUT_PIN);
  while (switch_status = digitalRead(INPUT_PIN) == 1){
    for (pos = 0; pos <= 180; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    switch_status = digitalRead(INPUT_PIN);
    if (switch_status != 1)
      break;
    delay(15);
  }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo1.write(pos);
      myservo2.write(pos);
      switch_status = digitalRead(INPUT_PIN);
      switch_status = digitalRead(INPUT_PIN);
    if (switch_status != 1)
      break;
      delay(15);
    }
  }
}
