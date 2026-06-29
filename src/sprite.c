#include "sprite.h"

//so the the sprite controller has three parameters sprite_x, sprite_y and sprite_enable
//these three are connected to their corresponding AXI slaves
//By manipulating these parameters, the sprite positions are manipulated 

void sprite_enable(){
    Xil_Out32(SPRITE_BASE + SPRITE_EN_OFFSET, 1);
}

void sprite_disable(){
    Xil_Out32(SPRITE_BASE + SPRITE_EN_OFFSET, 0);
}

void sprite_setPos(unsigned int x, unsigned int y){
    Xil_Out32(SPRITE_BASE + SPRITE_X_OFFSET, x);
    Xil_Out32(SPRITE_BASE + SPRITE_Y_OFFSET , y);
}