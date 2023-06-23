///////////SOFTWARE IN THE LOOP//////////////////////////
float SITLread_IMU() {
//accelx = SITL_accelx[a];
//accely = SITL_accely[a];
//accelz = SITL_accelz[a];
a++;
}

float SITLread_baro() {
  //altitude_previous = alt_present;
  //alt_present = altitude_fake[i];
}




//////////////////READING SENSORS///////////////////////////
float read_IMU() {
  a++;
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  lsm6ds33.getEvent(&accel, &gyro, &temp);

  accely = accel.acceleration.y;
  accelx = accel.acceleration.x * -1;
  accelz = accel.acceleration.z;

  gyrox = gyro.gyro.x * 57.2958;
  gyroy = gyro.gyro.y * 57.2958;
  gyroz = gyro.gyro.z * 57.2958;

}

float read_baro() {
  /*
  altitude_previous = alt_present;
  bmp388.getMeasurements(temperature, pressure, altitude); // get another set of measurements.
  alt_present = altitude - altitudeoffset;
  alt_speed = alt_present - altitude_previous/Time_step;
  */
}


 