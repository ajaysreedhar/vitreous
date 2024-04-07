#include "video.h"

void main() {
    video_init();

    draw_rect(150,150,400,400,0x03,0);
    draw_rect(300,300,350,350,0x2e,1);

    while (1) {
        // Run infinite loop.
    }
}
