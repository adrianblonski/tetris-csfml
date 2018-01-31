#ifndef game_H
#define game_H

#include <stdio.h>
#include <unistd.h>
#include "../gfx/map.h"

//zmienna prędkości
int speed;

void *gameStart(); //funkcja inicjująca wątek
void gameLoop();   //Główna pętla wątku opadania
bool checkMap();   //Sprawdzanie kolizji na mapie

#endif
