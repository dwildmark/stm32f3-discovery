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

#include <devmap.h>
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
    uint8_t rcc_bit;
    struct ST_GPIO *gpio_base;
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
        .rcc_bit = 21,
        .gpio_base = (struct ST_GPIO *)0x48001000,
    },
};

static struct gpio_pin pins[MAX_NUM_GPIO_PINS] = {
    {"PE9", 9, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE8", 8, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE10", 10, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE11", 11, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE12", 12, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE13", 13, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE14", 14, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
    {"PE15", 15, &bank_list[GPIO_E], GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_FLOATING, AVAILABLE},
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
    struct ST_GPIO *gpio_base = in_pin->bank->gpio_base;
    volatile uint32_t *rcc_reg = (uint32_t *)0x40021014;

    if (NULL == in_pin || in_pin->rq_state != REQUESTED) {
        return -1;
    }

    if (in_pin->bank->state != GPIO_BANK_ENABLED) {
        *rcc_reg |= 1 << in_pin->bank->rcc_bit;
        in_pin->bank->state = GPIO_BANK_ENABLED;
    }

    gpio_base->MODER |= 1 << (in_pin->pin_in_bank * 2);

    if (GPIO_LEVEL_HIGH == level) {
        gpio_base->BSRR = 1 << in_pin->pin_in_bank;
    } else {
        gpio_base->BSRR = 1 << (in_pin->pin_in_bank + 16);
    }

    return 0;
}
    







