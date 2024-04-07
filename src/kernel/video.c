#include "mailbox.h"
#include "video.h"

unsigned int width, height, pitch, isrgb;
unsigned char* fb;

unsigned int vgapal[] = {
    0x000000,
    0x0000AA,
    0x00AA00,
    0x00AAAA,
    0xAA0000,
    0xAA00AA,
    0xAA5500,
    0xAAAAAA,
    0x555555,
    0x5555FF,
    0x55FF55,
    0x55FFFF,
    0xFF5555,
    0xFF55FF,
    0xFFFF55,
    0xFFFFFF
};

void video_init() {
    mbuffer[0] = 35*4; // Length of message in bytes
    mbuffer[1] = MBOX_REQUEST;

    mbuffer[2] = MBOX_TAG_SETPHYWH; // Tag identifier
    mbuffer[3] = 8; // Value size in bytes
    mbuffer[4] = 0;
    mbuffer[5] = 1920; // Value(width)
    mbuffer[6] = 1080; // Value(height)

    mbuffer[7] = MBOX_TAG_SETVIRTWH;
    mbuffer[8] = 8;
    mbuffer[9] = 8;
    mbuffer[10] = 1920;
    mbuffer[11] = 1080;

    mbuffer[12] = MBOX_TAG_SETVIRTOFF;
    mbuffer[13] = 8;
    mbuffer[14] = 8;
    mbuffer[15] = 0; // Value(x)
    mbuffer[16] = 0; // Value(y)

    mbuffer[17] = MBOX_TAG_SETDEPTH;
    mbuffer[18] = 4;
    mbuffer[19] = 4;
    mbuffer[20] = 32; // Bits per pixel

    mbuffer[21] = MBOX_TAG_SETPXLORDR;
    mbuffer[22] = 4;
    mbuffer[23] = 4;
    mbuffer[24] = 1; // RGB

    mbuffer[25] = MBOX_TAG_GETFB;
    mbuffer[26] = 8;
    mbuffer[27] = 8;
    mbuffer[28] = 4096; // FrameBufferInfo.pointer
    mbuffer[29] = 0;    // FrameBufferInfo.size

    mbuffer[30] = MBOX_TAG_GETPITCH;
    mbuffer[31] = 4;
    mbuffer[32] = 4;
    mbuffer[33] = 0; // Bytes per line

    mbuffer[34] = MBOX_TAG_LAST;

    if (mailbox_send(MBOX_CH_PROP) && mbuffer[20] == 32 && mbuffer[28] != 0) {
        mbuffer[28] &= 0x3FFFFFFF; // Convert GPU address to ARM address
        width = mbuffer[10];       // Actual physical width
        height = mbuffer[11];      // Actual physical height
        pitch = mbuffer[33];       // Number of bytes per line
        isrgb = mbuffer[24];       // Pixel order
        fb = (unsigned char *)((long)mbuffer[28]);
    }
}

void draw_pixel(int x, int y, unsigned char attr) {
    int offs = (y * pitch) + (x * 4);
    *((unsigned int*)(fb + offs)) = vgapal[attr & 0x0f];
}

void draw_rect(int x1, int y1, int x2, int y2, unsigned char attr, int fill) {
    int y=y1;

    while (y <= y2) {
       int x=x1;
       while (x <= x2) {
	  if ((x == x1 || x == x2) || (y == y1 || y == y2)) draw_pixel(x, y, attr);
	  else if (fill) draw_pixel(x, y, (attr & 0xf0) >> 4);
          x++;
       }
       y++;
    }
}
