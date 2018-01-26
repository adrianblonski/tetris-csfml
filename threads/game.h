#ifndef game_H
#define game_H

#include <stdio.h>
#include <unistd.h>
#include "../gfx/map.h"

int speed;
void *gameStart();
void gameLoop();
bool checkMap();

#endif
