#include <LiquidCrystal.h>
#include<DHT.h> 
#define Type DHT11
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int time ; 
int FloatSensor = 8;
 int led = 13;
 int tempPin = 9 ; 
int buzzpin = 10 ; 
int buttonState = 1; //reads pushbutton status
float temp;
DHT ht(tempPin, Type); 
int trig = 7 ; 
int echo =6; 
int distance; 
void setup() {
  Serial.begin(9600);
  pinMode(FloatSensor, INPUT_PULLUP);
 pinMode (led, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(trig, OUTPUT);
  pinMode(buzzpin,OUTPUT); 
  lcd.begin(16, 2);
}
void loop() {
  lcd.setCursor(0, 1);
  lcd.clear(); 
digitalWrite(trig,LOW); 
delayMicroseconds(2); 
digitalWrite (trig,HIGH); 
delayMicroseconds(10); 
digitalWrite(trig,LOW); 

time = pulseIn(echo,HIGH); 
distance = (time/2)/29.1; 
lcd.print("The distance is:"); 
lcd.setCursor(1,1); 
lcd.print(distance); 
lcd.print(" CM"); 
delay(1000); 
lcd.clear();


temp = ht.readTemperature(); 
lcd.setCursor(0,0); 
lcd.print("Temprature : "); 
lcd.setCursor(0,1); 
lcd.print(temp);  
delay(750) ;
lcd.clear(); 
 
  buttonState = digitalRead(FloatSensor);


  if (buttonState == LOW) {
    digitalWrite(led, LOW);
    Serial.println("WATER LEVEL - LOW");
    digitalWrite(buzzpin,LOW); 

 
  }
  else {
    digitalWrite(led, HIGH);
    Serial.println("WATER LEVEL - HIGH");
    digitalWrite(buzzpin,HIGH); 
    lcd.clear(); 
    lcd.setCursor(0,0); 
    lcd.print("Tank is Full"); 
    delay(2000); 
    lcd.clear(); 
  }
  }
