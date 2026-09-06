/*
====================================================
MPU6050 Module

Reads the mpu for acl and gyd data

Handles:
- Accelerometer and Gyrometer reading
- Routing mpu data
====================================================
*/

// define the mpu reading variables
float accelXg;
float accelYg;
float accelZg;

float gyroXdps;
float gyroYdps;
float gyroZdps;

// define the mpu checking variables
float accelXgPrev = 0;
float accelYgPrev = 0;
float accelZgPrev = 0;

float gyroXdpsPrev = 0;
float gyroYdpsPrev = 0;
float gyroZdpsPrev = 0;

const int MPU_ADDRESS = 0x68; // adress for the mpu module

void setupMPU(){

  Wire.begin();

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

  if(Wire.available() < 14){ // have a check to make sure wire is responding 14 bytes

    Serial.println("MPU Error: Did not recieve 14 bytes ");
    return;
  }

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

  // convert values to useful units (Acl: gravity power, Gyro: °/second) and also round to the nearest tenth
  accelXg = round((accelX / 16384.0) * 10) / 10.0;
  accelYg = round((accelY / 16384.0) * 10) / 10.0;
  accelZg = round((accelZ / 16384.0) * 10) / 10.0;

  gyroXdps = round((gyroX / 131.0) * 10) / 10.0;
  gyroYdps = round((gyroY / 131.0) * 10) / 10.0;
  gyroZdps = round((gyroZ / 131.0) * 10) / 10.0;

  /* TEST: print the mpu values
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
  Serial.println("°/s");*/
}