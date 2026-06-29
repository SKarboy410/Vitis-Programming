#include "xil_printf.h"
#include "sprite.h"


int main(){
    int x = 0;
    int y = 10;

    sprite_enable();
    
    while(1){
        sprite_setPos(x,y);
        
        x++;
        y++;
        
        if(x>159)
            x=0;
        
        if(x>119)
            y=0;
        
        for (volatile int i = 0; i < 500000; i++);

    }
    return 0;
}   