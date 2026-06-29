#ifndef SPRITE_H
#define SPRITE_H

#include "xparameters.h"
#include <xil_io.h>

#define SPRITE_BASE XPAR_SPRITE_CONTROLLER_0_BASEADDR

//positions w.r.t SPRITE_BASE
#define SPRITE_X_OFFSET 0x00
#define SPRITE_Y_OFFSET 0x04
#define SPRITE_EN_OFFSET 0x08

void sprite_enable(void);
void sprite_disable(void);
void sprite_setPos(unsigned int x, unsigned int y);

#endif