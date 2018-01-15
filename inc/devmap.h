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

#ifndef DEVMAP_H
#define DEVMAP_H

#include <stdint.h>

#define _RO const volatile
#define _WO volatile
#define _RW volatile

struct ST_GPIO {
    _RW uint32_t MODER;
    _RW uint32_t OTYPER;
    _RW uint32_t OSPEEDR;
    _RW uint32_t PUPDR;
    _RO uint32_t IDR;
    _RW uint32_t ODR;
    _WO uint32_t BSRR;
    _RW uint32_t LCKR;
    _RW uint32_t AFRL;
    _RW uint32_t AFRH;
    _WO uint32_t BRR;
};



#endif /* DEVMAP_H */
