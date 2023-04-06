/*
DHT11

This example reads a DHT11 sensor hooked up on pin D7. Reads both
temperature and humidity and sends it to the Serial port

created in Feb 2019 by D. Cuartielles
based on work by F. Vanzati (2011) and M. Loglio (2013)

This example code is in the public domain.
*/

// include the EduIntro library
#include <EduIntro.h>
#define DHTPIN 2

DHT11 dht(DHTPIN);  // creating the object sensor on pin 'D7'


void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  dht.update();
    delay(2000);
  int h = dht.readHumidity();
  int t = dht.readCelsius();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

} 