#ifndef map_H
#define map_H

#include <string.h>
#include <stdlib.h>
#include <time.h>

//Predefiniowane stałe
#define MAP_WIDTH  10
#define MAP_HEIGHT 20
#define SCALE      32

//Definicja typu boolowskiego
typedef enum { false, true } bool;

//Definicja struktury puntu
typedef struct pt{
   int x, y, type;
}Point;

//Definicja kształtu
typedef struct shp{
   int siz;
   Point * offset; //Punkty tworzące kształt
}Shape;

int score;       //Zmienna przechowująca wynik
int level;       //Zmienna przechowująca poziom
int currentType; //Zmienna przechowująca obecny typ klocka
int nextShape;   //Zmienna przechowująca następny typ klocka
bool running;    //Zmienna boolowska sygnalizująca działanie programu
Point position;  //Struktura punktu odpowiadająca za pozycję spadającego klocka
Shape current;   //Struktura przechowująca obecny klocek
Shape shape[7];  //Tablica w której przechowywane są informacje o poszczególnych typach klocków

//Tablica przechowująca informacje o stanie mapy
int map[MAP_HEIGHT][MAP_WIDTH];

/*
mapInit: Ustawienie początkowych wartości zmiennych, wyzerowanie mapy
oraz nadanie ziarna losowania.
*/
void mapInit();

/*
checkScore: Odpowiedzialny za cykliczne sprawdzanie stanu mapy
i uzupełnianie punktacji
*/
void checkScore();

/*
shapeInit: Ustawienie kształtu danego typu jako obecny kształt
*/
void shapeInit(int, int);

/*
shapeRotate: Odpowiada za obrót kształtu
*/
void shapeRotate();

/*
shapeCleanup: Odświeża oryginalny wzorzec kształtu
*/
void shapeCleanup();

/*
shapePlace: Odpowiada za ustawenie kształtu na mapie, co umożliwa
przejście do kolejnego kształtu
*/
void shapePlace();

/*
shapeFall: Ma za zadanie przesunąć cały kształt o jedno pole w dół
*/
void shapeFall();

/*
shapeLeft i shapeRight odpowiadają za poruszanie się kształtem w lewo i prawo
*/
void shapeLeft();
void shapeRight();

#endif
