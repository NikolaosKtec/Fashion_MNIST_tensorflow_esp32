const byte LED_BUILTIN  = 2; 
// #include "driver/uart.h"
#include <typeinfo>
// // const uart_port_t uart_num = UART_NUM_2;
// const int BUF_SIZE = 1024;

// uint8_t *data = (uint8_t *) malloc(BUF_SIZE);

// uart_config_t uart_config = {
//       .baud_rate = 115200,
//       .data_bits = UART_DATA_8_BITS,
//       .parity = UART_PARITY_DISABLE,
//       .stop_bits = UART_STOP_BITS_1,
//       .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,
//       .rx_flow_ctrl_thresh = 122,
// };

uint16_t im;//[28][28][3];
int x = 0;
String res = "";
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
 
   while(Serial.available()){
    im = Serial.read();
    delay(10);
    Serial.write(im);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}





