float parachute_deploy(){
if(time_actual > 7){
  chute_deploy();
}
if(alt_present * 3.28 <15){
chute_deploy();
} 
if(abs(anglex) > 60) {
  chute_deploy();
}
if(abs(angley) > 60) {
  chute_deploy();
}
}

float chute_deploy() {
 // digitalWrite(mos, HIGH);
}
