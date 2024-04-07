#ifndef VTRS_KERNEL_VIDEO_H
#define VTRS_KERNEL_VIDEO_H 1

void video_init();
void draw_pixel(int x, int y, unsigned char attr);
void draw_rect(int x1, int y1, int x2, int y2, unsigned char attr, int fill);

#endif // VTRS_KERNEL_VIDEO_H