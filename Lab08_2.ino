//尋找ultrasonic arduino程式庫 下載桌面解壓縮 點開拿出第一個資料夾放到arduino  libraries  他資料夾點開有範例lcd和keyword可以看
// HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
#include <LiquidCrystal.h> // include the library code
#include <Ultrasonic.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 8); //跟check1不一樣  2腳換8腳
#define TRIGGER_PIN 13
#define ECHO_PIN 14
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
const byte intPin=2; //interrupt pin

void setup() {
 lcd.begin(20, 2);
Serial.begin(9600);
pinMode(intPin, INPUT_PULLUP); 
attachInterrupt(2, int0, LOW);

}
void loop(){  
 if(digitalRead(6) == LOW) {
    noInterrupts();
  }
  else {
    interrupts();
  }  
delay(1000);
}
void int0() { //interrupt handler
  float cmMsec, inMsec;
long microsec = ultrasonic.timing();
  cmMsec =  ultrasonic.convert(microsec, Ultrasonic::CM); //計算距離，單位:公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::CM);//計算距離，單位:英吋
    lcd.setCursor(0, 0);//利用設定在第一排讓他不會一直往後跑
    lcd.print("MS: ");
    lcd.print(microsec);
    lcd.print(", CM: ");
    lcd.print(cmMsec);
    lcd.setCursor(0, 1);
    lcd.print(", IN: "); 
    lcd.print(inMsec);
}
