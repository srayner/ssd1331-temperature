
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

#define	BLACK     0x0000
#define	BLUE      0x001F
#define	RED       0xF800
#define	GREEN     0x07E0
#define CYAN      0x07FF
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define WHITE     0xFFFF

#define cs  10
#define rst 9
#define dc  8
Adafruit_SSD1331 display = Adafruit_SSD1331(&SPI, cs, dc, rst);

int sensorPin = A5;
float currentTemp;

void setup(void) {
  Serial.begin(9600);
  display.begin();
  display.fillScreen(BLACK);
  displayText(0, 0, 1, "Temperature", YELLOW);
  display.drawLine(0, 40, 96, 40, YELLOW);
}

void loop() {
  float degC = averageTemp();
  if (degC != currentTemp){
    currentTemp = degC;
    updateDisplay(degC);
  }

  delay(2000);
}

void updateDisplay(float degC) {
  String tempText = String(degC);
  tempText.concat(char(247));
  tempText.concat("C");
  display.fillRect(0,20,200, 20, BLACK);
  displayText(0, 20, 2, tempText, CYAN);
}

void displayText(int x, int y, int size, String text, int color) {
  display.setCursor(x, y);
  display.setTextColor(color);
  display.setTextSize(size);
  display.print(text);
}

float averageTemp() {
  float sum = 0.0;
  for(int i = 0; i < 5; i++) {
    sum += getDegC();
  }
  float result = sum / 5.0;

  return result;
}

float getDegC() {
  int sensorValue = analogRead(sensorPin);
  float mV = sensorValue / 1023.0 * 4.96 * 1000;
  Serial.print(mV);
  Serial.print("mV ");

  float degC = (mV - 500) / 10;
  Serial.print(degC);
  Serial.println("degC");

  return degC;
}
