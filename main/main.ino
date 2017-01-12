/*
  Initial pass for blue tooth module
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

}

// the loop function runs over and over again forever
void loop() {

 // state machine
 idle: 
   readRadio();
   if(radioStrength<median+THRESHOLD) goto idle;

   // detect short pulse approx 5x100us
   count = 0;
   while(radioStrength>=median+THRESHOLD){
     readRadio();
     count++;
   }
   if(count<=4 || count>=6) goto reset;
   writeRGB(0,0,300);

   // detect period between pulses approx 37x100us
   count = 0;
   while(radioStrength<median+THRESHOLD){
     readRadio();
     count++;
   }
   if(count<36 || count>38) goto reset;  
   
   // detect short pulse approx 5x100us
   count = 0;
   while(radioStrength>=median+THRESHOLD){
     readRadio();
     count++;
   }
   if(count<=4 || count>=6) goto reset;

   // detect period between pulses approx 37x100us
   count = 0;
   while(radioStrength<median+THRESHOLD){
     readRadio();
     count++;
   }
   if(count<36 || count>38) goto reset;  
   
   // detect short pulse approx 5x100us
   count = 0;
   while(radioStrength>=median+THRESHOLD){
     readRadio();
     count++;
   }
   if(count<=4 || count>=6) goto reset;

   // cell phone detected !!!!!    
   // blink the RGB led
   writeRGB(300,0,0);
   delay(500);
   writeRGB(0, 300,0);
   delay(500);

}
