void LinePIDFilter() { // PID control in line tracking mode
  static double prev_error = 0, prev_I = 0;
  double p = 0, i = 0, d = 0, pid_value;
  if ((millis() - sys_start) < 5000) {
    kP = 30;
    kD = 39;
  }
  else if ((millis() - sys_start) < 9000) {
    kP = 100;
    kD = 180;
  }
  else if ((millis() - sys_start) < 15000) { //code vong loai thi tang toc tu giay thu 15
    temp_speed = 200;
    kP = 130;
    kD = 210;
  }  else {
    temp_speed = 255;
    kP = 30;
    kD = 39;
  }
  p = GetError();
  i = prev_I + p;
  d = p - prev_error;

  pid_value = kP * p + kI * i + kD * d;
  prev_I = i;
  prev_error = p;
  Motor[0] = INITIAL_SPEED + pid_value; // trai
  Motor[1] = INITIAL_SPEED - pid_value; // phai
}
