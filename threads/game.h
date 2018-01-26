#ifndef game_H
#define game_H

#include <unistd.h>
#include "../gfx/map.h"

int speed;
bool freeze;
void *gameStart();
void gameLoop();
bool checkMap();

#endif
