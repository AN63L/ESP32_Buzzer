#include <Wire.h>
#include <PMserial.h>
#define LED 2 // Onboard LED
#define RED 12 //D12
#define IR_SENSOR 13 //D13
#define BUZZER 4 // D4
int val = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT); // ONBOARD PIN
  pinMode(RED, OUTPUT);  // RED LED PIN
  digitalWrite(RED, LOW); // RED LED OFF
  pinMode(BUZZER, OUTPUT);  // Buzzer PIN
}

void loop() {
  Serial.println();
  Serial.println();

  digitalWrite(LED, HIGH);
  Serial.println("************************************");
  Serial.println("LED is on");
  Serial.println();
  val = digitalRead(IR_SENSOR); // IR Sensor output pin connected to D1  
  Serial.println(val);  // see the value in serial m0nitor in Arduino IDE  
  Serial.println();
  if(val == 0){  
   digitalWrite(RED, HIGH); // RED LED ON
   digitalWrite(BUZZER, HIGH); // BUZZER ON
  }  
  else{  
   digitalWrite(RED, LOW); // RED LED OFF
   digitalWrite(BUZZER, LOW); // BUZZER ON
  }  
  digitalWrite(LED, LOW);
  Serial.println("LED is off");
  Serial.println("************************************");
  Serial.println("************************************");
  Serial.println();
  delay(100); // wait for 1 second
}