#include "xil_printf.h"
#include "sprite.h"
#include "animation.h"


int main(){
    //animation_diagonal(TOP_LEFT_TO_BOTTOM_RIGHT, uint8_t 10, uint8_t 20);

    //animation_bounce(MIX, uint8_t 80, uint8_t 60);

    //animation_rectangle();

    //animation_circle(uint8_t 80, uint8_t 60, uint8_t 10);

    dvd_bounce(uint8_t 80, uint8_t 60);
    return 0;
}   