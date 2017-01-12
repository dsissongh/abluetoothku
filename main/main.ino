/*
  Initial pass for blue tooth module 
  Arduino UNO R3
  Kedsum Bluetooth module
*/

int state = 0;
int flag = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
if(Serial.available() > 0){
   state = Serial.read();
   flag=0;
 }

 if (state == '0') {
   digitalWrite(LED_BUILTIN, LOW);
   if(flag == 0){
     Serial.println("LED: off");
     flag = 1;
   }
 }

 else if (state == '1') {
 digitalWrite(LED_BUILTIN, HIGH);
 if(flag == 0){
 Serial.println("LED: on");
 flag = 1;
 }
 }
}
