/*
 * Emmanuel Velez
 *
*/

#include <stdlib.h>
#include <stdio.h>
//definicion 
struct point 
{
    int x;
    int y;
};
//definicion rectangulo
struct rectang
{
  struct point pt1;
  struct point pt2;
};
  
int main()
{
  int altura = 0, longitud = 0;
  
  struct rectang rectangulo;
  struct point punto;
  
  printf("Ingrese el punto x:\n");
  scanf("%d",&punto.x);
  printf("Ingrese el punto y:\n");
  scanf("%d",&punto.y);
  rectangulo.pt1 = punto;
  
  printf("Ingrese el punto x':\n");
  scanf("%d",&punto.x);
  printf("Ingrese el punto y':\n");
  scanf("%d",&punto.y);
  rectangulo.pt2 = punto;
  
  printf("Rectangulo Punto 1 : [%d,%d]\n",rectangulo.pt1.x,rectangulo.pt1.y);
  printf("Rectangulo Punto 2 : [%d,%d]\n",rectangulo.pt2.x,rectangulo.pt2.y);
//   rectangulo.y = y;  
  longitud = abs(rectangulo.pt1.x - rectangulo.pt2.x);
  altura = abs(rectangulo.pt1.y - rectangulo.pt2.y);
  
  printf("Rectangulo Area : %d\n",longitud*altura);
  
  
  return 0;
}
