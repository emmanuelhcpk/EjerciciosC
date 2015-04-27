#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct materias {
	char nombre[20];
	float nota;
	int creditos;

}str_materia;

int numero_materias(char const *ruta);
void escribir(FILE *file);
int main(int argc, char const *argv[])
{
	FILE *archivo;
	if (argc!=3)
		{
		printf("Argumentos insuficientes");
			return 0;
		}

	archivo = fopen(argv[1], "r");

	if(archivo == NULL)
		{

		printf("El archivo no existe");
		}
	
	char renglon[100];
	int num_materias = (numero_materias(argv[1]))-1;

	str_materia *mat = malloc(sizeof(str_materia)*num_materias);

	//strcpy(mat->nombre,"hola");
	//printf("%s\n",mat->nombre );
	printf("%d\n",num_materias);
	int i ;
	char *dato;


/*metodo leer 2

fgets(renglon,100,archivo);

//dato = strtok(strdup(renglon), ";");
for (i = 0; i < num_materias; ++i)
{
	if (i!=0){
	dato = strtok(strdup(renglon), ";");
	strcpy((mat+i)->nombre,dato);//meto nombre
	printf("%s\n",(mat+i)->nombre);
	printf("%s\n",strtok(NULL, ";"));
	//(mat+i)->nota = atof(strtok(NULL, ";"));
	//(mat+i)->creditos = atoi(strtok(NULL, ";"));;
	//printf("%s\n",(mat+i)->nombre);
	}//fin if interno
	fgets(renglon,100,archivo);
}*/


// metodo leer 1
int j=0;
while(fgets(renglon,100,archivo))
{
	dato = strtok(strdup(renglon), ";");
        while(dato != NULL){
            if(i==0)
            {
                strcpy((mat+j)->nombre,dato);
            }else if(i == 1)
            {
                (mat+j)->creditos = atoi(dato);
            }else
            {
                (mat+j)->nota = atof(dato);
            }
            //printf ("%s\n",dato);
            dato = strtok(NULL, ";");
            i++;
        }
        i = 0; 
        j++;   
	
}
for (i = 0; i < num_materias; ++i)
{
	//strcpy((mat+i)->nombre,dato);//meto nombre
	//(mat+i)->nota = atof(strtok(NULL, ";"));
	//(mat+i)->creditos = atoi(strtok(NULL, ";"));;
	printf("%s\n",(mat+i)->nombre);
}

	return 0;

fclose(archivo);
free(mat);
}

void escribir(FILE *file)
{

}

int numero_materias(char const *ruta)

{
	FILE *archivo = fopen(ruta, "r");
   int contador = 1;
   char buffer[100];
  
  while((fgets (buffer, sizeof(buffer), archivo)))
  {
    contador++;
  }
  return (contador);
//return 3;
}