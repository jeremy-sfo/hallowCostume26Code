/*
====================================================
MPU6050 Module

Reads the mpu for acl and gyd data

Handles:
- Accelerometer and Gyrometer reading
- Routing mpu data
====================================================
*/

const int MPU_ADDRESS = 0x68; // adress for the mpu module

void setupMPU(){

  Wire.beginTransmission(MPU_ADDRESS); // wake up the mpu at its adress
  Wire.write(0x6B); // start writing at that location
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.println("MPU6050 started!"); // ouput that the mpu is awoken

}

void readMPU(){

  // tell the mpu we want to start reading at 0x3B
  Wire.beginTransmission(MPU_ADDRESS); 
  Wire.write(0x3B);
  Wire.endTransmission();

  // request 14 bytes: Accel X, Y, Z | Temperature | Gyro X, Y, Z
  Wire.requestFrom((uint8_t)MPU_ADDRESS, (size_t)14, true);

  if(Wire.available() < 14) return; // have a check to make sure wire is responding 14 bytes

  // read the 3 axis for the acl
  int16_t accelX = Wire.read() << 8 | Wire.read();
  int16_t accelY = Wire.read() << 8 | Wire.read();
  int16_t accelZ = Wire.read() << 8 | Wire.read();

  // skip temperature for now
  Wire.read();
  Wire.read();

  // read the gyro on 3 axis
  int16_t gyroX = Wire.read() << 8 | Wire.read();
  int16_t gyroY = Wire.read() << 8 | Wire.read();
  int16_t gyroZ = Wire.read() << 8 | Wire.read();

  // convert values to useful units
  float accelXg = accelX / 16384.0;
  float accelYg = accelY / 16384.0;
  float accelZg = accelZ / 16384.0;

  float gyroXdps = gyroX / 131.0;
  float gyroYdps = gyroY / 131.0;
  float gyroZdps = gyroZ / 131.0;

  // TEST: print the values for now
  Serial.print("Accel X: ");
  Serial.print(accelXg);
  Serial.print("g | Y: ");
  Serial.print(accelYg);
  Serial.print("g | Z: ");
  Serial.print(accelZg);
  Serial.print("g");

  Serial.print("    Gyro X: ");
  Serial.print(gyroXdps);
  Serial.print("°/s | Y: ");
  Serial.print(gyroYdps);
  Serial.print("°/s | Z: ");
  Serial.print(gyroZdps);
  Serial.println("°/s");
}