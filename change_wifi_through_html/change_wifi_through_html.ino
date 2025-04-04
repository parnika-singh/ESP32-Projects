#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);
String networks = "";

void scanNetworks() {
    int numNetworks = WiFi.scanNetworks();
    networks = "<form action='/connect' method='POST'><select name='ssid'>";
    
    for (int i = 0; i < numNetworks; i++) {
        networks += "<option value='" + WiFi.SSID(i) + "'>" + WiFi.SSID(i) + "</option>";
    }
    networks += "</select><br>Password: <input type='password' name='password'><br><input type='submit' value='Connect'></form>";
}

void handleRoot() {
    scanNetworks();
    server.send(200, "text/html", "<html><body><h2>Select Wi-Fi</h2>" + networks + "</body></html>");
}

void handleConnect() {
    String ssid = server.arg("ssid");
    String password = server.arg("password");

    // Send a quick response before disconnecting
    server.send(200, "text/html", "<html><body><h2>ESP32 is connecting to " + ssid + 
                "...</h2><br>Please reconnect to the new network.</body></html>");

    delay(1000);  // Give the browser time to process response
    
    WiFi.disconnect();  
    WiFi.begin(ssid.c_str(), password.c_str());
    
    Serial.println("Connecting to " + ssid);
    
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected to " + ssid + " IP: " + WiFi.localIP().toString());
    } else {
        Serial.println("\nFailed to connect to " + ssid);
    }
}


void setup() {
    WiFi.mode(WIFI_STA);
    WiFi.begin("Clary", "parnika_sing"); // Change this to your initial Wi-Fi
    Serial.begin(115200);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to Clary! IP: " + WiFi.localIP().toString());

    server.on("/", handleRoot);
    server.on("/connect", handleConnect);
    server.begin();
}

void loop() {
    server.handleClient();
}
