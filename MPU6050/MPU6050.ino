//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

//const int mpuAddress = 0x69;  //Puede ser 0x68 o 0x69
const int mpuAddress = 0x68;  //Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);

int16_t ax, ay, az;
int16_t gx, gy, gz;

void printTab()
{
  Serial.print(F("\t"));
}

void printRAW()
{
  Serial.print(F("a[x y z] g[x y z]:t"));
  Serial.print(ax); printTab();
  Serial.print(ay); printTab();
  Serial.print(az); printTab();
  Serial.print(gx); printTab();
  Serial.print(gy); printTab();
  Serial.println(gz);
}
/*
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  for (uint8_t address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Scan complete");
}

void loop() {}
*/


void setup()
{
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
}


void loop()
{
  // Leer las aceleraciones y velocidades angulares
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  printRAW();
  
  delay(1000);
}
