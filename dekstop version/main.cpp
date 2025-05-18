// Desktop Simulation Version of Lane Departure Warning System
// Uses console output instead of hardware components

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

class LED {
  string name;
public:
  LED(string n) : name(n) {}
  void on()  { cout << name << " LED ON\n"; }
  void off() { cout << name << " LED OFF\n"; }
};

class BUZZER {
  string name;
public:
  BUZZER(string n) : name(n) {}
  void beep() {
    cout << name << " BUZZER BEEPING!\n";
    this_thread::sleep_for(chrono::milliseconds(500));
  }
};

LED ledLeft("Left");
LED ledMidd("Middle");
LED ledRite("Right");
LED ledOver("Overspeed");
BUZZER buzzLeft("Left");
BUZZER buzzRite("Right");

int readSpeed() {
  return rand() % 121;  // Simulate speed from 0 to 120
}

class LaneSensor {
public:
  bool leftDetected;
  bool rightDetected;

  LaneSensor() : leftDetected(true), rightDetected(true) {}

  void simulateInput() {
    leftDetected = rand() % 2;
    rightDetected = rand() % 2;
  }
};

class LaneDepartureSystem {
  LaneSensor& sensor;
public:
  LaneDepartureSystem(LaneSensor& s) : sensor(s) {}

  void checkLaneDeparture() {
    int speed = readSpeed();
    cout << "\nSpeed: " << speed << " km/h\n";

    if (!sensor.leftDetected && sensor.rightDetected) {
      cout << "Drifting LEFT! Correct your steering.\n";
      ledLeft.on(); ledMidd.off(); ledRite.off(); ledOver.off();
      if (speed > 75) {
        buzzLeft.beep();
        cout << "OVER SPEEDING! Reduce Speed NOW\n";
        ledOver.on();
      }
    } else if (sensor.leftDetected && !sensor.rightDetected) {
      cout << "Drifting RIGHT! Correct your steering.\n";
      ledLeft.off(); ledMidd.off(); ledRite.on(); ledOver.off();
      if (speed > 75) {
        buzzRite.beep();
        cout << "OVER SPEEDING! Reduce Speed NOW\n";
        ledOver.on();
      }
    } else if (!sensor.leftDetected && !sensor.rightDetected) {
      cout << "~~EMERGENCY: Completely off-lane!~~\n";
      ledLeft.on(); ledMidd.off(); ledRite.on(); ledOver.off();
      if (speed > 75) {
        buzzLeft.beep(); buzzRite.beep();
        cout << "OVER SPEEDING! Reduce Speed NOW\n";
        ledOver.on();
      }
    } else {
      cout << "In Lane.\n";
      ledLeft.off(); ledMidd.on(); ledRite.off(); ledOver.off();
      if (speed > 75) {
        cout << "OVER SPEEDING! Reduce Speed NOW\n";
        ledOver.on();
      }
    }
  }
};

int main() {
  srand(time(0));
  LaneSensor laneSensor;
  LaneDepartureSystem laneSystem(laneSensor);

  cout << "LDWS Desktop Simulation Starting...\n";
  this_thread::sleep_for(chrono::seconds(1));

  while (true) {
    laneSensor.simulateInput();
    laneSystem.checkLaneDeparture();
    this_thread::sleep_for(chrono::seconds(2));
  }
  return 0;
}
