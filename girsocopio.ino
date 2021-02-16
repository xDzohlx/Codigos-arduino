 /* Keep track of gyro angle over time
 * Connect Gyro to Analog Pin 0
 *
 * Sketch by eric barch / ericbarch.com
 * v. 0.1 - simple serial output
 *
 */

 //my gyro x4 = 33.3 mV
 //x1 8.3 mV

int gyroPin = 0;               //Gyro is connected to analog pin 0
float gyroVoltage = 3.33;         //Gyro is running at 5V
float gyroZeroVoltage = 174 ; // 1.25;   //Gyro is zeroed at 2.5V
float gyroSensitivity = 5.0; //3.33;  //Our example gyro is 7mV/deg/sec
float rotationThreshold = 16; //22;   //Minimum deg/sec to keep track of - helps with gyro drifting
float negrotationThreshold = 11; //22;   //Minimum deg/sec to keep track of - helps with gyro drifting
//se necesita calibrar en rotationThreshold
float currentAngle = 0;          //Keep track of our current angle

void setup() {
  Serial.begin (9600);
}

void loop() {
  //This line converts the 0-1023 signal to 0-5V
  //float gyroRate = (analogRead(gyroPin) * gyroVoltage) / 1023;
  float gyroRate = analogRead(gyroPin) ;
  //Serial.println(gyroRate);

  //This line finds the voltage offset from sitting still
  gyroRate -= gyroZeroVoltage;

  //This line divides the voltage we found by the gyro's sensitivity
  gyroRate /= gyroSensitivity;
//  Ignore the gyro if our angular velocity does not meet our threshold
  if (gyroRate >= rotationThreshold ) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    gyroRate /= 100;
    currentAngle += gyroRate;
  }else
   if (gyroRate <= -negrotationThreshold) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    //Serial.println(gyroRate);
    gyroRate /= 100;
    currentAngle += gyroRate;
    }
  //Keep our angle between 0-359 degrees
  if (currentAngle < 0)
    currentAngle += 360;
  else if (currentAngle > 359)
    currentAngle -= 360;

  //DEBUG
  Serial.println(currentAngle);
  //Serial.println(gyroRate);

  delay(10);
}