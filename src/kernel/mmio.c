/**
 * mmio.h - Memory mapped IO implementation.
 * 
 * Copyright (c) 2024 Ajay Sreedhar.
 *
 * Licensed under GNU General Public License 3.0.
 * See LICENSE file located in the project root for more information.
 */

#include "mmio.h"

void mmio_write(long address, unsigned int value) {
    *((volatile unsigned int*) address) = value;
}

unsigned int mmio_read(long address) {
    return *((volatile unsigned int*) address);
}
