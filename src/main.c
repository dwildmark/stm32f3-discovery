#include <stdio.h>
#include <gpio.h>

static void nops(unsigned nofnops)
{
    int i;
    for (i = 0; i < nofnops; i++) {
        __asm volatile ("NOP");
    }
}

int main(void)
{
    int i;
    uint32_t status;

    gpio_pin_t pe9 = gpio_request_pin_by_name("PE9");

    gpio_set_level(pe9, GPIO_LEVEL_HIGH);

    while (1) {
        nops(10000000);
        gpio_set_level(pe9, GPIO_LEVEL_LOW);
        nops(10000000);
        gpio_set_level(pe9, GPIO_LEVEL_HIGH);
    }
}
