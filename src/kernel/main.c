/**
 * main.c - Kernel main.
 * 
 * Copyright (c) 2024 Ajay Sreedhar.
 *
 * Licensed under GNU General Public License 3.0.
 * See LICENSE file located in the project root for more information.
 */

#include "video.h"

void main() {
    video_init();

    draw_rect(150,150,400,400,0x03,0);
    draw_rect(300,300,350,350,0x2e,1);

    while (1) {
        // Run infinite loop.
    }
}
