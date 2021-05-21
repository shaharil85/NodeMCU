#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "GmDzwQzNlGEbyUWSOehlJOtb--9H76L_";
char ssid[] = "mecha";
char pass[] = "mechatronic";

#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float ambient_temp = 0.0;
float object_temp  = 0.0;

BlynkTimer timer;

void sensor1(){
  ambient_temp = mlx.readAmbientTempC();
  Serial.print("Ambient Temp = ");
  Serial.println(ambient_temp);
  Blynk.virtualWrite(V4,ambient_temp); 
  object_temp = mlx.readObjectTempC();
  Serial.print("Object Temp = ");
  Serial.println(object_temp);
  Blynk.virtualWrite(V5,object_temp); 
}
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  mlx.begin();
  timer.setInterval(300L,sensor1);
}
void loop() {
  Blynk.run();
  timer.run();
}
