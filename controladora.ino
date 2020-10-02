#define BRAKE 0
#define CW    1
#define CCW   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").

//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1

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



short usSpeed = 150;  //default motor speed
unsigned short usMotor_Status = BRAKE;
 
void setup()                         
{
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);  

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);
//receptor dos canales 
    pinMode(10, INPUT);
    pinMode(11, INPUT);    
delay(50);
canal_1 = pulseIn(10,HIGH);
canal_2 = pulseIn(11,HIGH);
canal1_centro = map(canal_1,1000,2000,745,1255);
canal2_centro = map(canal_2,1000,2000,745,1255);
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH); 
//  Serial.begin(9600);              // Initiates the serial to do the monitoring 
//  Serial.println("Begin motor control");
//  Serial.println(); //Print function list for user selection
//  Serial.println("Enter number for control option:");
//  Serial.println("1. STOP");
//  Serial.println("2. FORWARD");
//  Serial.println("3. REVERSE");
//  Serial.println("4. READ CURRENT");
//  Serial.println("+. INCREASE SPEED");
//  Serial.println("-. DECREASE SPEED");
//  Serial.println();

}

void loop() 
{
  canal_1 = pulseInLong(10,HIGH);
  canal_2 = pulseInLong(11,HIGH);

accel = map(canal_1,1000,2000,745,1255);
giro = map(canal_2,1000,2000,745,1255);

motor_derecha = accel  + giro - canal1_centro;
motor_izquierda = accel +canal1_centro - giro;
  
//analogWrite(6,motor_derecha);
analogWrite(5,motor_izquierda);  
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

  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(6,motor_derecha_val);
}else{
  //adelante
  motor_derecha_val = motor_derecha_centro - motor_derecha;
  if(motor_derecha_val>limites){
    motor_derecha_val = limites;
  }
    digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(6,motor_derecha_val);
}


if(motor_izquierda_centro <= motor_izquierda){
 //atras
  motor_izquierda_val = motor_izquierda - motor_izquierda_centro;
    if(motor_izquierda_val>limites){
    motor_izquierda_val = limites;
  }

  digitalWrite(9,HIGH);
  digitalWrite(4,LOW); 
  analogWrite(5,motor_izquierda_val);
}else{
  //adelante
  motor_izquierda_val = motor_izquierda_centro - motor_izquierda;
  if(motor_izquierda_val>limites){
    motor_izquierda_val = limites;
  }
  digitalWrite(4,HIGH);
  digitalWrite(9,LOW);
  analogWrite(5,motor_izquierda_val);
}
    delay(1);  
}

void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);

}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void IncreaseSpeed()
{
  usSpeed = usSpeed + 10;
  if(usSpeed > 255)
  {
    usSpeed = 255;  
  }
  
  Serial.print("Speed +: ");
  Serial.println(usSpeed);

  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
}

void DecreaseSpeed()
{
  usSpeed = usSpeed - 10;
  if(usSpeed < 0)
  {
    usSpeed = 0;  
  }
  
  Serial.print("Speed -: ");
  Serial.println(usSpeed);

  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_2, pwm);
  }
}


