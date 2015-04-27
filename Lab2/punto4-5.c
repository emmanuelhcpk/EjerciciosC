/*
 * Emmanuel Velez
 * 
 *
*/

#include <stdlib.h>
#include <stdio.h>
//definicion
struct cdsMusica // Estructura de la structura cd musica
{
    char titulo[40];
    char artista[30];
    char genero[20];
    int numeroCanciones;
    int lanzamiento;
    int precio;
} cd1,cd2,cd3; //
  
int main()
{	//inicializacion de la var
    struct cdsMusica cd1 = {"Brindo con el alma","Diomedes Díaz","Vallenato",11,1986,19900};
    printf("Disco: %s \nAutor: %s\nGenero: %s\nN° Canciones: %d\nAño: %d\nPrecio: %d\n",cd1.titulo,cd1.artista,cd1.genero,cd1.numeroCanciones,cd1.lanzamiento,cd1.precio);
    
    return 0;
}

