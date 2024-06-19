// Code for Arduino Remote Controlled Car
// Purpose: Use remote to control car. It can be used to go forward, left or right.
// Made by: Azaria Kelman
// Date: April 18th, 2021

#include <IRremote.h> //IR Library for Arduino IR Receiver


const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup(){ // Runs only once
  
  Serial.begin(9600);
  irrecv.enableIRIn();
   pinMode(13, OUTPUT); // Sets arduino pin to output, for signal to left motor
   pinMode(12, OUTPUT); // Sets arduino pin to output, for signal to right motor

`}



void loop(){ // Runs continuously
  
Serial.println(results.value, HEX); // Prints the hex value a a button press, in the serial monitor. Allows me to determine results.value for each button.

  if (irrecv.decode(&results)){ // If ANY button is clicked, this would be true
    

        if (results.value == 0xFFA25D) {  // If power button is clicked, this would be true
          digitalWrite(13, HIGH);  //Left motor on
          digitalWrite(12, HIGH);  //Right motor on

          delay(300);       }  //The car will remain going in the direction it is set, unless it is told to stop, or to switch directions


          irrecv.resume(); // Receive the next value





  if (!irrecv.decode(&results)){

       if (results.value == 0xFFE21D) { // If stop button is clicked, this would be true
          digitalWrite(13, LOW);  //Left motor on
          digitalWrite(12, LOW);  //Right motor on

          delay(300);       }   

                           }



  if (!irrecv.decode(&results)){ // If left turning button is clicked, this would be true

       if (results.value == 0xFFC23D) {
          digitalWrite(13, LOW);  //Left motor off
          digitalWrite(12, HIGH);  //Right motor on

          delay(300);       }   

                           }

  if (!irrecv.decode(&results)){

       if (results.value == 0xFF22DD) { // If right turning button is clicked, this would be true
          digitalWrite(13, HIGH);  //Left motor on
          digitalWrite(12, LOW);  //Right motor on

          delay(300);       }   

                           }



        
        }




}
