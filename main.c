#include <stdio.h>
#include "gfx/renderer.h"
#include "threads/game.h"

int main(void){
   mapInit();
   shapeInit(nextShape, 3);
   windowInit(640, 704, "Tetris");
   return 0;
}

/*TODO:
   - zmiana grafik
   - dodanie prędkości spadania kolocków i leveli
*/
