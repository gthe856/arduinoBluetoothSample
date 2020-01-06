# arduinoBluetoothSample
Sample project of how to use the app with bluetooth module connected to arduino

Video tutorial in the link description below
https://www.youtube.com/watch?v=-xlHUpQPdi8&feature=youtu.be
Go to this link to obtain higher resolution images
https://www.instructables.com/id/Plotting-Real-time-Graph-on-Android-From-Arduino-T/

 
instructables



Plotting Real-time Graph on Android From Arduino Through HC-05

by TheG39



Hey there,

here's a tutorial of how to plot a real-time graph of values from a micro-controller such as an Arduino to the app. It uses a Bluetooth module such as the HC-05 to act as an messaging device to transmit and receive the data between the Arduino and Android.

The app is simple to use and can be used for other purposes such as a controller to control a robot car, a serial monitor, similar to that of offered by the Arduino IDE, to receive serial messages and send serial data.

ENOUGH CHIT-CHAT LET'S GETS STARTED

Supplies:

1.	Arduino nano or mega
2.	Serialize Bluetooth app (https://play.google.com/store/apps/details? id=com.athenaDEVKE.bluetoothserialcommunication)
3. HC-05
4.	Male jumper wires
5.	10K and 20K resistors to form a voltage divider. If not use two similar resistors of moderately high value in series will still work.





Step 1: Schematic and Connection
 
Connect the devices as shown above and power on the module Upload the following test code:

#include < SoftwareSerial.h >
// Connect bluetooth module HC-05 or HC-06 to arduino and declare the pins used if you plan on using the software serial

SoftwareSerial mySerial(12, 11);

// Used to identify graphing values String graphTag = "Graph:";
// Used to identify the separation of values inside the stream char valueSeparatorCharacter = '&';
// Used to identify the end of the stream. This will apply for both the serial monitor and graph char terminationSeparatorCharacter = '$';
void setup() {

// Declare the baud rate. The app only supports 9600 mySerial.begin(9600);
}

void loop() {

// An example loop of plotting a sine wave

for (float x = -2 * PI; x <= 2 * PI; x = x + PI / 50) { mySerial.print(graphTag);
mySerial.print(240 * sin(x)); mySerial.print(valueSeparatorCharacter); mySerial.print(240 * sin(x + (2 * PI / 3))); mySerial.print(valueSeparatorCharacter); mySerial.print(240 * sin(x + (4 * PI / 3))); mySerial.print(terminationSeparatorCharacter);
 
}

}

Ensure that you download the Serialize Bluetooth-Plotter,terminal &controller (https://play.google.com/store/apps/details?id=com	).
First ensure that you have paired the hc-05 module with your phone, then start the app
Select the Configure tab. Click on the refresh to populate the combo box. Select the module from the combo box. Then click the connect button and wait for pop up message stating that the device is connected.
Click the configure graph and set a graph tag,select a graph type ,set a character used to separate the values and a terminating character.

 
   
 
   
 
 


 
Step 2: Reading Inputs From App

With the same setup as above:
Upload the code below:


#include < SoftwareSerial.h >
SoftwareSerial mySerial(12,11); // Like usual set upp the tx and rx pins void setup() {
// Baud rate of the bluetooth module has to be set to 9600 to communicate with the app mySerial.begin(9600);
// Can be set to whatever baud rate you want Serial.begin(9600);
}

void loop() { if(mySerial.available()>0){
// Upon receiving data read string upto new line

String inputString = mySerial.readStringUntil('\n'); // Read input upto new line

// Print string Serial.println(inputString);
}

}

Test the controller and monitor the output on the serial monitor and voilà you are reading data from the app

 
 


Step 3: Video Review/Recap


If you are finding difficulties, please follow the above video tutorial




Nice, thanks for sharing! : )

