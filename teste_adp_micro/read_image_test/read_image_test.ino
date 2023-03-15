const byte LED_BUILTIN  = 2; 
#include "mbedtls/base64.h"

const uint8_t SIZE_BUFF= 32;
unsigned char *input_for_encode = (unsigned char*)malloc(SIZE_BUFF); 
unsigned char *input_for_decode = (unsigned char*)malloc(SIZE_BUFF); 

unsigned char *output_encoded = (unsigned char*)malloc(SIZE_BUFF);
unsigned char *output_decoded = (unsigned char*)malloc(SIZE_BUFF);
size_t outlen;



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  input_for_encode = (unsigned char*)"abc123"; //reinterpret_cast <unsigned char*>(const_cast<char*>("abc123"));
  input_for_decode = (unsigned char*)"QUEtQkItQ0MtREQtRUUtRkY6MDAwMA==";
  // encode
  mbedtls_base64_encode(output_encoded, SIZE_BUFF, &outlen, input_for_encode, strlen((const char*)input_for_encode));
  // decode
  mbedtls_base64_decode(output_decoded, SIZE_BUFF, &outlen, input_for_decode, strlen((const char*)input_for_decode));
}
 
void loop() {
  Serial.println("encoded");
  Serial.println((char*)output_encoded);

   Serial.println("decoded");
  Serial.println((char*)output_decoded);
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





