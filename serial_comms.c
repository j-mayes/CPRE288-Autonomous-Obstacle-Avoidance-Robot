/*
 * Serial Communication Over UART
 *
 * Author(s): Andre Chickering & Jensen Mayes
 */
#include <stdint.h>
#include <stdbool.h>
#include "TM4C123GH6PM.h"
#include "timer.h"
#include "lcd.h"

int main(void) {
  uint8_t num = 0, i = 0;
  char s_data, text[50];
  
  get_data_putty(text);
  
  //If text last value is \r then print whole string
  
  else {
    //transmit the last value stored in text and its array position
  
  UART_Init();
}

void UART_Init(void) {
  
  SYSCTL -> RCGCGPIO |= 0x02 | 0x20;
  SYSCTL -> RCGCUART = 0x02;
  
  GPIOB -> AFSEL = 0x03;
  GPIOB -> PCTL = 0x00000011;
  GPIOB -> DEN = 0x03;
  
  UART1 -> CTL &= 0xFFFFFFFE;
  UART1 -> IBRD = 0x8;
  UART1 -> FBRD = 0x2C;
  UART1 -> LCRH = 0x60;
  UART1 -> CC = 0x0;
  UART1 -> CTL |= 0x1;
}

void UART_Transmit(char sdata) {
  while ((UART1 -> FR & 0x20) != 0) {
    UART1 -> DR = sdata;
  }
}

char UART_Receive(void) {
  //Will be used to recieve data back from UART
    return x;
}
