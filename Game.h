//
//  Game.h
//  Game
//
//  Created by Drew Johnson on 1/16/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "Characters.h"
#include "Environment.h"

#define WIDTH 1000
#define HEIGHT 1000
#define GRAVITY 1.0f

SDL_Event event;       // Event Variable
SDL_Renderer *render;
SDL_Window * window;   // Window Variable

typedef struct
{
    Character player;
    Floor floor;
    
    // Game images
    SDL_Texture *playerTextures[12];
    SDL_Texture *leftTextures[12];
    SDL_Texture *jumpTextures[4];
    SDL_Texture *jumpLTextures[4];
    SDL_Texture *floorTexture;
    
    
    // Renderer for game images
    SDL_Renderer *gsRender;
    
    int time;
    
} GameState;

bool init(GameState *);
void cleanUp(GameState *);
void run(GameState *);
void drawScreen(void);

void renderScreen(SDL_Renderer *, GameState *);


#endif /* Game_h */
