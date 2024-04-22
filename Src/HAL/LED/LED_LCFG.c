// Self Files Inclusion
#include "../../../Inc/HAL/LED/LED_config.h"

// Led Objects Definitions

Led_t led_red1 =
{
    .led_port = GPIO_PORTB,
    .led_pin  = GPIO_PIN1,
    .led_logic = GPIO_LOW
};
Led_t led_yellow1 =
{
    .led_port = GPIO_PORTB,
    .led_pin  = GPIO_PIN0,
    .led_logic = GPIO_LOW
};
Led_t led_red2 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN2,
    .led_logic = GPIO_LOW
};
Led_t led_yellow2 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN3,
    .led_logic = GPIO_LOW
};
Led_t led_green1 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN4,
    .led_logic = GPIO_LOW
};
Led_t led_red3 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN5,
    .led_logic = GPIO_LOW
};
Led_t led_green2 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN6,
    .led_logic = GPIO_LOW
};
Led_t led_red4 =
{
    .led_port = GPIO_PORTA,
    .led_pin  = GPIO_PIN7,
    .led_logic = GPIO_LOW
};
