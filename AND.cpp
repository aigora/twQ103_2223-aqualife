#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_ROWS 1000

struct TDatos {
  char parametros[20];
  float pH;
  float conductividad;
  float turbidez;
  float coliformes;
};

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo; // Obtener informaci�n de la consola
  WORD saved_attributes; // Almacenar los atributos originales de la consola
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Obtener informaci�n de la consola
  saved_attributes = consoleInfo.wAttributes; // Almacenar los atributos originales de la consola

  // Modificar los atributos de la consola
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Azul claro

	struct TDatos datos[MAX_ROWS];
	char filename[100]; 
  	int num_rows = 0;
  	printf("--------------------BIENVENID@ A AQUALIFE-------------------\n");
  	//Abrimos el fichero
	FILE* fentrada;
  	//Se abrir� el fichero que el usuario introduzca entre los distintos ficheros con datos de fuentes que el programa puede ofrecer
  	printf("Estos son algunos archivos con los que puede trabajar: \n");
	printf("Lavapies.txt\n");
  	printf("Barajas.txt\n");
  	printf("Carabanchel.txt\n");
  	printf("Arganzuela.txt\n");
  	printf("Por favor, introduzca el nombre del archivo con el que desea trabajar: \n");//Imprime texto en la consola para que el usuario sepa lo que le est� pidiendo el programa
  	scanf("%s", filename); //Captura lo que ha escrito el usuario y le asigna una variable

  	fentrada= fopen(filename, "r");
  	if(fentrada== NULL){
    	printf("ERROR, no se pudo abrir el archivo.\n");
    	return 0;
  	}

  	//Leer los datos del archivo y almacenarlos en un arreglo de estructuras
  	while (fscanf(fentrada, "%s\t%f\t%f\t%f\t%f\n", datos[num_rows].parametros, &datos[num_rows].pH, &datos[num_rows].conductividad, &datos[num_rows].turbidez, &datos[num_rows].coliformes) !=EOF){
    	num_rows++;
  	}
	//Cerramos el fichero
  	fclose(fentrada);

  	int opcion;
  	do {//El bucle do-while se ejecutar� al menos una vez antes de verificar la opci�n es v�lida
  		
  		printf("---MENU---\n");
  		printf("Por favor, introduzca la opci�n que desea realizar: \n");
    	printf("1. Realizar la media del pH del agua de las fuentes.\n");
    	printf("2. Realizar la media de la conductividad del agua de las fuentes.\n");
    	printf("3. Realizar la media de la turbidez del agua de las fuentes.\n");
    	printf("4. Realizar la media de los coliformes presentes en el agua de las fuentes.\n");
    	printf("5. Buscar los datos de una fuente.\n");
    	printf("6. Imprimir los datos de las fuentes.\n");
		printf("7. Salir.\n");
    	scanf("%d", &opcion);

		 switch (opcion) {
      case 1: {
    	float media_pH = 0;
    	for (int i = 0; i < num_rows; i++) {
        	media_pH += datos[i].pH;
    	}
    	media_pH /= num_rows;
    	printf("La media del dato pH es: %.2f\n", media_pH);

    	if (media_pH < 7.0) {
        	printf("El valor medio del ph medido en el agua de las fuentes indica que esta es acida.\n");
    	} else if (media_pH > 7.0) {
        	printf("El valor medio del ph medido en el agua de las fuentes indica que esta es basica.\n");
    	} 
    	break;
      	}
      	
      case 2: {
        float media_conductividad = 0;
        for (int i = 0; i < num_rows; i++) {
          media_conductividad += datos[i].conductividad;
        }
        media_conductividad /= num_rows;
        printf("La media del dato conductividad es: %.2f\n", media_conductividad);
        break;
      }
      case 3: {
        float media_turbidez = 0;
        for (int i = 0; i < num_rows; i++) {
          media_turbidez += datos[i].turbidez;
        }
        media_turbidez /= num_rows;
        printf("La media del dato turbidez es: %.2f\n", media_turbidez);
        break;
      }
      case 4: {
        float media_coliformes = 0;
        for (int i = 0; i < num_rows; i++) {
          media_coliformes += datos[i].coliformes;
        }
        media_coliformes /= num_rows;
        printf("La media del dato coliformes es: %.2f\n", media_coliformes);
        break;
      }


