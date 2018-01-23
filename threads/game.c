#include "game.h"

void *gameStart(){
   speed = 300000;
   gameLoop();
}

void gameLoop(){
   while(running){
      checkMap();
      shapeFall();
      usleep(speed);
   }
}

void checkMap(){
   for(int i=0;i<current.siz;i++){
      if(current.offset[i].obstacle == true){
         int x = current.offset[i].x+position.x;
         int y = current.offset[i].y+position.y;
         if(y>=MAP_HEIGHT-1 || map[y+1][x]!=0){
            shapePlace();
         }
      }
   }

   //TUTAJ MA BY LINIJKI MAPY, KTORA JEST ZAPELNIONA
}
