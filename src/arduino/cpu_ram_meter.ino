#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float timeCounter = 0;

String message;

int data;
int cpuUsagePercent = 0;
int cpuGraphYPoints[65];
int cpuGraphYCoord1 = 0;
int cpuGraphYCoord2 = 0;

void setup() 
{
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  for (int i = 0; i < 64; i++) cpuGraphYPoints[i] = 128;
  pinMode(LED_BUILTIN, OUTPUT);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(16, 32);
  display.println(F("Test 0123"));
  display.display();
}

void UpdateGraph(int newValue)
{
  for (int i = 62; i >= 0; i--)
  {
    cpuGraphYPoints[i + 1] = cpuGraphYPoints[i];  
  }
  cpuGraphYPoints[0] = 63 - (newValue / 3);
  for (int i = 0; i < 63; i++)
  {
    cpuGraphYCoord1 = (int)cpuGraphYPoints[i];
    cpuGraphYCoord2 = (int)cpuGraphYPoints[i + 1];
    display.drawLine(128 - 2 * i, cpuGraphYCoord1, 128 - 2 * (i + 1), cpuGraphYCoord2, WHITE);  
  }
  display.display();
}

void loop() 
{
  display.clearDisplay();
  message = "";
  while (Serial.available())
  {
    data = Serial.read();
    message += (char)data;
    if (message[6] == '.') cpuUsagePercent = (int)message[5] - 48;
    else cpuUsagePercent = ((int)message[5] - 48) * 10 + ((int)message[6] - 48);
  }
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(message);
  display.display();
  UpdateGraph(cpuUsagePercent);
  delay(1000);
  Serial.println(1);
}
