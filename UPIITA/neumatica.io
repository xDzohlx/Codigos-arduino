//Varialbes
bool y1,y2;
bool y3,y4;
//sensores
int estado_a0 = 0;
int estado_a1 = 0;
int estado_b0 = 0;
int estado_b1 = 0;
int boton_arranque = 0;
int boton_paro = 0;
//pines sensores
const int pin_estado_a0 = 2;
const int pin_estado_a1 = 3;
const int pin_estado_b0 = 4;
const int pin_estado_b1 = 5;
const int pin_boton_arranque = 6;
const int pin_boton_paro = 7;
//pines salidas
const int salida_y1 = 8;
const int salida_y2 = 9;
const int salida_y3 = 10;
const int salida_y4 = 11;
//condiciones iniciales
//a1 = true;
//b1 = true;
int contador = 0;

void setup() {
 // configuración de entradas
pinMode(pin_estado_a0, INPUT);
pinMode(pin_estado_a1, INPUT);
pinMode(pin_estado_b0, INPUT);
pinMode(pin_estado_b1, INPUT);
//configuracion de salidas
pinMode(salida_y1, OUTPUT);
pinMode(salida_y2, OUTPUT);
pinMode(salida_y3, OUTPUT);
pinMode(salida_y4, OUTPUT);
//valores default
estado_a0 = digitalRead(pin_estado_a0);
estado_a1 = digitalRead(pin_estado_a1);
estado_b1 = digitalRead(pin_estado_b1);
//lectura de arranque
boton_arranque = digitalRead(pin_boton_arranque);
boton_paro = digitalRead(pin_boton_paro);
while((estado_a1 ==HIGH)&&(estado_b1 ==HIGH)&&(boton_arranque ==HIGH)&&!(boton_paro ==HIGH) ){
  estado_a0 = digitalRead(pin_estado_a0);
estado_a1 = digitalRead(pin_estado_a1);
estado_b1 = digitalRead(pin_estado_b1);

boton_arranque = digitalRead(pin_boton_arranque);
boton_paro = digitalRead(pin_boton_paro);
  }
}
//programa principal
void loop() {
 //lectura de pines
estado_a0 = digitalRead(pin_estado_a0);
estado_a1 = digitalRead(pin_estado_a1);
estado_b0 = digitalRead(pin_estado_b0);
estado_b1 = digitalRead(pin_estado_b1);

boton_arranque = digitalRead(pin_boton_arranque);
boton_paro = digitalRead(pin_boton_paro);
while(boton_paro ==HIGH){
boton_arranque = digitalRead(pin_boton_arranque);
boton_paro = digitalRead(pin_boton_paro);  
}
if(boton_arranque == HIGH){

  }
//estados que se siguen
if((estado_a1 == HIGH)&&(estado_b1 == HIGH)&&(estado_a0 == LOW)&&(estado_b0 == LOW)){
 if(contador == 0){
  digitalWrite(salida_y1, LOW);
  digitalWrite(salida_y2, HIGH);
  digitalWrite(salida_y3, LOW);
  digitalWrite(salida_y4, HIGH);
 contador=contador+1;
 }
}
if((estado_a1 == LOW)&&(estado_b1 == LOW)&&(estado_a0 == HIGH)&&(estado_b0 == HIGH)){
  if(contador == 1){
  digitalWrite(salida_y1, HIGH);
  digitalWrite(salida_y2, LOW);
  digitalWrite(salida_y3, LOW);
  digitalWrite(salida_y4, HIGH);
  contador=contador+1;
  }
}
if((estado_a1 == HIGH)&&(estado_b1 == LOW)&&(estado_a0 == LOW)&&(estado_b0 == HIGH)){
  if(contador == 2){
  digitalWrite(salida_y1, LOW);
  digitalWrite(salida_y2, HIGH);
  digitalWrite(salida_y3, LOW);
  digitalWrite(salida_y4, HIGH);
  contador=contador+1;}
}
if((estado_a1 == LOW)&&(estado_b1 == LOW)&&(estado_a0 == HIGH)&&(estado_b0 == HIGH)){
  if(contador == 3){
  digitalWrite(salida_y1, HIGH);
  digitalWrite(salida_y2, LOW);
  digitalWrite(salida_y3, HIGH);
  digitalWrite(salida_y4, LOW);
  contador=contador+1;}
}
if((estado_a1 == LOW)&&(estado_b1 == LOW)&&(estado_a0 == HIGH)&&(estado_b0 == HIGH)){
  if(contador == 4){
  digitalWrite(salida_y1, HIGH);
  digitalWrite(salida_y2, LOW);
  digitalWrite(salida_y3, HIGH);
  digitalWrite(salida_y4, LOW);
  contador=contador+1;}
}//end loop, while paro
}
