//
//  Characters.h
//  Game
//
//  Created by Drew Johnson on 1/18/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#ifndef Characters_h
#define Characters_h

#include <SDL2/SDL.h>

typedef struct
{
    float x, y;
    float dx, dy;
    short health;
    
    int animFrame, slowingDown, falling, facingLeft, jumping, jumpAnimFrame;
    
} Character;


#endif /* Characters_h */
