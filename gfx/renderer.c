#include "renderer.h"

void windowInit(int width, int height, const char * title){
   sfVideoMode mode = {width, height};
   win = sfRenderWindow_create(mode, title, sfClose, NULL);

   block[0] = blockInit("images/outline.jpg");
   block[1] = blockInit("images/block.png");
   block[2] = blockInit("images/outline.jpg");

   windowShow();
}

void windowShow(){
   sfColor bgColor = sfBlack;
   sfEvent event;
   while(running){
      sfRenderWindow_clear(win, bgColor);
      checkScore();
      while(sfRenderWindow_pollEvent(win, &event)){
         if(event.type == sfEvtClosed){
            running = false;
         }else if(event.type == sfEvtKeyPressed){
            if(event.key.code == sfKeySpace) {
               shapeRotate();
            }else if(event.key.code == sfKeyLeft) {
               shapeLeft();
            }else if(event.key.code == sfKeyRight) {
               shapeRight();
            }
         }
      }
      drawMap();
      drawGui(block[0].sprite);

      sfRenderWindow_display(win);
   }

   for(int i=0;i<blocksCount;i++) {
      sfTexture_destroy(block[i].texture);
      sfSprite_destroy(block[i].sprite);
   }
   sfRenderWindow_destroy(win);
}

void drawGui(sfSprite * outline){
   for(int i=0;i<MAP_WIDTH+10;i++){
      setSpritePos(outline, i*SCALE, 0);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
   for(int i=MAP_WIDTH+1;i<MAP_WIDTH+10;i++){
      setSpritePos(outline, i*SCALE, 6*SCALE);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
   for(int i=0;i<6;i++){
      setSpritePos(outline, (MAP_WIDTH+9)*SCALE, i*SCALE);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
   for(int i=0;i<MAP_WIDTH+2;i++){
      setSpritePos(outline, i*SCALE, (MAP_HEIGHT+1)*SCALE);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
   for(int i=0;i<MAP_HEIGHT+1;i++){
      setSpritePos(outline, 0, i*SCALE);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
   for(int i=0;i<MAP_HEIGHT+1;i++){
      setSpritePos(outline, (MAP_WIDTH+1)*SCALE, i*SCALE);
      sfRenderWindow_drawSprite(win, outline, NULL);
   }
}

void drawMap(){
   for(int y=0;y<MAP_HEIGHT;y++){
      for(int x=0;x<MAP_WIDTH;x++){
         if(map[y][x] != 0){
            setSpritePos(block[map[y][x]].sprite, (x+1)*SCALE, (y+1)*SCALE);
            sfRenderWindow_drawSprite(win, block[map[y][x]].sprite, NULL);
         }
      }
   }

   for(int i=0;i<current.siz;i++){
      setSpritePos(
         block[current.offset[i].type].sprite, 
         (current.offset[i].x+position.x+1)*SCALE, 
         (current.offset[i].y+position.y+1)*SCALE
      );

      sfRenderWindow_drawSprite(win, block[current.offset[i].type].sprite, NULL);
   }
}

void setSpritePos(sfSprite * spr, int x, int y){
   sfSprite_setPosition(spr, (sfVector2f){x,y});
}

Block blockInit(const char * file){
   Block temp;
   temp.sprite = sfSprite_create();
   temp.texture = sfTexture_createFromFile(file, NULL);
   sfSprite_setTexture(temp.sprite, temp.texture, 0);
   sfSprite_setScale(temp.sprite, (sfVector2f){0.125,0.125});
   return temp;
}
