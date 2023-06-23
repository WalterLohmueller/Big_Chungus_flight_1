float pad_print() {

  dataFile = SD.open("dat.txt", FILE_WRITE);  //open the sd card file

  /////////////////PRINT DATA////////////////////////////////////
  Serial.print(" altitude ");
  Serial.print(" systemstate is ");
  Serial.print(" error boi ");
  Serial.print(" altitude_speed ");
  Serial.print(" altitude_error ");
  Serial.print(" velocity_error ");
  Serial.print(" drag_deflection ");
  Serial.print(" velocity_x ");
  Serial.print(" accel altitude ");
  Serial.print(" Time since startup ");
  Serial.print(Time / 1000);
  Serial.print(" Time since launch ");
  Serial.print("f");
  Serial.print("a");
  Serial.print(" Acceleration X ");
  Serial.print(" Y ");
  Serial.println(" Z ");

  dataFile.print("altitude");
  dataFile.print(" systemstate is ");
  dataFile.print(" error boi ");
  dataFile.print(" altitude speed ");
  dataFile.print(" altitude_error ");
  dataFile.print(" velocity_error ");
  dataFile.print(" drag_deflection ");
  dataFile.print(" velocity_x ");
  dataFile.print(" accel altitude ");
  dataFile.print(" Time since startup ");
  dataFile.print(Time / 1000);
  dataFile.print(" Time since launch ");
  dataFile.print(time_actual);

  dataFile.print(" Acceleration X ");
  dataFile.print(" Y ");
  dataFile.println(" Z ");
  dataFile.close();
}

float DATALOG() {
 
  Serial.print(pitchX * 57.2958);
  Serial.print("    ");
  Serial.print(yawY * 57.2958);
  Serial.print("    ");
  Serial.print(anglex);
  Serial.print("    ");
  Serial.print(angley);
  Serial.print("    ");
  Serial.print(anglez);
  Serial.print("    ");
  Serial.print(gyrox - gyrox_offset);
  Serial.print("    ");
  Serial.print(gyroz - gyroz_offset);
  Serial.print("    ");
  Serial.print(gyroy - gyroy_offset);
  Serial.print("    ");

  Serial.print(Pitch_servo);
  Serial.print("    ");
  Serial.print(Roll_servo);
  Serial.print("    ");

  Serial.print("    ");
  Serial.print(starting_pitch);
  Serial.print("    ");

  Serial.print(starting_roll);
  Serial.print("    ");

  Serial.print(SD_close_counter);
  Serial.print("    ");

  Serial.print(Time_step);
  Serial.print("    ");

  Serial.print(alt_present * 3.28);
  Serial.print("    ");
  Serial.print(systemstate);
  Serial.print("   ");
  Serial.print(errorboi);
  Serial.print("    ");

  Serial.print(velocity_offset * 2.22);
  Serial.print("   ");
  Serial.print(altitude_offset * 3.28);
  Serial.print("   ");

  Serial.print(velocity_new * 2.23 - velocity_offset * 2.22);

  Serial.print("   ");
  Serial.print(accel_altitude * 3.28 - altitude_offset * 3.28);

  Serial.print("    ");
  Serial.print(Time / 1000);
  Serial.print("    ");
  Serial.print(time_actual);
  Serial.print("    ");
  Serial.print(a);

  Serial.print("    ");

  Serial.print(accelx);

  Serial.print("    ");
  Serial.print(accely);
  Serial.print("  ");
  Serial.println(accelz);

 // Serial.print("  ");
  //Serial.println(parachute_deploy_counter);

  if (systemstate == -1 && Time / 1000 / SD_pad_close > 0.07) {
    SD_pad_close++;

    dataFile = SD.open("dat.txt", FILE_WRITE);  //open the sd card file
    dataFile.print("    ");

    dataFile.print(SD_close_counter);
    dataFile.print("    ");

    dataFile.print(Time_step);
    dataFile.print("    ");

    dataFile.print(systemstate);
    dataFile.print("   ");
    dataFile.print(errorboi);
    dataFile.print("    ");


    dataFile.print(velocity_offset * 2.22);

    dataFile.print("   ");
    dataFile.print(altitude_offset * 3.28);
    dataFile.print("    ");


    dataFile.print(velocity_new * 2.23 - velocity_offset * 2.22);

    dataFile.print("   ");
    dataFile.print(accel_altitude * 3.28 - altitude_offset * 3.28);

    dataFile.print("    ");
    dataFile.print(Time / 1000);
    dataFile.print("    ");
    dataFile.print(time_actual);
    dataFile.print("    ");
    dataFile.print(a);

    dataFile.print("    ");

    dataFile.print(accelx);

    dataFile.print("    ");
    dataFile.print(accely);
    dataFile.print("  ");
    dataFile.print(accelz);

    dataFile.print("  ");
    dataFile.println(parachute_deploy_counter);
    dataFile.close();
  }


  if (time_actual / SD_close_counter > 0.055) {
    SD_close_counter++;

    dataFile = SD.open("dat.txt", FILE_WRITE);  //open the sd card file
    dataFile.print(anglex);
   dataFile.print("    ");
   dataFile.print(angley);
   dataFile.print("    ");
   dataFile.print(anglez);
   dataFile.print("    ");
   dataFile.print(gyrox - gyrox_offset);
   dataFile.print("    ");
   dataFile.print(gyroz - gyroz_offset);
   dataFile.print("    ");
   dataFile.print(gyroy - gyroy_offset);
   dataFile.print("    ");

  dataFile.print(Pitch_servo);
  dataFile.print("    ");
   dataFile.print(Roll_servo);
   dataFile.print("    ");

   dataFile.print("    ");
   dataFile.print(starting_pitch);
   dataFile.print("    ");

   dataFile.print(starting_roll);
   dataFile.print("    ");
    dataFile.close();
  }
}