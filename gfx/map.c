#include "map.h"

void mapInit(){
   srand(time(NULL));
   nextShape = rand() % 5;
   running = true;
   memset(map, 0, sizeof(int) * MAP_HEIGHT * MAP_WIDTH);
   current.siz = -1;

   //shape I
   shape[0].siz = 4;
   shape[0].offset = malloc(sizeof(Point) * shape[0].siz);
   shape[0].offset[0] = (Point){ 0, 0, 1, true};
   shape[0].offset[1] = (Point){ 0,-1, 1, false};
   shape[0].offset[2] = (Point){ 0,-2, 1, false};
   shape[0].offset[3] = (Point){ 0,-3, 1, false};

   //shape T
   shape[1].siz = 4;
   shape[1].offset = malloc(sizeof(Point) * shape[1].siz);
   shape[1].offset[0] = (Point){ 0, 0, 1, true};
   shape[1].offset[1] = (Point){ 0,-1, 1, false};
   shape[1].offset[2] = (Point){-1,-1, 1, true};
   shape[1].offset[3] = (Point){ 1,-1, 1, true};

   //shape O
   shape[2].siz = 4;
   shape[2].offset = malloc(sizeof(Point) * shape[1].siz);
   shape[2].offset[0] = (Point){ 0, 0, 1, true};
   shape[2].offset[1] = (Point){ 1, 0, 1, true};
   shape[2].offset[2] = (Point){ 0,-1, 1, false};
   shape[2].offset[3] = (Point){ 1,-1, 1, false};

   //shape L
   shape[3].siz = 4;
   shape[3].offset = malloc(sizeof(Point) * shape[1].siz);
   shape[3].offset[0] = (Point){ 0, 0, 1, true};
   shape[3].offset[1] = (Point){ 1, 0, 1, true};
   shape[3].offset[2] = (Point){ 1,-1, 1, false};
   shape[3].offset[3] = (Point){ 1,-2, 1, false};

   //shape J
   shape[4].siz = 4;
   shape[4].offset = malloc(sizeof(Point) * shape[1].siz);
   shape[4].offset[0] = (Point){ 0, 0, 1, true};
   shape[4].offset[1] = (Point){ 1, 0, 1, true};
   shape[4].offset[2] = (Point){ 0,-1, 1, false};
   shape[4].offset[3] = (Point){ 0,-2, 1, false};
}

void shapeInit(int type, int x){
   current = shape[type];
   position = (Point){x, -1};
}

void shapePlace(){
   for(int i=0;i<current.siz;i++){
      map[position.y+current.offset[i].y][position.x+current.offset[i].x] = current.offset[i].type;
   }
   shapeInit(nextShape, 4);
   nextShape = rand() % 5;
}

void shapeLeft(){
   position.x--;
}

void shapeRight(){
   position.x++;
}

void shapeFall(){
   position.y++;
}
