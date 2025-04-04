#include <WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "YOUR_SSID";         // Replace with your Wi-Fi SSID
const char* password = "PASSWORD"; // Replace with your Wi-Fi Password

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // OTA Setup
  ArduinoOTA.setHostname("ESP32_OTA");
  ArduinoOTA.begin();
  Serial.println(WiFi.localIP());

}

void loop() {
  ArduinoOTA.handle();  // Keeps OTA running in the background
}
