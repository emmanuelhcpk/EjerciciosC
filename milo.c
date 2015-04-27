#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct materia{
    char nombre[30];
    int creditos;
    float nota; 
}str_materia;


int main(int argc, char *argv[]){

    str_materia *materias = malloc(sizeof(str_materia));
    FILE *archivo;
    char renglon[100];
    char *dato;
    int i = 0;
    archivo = fopen(argv[1], "r");
    
    while(fgets(renglon,100,archivo)){
        dato = strtok(strdup(renglon), ";");
        while(dato != NULL){
            if(i==0){
                strcpy(materias->nombre,dato);
            }else if(i == 1){
                materias->creditos = atoi(dato);
            }else{
                materias->nota = atof(dato);
            }
            //printf ("%s\n",dato);
            dato = strtok(NULL, ";");
            i++;
        }
        i = 0;    
    }
    printf("%s -- %d --- %lf\n",materias->nombre,materias->creditos,materias->nota);
    fclose(archivo);
    return 0;
}