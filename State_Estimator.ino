float get_offsets() {
  if (Time / 1000 / offset_counter > 1) {
    offset_counter++;
    velocity_offset = velocity_new;
    altitude_offset = accel_altitude;
  }
  ///////GYROSCOPE OFFSETS////////////
  if (Time / 1000 < 25) {
    gyrox_offset = gyrox;
    gyroy_offset = gyroy;
    gyroz_offset = gyroz;

    delay(50);
    gyrox_offset1 = gyrox;
    gyroy_offset1 = gyroy;
    gyroz_offset1 = gyroz;
    delay(50);
    gyrox_offset2 = gyrox;
    gyroy_offset2 = gyroy;
    gyroz_offset2 = gyroz;

    gyrox_offset = (gyrox_offset + gyrox_offset1 + gyrox_offset2) / 3;
    gyroy_offset = (gyroy_offset + gyroy_offset1 + gyroy_offset2) / 3;
    gyroz_offset = (gyroz_offset + gyroz_offset1 + gyroz_offset2) / 3;



    //DETERMINE STARTING ANGLE OF THE ROCKET
    starting_pitch = -atan2(accely / 9.8, accelx / 9.8) / 2 / 3.141592654 * 360;
    starting_roll = atan2(accelz / 9.8, accelx / 9.8) / 2 / 3.141592654 * 360;
  }
}

float Estimate_state() {

  // read sensors
  time_old = time_new;
  time_new = micros();
  Time_step = (time_new - time_old) / 1000000;  // time_step in seconds

  if (Time_step > 0.05) {
    Time_step = 0.03;
  }
  f++;
  // velocity_new = (accelx) * Time_step + velocity_new;
  //  accel_altitude = accel_altitude + velocity_new * Time_step;
  if (accelx_old == 0) {
    velocity_new = accelx * Time_step + velocity_old;
    accelx_old = accelx;
  } else {




    //////////////////VELOCITY AND ALTITUDE OFFSET APPLICATION//////////////////////
    //this bit of code was supposed to be in the state estimator tab but because code has a
    //way of making itself more complicated that it needs to be it will only work if it is in the main loop :(

    velocity_new = velocity_new - velocity_offset;
    //get velocity estimate
    velocity_new = (accelx + accelx_old) / 2 * Time_step + velocity_old;
  }
  //apply offset correction to estimate and integrate it
  if (velocity_new > 0) {
    accel_altitude = ((velocity_new - velocity_offset) + (velocity_old - velocity_offset)) / 2 * Time_step + accel_altitude_new;
  }

  if (velocity_new < 0) {
    accel_altitude = ((velocity_new + abs(velocity_offset)) + (velocity_old + abs(velocity_offset))) / 2 * Time_step + accel_altitude_new;
    //accel_altitude = accel_altitude + abs(altitude_offset);
  }

  /*
  velocity_new = (accelx + accelx_old) / 2 * Time_step + velocity_old;

   accel_altitude = (velocity_new + velocity_old)/ 2 * Time_step + accel_altitude_new;
*/
  accelx_old = accelx;
  velocity_old = velocity_new;
  accel_altitude_new = accel_altitude;

  //////////////////////////////COMPLEMENTRY FILTER IMPLEMENTATION///////////////////////////////
}
float caculate_angles() {
  //GYROSCOPE INTEGRATION

  anglex = ((gyrox - gyrox_offset) * Time_step) + anglex_old;
  angley = ((gyroy - gyroy_offset) * Time_step) + angley_old;
  anglez = ((gyroz - gyroz_offset) * Time_step) + anglez_old;

  anglex_old = anglex;
  angley_old = angley;
  anglez_old = anglez;

    //  GET QUATERNIONS STARTED 

  //caluclate the partial rotation
dx += (gyrox - gyrox_offset) / 57.2958 * Time_step;
dy += (gyroy - gyroy_offset) / 57.2958 * Time_step;
dz += (gyroz - gyroz_offset)/ 57.2958 * Time_step;

    //update the quaternion rotation
      
    const float rotn2rad = gyro_gain * (3.14159265359 / 180) / 1000000;
    ddx = dx * rotn2rad;
    ddy = dy * rotn2rad;
    ddz = dz * rotn2rad;
      
    getQuatRotn(ddx, ddy, ddz);
    dx = dy = dz = 0L;
      
}

