#include <WiFi.h>
#include <ArduinoOTA.h>
#include <time.h>

// WiFi Credentials
const char* ssid = "YOUR_SSID";
const char* password = "PASSWORD";

// NTP Server Settings
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800; // GMT+5:30 for IST
const int   daylightOffset_sec = 0; // No DST

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  // Initialize OTA
  ArduinoOTA.begin();

  // Configure NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  // Handle OTA updates
  ArduinoOTA.handle();

  // Get and print current time
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%Y-%m-%d %H:%M:%S");

  delay(1000); // Print time every second
}
