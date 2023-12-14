#include <Wire.h>

#define UNO_ADDR 9
#define RESP_SIZE 15
String data = "Hi, I'm Arduino UNO R3";

void setup() {
  Serial.begin(9600);
  Wire.begin(UNO_ADDR);
  Wire.onReceive(DataReceive);
  Wire.onRequest(DataRequest);

}

void loop() {
  delay(500);
}

// void DataReceive(int numBytes)
// {
//   int i = 0;
//   char data[RESP_SIZE];
//   memset(data, 0, RESP_SIZE);
//   while (Wire.available())
//   {
//     data[i++] = Wire.read();
//   }
//   Serial.println("Recv Event");
//   Serial.println(String(data));
// }

void DataReceive(int numByte) 
{
  while (0 < Wire.available())
  {
    char c = Wire.read();
    Serial.println(c);
  }
  Serial.println();
}

void DataRequest()
{
  Wire.write("Hello I'm Arduino");
}

// void DataRequest()
// {
//   byte resp[RESP_SIZE];
//   for (byte i = 0; i < RESP_SIZE; i++) {
//     resp[i] = (byte)data.charAt(i);
//   }
//   Wire.write(resp, sizeof(resp));
//   Serial.println();
// }