#include <SoftwareSerial.h>

SoftwareSerial mySerial(12,11); // Like usual set upp the tx and rx pins

void setup() {
  // Baud rate of the bluetooth module has to be set to 9600 to communicate with the app
  mySerial.begin(9600);

  // Can be set to whatever baud rate you want
  Serial.begin(9600); 
}

void loop() {
  if(mySerial.available()>0){
    // Upon receiving data read string upto new line
    String inputString = mySerial.readStringUntil('\n'); // Read input upto new line
    // Print string
    Serial.println(inputString);
  }
}
