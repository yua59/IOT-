/*!
 * @file readDHT11.ino
 * @brief DHT11 is used to read the temperature and humidity of the current environment. 
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Wuxiao](xiao.wu@dfrobot.com)
 * @version  V1.0
 * @date  2018-09-14
 * @url https://github.com/DFRobot/DFRobot_DHT11
 */
#include <SoftwareSerial.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 5
SoftwareSerial bluetooth(0, 1);
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  bluetooth.print("온도 : ");
  bluetooth.print(DHT.temperature);
  bluetooth.println("℃"); 
  bluetooth.print("습도 : ");
  bluetooth.println(DHT.humidity);


  delay(2000);
 
}
