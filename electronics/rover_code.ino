//WARNING: THIS CODE IS COMPLETELY UNTESTED - DO NOT USE WITHOUT VERIFYING MANUALLY.
//current iteration variable/settings may cause jerky rover movements. use carefully

//#include <RadioLib.h>  
  
  // 6 Wheel Robot with 3 Motor Drivers
// Each driver: PWM1, DIR1, PWM2, DIR2

// ---------------- Pin Definitions ----------------
#define DRIVER1_PWM1 2
#define DRIVER1_DIR1 22
#define DRIVER1_PWM2 4
#define DRIVER1_DIR2 26

#define DRIVER2_PWM1 5
#define DRIVER2_DIR1 30
#define DRIVER2_PWM2 8
#define DRIVER2_DIR2 34

#define DRIVER3_PWM1 10
#define DRIVER3_DIR1 38
#define DRIVER3_PWM2 12
#define DRIVER3_DIR2 42
// -------------------------------------------------

int speed = 0;

bool isForward =false;
bool isBackward =false;
bool isRotLeft =false;
bool isRotRight =false;
char receivedData;

//---------------------------For the current readings
const int sensorPin = A0;
//SX1276 radio = new Module(10, 2, 6, 3);
const float sensitivity = 0.100; // Use 0.185 for 5A, 0.100 for 20A, or 0.066 for 30A
const float vOffset = 0;      // Center voltage at 0 Amps


// ---------------- Movement Functions ----------------

// Forward: all motors forward at PWM = 200
void moveForward() {
 // publishCurrentReadings();
  digitalWrite(DRIVER1_DIR1, HIGH);
  digitalWrite(DRIVER1_DIR2, HIGH);
  digitalWrite(DRIVER2_DIR1, HIGH);
  digitalWrite(DRIVER2_DIR2, HIGH);
  digitalWrite(DRIVER3_DIR1, HIGH);
  digitalWrite(DRIVER3_DIR2, HIGH);

  int i = 0;
  while(i <= 70){
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, i);
    analogWrite(DRIVER2_PWM2, i);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i += 10;
    delay(100);
  }  
}

void moveBackward() {

  digitalWrite(DRIVER1_DIR1, LOW);
  digitalWrite(DRIVER1_DIR2, LOW);
  digitalWrite(DRIVER2_DIR1, LOW);
  digitalWrite(DRIVER2_DIR2, LOW);
  digitalWrite(DRIVER3_DIR1, LOW);
  digitalWrite(DRIVER3_DIR2, LOW);
  
  int i = 0;
  while(i <= 130){
   // publishCurrentReadings();
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, i);
    analogWrite(DRIVER2_PWM2, i);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i += 10;
    delay(100);
  }

}
void rotateRightInPlace() {

  digitalWrite(DRIVER1_DIR1, LOW);
  digitalWrite(DRIVER1_DIR2, HIGH);
  digitalWrite(DRIVER2_DIR1, LOW);
  digitalWrite(DRIVER2_DIR2, HIGH);
  digitalWrite(DRIVER3_DIR1, LOW);
  digitalWrite(DRIVER3_DIR2, HIGH);
  
  int i = 0;
  int j = 0;
  while(i <= 60 && j <= 70){
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, j);
    analogWrite(DRIVER2_PWM2, j);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i += 6;
    j += 7;
    delay(100);
  }

}

void rotateLeftInPlace() {

  digitalWrite(DRIVER1_DIR1, HIGH);
  digitalWrite(DRIVER1_DIR2, LOW);
  digitalWrite(DRIVER2_DIR1, HIGH);
  digitalWrite(DRIVER2_DIR2, LOW);
  digitalWrite(DRIVER3_DIR1, HIGH);
  digitalWrite(DRIVER3_DIR2, LOW);
  
  int i = 0;
  int j = 0;
  while(i <= 60 && j <= 70){
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, j);
    analogWrite(DRIVER2_PWM2, j);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i += 6;
    j += 7;
    delay(100);
  }

}
// Stop all motors
void stopAll() 
{
  isForward=false;
  isBackward=false;
  int i = 130;
  
  
  while(i>=0){
    //publishCurrentReadings();
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, i);
    analogWrite(DRIVER2_PWM2, i);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i-=10;
    delay(100);
  }

}

void stopAllTurn() 
{
  isRotLeft =false;
  isRotRight =false;
  int i = 60;
  int j = 70;
  
  
  while(i>=0 && j>=0){
  //  publishCurrentReadin gs();
    analogWrite(DRIVER1_PWM1, i);
    analogWrite(DRIVER1_PWM2, i);
    analogWrite(DRIVER2_PWM1, j);
    analogWrite(DRIVER2_PWM2, j);
    analogWrite(DRIVER3_PWM1, i);
    analogWrite(DRIVER3_PWM2, i);
    i-=7;
    j-=6;
    delay(100);
  }
 
}


// ---------------------------------------------------

void setup() {
  Serial.begin(9600);
//  Serial1.begin(9600);
  // Setup all pins as OUTPUT
  pinMode(DRIVER1_PWM1, OUTPUT);
  pinMode(DRIVER1_DIR1, OUTPUT);
  pinMode(DRIVER1_PWM2, OUTPUT);
  pinMode(DRIVER1_DIR2, OUTPUT);

  pinMode(DRIVER2_PWM1, OUTPUT);
  pinMode(DRIVER2_DIR1, OUTPUT);
  pinMode(DRIVER2_PWM2, OUTPUT);
  pinMode(DRIVER2_DIR2, OUTPUT);

  pinMode(DRIVER3_PWM1, OUTPUT);
  pinMode(DRIVER3_DIR1, OUTPUT);
  pinMode(DRIVER3_PWM2, OUTPUT);
  pinMode(DRIVER3_DIR2, OUTPUT);


  moveForward();
  delay(3250);
  stopAll();
  delay(500);

  rotateRightInPlace();
  delay(3250);
  stopAllTurn();
  delay(300);

  moveForward();
  delay(3250);
  stopAll();
  delay(500);

  rotateRightInPlace();
  delay(3250);
  stopAllTurn();
  delay(300);

  moveForward();
  delay(3250);
  stopAll();
  delay(500);

  rotateRightInPlace();
  delay(3250);
  stopAllTurn();
  delay(300);

  moveForward();
  delay(3250);
  stopAll();

    
}


void loop() {
  // End program (stay stopped)
  while (true);
}