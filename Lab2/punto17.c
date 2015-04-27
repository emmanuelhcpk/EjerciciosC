/* 
 * Emmanuel Velez
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//macros
#define TAMANO_LINEA 100
#define MATERIAS_POR_LINEA 3
#define NOTAMINIMA 3.0

struct materia{
  char nombre[30];
  int creditos;
  double promedio;
};

int cuentaMaterias(FILE *file,int lineasPorMateria);
void infoMateria(FILE *file,struct materia *materias,int totalMaterias,int materiasPorLinea );
char* obtenerInfoDosPuntos(char buffer[TAMANO_LINEA]);
double promedioNotas(char buffer[TAMANO_LINEA]);
void generarBoletin(FILE *out_file, struct materia *materias, int totalMaterias);

int main(int argc, char *argv[])
{
  
  if(argc != 3)
  {
   printf("Faltan argumentos...\n ./generarBoletin [pathArchivoEntrada] [pathArchivosalida]\n intente nuevamente..\n");
  }
  
  int totalMaterias = 0; 
  FILE *in_file,*out_file; 
  
  in_file = fopen(argv[1],"r");
  out_file = fopen(argv[2],"w");
  
  if(in_file == NULL) 
  {
    printf("No es posible abrir el archivo de origen \n");
    return -1;
  }
  
  if(out_file == NULL) 
  {
    printf("No es posible abrir el archivo de destino \n");
    return 0;
  }  
  totalMaterias =cuentaMaterias(in_file,MATERIAS_POR_LINEA);
  struct materia *materias = (struct materia*)malloc(totalMaterias*sizeof(struct materia));
  rewind(in_file);
  infoMateria(in_file,materias,totalMaterias,MATERIAS_POR_LINEA);
  generarBoletin(out_file,materias,totalMaterias);  
  free(materias);
  fclose(in_file);
  fclose(out_file);
  return 0;
}

void generarBoletin(FILE *out_file, struct materia *materias, int totalMaterias)
{
  double promedioPonderado = 0.0;
  int materiasPasadas = 0;
  int materiasPerdidas = 0;
  int totalCreditos = 0;
  int contadorMaterias = 0;
  
  fprintf(out_file,"\tMateria\t\tN° Creditos\t\tNota\n\n");
  
   while(contadorMaterias < totalMaterias)
   {
    fprintf(out_file,"\t%s\t\t%d\t\t%.1f\n",materias->nombre,materias->creditos,materias->promedio);
    promedioPonderado = promedioPonderado + (materias->promedio)*(materias->creditos);
    totalCreditos += materias->creditos;

    if(materias->promedio < NOTAMINIMA)
    {
      materiasPerdidas++;
    }
    contadorMaterias++;
    materias++; 
    }
    
    promedioPonderado = promedioPonderado/totalCreditos;
    materiasPasadas = totalMaterias - materiasPerdidas;
    
    fprintf(out_file,"\t\t N° Total de Materias : %d\n",totalMaterias);
    fprintf(out_file,"\t\t N° Total Creditos : %d\n",totalCreditos);
    fprintf(out_file,"\t\t\tN° Materias Ganadas : %d\n",materiasPasadas);
    fprintf(out_file,"\t\t\tN° Materias Pasadas : %d\n",materiasPerdidas);
    fprintf(out_file,"\t\t\tPromedio Ponderarado: %.2f\n",promedioPonderado);
}

int cuentaMaterias(FILE *file,int lineasPorMateria)
{
  int contador = 1;
  char buffer[TAMANO_LINEA];
  
  while((fgets (buffer, sizeof(buffer), file)))
  {
    contador++;
  }
  return (contador/lineasPorMateria);
}

void infoMateria(FILE *file,struct materia *materias,int totalMaterias,int materiasPorLinea )
{  
  int contador = 1;
  int contadorMaterias = 1;
  char buffer[TAMANO_LINEA];
  char *creditos;
  double promedio;
  char *notas;
  char *nombreMateria;
  int  tamanoNombre;
  int posCaracter;
  
  while(totalMaterias >= contadorMaterias)
  {
    
	  fgets (buffer, sizeof(buffer), file);
	  nombreMateria =obtenerInfoDosPuntos(buffer);
	  tamanoNombre = strlen(nombreMateria) - 1;
	  posCaracter = 0;
	
	  while(posCaracter < tamanoNombre)
	  {
	    materias->nombre[posCaracter] = *(nombreMateria + posCaracter);
	    posCaracter++;
	  }  

	  fgets (buffer, sizeof(buffer), file);
	  notas = obtenerInfoDosPuntos(buffer);
	  promedio = promedioNotas(notas);
	  materias->promedio = promedio;
	  
	
	  fgets (buffer, sizeof(buffer), file);
	  creditos = obtenerInfoDosPuntos(buffer);
	  materias->creditos = atoi(creditos) ;
	  
	  contadorMaterias++;
	  materias++;
  }
}

char* obtenerInfoDosPuntos(char buffer[TAMANO_LINEA])
{
    char* token1 = strtok(buffer, ":");
    char* token2 = strtok(NULL, ":");    
    return token2;
}

double promedioNotas(char buffer[TAMANO_LINEA])
{
  double notas = 0;
  int totalNotas = 0;;
  
  char* notaTo = strtok(buffer, ";");
  while( notaTo != NULL ) 
  {

      notas = notas + atof(notaTo); 
      totalNotas++;
      notaTo = strtok(NULL, ";");
  }
  return (notas/totalNotas);
}


