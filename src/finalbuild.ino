#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);
#define LATCH_PIN 3 // CI 12
#define CLOCK_PIN 4 // CI 11
#define DATA_PIN 2  // CI 14
//Music
#define BEAT 300
#define PIN 13

#define DO 262
#define RE 294
#define MI 330
#define FA 349
#define SO 392
#define RA 440
#define SI 494
#define HDO 523

//Timer
//int counter = 0;
int water = 0;
const int dry = 270;
const int pumpPin = 9;
const int tankPin = 10;
const int soilSensor = A0;
const int waterSensor = A2;
const int poten = A3;
const int pirSensor = 5;
const int BUTTON_PIN = 7;
const int obstacle = 8;
int buttonState = 0;
int var;
int hiz = 0;

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(tankPin, OUTPUT);
  pinMode(obstacle, OUTPUT);
  pinMode(soilSensor, INPUT);
  pinMode(waterSensor, INPUT);
  pinMode(pirSensor, INPUT);
  Serial.begin(9600);

  lcd_1.begin(16, 2);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int sensorval = digitalRead(pirSensor);
  Serial.println(sensorval);
  
  if (sensorval == HIGH) {
    digitalWrite(obstacle, HIGH);
    delay(50);
    digitalWrite(obstacle, LOW);
    delay(50);
  }
  else {
    digitalWrite(obstacle, LOW);
  }
  ckeckBME280();
  checkWater();
  checkMoisture();
  buttonState = digitalRead(BUTTON_PIN);
  if(buttonState == LOW)        
    digitalWrite(pumpPin, HIGH);
  int sensorvalue = analogRead(A3);
  int voltage = sensorvalue * (10 / 1023.0);
  //Serial.println(voltage);
  
  switch(voltage)
  {
  case 1:
    Serial.println("State 1 ");
    analogWrite(pumpPin,0);
    break;
  case 2:
    Serial.println("State 2 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 3:
    Serial.println("State 3 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 4:
    Serial.println("State 4 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 5:
    Serial.println("State 5 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 6:
    Serial.println("State 6 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 7:
    Serial.println("State 7 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 8:
    Serial.println("State 8 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 9:
    Serial.println("State 9 ");
    analogWrite(pumpPin,voltage);
    break;    
  case 10:
    Serial.println("State 10 ");
    analogWrite(pumpPin,voltage);
    break;    

  }
}

//Temperature
void ckeckBME280(){
  int tmp = analogRead(A1);
  float voltage = (tmp * 5.0)/1024;
  float milliVolt = voltage * 1000; 
  float tmpCel =  (milliVolt-500)/10 ;  
  float tmpFer = (((tmpCel*9)/5)+32);
  
  lcd_1.setCursor(0, 0);
  lcd_1.print(tmpCel);
  lcd_1.setBacklight(1);
}

//Water Sensor
void checkWater(){
  //Check the water level in the bucket.
water = analogRead(waterSensor); 
    if (water<=100)
    { 
        Serial.println("Water Level: Empty"); 
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b10000000);
        digitalWrite(LATCH_PIN, HIGH);
      	digitalWrite(tankPin, HIGH);
    	// keep watering for 5 sec
    	delay(5000);
    	// turn off water
    	digitalWrite(tankPin, LOW);
    } 
    else if (water>100 && water<=400)
    { 
        Serial.println("Water Level: Low");
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11100000);
        digitalWrite(LATCH_PIN, HIGH); 
    } 
    else if (water>400 && water<=450)
    { 
        Serial.println("Water Level: Medium");
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11111000);
        digitalWrite(LATCH_PIN, HIGH);  
    } 
    else if (water>450){ 
        Serial.println("Water Level: High"); 
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11111111);
        digitalWrite(LATCH_PIN, HIGH);  
    }
    delay(1000); 
}

//moisture sensor
void checkMoisture(){
  //Measure soil humidity
  int moisture = analogRead(soilSensor);
  Serial.println(moisture);
  delay(2000);
  
  lcd_1.setCursor(0, 1);
  lcd_1.print("Moisture: " + String(moisture) + "   ");
  //Serial.Write(moisture);
  if (moisture <= dry) {
    // the soil is too dry, water!
    watering(); 
  } else {
    Serial.println("Moisture is adequate. No watering needed " + String(moisture));
  	digitalWrite(pumpPin, LOW);
  }
}
//Watering
void watering(){
  int moisture = analogRead(soilSensor);
  Serial.println("Watering now..moisture is " + String(moisture));
    digitalWrite(pumpPin, HIGH);
    // keep watering for 5 sec
    delay(5000);
    // turn off water
    digitalWrite(pumpPin, LOW);
  completeWatering();
  //counter++; 
}
//Music
void completeWatering(){
  //Let them know that watering is complete.
	  lcd_1.setCursor(0, 0);
  	  lcd_1.print("   Thank you!   ");
      lcd_1.setCursor(0, 1);
      lcd_1.print("   (^ O ^)/     ");
      Serial.println("Done watering.");
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,MI,1200) ; // E
      delay(BEAT) ;
      delay(BEAT) ;
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,MI,BEAT) ; // E
      delay(BEAT) ;
      tone(PIN,RE,BEAT) ; // D
      delay(BEAT) ;
      tone(PIN,DO,BEAT) ; // C
      delay(BEAT) ;
      tone(PIN,RE,1200) ; // D
      delay(BEAT) ;
      delay(BEAT) ;
  delay(4400);
  //counter++;
   lcd_1.setCursor(0, 0);
   lcd_1.print("                  ");
   lcd_1.setCursor(0, 1);
   lcd_1.print("                  ");
  ckeckBME280();
  int moisture = analogRead(A0);
   lcd_1.setCursor(0, 1);
   lcd_1.print("Moisture: " + String(moisture) + "   ");
  Serial.println("Soil moisture is " + String(moisture));
}
