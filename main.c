#include <FaNES.h>
#include "imageLeft.h"
#include "imageRight.h"

const uchar palette[16] = {
    0x11, 0x00, 0x10, 0x30,
    0x01, 0x21, 0x31, 0x30,
    0x06, 0x16, 0x26, 0x36,
    0x0A, 0x09, 0x19, 0x29
};

static uint topScrollX, topScrollY;
static int topSpeedHorizontal, topSpeedVertical;

int main(void) {
    setPaletteBackground(palette);
    unpackNametableRLE(imageLeft, NAMETABLE_A);
    unpackNametableRLE(imageRight, NAMETABLE_D);
    onGraphics();
    while(TRUE) {
        uchar pad = padPush(PAD_PORT__1);
        if(pad & PAD_BUTTON_LEFT) --topSpeedHorizontal;
        if(pad & PAD_BUTTON_RIGHT) ++topSpeedHorizontal;
        if(pad & PAD_BUTTON_UP) --topSpeedVertical;
        if(pad & PAD_BUTTON_DOWN) ++topSpeedVertical;
        topScrollX += topSpeedHorizontal;
        topScrollY += topSpeedVertical;
        setBackgroundScrollI(topScrollX, topScrollY);
        waitFrame();
    }
}
