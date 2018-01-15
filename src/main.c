
#include <delay.h>
#include <gpio.h>
#include <stdio.h>

int main(void)
{
    int i;

    gpio_pin_t red_led = gpio_request_pin_by_name("PE9");
    gpio_pin_t blue_led = gpio_request_pin_by_name("PE8");
    gpio_pin_t orange_led = gpio_request_pin_by_name("PE10");
    gpio_pin_t green_led = gpio_request_pin_by_name("PE15");
    gpio_pin_t green2_led = gpio_request_pin_by_name("PE11");
    gpio_pin_t orange2_led = gpio_request_pin_by_name("PE14");
    gpio_pin_t blue2_led = gpio_request_pin_by_name("PE12");
    gpio_pin_t red2_led = gpio_request_pin_by_name("PE13");

    gpio_set_level(red_led, GPIO_LEVEL_HIGH);
    gpio_set_level(blue_led, GPIO_LEVEL_HIGH);
    gpio_set_level(orange_led, GPIO_LEVEL_HIGH);
    gpio_set_level(green_led, GPIO_LEVEL_HIGH);
    gpio_set_level(green2_led, GPIO_LEVEL_HIGH);
    gpio_set_level(orange2_led, GPIO_LEVEL_HIGH);
    gpio_set_level(blue2_led, GPIO_LEVEL_HIGH);
    gpio_set_level(red2_led, GPIO_LEVEL_HIGH);

    while (1) {
        delay_ms(1000);
        gpio_set_level(red_led, GPIO_LEVEL_LOW);
        gpio_set_level(blue_led, GPIO_LEVEL_LOW);
        gpio_set_level(orange_led, GPIO_LEVEL_LOW);
        gpio_set_level(green_led, GPIO_LEVEL_LOW);
        gpio_set_level(green2_led, GPIO_LEVEL_LOW);
        gpio_set_level(orange2_led, GPIO_LEVEL_LOW);
        gpio_set_level(blue2_led, GPIO_LEVEL_LOW);
        gpio_set_level(red2_led, GPIO_LEVEL_LOW);
        delay_ms(1000);
        gpio_set_level(red_led, GPIO_LEVEL_HIGH);
        gpio_set_level(blue_led, GPIO_LEVEL_HIGH);
        gpio_set_level(orange_led, GPIO_LEVEL_HIGH);
        gpio_set_level(green_led, GPIO_LEVEL_HIGH);
        gpio_set_level(green2_led, GPIO_LEVEL_HIGH);
        gpio_set_level(orange2_led, GPIO_LEVEL_HIGH);
        gpio_set_level(blue2_led, GPIO_LEVEL_HIGH);
        gpio_set_level(red2_led, GPIO_LEVEL_HIGH);
    }
}
