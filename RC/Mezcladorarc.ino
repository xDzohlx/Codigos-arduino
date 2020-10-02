
//Created by xDzohlx
// pines pwm 
// d3 canal 1
// d5 canal 2

// direccion 
// d6 canal 1
// d9 canal 2

//pines rc
// d10
// d11

unsigned long currentMillis = 0; 
 int motor_izquierda = 1000;
 int motor_derecha = 1000;
 int motor_izquierda_centro = 1000;
 int motor_derecha_centro = 1000;
 int motor_izquierda_accel = 0x00;
 int motor_derecha_accel = 0x00; 
 int motor_derecha_val = 0;
 int motor_izquierda_val = 0;
 int canal1_centro = 0;
 int canal2_centro = 0;
 int canal_1 = 0;
 int canal_2 = 0;
 int accel = 0;
 int giro = 0;
 int otrogiro = 0;
bool sensor_centro =  false;
bool sensor_derecha =  false;
bool sensor_izquierda =  false;
bool primero = true;
bool otra  = true;
bool segundo = true;
int limites = 200;//velocidad maxima
int vel_busqueda = 30;//velocidad bajapara buscar


//int giro = 25;//velocidad de las vueltas y control
void setup() {
//MOTORES
Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
//receptor dos canales 
    pinMode(7, INPUT);
    pinMode(4, INPUT);    
delay(50);
canal_1 = pulseIn(7,HIGH);
canal_2 = pulseIn(4,HIGH);
canal1_centro = map(canal_1,21000,21900,745,1255);
canal2_centro = map(canal_2,21000,21190,745,1255);
}

void loop() {
canal_1 = pulseInLong(7,LOW);
canal_2 = pulseInLong(4,LOW);

accel = map(canal_1,21000,21900,745,1255);
giro = map(canal_2,21000,21900,745,1255);
     
motor_derecha = (510 - (accel  + giro - canal1_centro) + 10540 + 1020 - 300 +100 - 1100 -6500);

motor_izquierda =    (510 - (accel +canal1_centro - giro) -10540 + 1000 - 300+100-50);
////--------------------------No tocar de aqui a abajo
 if(motor_derecha>(motor_derecha_centro + limites)){
  motor_derecha = motor_derecha_centro + limites;
 }
 if(motor_izquierda>(motor_izquierda_centro + limites)){
  motor_izquierda = motor_izquierda_centro + limites;
 }

  if(motor_derecha<(motor_derecha_centro-limites)){
  motor_derecha = motor_derecha_centro-limites;
 }
 
 if(motor_izquierda<(motor_izquierda_centro-limites)){
  motor_izquierda = motor_izquierda_centro-limites;
 }

if(motor_derecha_centro <= motor_derecha){
 //atras
  motor_derecha_val = motor_derecha - motor_derecha_centro;
  if(motor_derecha_val>limites){
    motor_derecha_val = limites;
  }

  digitalWrite(6,HIGH);
  analogWrite(3,motor_derecha_val);
}else{
  //adelante
  motor_derecha_val = motor_derecha_centro - motor_derecha;
  if(motor_derecha_val>limites){
    motor_derecha_val = limites;
  }
    digitalWrite(6,LOW);
  analogWrite(3,motor_derecha_val);
}


if(motor_izquierda_centro <= motor_izquierda){
 //atras
  motor_izquierda_val = motor_izquierda - motor_izquierda_centro;
    if(motor_izquierda_val>limites){
    motor_izquierda_val = limites;
  }

  digitalWrite(8,HIGH);
  analogWrite(5,motor_izquierda_val);
}else{
  //adelante
  motor_izquierda_val = motor_izquierda_centro - motor_izquierda;
  if(motor_izquierda_val>limites){
    motor_izquierda_val = limites;
  }
    digitalWrite(8,LOW);
  analogWrite(5,(motor_izquierda_val));
}
Serial.println(motor_izquierda_val);
    delay(1);
}
