# 🌬️ Air Quality Monitor Project

This is my custom air quality monitoring device based on the ESP32-WROOM-32 microcontroller and a 3.7" e-ink display.  
The device measures indoor air quality parameters such as CO₂, particulate matter, VOC, and NOx, and displays the data on a low-power e-ink screen.

![Product](cad.png)

---

# 📐 Screenshot: Schematic

![Schematic](schematic.png)

---

# 🟩 Screenshot: PCB

![PCB](pcb.png)

---

# 🧱 Screenshot: Case and Component Fit

![Case](cad.png)

---

# 🌡️ Sensors Used

## Sensirion SEN54
- PM1.0, PM2.5, PM4.0, PM10
- VOC index
- NOx index

![SEN54](sen54.png)

## Sensirion SCD41
- CO₂
- Temperature
- Relative humidity

![SCD41](SCD41.png)

---

# 📦 BOM – Bill of Materials

| Quantity | Name | Description |
|--------|------|------------|
| 1× | ESP32-WROOM-32 | Main microcontroller |
| 1× | Sensirion SEN54 | PM, VOC, NOx sensor |
| 1× | Sensirion SCD41 | CO₂, temperature, humidity sensor |
| 1× | 3.7" E-Ink Display | 416×240 resolution |
| 1× | DESPI-C02 | E-paper adapter board |
| 1× | Custom PCB | Designed for this project |
| 1× | Enclosure | Designed in Fusion 360 |
| 1× | USB-C power input | Power supply |

---

# 🛠 Tools Used

- Fusion 360 – case design  
- KiCad – schematic and PCB design  
- Arduino IDE – firmware development  
- GitHub – version control and documentation  
