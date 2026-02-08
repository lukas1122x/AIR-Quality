#include <Wire.h>

// E-ink
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold12pt7b.h>

// Sensors
#include <SensirionI2CScd4x.h>
#include <SensirionI2CSen5x.h>

// ===== E-INK DISPLAY (3.7" 416x240) =====
GxEPD2_BW<GxEPD2_370, GxEPD2_370::HEIGHT> display(
  GxEPD2_370(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY)
);

// ===== SENSORS =====
SensirionI2CScd4x scd41;
SensirionI2CSen5x sen54;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C
  Wire.begin(21, 22);

  // Init display
  display.init();
  display.setRotation(1);
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);

  // Init SCD41
  scd41.begin(Wire);
  scd41.stopPeriodicMeasurement();
  scd41.startPeriodicMeasurement();

  // Init SEN54
  sen54.begin(Wire);
  sen54.deviceReset();
  delay(100);
  sen54.startMeasurement();

  drawText("Air Quality Monitor\nStarting...");
  delay(2000);
}

void loop() {
  uint16_t co2;
  float temp, hum;

  uint16_t error;
  char errorMessage[256];

  // ===== READ SCD41 =====
  scd41.readMeasurement(co2, temp, hum);

  // ===== READ SEN54 =====
  float pm1, pm2_5, pm4, pm10;
  int16_t vocIndex, noxIndex;

  sen54.readMeasuredValues(pm1, pm2_5, pm4, pm10, vocIndex, noxIndex);

  // ===== DISPLAY =====
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(10, 30);

    display.println("AIR QUALITY");
    display.println("----------------");

    display.print("CO2: ");
    display.print(co2);
    display.println(" ppm");

    display.print("Temp: ");
    display.print(temp, 1);
    display.println(" C");

    display.print("Humidity: ");
    display.print(hum, 1);
    display.println(" %");

    display.println("");

    display.print("PM2.5: ");
    display.print(pm2_5, 1);
    display.println(" ug/m3");

    display.print("PM10: ");
    display.print(pm10, 1);
    display.println(" ug/m3");

    display.print("VOC index: ");
    display.println(vocIndex);

    display.print("NOx index: ");
    display.println(noxIndex);

  } while (display.nextPage());

  // E-ink refresh interval
  delay(30000); // 30 seconds
}

// ===== SIMPLE TEXT SCREEN =====
void drawText(const char* text) {
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(10, 40);
    display.println(text);
  } while (display.nextPage());
}
