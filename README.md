# 🚗 Lane Departure Warning System (LDWS) with Over-speed Alert | Arduino Project

A compact Advanced Driver Assistance System (ADAS)-inspired project that simulates lane departure detection and vehicle speed monitoring using LEDs, buzzers, a slide potentiometer, and a 16x4 I2C LCD.

---

## 📷 Project Preview

![Project Schematic](<upload or link to your image here>)

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

---

## 📂 Project Structure

