#ifndef map_H
#define map_H

#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH  10
#define MAP_HEIGHT 20
#define SCALE      32

typedef enum { false, true } bool;

typedef struct pt{
   int x, y, type;
   bool obstacle;
}Point;

typedef struct shp{
   int siz;
   Point * offset;
}Shape;

int nextShape;
bool running;
Point position;
Shape current;
Shape shape[7];
int map[MAP_HEIGHT][MAP_WIDTH];

void mapInit();
void shapeInit(int, int);
void shapePlace();
void shapeFall();
void shapeLeft();
void shapeRight();

#endif
