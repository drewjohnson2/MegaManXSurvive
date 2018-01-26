//
//  Game.c
//  Game
//
//  Created by Drew Johnson on 1/16/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <time.h>
#include "Game.h"
#include "Environment.h"
#include "Physics.h"


//---------------------------------------------------
bool init(GameState *gameState)
{
    bool success = true;
    SDL_Surface *surface = NULL;  // Initialize surface for character
    
    // Initialize window
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("An error occurred initializing SDL. ");
        success = false;
    }
    
    else
    {
        // Creates Window
        window = SDL_CreateWindow("Mega Man X: Survival",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  WIDTH,
                                  HEIGHT,
                                  SDL_WINDOW_OPENGL);
        
        // Create renderer for the screen
        render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        // Set GameState renderer equal to window renderer
        gameState->gsRender = render;
        
        if(window == NULL || render == NULL || gameState->gsRender == NULL)
        {
            printf("An error occured loading window. ");
            success = false;
        }
        
    }
    
    /*--------------------------------------------------
     
    
     
                    Load Character images
     
     
     
    ---------------------------------------------------*/
    
    //                     //
    // Right facing images //
    //                     //
    
    surface = IMG_Load("images/movingright/mega0.png");
    
    gameState->playerTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega1.png");
    
    gameState->playerTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega2.png");
    
    gameState->playerTextures[2] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega3.png");
    
    gameState->playerTextures[3] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega4.png");
 
    gameState->playerTextures[4] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega5.png");

    gameState->playerTextures[5] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega6.png");
    
    gameState->playerTextures[6] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega7.png");

    gameState->playerTextures[7] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega8.png");

    gameState->playerTextures[8] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega9.png");

    gameState->playerTextures[9] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega10.png");

    gameState->playerTextures[10] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingright/mega11.png");
    
    gameState->playerTextures[11] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    //                    //
    // Left facing images //
    //                    //

    surface = IMG_Load("images/movingleft/mega0.png");

    gameState->leftTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega1.png");

    gameState->leftTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega2.png");

    gameState->leftTextures[2] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega3.png");

    gameState->leftTextures[3] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega4.png");

    gameState->leftTextures[4] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega5.png");

    gameState->leftTextures[5] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega6.png");

    gameState->leftTextures[6] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega7.png");

    gameState->leftTextures[7] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega8.png");

    gameState->leftTextures[8] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega9.png");

    gameState->leftTextures[9] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/movingleft/mega10.png");

    gameState->leftTextures[10] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/movingleft/mega11.png");
    
    gameState->leftTextures[11] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    
    //                  //
    // Load Jump images //
    //                  //
    
    surface = IMG_Load("images/jump/jump0.png");

    gameState->jumpTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/jump/jump1.png");
    
    gameState->jumpTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("images/jump/jump2.png");

    gameState->jumpTextures[2] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/jump/jump3.png");
    
    gameState->jumpTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    // Left facing jump
    
    surface = IMG_Load("images/jump/jump0.png");
    
    gameState->jumpLTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/jump/jump1l.png");
    
    gameState->jumpLTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/jump/jump2l.png");
    
    gameState->jumpLTextures[2] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/jump/jump3l.png");
    
    gameState->jumpLTextures[3] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);

    //                  //
    // Load dash images //
    //                  //
    
    surface = IMG_Load("images/dashright/dash00.png");
    
    gameState->dashTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/dashright/dash01.png");
    
    gameState->dashTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    // Left facing dash
    
    surface = IMG_Load("images/dashleft/dash00.png");
    
    gameState->dashLTextures[0] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("images/dashleft/dash01.png");
    
    gameState->dashLTextures[1] = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    /*--------------------------------------------------
     
     
     
                End Load Character images
     
     
     
     ---------------------------------------------------*/
    
    // Initialize starting position
    gameState->player.x = 50;
    gameState->player.y = 503;
    gameState->player.dx = 0;
    gameState->player.dy = 0;
    gameState->player.facingLeft = 0;
    
    surface = IMG_Load("floor.png");
    
    gameState->floorTexture = SDL_CreateTextureFromSurface(gameState->gsRender, surface);
    SDL_FreeSurface(surface);
    
    gameState->floor.x = 0;
    gameState->floor.y = 600;
    gameState->floor.w = 1000;
    gameState->floor.h = 300;
    
    return success;
}

//---------------------------------------------------
void run(GameState *gameState)
{
    
    if(init(gameState))
    {
        bool running = true;
        
        // Loop reading events
        while(running)
        {
            processEvents(gameState, &running);
            processMovement(gameState);
            renderScreen(render, gameState);
            
        }
    }
}

//---------------------------------------------------
void renderScreen(SDL_Renderer *render, GameState *gameState)
{
    // Set background color
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    SDL_RenderClear(render);
    int height = 100, width = 100;
    
    // Draw floor
    SDL_Rect floorRect = {gameState->floor.x, gameState->floor.y, gameState->floor.w, gameState->floor.h};
    SDL_RenderCopy(render, gameState->floorTexture, NULL, &floorRect);
    
    if(gameState->player.jumping && gameState->player.dash)
    {
        height = 120;
        width = 85;
    }
    
    else if(gameState->player.dash && !gameState->player.jumping)
    {
        height = 92;
        width = 100;
    }
    
    SDL_Rect rect = {gameState->player.x, gameState->player.y , width, height};
    
    if(!gameState->player.facingLeft && !gameState->player.jumping && !gameState->player.dash)
    {
        SDL_RenderCopyEx(render, gameState->playerTextures[gameState->player.animFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else if(gameState->player.facingLeft && !gameState->player.jumping && !gameState->player.dash)
    {
        SDL_RenderCopyEx(render, gameState->leftTextures[gameState->player.animFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else if (gameState->player.jumping && !gameState->player.facingLeft)
    {
        SDL_RenderCopyEx(render, gameState->jumpTextures[gameState->player.jumpAnimFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else if (gameState->player.jumping && gameState->player.facingLeft)
    {
        SDL_RenderCopyEx(render, gameState->jumpLTextures[gameState->player.jumpAnimFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else if(gameState->player.dash && !gameState->player.jumping && !gameState->player.facingLeft)
    {
        SDL_RenderCopyEx(render, gameState->dashTextures[gameState->player.animFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else if(gameState->player.dash && !gameState->player.jumping && gameState->player.facingLeft)
    {
        SDL_RenderCopyEx(render, gameState->dashLTextures[gameState->player.animFrame], NULL, &rect, 0, NULL, 0);
    }
    
    else
    {
        SDL_RenderCopyEx(render, gameState->playerTextures[0], NULL, &rect, 0, NULL, 0);
    }

    
    // Display images
    SDL_RenderPresent(render);
}

//---------------------------------------------------
void cleanUp(GameState *gameState)
{
    for(int i = 0; i < 12; i++)
    {
        SDL_DestroyTexture(gameState->playerTextures[i]);
        SDL_DestroyTexture(gameState->leftTextures[i]);
    }
    
    for(int i = 0; i < 4; i++)
    {
        SDL_DestroyTexture(gameState->jumpTextures[i]);
        SDL_DestroyTexture(gameState->jumpLTextures[i]);
    }
    
    for(int i = 0; i < 2; i++)
    {
        SDL_DestroyTexture(gameState->dashTextures[i]);
        SDL_DestroyTexture(gameState->dashLTextures[i]);
    }
    
    
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}










