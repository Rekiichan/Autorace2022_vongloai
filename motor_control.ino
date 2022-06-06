void StopAllMotor() { // Idle the robot
  analogWrite(MotorInput[0], 0);
  digitalWrite(MotorInput[1], LOW);
  analogWrite(MotorOutput[0], 0);
  digitalWrite(MotorOutput[1], LOW);
}

void back() {
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  analogWrite(11, 135);
  analogWrite(7, 135);
}

void ShiftSpeed(int * MotorSpeed) { // Shift the speed to the motors
  MotorMapping(MotorSpeed);

  for (int i = 0; i < 2; i++) {
    if (MotorSpeed[i] >= 0) {
      analogWrite(MotorInput[i], MotorSpeed[i]);
      digitalWrite(MotorOutput[i], LOW);
    } else {
      digitalWrite(MotorInput[i], LOW);
      analogWrite(MotorOutput[i], -MotorSpeed[i]);
    }
  }
  if (Line[1] || Line[2] || Line[3]) {
    check_barrier_end();
  }
}

void MotorMapping(int * MotorSpeed) {
  int TEMP_INITIAL_SPEED = 0;
  if (millis() - sys_start < 5000) {
    TEMP_INITIAL_SPEED = 160;
  }
  else {
    TEMP_INITIAL_SPEED = temp_speed;
  }
  int maxx = MotorSpeed[0];
  maxx = (maxx < MotorSpeed[1]) ? MotorSpeed[1] : maxx;
  if (maxx > TEMP_INITIAL_SPEED) {
    double ratio = (double) TEMP_INITIAL_SPEED / maxx;
    for (int i = 0; i < 2; i++) {
      MotorSpeed[i] *= ratio;
    }
  }
}
