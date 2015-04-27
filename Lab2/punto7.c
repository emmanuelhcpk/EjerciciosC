/*
 * Emmanuel Velez
 *
*/

#include <stdlib.h>
#include <stdio.h>

struct estudiante
{
    char nombre[40];
    int numEstiante;
    int agnoMatricula;
    float nota;
};

int main()
{
    char tecla;
    struct estudiante est1 = {"Emmanuel",1152201840,20151,5.00};
    struct estudiante *ptrEst1;
    ptrEst1 = &est1; //se crea apuntador
    
    printf("Estudiante: %s\nNota: %f\nAño Matricula: %d\nN° Estudiante: %d\n",ptrEst1->nombre,ptrEst1->nota,ptrEst1->agnoMatricula,ptrEst1->numEstiante);
    tecla = getchar();
    if(tecla=='c'){
	printf("Correción de Información...\n");
	printf("Ingrese el nombre del estudiante: ");
	scanf("%s",&ptrEst1->nombre);
	printf("Ingrese el número del estudiante: ");
	scanf("ds",&ptrEst1->numEstiante);
	printf("Ingrese el año de matricula del estudiante: ");
	scanf("%d",&ptrEst1->agnoMatricula);
	printf("Ingrese la nota del estudiante: ");
	scanf("%f",&ptrEst1->nota);	
	printf("Estudiante: %s\nNota: %f\nAño Matricula: %d\nN° 	Estudiante: %d\n",ptrEst1->nombre,ptrEst1->nota,ptrEst1->agnoMatricula,ptrEst1->numEstiante);
    }
    return 0;
        
}
