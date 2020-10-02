const int pingPin = 7;
unsigned long currentMillis = 0;
int motor1,motor2;
int vueltas = 0;
long error = 0;
bool izquierda_1 = false;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
 //ULTRASONICOS
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);

  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  //MOTORES
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
currentMillis = millis();
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  long duration_2;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(5);
  digitalWrite(11, LOW);


  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(10, HIGH);
 
  //Serial.println(duration);
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(5);
  digitalWrite(7, LOW);

  duration_2 = pulseIn(8, HIGH);
adelante();

//Serial.println(duration_2);
motor1= 255;
motor2= 255;
if(duration<2000){//
    if(!izquierda_1){
    derecha();
    delay(2000);
    }else{
      if(duration<1800)
        izquierda();
    }
    vueltas = vueltas + 1;
    while(duration<3000){
      digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(5);
  digitalWrite(11, LOW);
  duration = pulseIn(10, HIGH);  
    }
}else{
  
  if((millis()-currentMillis>=35000)&&(duration_2>2000)&&(!izquierda_1)){//sensor ultra sonico lateral
    adelante();
    delay(200);
    izquierda();
    delay(3300);
        adelante();
    delay(2000);
   
    izquierda_1  = true;
  }else{
  adelante();  
  }
}
  delay(10);
}


long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
void adelante(){
    digitalWrite(5,HIGH);// ADELANTE 
  digitalWrite(3, LOW);

  digitalWrite(6, LOW);
  digitalWrite(9,HIGH);
  

}
void stop_1(){
  digitalWrite(3, LOW);// ADELANTE 
  digitalWrite(5, LOW);

  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  }

void derecha(){

  digitalWrite(3,HIGH);// ADELANTE 
  digitalWrite(5, LOW);

  digitalWrite(6, LOW);
  digitalWrite(9,HIGH);
}

void izquierda(){

  digitalWrite(5,HIGH);// ADELANTE 
  digitalWrite(3, LOW);

  digitalWrite(9, LOW);
  digitalWrite(6,HIGH);
}

