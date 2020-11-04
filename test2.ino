#include <Wire.h> //I2C Arduino Library

#define addr 0x0D //I2C Address for The HMC5883

void setup() {

  Serial.begin(9600);
  Wire.begin();


  Wire.beginTransmission(addr); //start talking
  Wire.write(0x0B); // Tell the HMC5883 to Continuously Measure
  Wire.write(0x01); // Set the Register
  Wire.endTransmission();
  Wire.beginTransmission(addr); //start talking
  Wire.write(0x09); // Tell the HMC5883 to Continuously Measure
  Wire.write(0x1D); // Set the Register
  Wire.endTransmission();
}

void loop() {

  
//  Serial.print("Place the magnet at the count of 5\n");
//  delay(1000);
//  Serial.print("5\n");
//  delay(1000);
//  Serial.print("4\n");
//  delay(1000);
//  Serial.print("3\n");
//  delay(1000);
//  Serial.print("2\n");
//  delay(1000);
//  Serial.print("1\n");
//  delay(1000);
//  Serial.print("Readings are started... Wait for 5 seconds\n");
  int x, y, z; //triple axis data
  double sum_x = 0;
  double sum_y = 0;
  double sum_z = 0;
  long  int time_now = millis();
  while(millis()<100+time_now){
    //Tell the HMC what regist to begin writing data into
//      if((millis()-time_now) == 4000){
//        Serial.print("4\n");
//      }
//      if((millis()-time_now) == 3000){
//        Serial.print("3\n");
//      }
//      if((millis()-time_now) == 2000){
//        Serial.print("2\n");
//      }
//      if((millis()-time_now) == 1000){
//        Serial.print("1\n");
//      }
      
      Wire.beginTransmission(addr);
      Wire.write(0x00); //start with register 3.
      Wire.endTransmission();
    
      //Read the data.. 2 bytes for each axis.. 6 total bytes
      Wire.requestFrom(addr, 6);
      if (6 <= Wire.available()) {
        x = Wire.read(); //MSB  x
        x |= Wire.read() << 8; //LSB  x
        z = Wire.read(); //MSB  z
        z |= Wire.read() << 8; //LSB z
        y = Wire.read(); //MSB y
        y |= Wire.read() << 8; //LSB y
      }
      sum_x = sum_x + x;
      sum_y = sum_y + y;
      sum_z = sum_z + z;
    }
//      sum_x = sum_x + 1383;
//      sum_y = sum_y + 408;
//      sum_z = sum_z - 4490;
      double tsum_x = sum_x/100 +800;
      double tsum_y = sum_y/100 +575;
      double tsum_z = sum_z/100 +1721;
      double bsquare = (tsum_x*tsum_x) + (tsum_y*tsum_y) + (tsum_z*tsum_z);
      //Serial.print("Net Value: ");
      //Serial.println(bsquare);
      double intensity = abs(sqrt(abs(bsquare)));
      //Serial.print("Intensity value: ");
      //Serial.println(intensity);
//      Serial.print("\t");
      //Serial.print("Distance square value: ");
      double dsquare = (377200/intensity);
      //Serial.println(dsquare);

      //Serial.print(">>> \t Distance value: ");
      double dist = abs(sqrt(abs(dsquare)));
      Serial.println(dist);
  // Show Values
//  Serial.print("X Value: ");
//  Serial.println(sum_x/100 +800);//subtract magnetic feild here
//  Serial.print("Y Value: ");
//  Serial.println(sum_y/100+575);
//  Serial.print("Z Value: ");
//  Serial.println(sum_z/100 +1721);
//  Serial.println();
 //Serial.print(-10);  // To freeze the lower limit
//Serial.print(" ");
//Serial.print(10);  // To freeze the upper limit
//Serial.print(" ");
//Serial.println(sensorValue);
  
  //Serial.println(abs(sqrt(dsquare)));

//Serial.print(x-1820);
//Serial.print("\t");
//Serial.print(y-610);
//Serial.print("\t");
//Serial.println(z-10);
//Serial.print("\t");

//Serial.println(abs(x+y+z-2500));

  delay(100);
}
