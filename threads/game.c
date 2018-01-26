#include "game.h"

void *gameStart(){
   speed = 300000;
   gameLoop();
}

void gameLoop(){
   while(running){
      if(checkMap()){
         usleep(600000);
      }
      shapeFall();
      usleep(speed);
   }
}

bool checkMap(){
   for(int i=0;i<current.siz;i++){
      int x = current.offset[i].x+position.x;
      int y = current.offset[i].y+position.y;
      if(y>=MAP_HEIGHT-1 || map[y+1][x]!=0){
         shapePlace();
         printf("placing at x=%d y=%d\n", x, y);
         return true;
      }
   }
   return false;

   //TUTAJ MA BY LINIJKI MAPY, KTORA JEST ZAPELNIONA
}
