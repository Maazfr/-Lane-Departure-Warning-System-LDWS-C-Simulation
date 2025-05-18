# 🚗 Lane Departure Warning System (LDWS) with Over-speed Alert | Arduino Project

A compact Advanced Driver Assistance System (ADAS)-inspired project that simulates lane departure detection and vehicle speed monitoring using LEDs, buzzers, a slide potentiometer, and a 16x4 I2C LCD.

---



---

## ⚙️ Features

- ✅ Simulated **Lane Departure Detection** using random inputs
- 🚨 Real-time **Over-speed Warning System**
- 💡 Visual alerts using **3 LEDs** (Left, Middle, Right)
- 🔊 Sound alerts using **buzzers**
- 🎛️ Speed simulation via **slide potentiometer**
- 📟 UI interface using a **16x4 I2C LCD**

---

## 🧠 Project Logic

The system randomly simulates lane detection inputs. Based on the drift:

- **Left Drift** → Left LED + Buzzer
- **Right Drift** → Right LED + Buzzer
- **Off Lane** → Both outer LEDs + Both buzzers
- **In Lane** → Center LED

If vehicle speed > 75 km/h, an **Over-speed Warning** is displayed on the LCD and an additional LED is triggered.

---

## 🔩 Components Used

| Component           | Quantity |
|---------------------|----------|
| Arduino Uno         | 1        |
| 16x4 I2C LCD Display| 1        |
| Red LEDs            | 3        |
| Buzzer              | 2        |
| Slide Potentiometer | 1        |
| Jumper Wires        | -        |
| Breadboard          | 1        |

---

## 🖥️ How to Run

1. Clone or download the repository.
2. Open the `.ino` file in the Arduino IDE or VS Code with the **PlatformIO** extension.
3. Connect your components according to the schematic.
4. Upload the code to your Arduino Uno.
5. Adjust the potentiometer to simulate speed.
6. Or just go to the following link - https://wokwi.com/projects/431041630194126849
---

## 📂 Project Structure







---

## 🧪 Key Concepts Covered

- Object-Oriented Programming in C++
- LCD handling with `LiquidCrystal_I2C`
- Analog sensor mapping
- ADAS basics: Lane Departure, Over-speed logic
- Serial monitoring for debugging

---

## 🚀 Future Improvements

- Add Ultrasonic or IR sensors for real lane detection
- Integrate GPS/GSM module for vehicle telemetry
- Build a dashboard with OLED or TFT screen
- Implement `millis()` for non-blocking behavior

---

## 🤖 Created By

**Maaz Khan**  
4th Year B.Tech (CSE)  
MIT College, RGPV University

---

## 📜 License

Open-source for learning and demonstration purposes.


