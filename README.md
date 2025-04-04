# ESP32-Projects

This repository contains various ESP32 projects covering basic to advanced functionalities, including LED control, 7-segment displays, OTA updates, Wi-Fi management, and web server integration.

## 📂 Project Structure

### 1️⃣ 3_LED_Sequance
- Lights up three LEDs (Red, Green, Yellow) in sequence.
- A basic program to get started with ESP32.

### 2️⃣ 4_7_segment_display
- Controls four 7-segment displays placed side by side.
- Useful for multi-digit numerical displays.

### 3️⃣ 7-seg-display-0-9
- Controls a single 7-segment display.
- Displays digits from 0 to 9.
- A foundational project before working with multiple displays.

### 4️⃣ Arduino_OTA
- Enables Over-The-Air (OTA) programming for ESP32.
- Contains two subprojects:
  - **simple_led**: Basic OTA server setup.
  - **ESP_digital_clock**: Digital clock implementation with OTA.
- Note: The ESP32 must be connected to an external power supply for OTA updates.

### 5️⃣ change_wifi_through_html
- Connects ESP32 to an initial Wi-Fi network.
- Generates an IP address that leads to an HTML page.
- Allows switching to another Wi-Fi network from the list of available networks.

### 6️⃣ led_web_server
- Controls three LEDs (Red, Green, Yellow) via an HTML-based web interface.
- A screenshot of the web interface is included in the repository.

## 🖼️ Images Included  

- Screenshot of Web Page:  
  <img src="https://github.com/user-attachments/assets/fe82eec3-fcf6-494c-b67e-9403f87cbe52" alt="Web Server Screenshot" width="300">  

- ESP32 connected to 3 LEDs (Red, Green, Yellow):  
  <img src="https://github.com/user-attachments/assets/55f1f7b0-dca2-437e-9bd5-4a600a1149e4" alt="LED Setup" width="350">  

- ESP32 pin diagram:  
  <img src="https://github.com/user-attachments/assets/3ba875bc-1331-46e2-9983-5a1d57678d1c" alt="ESP32 Pin Diagram" width="450">  

## 📜 How to Use
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ESP32-Projects.git
   ```
2. Open the respective project in Arduino IDE or VS Code.
3. Upload the code to your ESP32 board.
4. Follow project-specific instructions for additional setup.

## 📌 Dependencies
- **ESP32 Board Package**: Install via Arduino Board Manager.
- **Wi-Fi and Web Server Libraries**: Required for relevant projects.
- **OTA Update Libraries**: For `Arduino_OTA`.
