#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "config.h"

#define NEOPIXEL 21

void setup()
{
  Serial.begin(115200);
  delay(100);

  // pinMode(NEOPIXEL_PIN, OUTPUT);

  // Connect to WiFi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.begin();
}

// the loop function runs over and over again forever
void loop()
{
  ArduinoOTA.handle();

  neopixelWrite(NEOPIXEL, RGB_BRIGHTNESS, 0, 0); // Red
  delay(1000);
  neopixelWrite(NEOPIXEL, 0, RGB_BRIGHTNESS, 0); // Green
  delay(1000);
  neopixelWrite(NEOPIXEL, 0, 0, RGB_BRIGHTNESS); // Blue
  delay(1000);
  neopixelWrite(NEOPIXEL, 0, 0, 0); // Off / black
  delay(1000);
}