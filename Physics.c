//
//  Physics.c
//  Game
//
//  Created by Drew Johnson on 1/19/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <time.h>
#include "Game.h"
#include "Environment.h"
#include "Physics.h"

//---------------------------------------------------
void processEvents(GameState *gameState, bool *running)
{
    gameState->time++;
    
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            *running = false;
            break;
        }
        
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        
        if(!gameState->player.jumping)
        {
            if(state[SDL_SCANCODE_S])
            {
                if(gameState->player.y >= 485)
                {
                    gameState->player.dy = -15;
                    gameState->player.jumping = 1;
                    gameState->player.jumpAnimFrame = 0;
                }
                
                else
                { 
                    gameState->player.dy += GRAVITY;
                }
            }
        }
        
        if(state[SDL_SCANCODE_D] && !gameState->player.jumping && !gameState->player.dash)
        {
            if(gameState->player.facingLeft) gameState->player.dx = -20;
            
            else gameState->player.dx = 24;
            
            gameState->player.dash = 1;
        }
        
        //Walking
        if(state[SDL_SCANCODE_LEFT] && !gameState->player.dash)
        {
            gameState->player.facingLeft = 1;
            gameState->player.dx = -4.9;
        }
        
        else if(state[SDL_SCANCODE_RIGHT] && !gameState->player.dash)
        {
            gameState->player.facingLeft = 0;
            gameState->player.dx = 4.9;
            
        }
        
        // Resets animation frame and stops character from moving
        else if(!(state[SDL_SCANCODE_LEFT]) && !(state[SDL_SCANCODE_RIGHT]) && !gameState->player.jumping && !(state[SDL_SCANCODE_S])
                && !(state[SDL_SCANCODE_D]))
        {
            gameState->player.animFrame = 0;
            gameState->player.dx = 0;
            
        }
        
        else if(!(state[SDL_SCANCODE_S]) && gameState->player.dy < 0 && !gameState->player.dash)
        {
            gameState->player.dy = 0;
            gameState->player.falling = 1;
            gameState->player.dx = 0;
        }
        
        else
        {
            if(!gameState->player.dash)
                gameState->player.dx = 0;

        }
        
    }
    
}

//---------------------------------------------------
void processMovement(GameState *gameState)
{
    //add time
    gameState->time++;
    
    //man movement
    Character *player = &gameState->player;
    
    player->x += player->dx;
    player->y += player->dy;
    
    if(player->dx != 0 && !player->jumping && !player->dash)
    {
        if(gameState->time % 6 == 0)
        {
            if(player->animFrame == 0)
            {
                player->animFrame = 1;
            }
            
            else if(player->animFrame == 1)
            {
                player->animFrame = 2;
            }
            
            else if(player->animFrame == 2)
            {
                player->animFrame = 3;
            }
            
            else if(player->animFrame == 3)
            {
                player->animFrame = 4;
            }
            
            else if(player->animFrame == 4)
            {
                player->animFrame = 5;
            }
            
            else if(player->animFrame == 5)
            {
                player->animFrame = 6;
            }
            
            else if(player->animFrame == 6)
            {
                player->animFrame = 7;
            }
            
            else if(player->animFrame == 7)
            {
                player->animFrame = 8;
            }
            
            else if(player->animFrame == 8)
            {
                player->animFrame = 9;
            }
            
            else if(player->animFrame == 9)
            {
                player->animFrame = 10;
            }
            
            else if(player->animFrame == 10)
            {
                player->animFrame = 11;
            }
            
            else if(player->animFrame == 11)
            {
                player->animFrame = 2;
            }
            
            else
            {
                player->animFrame = 0;
            }
            
        }
    }
    
    else if(player->jumping)
    {
        if(player->dash)
        {
            if(player->dx > 0 && !player->facingLeft)
            {
                player->dx -= DASH_SLOWDOWN_RATE;
                
            }
            
            else if(player->dx < 0 && player->facingLeft)
            {
                player->dx += DASH_SLOWDOWN_RATE;
            }
            
            else if(player->dx == 0 && !player->jumping)
            {
                player->dash = 0;
            }
            
        }
        
        if(gameState->time % 4 == 0 && player->dy < 0 && player->y > 460)
        {
            player->jumpAnimFrame = 0;
        }
        
        else if(gameState->time % 4 == 0 && player->dy < 0 && player->y < 480)
        {
            player->jumpAnimFrame = 1;
        }
        
        else if(gameState->time % 4 == 0 && player->dy > 0 && player->y < 480 && player->dy < 15)
        {
            player->jumpAnimFrame = 2;
        }
        
        else if(gameState->time % 4 == 0 && player->dy > 0  && player->dy >=15)
        {
            player->jumpAnimFrame = 3;
        }
    }
    
    else if(player->dash)
    {
        if(player->dx > 0 && !player->facingLeft)
        {
            if(player->dx >= 24 || player->dx <= 6)
            {
                gameState->player.animFrame = 0;
            }
            
            else
            {
                gameState->player.animFrame = 1;
            }
            
            player->dx -= DASH_SLOWDOWN_RATE;
        }
        
        else if(player->dx < 0 && player->facingLeft)
        {
            if(player->dx <= -24 || player->dx >= -6)
            {
                gameState->player.animFrame = 0;
            }

            else
            {
                gameState->player.animFrame = 1;
            }

            player->dx += DASH_SLOWDOWN_RATE;
        }
        
        else if(player->dx >= 0 && !player->jumping && player->facingLeft)
        {
            player->dash = 0;
            player->dx = 0;
        }
        
        else if(player->dx <= 0 && !player->jumping && !player->facingLeft)
        {
            player->dash = 0;
            player->dx = 0;
        }
        
    }
    
    if(player->y <= MAX_JUMP_LOCATION)
    {
        player->falling = 1;
    }
    
    if(player->falling)
    {
        player->dy += GRAVITY;
        
        if(player->y >= 484)
        {
            player->y = 485;
            player->dy = 0;
            player->falling = 0;
            player->jumping = 0;
            player->animFrame = 0;
            player->jumpAnimFrame = 3;
        }
    }
    
}
//---------------------------------------------------









