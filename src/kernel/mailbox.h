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

enum {
    MBOX_REQUEST  = 0
};

enum {
    MBOX_CH_POWER = 0,
    MBOX_CH_FB    = 1,
    MBOX_CH_VUART = 2,
    MBOX_CH_VCHIQ = 3,
    MBOX_CH_LEDS  = 4,
    MBOX_CH_BTNS  = 5,
    MBOX_CH_TOUCH = 6,
    MBOX_CH_COUNT = 7,
    MBOX_CH_PROP  = 8 // Request from ARM for response by VideoCore
};

enum {
    MBOX_TAG_SETPOWER   = 0x28001,
    MBOX_TAG_SETCLKRATE = 0x38002,
    MBOX_TAG_SETPHYWH   = 0x48003,
    MBOX_TAG_SETVIRTWH  = 0x48004,
    MBOX_TAG_SETVIRTOFF = 0x48009,
    MBOX_TAG_SETDEPTH   = 0x48005,
    MBOX_TAG_SETPXLORDR = 0x48006,
    MBOX_TAG_GETFB      = 0x40001,
    MBOX_TAG_GETPITCH   = 0x40008,
    MBOX_TAG_LAST       = 0
};

extern volatile unsigned int mbuffer[36];

unsigned int mailbox_send(unsigned char);

#endif // VTRS_KERNEL_MAILBOX_H