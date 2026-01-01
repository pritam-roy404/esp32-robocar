
# 🤖 ESP32 RoboCar
ESP32 based Bluetooth controlled robocar using two L298N motor driver.  
This project is made for learning **ESP32, motor control, and Bluetooth communication**.

---

## 🚀 Features
- Bluetooth controlled via mobile app
- ESP32 microcontroller
- Dual L298N motor driver
- Speed control using PWM
- Easy to modify & beginner friendly

---

## 🧰 Components Used
- ESP32 Dev Module
- 2 × L298N Motor Driver
- DC Motors (4)
- Robot Chassis
- Battery (7.4V / 12V)
- Jumper Wires
- Smartphone (Bluetooth controller app)

---


## 🔌 Connection Diagram

### L298N – 1 (Left Motors)
| ESP32 Pin | L298N |
|----------|-------|
| GPIO 25  | IN1   |
| GPIO 26  | IN2   |
| GPIO 27  | IN3   |
| GPIO 14  | IN4   |
| GPIO 33  | ENA   |
| GPIO 12  | ENB   |

### L298N – 2 (Right Motors)
| ESP32 Pin | L298N |
|----------|-------|
| GPIO 18  | IN1   |
| GPIO 5   | IN2   |
| GPIO 17  | IN3   |
| GPIO 16  | IN4   |
| GPIO 19  | ENA   |
| GPIO 4   | ENB   |

## Controller
Use Bluetooth RC controler
available from playstore 

📷 _Connection diagram image will be added_
---

## 👨‍🎓 Author
**Pritam Roy**  
EE Student | IoT & Embedded Systems  
Learning • Building • Overthinking ⚡

---

## 📜 License
This project is licensed under the **MIT License**  
Feel free to use, modify & share 😊
