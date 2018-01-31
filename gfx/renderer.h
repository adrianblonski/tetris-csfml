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

void windowInit(int, int, const char *); //Inicjuje okno
void windowDestroy(); //Usuwa okno
void windowShow(); //Pętla wyświetlająca grafikę
void drawMap(); //Rysowanie mapy
void drawGui(sfSprite *); //Rysowanie interfejsu
void drawText(const char *, int, int, int); //Rysowanie tekstu
void setSpritePos(sfSprite *, int, int); //Ustawianie pozycji "obiektu" graficznego
Block blockInit(const char *); //"Konstruktor" bloku

#endif
