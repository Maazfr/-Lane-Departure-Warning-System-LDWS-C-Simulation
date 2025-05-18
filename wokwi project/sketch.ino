#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);




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
LED ledOver(8);
BUZZER buzzLeft(10);
BUZZER buzzRite(9);

int readSpeed()
{
  int sensorValue = analogRead(A1);
  return map(sensorValue, 0 , 1023 , 0 , 120);
}

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
    int speed = readSpeed();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Speed :");
    lcd.print(speed);
    lcd.print("km\h");
    
    lcd.setCursor(0,1);

    if (!sensor.leftDetected && sensor.rightDetected) {
      Serial.println(" Drifting LEFT! Correct your steering.");
      lcd.print("Drifting Left");
      ledLeft.on();
      ledMidd.off();
      ledRite.off();
      ledOver.off();
      if(speed > 75) 
      {
        lcd.setCursor(0, 3);
        buzzLeft.beep();
        Serial.println("Over Speeding! Reduce Speed NOW");
        lcd.print("OVER SPEEDING");
        ledOver.on();
      }
    }
    else if (sensor.leftDetected && !sensor.rightDetected) {
      Serial.println(" Drifting RIGHT! Correct your steering.");
      lcd.print("Drifting Right");
      ledLeft.off();
      ledMidd.off();
      ledRite.on();
      ledOver.off();
      if(speed > 75) 
      {
        lcd.setCursor(0, 4);
        buzzRite.beep();
        Serial.println("Over Speeding! Reduce Speed NOW");
        lcd.print("OVER SPEEDING");
        ledOver.on();
      }
    }
    else if (!sensor.leftDetected && !sensor.rightDetected) {
      Serial.println(" Completely off-lane! Emergency!");
      lcd.print("~~EMERGENCY~~");
      ledLeft.on();
      ledMidd.off();
      ledRite.on();
      ledOver.off();
      if(speed > 75)
      {
        lcd.setCursor(0, 3);
      buzzLeft.beep();
      buzzRite.beep();
      Serial.println("Over Speeding! Reduce Speed NOW");
      lcd.print("OVER SPEEDING");
      ledOver.on();
      }
    }
    else {
      Serial.println(" In lane.");
      lcd.print("IN LANE");
      ledLeft.off();
      ledMidd.on();
      ledRite.off();
      ledOver.off();
      if(speed > 75)
      {
        lcd.setCursor(0, 3);
        Serial.println("Over Speeding! Reduce Speed NOW");
        lcd.print("OVER SPEEDING");
        ledOver.on();
      }
    }
  }
};
LaneSensor laneSensor;
LaneDepartureSystem laneSystem(laneSensor);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LDWS starting");
  delay(1000);
  lcd.clear();
  
}

void loop() {
  laneSensor.simulateInput();      
  laneSystem.checkLaneDeparture();
  delay(2000); 
}

