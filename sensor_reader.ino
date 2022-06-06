void GetSensorStatus() { // Get all the sensor status
  for (int i = 0; i < 5; i++) {
    Line[i] = ReadLine(i);
  }
}

bool ReadLine(int index) { // Get the sensor status for each sensor
  int temp = analogRead(Sensors[index]);
  if (temp >= Sensor_HIGH) {
    return true;
  } else {
    return false;
  }
}

int HighSignalCount() { // Count the high signal that speed up the GetError function
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (Line[i]) {
      count++;
    }
  }
  return count;
}
