void getQuatRotn(float dx, float dy, float dz){

  //Local Vectors
  float QuatDiff[5];
  float Rotn1[4];
  float Rotn2[4];
  float Rotn3[4];
 
  //Local rotation holders
  static long prevRollZ = 0;
  static long quatRollZ = 0;
  static long fullRollZ = 0;
 
  //Compute quaternion derivative
  QuatDiff[1] = 0.5 * (-1 * dx * Quat[2] - dy * Quat[3] - dz * Quat[4]);
  QuatDiff[2] = 0.5 * (     dx * Quat[1] - dy * Quat[4] + dz * Quat[3]);
  QuatDiff[3] = 0.5 * (     dx * Quat[4] + dy * Quat[1] - dz * Quat[2]);
  QuatDiff[4] = 0.5 * (-1 * dx * Quat[3] + dy * Quat[2] + dz * Quat[1]);
 
  //Update the quaternion
  Quat[1] += QuatDiff[1];
  Quat[2] += QuatDiff[2];
  Quat[3] += QuatDiff[3];
  Quat[4] += QuatDiff[4];
 
  //re-normalize
  float quatLen = powf( Quat[1]*Quat[1] + Quat[2]*Quat[2] + Quat[3]*Quat[3] + Quat[4]*Quat[4], -0.5);
  Quat[1] *= quatLen;
  Quat[2] *= quatLen;
  Quat[3] *= quatLen;
  Quat[4] *= quatLen;
      
  //compute the components of the rotation matrix
  float a = Quat[1];
  float b = Quat[2];
  float c = Quat[3];
  float d = Quat[4];
  float a2 = a*a;
  float b2 = b*b;
  float c2 = c*c;
  float d2 = d*d;
  float ab = a*b;
  float ac = a*c;
  float ad = a*d;
  float bc = b*c;
  float bd = b*d;
  float cd = c*d;
      
  //Compute rotation matrix
  Rotn1[1] = a2 + b2 - c2 - d2;
  //Rotn1[2] = 2 * (bc - ad);
  //Rotn1[3] = 2 * (bd + ac);
  Rotn2[1] = 2 * (bc + ad);
  //Rotn2[2] = a2 - b2 + c2 - d2;
  //Rotn2[3] = 2 * (cd - ab);
  Rotn3[1] = 2 * (bd - ac);
  Rotn3[2] = 2 * (cd + ab);
  Rotn3[3] = a2 - b2 - c2 + d2;
 
  //compute 3D orientation
  pitchX = atan2(Rotn3[2], Rotn3[3]);
  yawY = asin(-1*Rotn3[1]);
 
  prevRollZ = quatRollZ;
  quatRollZ = atan2(Rotn2[1], Rotn1[1]);
  if(quatRollZ - prevRollZ > 1800){fullRollZ--;}
  else if(quatRollZ - prevRollZ < -1800){fullRollZ++;}
  rollZ = (fullRollZ*3600 + quatRollZ)*.1;
 
  //Compute angle off vertical
  float tanYaw = tan(yawY);
  float tanPitch = tan(pitchX);
 
  float hyp1 = tanYaw*tanYaw + tanPitch*tanPitch;
  float hyp2 = powf(hyp1, 0.5);
  offVert = atan(hyp2);
 
}//end getQuatRotn
