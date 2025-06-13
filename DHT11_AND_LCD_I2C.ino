
#include<DHT.h>      
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int DHTPIN = 9;       //DHT 11 pin is D9
const int DHTTYPE = DHT11; 
DHT dht(DHTPIN, DHTTYPE);
int buzzer = 11;
byte pointattop[] = {
  B01100,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000
};
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();      
  lcd.backlight( );
  lcd.createChar(0, pointattop);
  pinMode(motor, OUTPUT);
  lcd.setCursor(4,0);
  lcd.print("Welcome");
  lcd.setCursor(2,1);
  lcd.print("Mr.Dang Nhan");
  delay(2000);
  lcd.clear();
 
}
 
void loop() {
  
  float h = dht.readHumidity();    //Humidity read
  float t = dht.readTemperature();
  

  Serial.print("Nhiet do: ");
  Serial.println(t);               //Print temperature
  Serial.print("Do am: ");
  Serial.println(h);               //Print humidity
  Serial.println();
  lcd.setCursor(2,0);
  lcd.print("t");
  lcd.setCursor(3,0);
  lcd.write(byte(0));
  lcd.setCursor(4,0);
  lcd.print("=");
  lcd.setCursor(5,0);
  lcd.print(t,1);
  lcd.setCursor(9,0);
  lcd.write(byte(0));
  lcd.setCursor(10,0);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid:");
  lcd.setCursor(7,1);
  lcd.print(h,1);
  lcd.setCursor(11,1);
  lcd.print("%");
  
  if(t>30 or t<20)
  {digitalWrite(buzzer, HIGH);}
  else
  {digitalWrite(buzzer, LOW);
  }
 }

 
