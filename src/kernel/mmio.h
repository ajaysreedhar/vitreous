/**
 * mmio.h - Memory mapped IO header.
 * 
 * Copyright (c) 2024 Ajay Sreedhar.
 *
 * Licensed under GNU General Public License 3.0.
 * See LICENSE file located in the project root for more information.
 */

#ifndef VTRS_KERNEL_MMIO_H
#define VTRS_KERNEL_MMIO_H 1

#define PERIPHERAL_BASE_ADDR 0x0000B880

void mmio_write(long, unsigned int);
unsigned int mmio_read(long);

#endif // VTRS_KERNEL_MMIO_H
