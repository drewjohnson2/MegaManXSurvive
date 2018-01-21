//
//  Player.h
//  Game
//
//  Created by Drew Johnson on 1/17/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Characters.h"
#include "Game.h"

void moveCharacterRight(GameState *);
void moveCharacterLeft(GameState *);
void moveCharacterUp(GameState *);
void moveCharacterDown(GameState *);

#endif /* Player_h */
