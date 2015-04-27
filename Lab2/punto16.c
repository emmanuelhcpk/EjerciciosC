/*
 * Emmanuel Velez
 *
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int count = 0; // contador
  char FILE_NAME_ORIGIN[30] = "input.txt",FILE_NAME_DESTINATION[30] = "output.txt";
  FILE *in_file,*out_file; 
  int ch; 
  int chout; 
  
  printf("Duplicador de archivos \n\n");
//   printf("Ingrese el nombre del archivo de origen:");
//   scanf("%s",&FILE_NAME_ORIGIN);
// 
//   printf("Ingrese el nombre del archivo de destino:");
//   scanf("%s",&FILE_NAME_DESTINATION);
  
  in_file = fopen(FILE_NAME_ORIGIN,"r");  abrira en modo lectura
  out_file = fopen(FILE_NAME_DESTINATION,"w+"); 
  
  if(in_file == NULL) // se checkea si se puede abrir el archivo
  {
    printf("No es posible abrir el archivo de origen %s\n",FILE_NAME_ORIGIN);
  }
  
  if(out_file == NULL) 
  {
    printf("No es posible abrir el archivo de destino %s\n",FILE_NAME_DESTINATION);
  }  
  
  while(1)
  {
    ch = fgetc(in_file);
    if(ch == EOF) 
    {
//       printf("Error de lectura en el archivo de origen %s\n",FILE_NAME_ORIGIN);
      break;
    }
    printf("Caracter: %d\n",ch);
    chout = fputc(ch,out_file);
    if(chout == EOF) // 
    {
      printf("Error de escritura en el archivo de destino %s\n",FILE_NAME_DESTINATION);
      break;
    }
    ++count;
  }

  return 0;
}
