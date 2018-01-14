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

typedef void * gpio_pin_t;

enum gpio_level {
    GPIO_LEVEL_LOW = 0,
    GPIO_LEVEL_HIGH = 1,
    _INVALID_GPIO_LEVEL,
};

enum gpio_mode {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    _INVALID_GPIO_MODE,
};

enum gpio_output_mode {
    GPIO_OP_MODE_PUSH_PULL,
    GPIO_OP_MODE_OPEN_DRAIN,
    _INVALID_GPIO_OP_MODE,
};

enum gpio_io_mode {
    GPIO_IO_MODE_FLOATING,
    GPIO_IO_MODE_PULL_UP,
    GPIO_IO_MODE_PULL_DOWN,
    _INVALID_GPIO_IO_MODE,
};


gpio_pin_t gpio_request_pin_by_name(const char *name);

int
gpio_set_level(gpio_pin_t pin, enum gpio_level level);

enum gpio_level
gpio_get_level(gpio_pin_t pin);

void gpio_release_pin(gpio_pin_t pin);
