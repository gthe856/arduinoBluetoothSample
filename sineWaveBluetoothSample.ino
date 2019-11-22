#include <SoftwareSerial.h>
// Connect bluetooth module HC-05 or HC-06 to arduino and declare the pins used if you plan on using the software serial
SoftwareSerial mySerial(12,11);
                    
// Used to identify graphing values
String graphTag = "Graph:";  

// Used to identify the separation of values inside the stream
char valueSeparatorCharacter = '&';

// Used to identify the end of the stream. This will apply for both the serial monitor and graph
char terminationSeparatorCharacter = '$';

void setup() {
  // Declare the baud rate. The app only supports 9600
  mySerial.begin(9600);
}

void loop() {
  // An example loop of plotting a sine wave 
  for(float x=-2*PI; x<=2*PI; x=x+PI/30){
    mySerial.print(graphTag);
    mySerial.print(240*sin(x));mySerial.print(valueSeparatorCharacter);
    mySerial.print(240*sin(x+(2*PI/3)));mySerial.print(valueSeparatorCharacter);
    mySerial.print(240*sin(x+(4*PI/3)));mySerial.print(terminationSeparatorCharacter);
  }
 }
 
