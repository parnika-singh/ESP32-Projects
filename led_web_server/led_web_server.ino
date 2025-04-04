#include <WiFi.h>

//wifi network password and name:
const char* ssid = "YOUR_SSID";
const char* psswd = "PASSWORD";

//setting web server port no to 80
WiFiServer Server(80);

//variable to store the http request
String header;

//these variable store current output of LED
String op_r1 = "off";
String op_y1 = "off";
String op_g1 = "off";

//output variable to store GPIO pins
const int led_y1 = 2, led_r1=15, led_g1=4 ;

//current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup(){
  Serial.begin(115200);
  //initialise the output variables as outputs
  pinMode(led_r1, OUTPUT);
  pinMode(led_y1, OUTPUT);
  pinMode(led_g1, OUTPUT); 

  //set ouput to high so that led is off
  digitalWrite(led_r1, HIGH);
  digitalWrite(led_y1, HIGH);   
  digitalWrite(led_g1, HIGH);

  //Connect to wifi network with ssid and psswd
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, psswd);
  while (WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  //print local ip address and start web server
  Serial.println("");
  Serial.println("WiFi Connected.");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  Server.begin();
}

void loop(){
  WiFiClient client = Server.available(); // Listen for incoming clients

  if (client) { // If a new client connects,
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = ""; // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis(); 
      if (client.available()) { // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c); // print it out the serial monitor
        header += c;
        if (c == '\n') { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
          // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
          // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


            //turns the GPIOs on and iff
            if (header.indexOf("GET /15/on") >= 0){
              Serial.println("RED LED 1 is on");
              op_r1 = "on";
              digitalWrite(led_r1, LOW);
            }
            else if(header.indexOf("GET /15/off") >= 0){
              Serial.println("RED LED 1 is off");
              op_r1="off";
              digitalWrite(led_r1, HIGH);
            }

            else if (header.indexOf("GET /2/on") >= 0){
              Serial.println("YELLOW LED 1 is on");
              op_y1 = "on";
              digitalWrite(led_y1, LOW);
            }
            else if(header.indexOf("GET /2/off")>=0){
              Serial.println("YELLOW LED 1 is off");
              op_y1="off";
              digitalWrite(led_y1, HIGH);
            }

            else if (header.indexOf("GET /4/on") >= 0){
              Serial.println("GREEN LED 1 is on");
              op_g1 = "on";
              digitalWrite(led_g1, LOW);
            }
            else if(header.indexOf("GET /4/off")>=0){
              Serial.println("GREEN LED 1 is off");
              op_g1 = "off";
              digitalWrite(led_g1, HIGH);
            }

            //Display html web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            //css file
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".buttonRed { background-color: #ff0000; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonGreen { background-color: #00ff00; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonYellow { background-color: #feeb36; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 16px 40px; border-radius: 70%;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
  
            client.println("<body><h1>My LED Control Server</h1>");
            //state of led
            client.println("<p>Red LED 1 is " + op_r1 + "</p>");
            // If the outputRedState is off, it displays the OFF button 
            if (op_r1=="off") {
              client.println("<p><a href=\"/15/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/15/off\"><button class=\"button buttonRed\">ON</button></a></p>");
            } 

            client.println("<p>YEELOW LED 1 is " + op_y1 + "</p>");
            // If the outputRedState is off, it displays the OFF button 
            if (op_y1=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button buttonRed\">ON</button></a></p>");
            } 

            client.println("<p>GREEN LED 1 is " + op_g1 + "</p>");
            // If the outputRedState is off, it displays the OFF button 
            if (op_g1=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button buttonOff\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button buttonRed\">ON</button></a></p>");
            } 

            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
        // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') { // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
  // Clear the header variable
    header = "";
  // Close the connection
  client.stop();
  Serial.println("Client disconnected.");
  Serial.println("");


  }
}
