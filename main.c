#include <stdio.h>
#include "gfx/renderer.h"
#include "threads/game.h"

int main(void){
   //Zainicjowanie mapy
   mapInit();
   //Zainicjowanie pierwszego klocka
   shapeInit(nextShape, 3);
   //Stworzenie okna głównego gry
   windowInit(640, 704, "Tetris");
   return 0;
}

/*TODO:
   - zmiana grafik
   - dodanie zmiennej prędkości spadania kolocków i poziomów
*/
