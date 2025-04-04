#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "SSID";     // Replace with your WiFi SSID
const char* password = "PASSWORD"; // Replace with your WiFi Password

void setup() {
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");

    // Start OTA
    ArduinoOTA.begin();

    // Set pin modes for LEDs
    pinMode(15, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);

    // Turn ON LEDs
    digitalWrite(15, HIGH);
    delay(500);
    digitalWrite(15,LOW);
    delay(500);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(15, LOW);
    delay(500);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4,LOW);
}

void loop() {
    ArduinoOTA.handle(); // Keep OTA running
}
