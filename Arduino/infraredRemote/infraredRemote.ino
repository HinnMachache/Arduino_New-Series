#include <IRremote.h>
int remotePin = 6;
IRrecv IR(remotePin);
decode_results cmdResults;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&cmdResults) == 0){

  }
  Serial.println(cmdResults.value,HEX);
  delay(1500);
  IR.resume();
}
