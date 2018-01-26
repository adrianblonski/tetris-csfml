#include "map.h"

void mapInit(){
   score = 0;
   level = 1;
   srand(time(NULL));
   nextShape = rand() % 6;
   memset(map, 0, sizeof(int) * MAP_HEIGHT * MAP_WIDTH);
   current.siz = -1;
   shapeCleanup();
   running = true;
}

void checkScore(){
   for(int y=0;y<MAP_HEIGHT;y++){
      int counter = 0;
      for(int x=0;x<MAP_WIDTH;x++){
         if(map[y][x]!=0) counter++;
      }
      if(counter==MAP_WIDTH){
         for(int i=y;i>=0;i--){
            for(int x=0;x<MAP_WIDTH;x++){
               map[i][x]=map[i-1][x];
            }
         }
         for(int x=0;x<MAP_WIDTH;x++){
            map[0][x]=0;
         }
         score++;
         checkScore();
         break;
      }
   }
}

void shapeInit(int type, int x){
   currentType = type;
   current.siz = shape[type].siz;
   Point * pt = malloc(sizeof(Point) * shape[type].siz);
   for(int i=0;i<shape[type].siz;i++)
      pt[i] = shape[type].offset[i];
   current.offset = pt;
   position = (Point){x, -1};
}

void shapeRotate(){
   if(currentType==2) return;
   for(int i=0;i<current.siz;i++){
      int x = current.offset[i].x;
      int y = current.offset[i].y;
      if(!(-y+position.x > -1 && map[x+position.y][-y+position.x]==0)) return;
   }

   for(int i=0;i<current.siz;i++){
      int x = current.offset[i].x;
      int y = current.offset[i].y;
      current.offset[i].x = -y;
      current.offset[i].y = x;
   }
}

void shapePlace(){
   if(position.y<0) return;
   for(int i=0;i<current.siz;i++){
      map[position.y+current.offset[i].y][position.x+current.offset[i].x] = current.offset[i].type;
   }
   shapeCleanup();
   shapeInit(nextShape, 4);
   nextShape = rand() % 6;
}

void shapeLeft(){
   for(int i=0;i<current.siz;i++){
      int x = current.offset[i].x+position.x;
      int y = current.offset[i].y+position.y;
      if(!(x > 0 && map[y][x-1]==0)) return;
   }
   position.x--;
}

void shapeRight(){
   for(int i=0;i<current.siz;i++){
      int x = current.offset[i].x+position.x;
      int y = current.offset[i].y+position.y;
      if(!(x < MAP_WIDTH-1 && map[y][x+1]==0)) return;
   }
   position.x++;
}

void shapeFall(){
   position.y++;
}

void shapeCleanup(){
   //shape I
   shape[0].siz = 4;
   shape[0].offset = malloc(sizeof(Point) * shape[0].siz);
   shape[0].offset[0] = (Point){ 0, 0, 1};
   shape[0].offset[1] = (Point){ 0,-1, 1};
   shape[0].offset[2] = (Point){ 0,-2, 1};
   shape[0].offset[3] = (Point){ 0,-3, 1};

   //shape T
   shape[1].siz = 4;
   shape[1].offset = malloc(sizeof(Point) * shape[1].siz);
   shape[1].offset[0] = (Point){ 0, 0, 1};
   shape[1].offset[1] = (Point){ 0,-1, 1};
   shape[1].offset[2] = (Point){-1,-1, 1};
   shape[1].offset[3] = (Point){ 1,-1, 1};

   //shape O
   shape[2].siz = 4;
   shape[2].offset = malloc(sizeof(Point) * shape[2].siz);
   shape[2].offset[0] = (Point){ 0, 0, 1};
   shape[2].offset[1] = (Point){ 1, 0, 1};
   shape[2].offset[2] = (Point){ 0,-1, 1};
   shape[2].offset[3] = (Point){ 1,-1, 1};

   //shape L
   shape[3].siz = 4;
   shape[3].offset = malloc(sizeof(Point) * shape[3].siz);
   shape[3].offset[0] = (Point){ 0, 0, 1};
   shape[3].offset[1] = (Point){ 1, 0, 1};
   shape[3].offset[2] = (Point){ 1,-1, 1};
   shape[3].offset[3] = (Point){ 1,-2, 1};

   //shape J
   shape[4].siz = 4;
   shape[4].offset = malloc(sizeof(Point) * shape[4].siz);
   shape[4].offset[0] = (Point){ 0, 0, 1};
   shape[4].offset[1] = (Point){ 1, 0, 1};
   shape[4].offset[2] = (Point){ 0,-1, 1};
   shape[4].offset[3] = (Point){ 0,-2, 1};

   //shape S
   shape[5].siz = 4;
   shape[5].offset = malloc(sizeof(Point) * shape[5].siz);
   shape[5].offset[0] = (Point){ 0, 0, 1};
   shape[5].offset[1] = (Point){ 1, 0, 1};
   shape[5].offset[2] = (Point){ 1,-1, 1};
   shape[5].offset[3] = (Point){ 2,-1, 1};

   //shape Z
   shape[6].siz = 4;
   shape[6].offset = malloc(sizeof(Point) * shape[6].siz);
   shape[6].offset[0] = (Point){ 0, 0, 1};
   shape[6].offset[1] = (Point){-1, 0, 1};
   shape[6].offset[2] = (Point){-1,-1, 1};
   shape[6].offset[3] = (Point){-2,-1, 1};
}
