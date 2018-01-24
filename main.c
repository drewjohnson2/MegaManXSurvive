//
//  main.c
//  Game
//
//  Created by Drew Johnson on 1/15/18.
//  Copyright © 2018 Drew Johnson. All rights reserved.
//

#include <stdio.h>
#include "Game.h"

//typedef struct
//{
//    int x, y;
//    short life;
//    char * name;
//
//} Player;


int main(int argc, const char * argv[])
{
    GameState gameState;
    
    // Run the main game loop
    run(&gameState);
    
    // Closes renderer, window, quits SDL
    cleanUp(&gameState);
    
    return 0;
}
