#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// Constants
#define DHTPIN 2     
#define DHTTYPE DHT22   
#define TRIG_PIN 11
#define ECHO_PIN 12
#define LED_PIN A2
#define DIST_THRESHOLD 20 // Distance threshold in cm

// Objects
LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo myServo;
DHT dht(DHTPIN, DHTTYPE); 

// Variables
float hum;   
float temp;
long duration;
float distance;

// Keypad configuration
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = { 
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; 
byte colPins[COLS] = {6, 5, 4}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
    // Initialize components
    dht.begin();
    lcd.init(); 
    lcd.backlight();
    myServo.attach(3);
    Serial.begin(9600);
  
    // Ultrasonic pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // LED pin
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{    char key = keypad.getKey();
    if (key) {
        Serial.print("CMD:");
        Serial.println(key); // Send the key pressed to Qt
    }
    temp = dht.readTemperature();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
   // Read ultrasonic distance
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = duration * 0.034 / 2;

    // Turn LED on/off based on distance
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        if (command == "LED_ON") {
            digitalWrite(LED_PIN, HIGH);
            lcd.setCursor(0, 1);
            lcd.print("Person Detected");
        }
         if (command == "dooropen") {
            myServo.write(90);
            lcd.setCursor(0, 1);
            lcd.print("dooropen");
        }
          if (command == "doorclose") {
            myServo.write(0);
            lcd.setCursor(0, 1);
            lcd.print("doorclose");
        }
         if (command == "HOT") {
        
            lcd.setCursor(12, 0);
            lcd.print("HOT");
        }
        if (command == "COLD") {
            
            lcd.setCursor(12, 0);
            lcd.print("Cold");
        }
        if (command != "LED_OFF" && command !="COLD" && command != "LED_OFF" && command != "LED_ON" && command !="HOT") {
            lcd.setCursor(12, 0);
            lcd.print("    ");
        }
          if (command == "LED_OFF") {
            digitalWrite(LED_PIN, LOW);
            lcd.setCursor(0, 1);
            lcd.print("               ");
        }
        }
    
    Serial.print("TEMP:");
    Serial.println(temp);
    Serial.print("DIST:");
    Serial.println(distance);

    delay(100); 

}
