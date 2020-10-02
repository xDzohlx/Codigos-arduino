/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

unsigned long currentMillis = 0;  
int pos = 0;    // variable to store the servo position
int pos1=90;
int vueltas = 0;
long duration;
void setup() {
Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  servo4.attach(6);
  servo5.attach(5);// Derecha mano
  servo6.attach(4);// Izquierda
servo5.write(150);
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
  currentMillis = millis();
adelante();
}

void loop() {

  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(5);
  digitalWrite(11, LOW);
  duration = pulseIn(10, HIGH);
  
  //servo5.write(0);
  //servo6.write(180);   
  //if(duration>2000){Serial.println("Si");}else{Serial.println("No");}
  if(duration>1500){
    if((millis()-currentMillis>=4000)){
      servo5.write(150);
     adelante_lento();
      }else{
        adelante();
        }
    
    delay(175);
    }else{
    if((millis()-currentMillis>=4000)){
    vueltas ++;
    parar();
    delay(150);
    if(vueltas<3){
     izquierda(); 
      }else{
    derecha();
    vueltas = 0;
      }
    delay(220);
    }
    }
    }
 void adelante(){
  servo1.write(80);
  servo2.write(120);
  servo3.write(100);
  servo4.write(70);
  }
   void adelante_lento(){
  servo1.write(99);
  servo2.write(107);
  servo3.write(88);
  servo4.write(85);
  }
 void parar(){
  servo1.write(102);
  servo2.write(104);
  servo3.write(85);
  servo4.write(87);
  }
  void derecha(){
    servo1.write(120);
  servo2.write(120);
  servo3.write(100);
  servo4.write(100);
  }
  void izquierda(){
  servo1.write(80);
  servo2.write(80);
  servo3.write(60);
  servo4.write(60);
  }
  void derecha_lento(){
  servo1.write(105);
  servo2.write(107);
  servo3.write(88);
  servo4.write(90);
  }
  void izquierda_lento(){
  servo1.write(99);
  servo2.write(101);
  servo3.write(82);
  servo4.write(85);
  
  }
      
