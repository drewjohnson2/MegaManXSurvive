//
//  Physics.h
//  Game
//
//  Created by Drew Johnson on 1/19/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#ifndef Physics_h
#define Physics_h

#define DASH_SLOWDOWN_RATE 0.8f
#define MAX_JUMP_LOCATION 450

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <time.h>
#include "Game.h"
#include "Environment.h"

void processEvents(GameState *, bool *);
void processMovement(GameState *);

#endif /* Physics_h */
