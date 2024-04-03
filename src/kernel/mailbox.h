/**
 * mailbox.h - ARM mailbox header.
 * 
 * Copyright (c) 2024 Ajay Sreedhar.
 *
 * Licensed under GNU General Public License 3.0.
 * See LICENSE file located in the project root for more information.
 */

#ifndef VTRS_KERNEL_MAILBOX_H
#define VTRS_KERNEL_MAILBOX_H 1

#include "mmio.h"

enum {
    VIDEOCORE_MBOX_ADDR = (PERIPHERAL_BASE_ADDR + 0x0000B880),
    MBOX_STATUS_REG = (VIDEOCORE_MBOX_ADDR + 0x18),
    MBOX_WRITE_REG = (VIDEOCORE_MBOX_ADDR + 0x20),
    MBOX_EMPTY_FLAG = 0x40000000,
    MBOX_FULL_FLAG = 0x80000000,
    MBOX_RESPONSE_FLAG = MBOX_FULL_FLAG
};

unsigned int mailbox_send(unsigned char);

#endif // VTRS_KERNEL_MAILBOX_H