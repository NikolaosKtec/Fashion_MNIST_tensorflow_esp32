const byte LED_BUILTIN  = 2; 
#include "mbedtls/base64.h"


unsigned char *input = (unsigned char*)malloc(32); 

unsigned char *output = (unsigned char*)malloc(32);
size_t outlen;



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  input = (unsigned char*)"abc123"; //reinterpret_cast <unsigned char*>(const_cast<char*>("abc123"));
  // encode
  mbedtls_base64_encode(output, 64, &outlen, input, strlen((const char*)input));
}
 
void loop() {
 
  Serial.println((char*)output);
  delay(1000);

  
  //  while(Serial.available()){
  //   im = Serial.read();
  //   delay(10);
  //   Serial.write(im);
  //   digitalWrite(LED_BUILTIN, HIGH);
  // }
  
  // delay(100);
  // digitalWrite(LED_BUILTIN, LOW);
}





