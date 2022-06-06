#include <NewPing.h>
#define TRIGGER_PIN  8  // trigger pin
#define ECHO_PIN     9  // echo pin
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define Sensor_HIGH 500 // High level for optical sensor
int INITIAL_SPEED = 255;
int temp_speed = 120; // hieu chinh lai max speed trong ham motor mapping
int sonar_check = 0;

double kP = 100;
double kI = 0;
double kD = 180;

const int MotorInput[2] = {
  10,
  6
};
const int MotorOutput[2] = {
  11,
  7
};
const int Sensors[5] = {
  A0,
  A1,
  A2,
  A3,
  A4
};

int Motor[2] = {
  0
};
bool Line[5] = {
  false
};

void( * SystemReset)(void) = 0;
long long int sys_start = 0;

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(MotorInput[i], OUTPUT);
    pinMode(MotorOutput[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(Sensors[i], INPUT);
  }
  StopAllMotor();
  Serial.begin(9600);
  check_barrier_start();
  sys_start = millis();
}

void loop() {
  FollowLine();
}

void FollowLine() { // Main action for the robot to follow the line
  GetSensorStatus();
  LinePIDFilter();
  ShiftSpeed(Motor);
}
