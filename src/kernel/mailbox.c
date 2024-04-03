/**
 * mailbox.h - Mailbox function implementation.
 * 
 * Copyright (c) 2024 Ajay Sreedhar.
 *
 * Licensed under GNU General Public License 3.0.
 * See LICENSE file located in the project root for more information.
 */

#include "mmio.h"
#include "mailbox.h"

volatile unsigned int __attribute__ ((aligned(16))) mbuffer[36];

unsigned int mailbox_send(unsigned char value) {
    unsigned int reg = ((unsigned int)((long) &mbuffer) & ~0xF) | (value & 0xF);

    while (mmio_read(MBOX_STATUS_REG) & MBOX_FULL_FLAG) {
        /* Wait until mailbox is available to write. */
    }

    mmio_write(MBOX_WRITE_REG, reg);

    while (1) {
        while (mmio_read(MBOX_STATUS_REG) & MBOX_EMPTY_FLAG) {
            /* Wait for reply. */
        }

        if (reg == mmio_read(VIDEOCORE_MBOX_ADDR)) {
            return mbuffer[1] == MBOX_RESPONSE_FLAG;
        }
    }

    return 0;
}
