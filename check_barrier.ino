void check_barrier_start() {
  sonar_check = sonar.ping_cm();
  Serial.println(sonar_check);
  while (sonar_check < 50) {
    sonar_check = sonar.ping_cm();
    Serial.println(sonar_check);
    StopAllMotor();
  }
}
void check_barrier_end() {
  sonar_check = sonar.ping_cm();
  Serial.println(sonar_check);
  while (sonar_check < 18 && sonar_check > 1) {
    sonar_check = sonar.ping_cm();
    Serial.println(sonar_check);
    StopAllMotor();
    delay(5000);
  }
}
