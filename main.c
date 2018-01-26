#include <stdio.h>
#include <pthread.h>
#include "gfx/renderer.h"
#include "threads/game.h"

int main(void){
   pthread_t game;
   gameStart();
   mapInit();
   shapeInit(nextShape, 3);
   pthread_create(&game, NULL, gameStart, NULL);
   windowInit(640, 704, "Tetris");
   pthread_join(game, NULL);
   return 0;
}

/*TODO:
   - punktacja i poziomy
*/
