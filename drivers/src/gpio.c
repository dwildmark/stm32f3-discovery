/* *****************************************************************************
 * Copyright (c) 2017 Dennis Wildmark
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ****************************************************************************/

/*
 * Author(s): Dennis Wildmark <d.wildmark@gmail.com>
 */

#include <gpio.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h> 

#define MAX_PIN_NAME_LEN 10
#define MAX_NUM_GPIO_PINS 10

enum pin_request_state {
    AVAILABLE,
    REQUESTED,
};

enum gpio_bank_power_state {
    GPIO_BANK_DISABLED,
    GPIO_BANK_ENABLED,
};

enum gpio_bank_id {
    GPIO_A,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E,
    GPIO_F,
};

struct gpio_bank {
    enum gpio_bank_id id;
    enum gpio_bank_power_state state;
    uint32_t *bank_base;
    uint8_t rcc_bit;
};

struct gpio_pin {
    const char *name;
    uint8_t pin_in_bank;
    struct gpio_bank *bank;
    enum gpio_mode mode;
    enum gpio_output_mode out_mode;
    enum gpio_io_mode io_mode;
    enum pin_request_state rq_state;
};

static struct gpio_bank bank_list[] = {
    [GPIO_E] = {
        .id = GPIO_E,
        .state = GPIO_BANK_DISABLED,
        .bank_base = 0x48001000,
        .rcc_bit = 21,
    },
};

static struct gpio_pin pins[MAX_NUM_GPIO_PINS] = {
    {
        .name = "PE9",
        .pin_in_bank = 9,
        .bank = &bank_list[GPIO_E],
        .mode = GPIO_MODE_OUTPUT,
        .out_mode = GPIO_OP_MODE_PUSH_PULL,
        .io_mode = GPIO_IO_MODE_FLOATING,
        .rq_state = AVAILABLE,
    },
};

gpio_pin_t gpio_request_pin_by_name(const char *name)
{
    int i;
    struct gpio_pin *curr_pin;
    
    for (i = 0; i < MAX_NUM_GPIO_PINS; i++) {
        curr_pin = &pins[i];
        if (!strncmp(curr_pin->name, name, MAX_PIN_NAME_LEN) &&
            curr_pin->rq_state == AVAILABLE) {
            curr_pin->rq_state = REQUESTED;
            return curr_pin;
        }
    }

    return NULL;
}

int gpio_set_level(gpio_pin_t pin, enum gpio_level level)
{
    struct gpio_pin *in_pin = pin;
    volatile uint32_t *gpio_base;
    volatile uint32_t *gpio_oena;
    volatile uint32_t *gpio_bsrr_reg;
    volatile uint32_t *rcc_reg = (uint32_t *)0x40021014;

    if (NULL == in_pin || in_pin->rq_state != REQUESTED) {
        return -1;
    }

    if (in_pin->bank->state != GPIO_BANK_ENABLED) {
        *rcc_reg |= 1 << 21;
        in_pin->bank->state = GPIO_BANK_ENABLED;
    }

    gpio_base = in_pin->bank->bank_base;
    gpio_bsrr_reg = 0x48001018;

    *gpio_base = 1 << (in_pin->pin_in_bank * 2);

    if (GPIO_LEVEL_HIGH == level) {
        *gpio_bsrr_reg = 1 << in_pin->pin_in_bank;
    } else {
        *gpio_bsrr_reg = 1 << (in_pin->pin_in_bank + 16);
    }

    return 0;
}
    







