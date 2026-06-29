#include "sprite.h"
#include "animation.h"

#include <math.h>
#include <stdint.h>


void animationDelay(uint32_t delay_val){
    for (volatile uint32_t i = 0; i < delay_val; i++);
}

void animation_diagonal(diagonalDirection dir, uint8_t startX, uint8_t startY){
    Sprite sprite = {.x = startX, .y = startY};

    sprite_enable();

    switch (dir){
        case TOP_LEFT_TO_BOTTOM_RIGHT:
            sprite.dx = 1;
            sprite.dy = 1;
            break;

        case TOP_RIGHT_TO_BOTTOM_LEFT:
            sprite.dx = -1;
            sprite.dy = 1;
            break;

        case BOTTOM_LEFT_TO_TOP_RIGHT:
            sprite.dx = 1;
            sprite.dy = -1;
            break;

        case BOTTOM_RIGHT_TO_TOP_LEFT:
            sprite.dx = -1;
            sprite.dy = -1;
            break;
        }

    while(1){
        sprite_setPos(sprite.x, sprite.y);

            sprite.x += sprite.dx;
            sprite.y += sprite.dy;
            
            if (sprite.x >= SCREEN_WIDTH)
                sprite.x = 0;

            if (sprite.x < 0)
                sprite.x = SCREEN_WIDTH - 1;

            if (sprite.y >= SCREEN_HEIGHT)
                sprite.y = 0;

            if (sprite.y < 0)
                sprite.y = SCREEN_HEIGHT - 1;
        
        animationDelay(ANIMATION_DELAY);
    }
    
}

void animation_bounce(bounceDir dir, uint8_t startX, uint8_t startY){
    Sprite sprite = {.x = startX, .y = startY, .dx = 1, .dy = 1};
    
    sprite_enable();

    while(1){
        sprite_setPos(sprite.x,sprite.y);

        switch (dir) {
            case HORIZONTAL:
                 sprite.x += sprite.dx;
                 if (sprite.x >= SCREEN_WIDTH - 1 || sprite.x <= 0)
                    sprite.dx = -sprite.dx;
                break;
            case VERTICAL:
                sprite.y += sprite.dy;
                if (sprite.y >= SCREEN_HEIGHT - 1 || sprite.y <= 0)
                    sprite.dy = -sprite.dy; 
                break;
            case MIX:
                sprite.x += sprite.dx;
                sprite.y += sprite.dy;

                if (sprite.x >= SCREEN_WIDTH - 1 || sprite.x <= 0)
                    sprite.dx = -sprite.dx;

                if (sprite.y >= SCREEN_HEIGHT - 1 || sprite.y <= 0)
                    sprite.dy = -sprite.dy;
                break;
        }
    
  
        animationDelay(ANIMATION_DELAY);
    }
    
}

void animation_rectangle(void){
    Sprite sprite = {.x = 20, .y = 20};

        static const uint8_t RIGHT_BOUND = 140;
        static const uint8_t LEFT_BOUND = 20;
        static const uint8_t TOP_BOUND = 20;
        static const uint8_t BOTTOM_BOUND = 100;

    rectangleState state = MOVE_RIGHT;
    
    sprite_enable();
    
    while(1){
        sprite_setPos(sprite.x, sprite.y);

        switch(state){
            case MOVE_RIGHT:
                sprite.x++;

                if(sprite.x >= RIGHT_BOUND)
                    state = MOVE_DOWN;
                break;
            case MOVE_DOWN:
                sprite.y++;

                if(sprite.y >= BOTTOM_BOUND)
                    state = MOVE_LEFT;
                break;
            case MOVE_LEFT:
                sprite.x--;

                if(sprite.x <= LEFT_BOUND)
                    state = MOVE_UP;
                break;
            case MOVE_UP:
                sprite.y--;

                if(sprite.y <= TOP_BOUND)
                    state = MOVE_RIGHT;
                break;
            
        }

        animationDelay(ANIMATION_DELAY);
    }
}


void animation_circle(uint8_t centreX, uint8_t centreY, uint8_t radius){
    Sprite sprite = {.x = centreX + radius, .y = centreY};

    float angle = 0;
    sprite_enable();

    while(1){
        //parametric equations
        sprite.x = centreX + radius * cos(angle);
        sprite.y = centreY + radius * sin(angle);

        if(angle >= 2*M_PI)
            angle = 0;
        else
            angle+=0.1;


        sprite_setPos(sprite.x, sprite.y);
        animationDelay(ANIMATION_DELAY);
    }
}

void dvd_bounce(uint8_t startX, uint8_t startY){
    Sprite sprite = {.x = startX, .y = startY, .dx = 1, .dy = 1}; 
    
    sprite_enable();

    while(1){
        sprite.x+=sprite.dx;
        sprite.y+=sprite.dy;

        
        if (sprite.x >= SCREEN_WIDTH-SPRITE_WIDTH){
            sprite.dx = -sprite.dx;
            sprite.x = SCREEN_WIDTH-SPRITE_WIDTH;
        }
        if(sprite.x <= 0){
            sprite.dx = -sprite.dx;
            sprite.x = 0;
        }
        if(sprite.y >= SCREEN_HEIGHT-SPRITE_HEIGHT){
            sprite.dy = -sprite.dy;
            sprite.y = SCREEN_HEIGHT - SPRITE_HEIGHT;
        }
        if(sprite.y <= 0){
            sprite.dy = -sprite.dy;
            sprite.y = 0;
        }

        sprite_setPos(sprite.x, sprite.y);
        

        animationDelay(ANIMATION_DELAY);
    }
}