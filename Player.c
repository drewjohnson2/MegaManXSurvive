//
//  Player.c
//  Game
//
//  Created by Drew Johnson on 1/17/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#include "Player.h"
#include "Game.h"

void moveCharacterRight(GameState *gameState)
{
    //gameState->player.x += 10;
    
    gameState->player.dx += 0.5;
    if(gameState->player.dx > 6)
    {
        gameState->player.dx = 6;
    }
    //gameState->player.facingLeft = 0;
    gameState->player.slowingDown = 0;
    
}

void moveCharacterLeft(GameState *gameState)
{
    //gameState->player.x -= 10;
    
    gameState->player.dx -= 0.5;
    if(gameState->player.dx < -6)
    {
        gameState->player.dx = -6;
    }
    //gameState->player.facingLeft = 1;
    gameState->player.slowingDown = 0;
}

void moveCharacterUp(GameState *gameState)
{
    gameState->player.y -= 10;
}
void moveCharacterDown(GameState *gameState)
{
    gameState->player.y += 10;
}
