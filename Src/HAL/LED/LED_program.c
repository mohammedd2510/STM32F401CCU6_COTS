// Self Files Inclusion
#include "../../../Inc/HAL/LED/LED_interface.h"
#include "../../../Inc/HAL/LED/LED_private.h"


// Software Interfaces Definitions
void LED_voidInit(Led_t* REF_LedObj) {
  switch (REF_LedObj->led_port) {
    case GPIO_PORTA:
      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOAEN);
      break;
    case GPIO_PORTB:
      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOBEN);
      break;
    case GPIO_PORTC:
      RCC_voidEnablePeripheralClock(RCC_AHB,RCC_AHB_GPIOCEN);
      break;
    default:
      break;
  }
  GPIO_voidSetPinMode(REF_LedObj->led_port,REF_LedObj->led_pin,GPIO_OUTPUT_PIN_MODE);
  GPIO_voidSetPinOutputMode(REF_LedObj->led_port,REF_LedObj->led_pin,GPIO_OUTPUT_PIN_PUSH_PULL);
  GPIO_voidSetPinOutputSpeed(REF_LedObj->led_port,REF_LedObj->led_pin,GPIO_OUTPUT_PIN_LOW_SPEED);
  GPIO_voidSetPinValue(REF_LedObj->led_port,REF_LedObj->led_pin,REF_LedObj->led_logic);
}
void LED_voidOn(Led_t* REF_LedObj) {
    GPIO_voidSetPinValue(REF_LedObj->led_port,REF_LedObj->led_pin,GPIO_HIGH);
    REF_LedObj->led_logic = GPIO_HIGH;
}
void LED_voidOff(Led_t* REF_LedObj) {
    GPIO_voidSetPinValue(REF_LedObj->led_port,REF_LedObj->led_pin,GPIO_LOW);
    REF_LedObj->led_logic = GPIO_LOW;
}
void LED_voidToggle(Led_t* REF_LedObj)
{
    if (REF_LedObj->led_logic == GPIO_HIGH)
    {
        LED_voidOff(REF_LedObj);
    }
    else if(REF_LedObj->led_logic == GPIO_LOW){
        LED_voidOn(REF_LedObj);
    }
}