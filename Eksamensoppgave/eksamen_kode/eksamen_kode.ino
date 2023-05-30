#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,20,4);  // Sett LCD-adressen til 0x27 for en 16 tegn og 2 linjers skjerm

int val = 0;
//Deklarer en variabel for soil moisture sensor 
int soilPin = A0;
int soilPower = 7;//Variabel for Soil moisture Power
int sensorValue;


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);

  //soil moisture sensor
  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);
  //vannpumpe-Motor
  pinMode(3, OUTPUT);

}

void loop() {
 
  Serial.println(readSoil());
  
  //Denne tidsrammen på 1 sekund brukes slik at du kan teste sensoren og se den endres i sanntid.
  //Tar en lesning hvert sekund
  delay(1000);
  float getVoltage(int pin);


  if (val > 100) {
    digitalWrite(3, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump IS OF");
  } 

  else {
    digitalWrite(3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Pump IS ON ");

  }
}

//Dette er en funksjon som brukes for å få soil moisture content
int readSoil()
{
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    //vent 10 millisekunder
    delay(10);
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture verdig
}



