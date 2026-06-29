#ifndef ANIMATION_H
#define ANIMATION_H

//screen positions 
#include <stdint.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 120

#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 8

#define ANIMATION_DELAY 500000

typedef struct{
    int16_t x;
    int16_t y;

    int8_t dx;
    int8_t dy;
} Sprite;

//for diagonal
typedef enum{
    TOP_LEFT_TO_BOTTOM_RIGHT,
    TOP_RIGHT_TO_BOTTOM_LEFT,
    BOTTOM_LEFT_TO_TOP_RIGHT,
    BOTTOM_RIGHT_TO_TOP_LEFT
} diagonalDirection;

//for bounce
typedef enum{
    HORIZONTAL,
    VERTICAL,
    MIX
} bounceDir;

//for rectangle
typedef enum{
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_UP
}rectangleState;


void animationDelay(uint32_t delay_val);

void animation_diagonal(diagonalDirection dir, uint8_t startX, uint8_t startY);
void animation_bounce(bounceDir dir, uint8_t startX, uint8_t startY);
void animation_rectangle(void);
void animation_circle(uint8_t centreX, uint8_t centreY, uint8_t radius);
void dvd_bounce(uint8_t startX, uint8_t startY);

#endif