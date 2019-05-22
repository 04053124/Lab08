#include <LiquidCrystal.h>
#include <Ultrasonic.h>
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
#define TRIGGER_PIN 13
#define ECHO_PIN 14
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
 lcd.begin(20, 2);
Serial.begin(9600);
}
void loop(){
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); 
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); 
 lcd.setCursor (0,0);
lcd.print("MS: "); lcd.print(microsec);
 lcd.setCursor(0, 1); 
lcd.print(" CM: ");lcd.print(cmMsec);
lcd.print(",IN: "); lcd.print(inMsec);
  delay(1000); 
 lcd.clear();
 delay(100); 

}
