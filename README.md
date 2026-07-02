
## Application Code for the previous FPGA SoC Project

This repository contains some application code the previous project. In my project, the processor can control the position and visibility of the sprite. So that is exactly what I have done here. I used C in Vitis to write programs for the SoC.

Let me explain all the files I wrote.

### Sprite(sprite.c and sprite.h)

So the CPU can control 3 pararmeters: *sprite_x, sprite_y* and *sprite_enable*. All these values are stored at the address **XPAR_SPRITE_CONTROLLER_0_BASEADDR**(Named as **SPRITE_BASE**). So at position '**XPAR_SPRITE_CONTROLLER_0_BASEADDR + 0x00**' sprite_*x is stored, at '*XPAR_SPRITE_CONTROLLER_0_BASEADDR + 0x04*' sprite_y is stored and at '**XPAR_SPRITE_CONTROLLER_0_BASEADDR + 0x08**' **** is stored. We can write values to these addresses to get various functionality. This is depicted in 'sprite.c', where the default xilinix function *Xil_Out32* is used to write to these addresses. 

### Animation(animation.c and animation.h)

Now that we can control the positions, we can use math to get various shapes. I am not going to explain the maths behind each shape cause is is pretty basic(you can look it up). The animations I have implemented are:

Diagonal Movement - Set the direction and start points and enjoy the sweet diagonal movements

Bounce - Set the direction and start points and BOUNCE

 Rectangle - No customization here, this is just a state machine which checks the boundary conditions for a rectangle of a specific area and moves

Circle - Set the center and radius and using the magic of parametric equation: circle 

DVD Bounce - This just detects the edge of the screen(with some conditions) and reverses its velocity

I couldn't actually test this on actual hardware, hopefully someday I will. But yes that's some experimentation I did in Vitis.
