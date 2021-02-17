//SUPERMINISUMO
//PUERTOS:
//D5 DIPSWITCH_1
//D6 DIPSWITCH_2
//D7 DIPSWITCH_3

// D8 LED  //Viriiiii!!!!!!
// D9 LED

// D10 START PIN

//A0-- A3 SENSORS

// MOTORES

//D3 MOTOR IZQUIERDA PWM
//D12 MOTOR IZQUIERDA DIRECCION

 // D11 MOTOR DERECHA PWM
 // D13 MOTOR DERECHA DIRECCION

//sensor izquierda
//sensor derecha
//sensor centro
unsigned long currentMillis = 0; 
 int motor_izquierda = 1000;
 int motor_derecha = 1000;
 int motor_izquierda_centro = 1000;
 int motor_derecha_centro = 1000;
 int motor_izquierda_accel = 0x00;
 int motor_derecha_accel = 0x00; 
 int motor_derecha_val = 0;
 int motor_izquierda_val = 0;
bool sensor_centro =  false;
bool sensor_derecha =  false;
bool sensor_izquierda =  false;
void setup() {
//MOTORES
pinMode(3, OUTPUT);
pinMode(12, OUTPUT);

pinMode(11, OUTPUT);
pinMode(13, OUTPUT);
//DIPSWITCH
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);

pinMode(10,INPUT);

  motor_derecha = 1030;
  motor_izquierda = 1030;
  currentMillis = millis();
delay(500);
}

void loop() {

  //digitalWrite(12,HIGH);
  //analogWrite(3,20);

  //digitalWrite(13,HIGH);
  //analogWrite(11,20);
if(currentMillis+3000>millis()){
if(digitalRead(0)){//izquierda
  motor_derecha = motor_derecha - 2;
  motor_izquierda = motor_izquierda + 3;
}
if(digitalRead(2)){//derecha
  motor_derecha = motor_derecha + 2;
  motor_izquierda = motor_izquierda - 1;  
}

}else{
  //soft stop
  
  motor_derecha = 1000;
  motor_izquierda = 1000;  

}
  

//ya funcionan los motores
if(motor_derecha_centro <= motor_derecha){
 //atras
  motor_derecha_val = motor_derecha - motor_derecha_centro;
  if(motor_derecha_val>60){
    motor_derecha_val = 60;
  }

  digitalWrite(12,HIGH);
  analogWrite(3,motor_derecha_val);
}else{
  //adelante
  motor_derecha_val = motor_derecha_centro - motor_derecha;
  if(motor_derecha_val>60){
    motor_derecha_val = 60;
  }
    digitalWrite(12,LOW);
  analogWrite(3,motor_derecha_val);
}


if(motor_izquierda_centro <= motor_izquierda){
 //atras
  motor_izquierda_val = motor_izquierda - motor_izquierda_centro;
    if(motor_izquierda_val>60){
    motor_izquierda_val = 60;
  }

  digitalWrite(13,HIGH);
  analogWrite(11,motor_izquierda_val);
}else{
  //adelante
  motor_izquierda_val = motor_izquierda_centro - motor_izquierda;
  if(motor_izquierda_val>60){
    motor_izquierda_val = 60;
  }
    digitalWrite(13,LOW);
  analogWrite(11,motor_izquierda_val);
}
    delay(1);
}
