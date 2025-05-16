class LED
{
int pin;
public:
LED(int p) : pin(p)
{
  pinMode(p, OUTPUT);
}
void on(){
  digitalWrite(pin, HIGH);
}
void off(){ 
  digitalWrite(pin, LOW);
}
};

class BUZZER
{
  int pin;
  public:
  BUZZER(int p) : pin(p)
  {
    pinMode(p, OUTPUT);
  }
  void beep()
  {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
  }
};

LED ledLeft(13);
LED ledMidd(12);
LED ledRite(11);
BUZZER buzzLeft(10);
BUZZER buzzRite(9);

class LaneSensor {
  public:
    bool leftDetected;
    bool rightDetected;

    LaneSensor() : leftDetected(true), rightDetected(true) {}

    void update(bool left, bool right) {
      leftDetected = left;
      rightDetected = right;
    }

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
    if (!sensor.leftDetected && sensor.rightDetected) {
      Serial.println(" Drifting LEFT! Correct your steering.");
      ledLeft.on();
      ledMidd.off();
      ledRite.off();
      buzzLeft.beep();
    }
    else if (sensor.leftDetected && !sensor.rightDetected) {
      Serial.println(" Drifting RIGHT! Correct your steering.");
      ledLeft.off();
      ledMidd.off();
      ledRite.on();
      buzzRite.beep();
    }
    else if (!sensor.leftDetected && !sensor.rightDetected) {
      Serial.println(" Completely off-lane! Emergency!");
      ledLeft.on();
      ledMidd.off();
      ledRite.on();
      buzzLeft.beep();
      buzzRite.beep();
    }
    else {
      Serial.println(" In lane.");
      ledLeft.off();
      ledMidd.on();
      ledRite.off();
    }
  }
};
LaneSensor laneSensor;
LaneDepartureSystem laneSystem(laneSensor);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); 
}

void loop() {
  laneSensor.simulateInput();      
  laneSystem.checkLaneDeparture();
  delay(2000); 
}

