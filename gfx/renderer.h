#ifndef renderer_H
#define renderer_H

#include <stdio.h>
#include <pthread.h>
#include <SFML/Graphics.h>
#include "../threads/game.h"
#include "map.h"

#define blocksCount 2

sfRenderWindow * win;
sfFont * font;
sfText * text;

typedef struct Blk{
   sfSprite * sprite;
   sfTexture * texture;
}Block;

Block block[blocksCount];

pthread_t game;

void windowInit(int, int, const char *);
void windowDestroy();
void windowShow();
void drawMap();
void drawGui(sfSprite *);
void drawText(const char *, int, int, int);
void setSpritePos(sfSprite *, int, int);
Block blockInit(const char *);

#endif
