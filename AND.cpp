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
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Almacena identificador de la consola
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo; // Almacena información de la consola
  WORD saved_attributes; // Almacenar los atributos originales de la consola
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Obtener información de la consola
  saved_attributes = consoleInfo.wAttributes; // Almacenar los atributos originales de la consola

  	// Modificar los atributos de la consola
  	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Azul claro

	struct TDatos datos[MAX_ROWS];
	char filename[100]; 
  	int num_rows = 0;
  	printf("--------------------BIENVENID@ A AQUALIFE-------------------\n");
  	//Abrimos el fichero
	FILE* fentrada;
	
	printf("");
	printf("1. Ya tiene una cuenta? Iniciar sesion");
	printf("2. Es nuevo? Registrarse");
	printf("3. Acceder como invitado");
	printf("4. Acceder como administrador");
	scanf("");
	
  	//Se abrirá el fichero que el usuario introduzca entre los distintos ficheros con datos de fuentes que el programa puede ofrecer
  	printf("Estos son algunos archivos con los que puede trabajar: \n");
	printf("Lavapies.txt\n");
  	printf("Barajas.txt\n");
  	printf("Carabanchel.txt\n");
  	printf("Arganzuela.txt\n");
  	printf("Por favor, introduzca el nombre del archivo con el que desea trabajar: \n");//Imprime texto en la consola para que el usuario sepa lo que le estï¿½ pidiendo el programa
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
  	do {//El bucle do-while se ejecutara al menos una vez antes de verificar la opcion es valida
  		
  		printf("---MENU---\n");
  		printf("Por favor, introduzca la opcion que desea realizar: \n");
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
      case 5: {
        char fuente[20];
        printf("Ingrese el nombre del parametro (fuente): ");
        scanf("%s", fuente);
        int encontrado = 0;
        for (int i = 0; i < num_rows; i++) {
          if (strcmp(datos[i].parametros, fuente) == 0) {
        	encontrado = 1;
            printf("Parametro: %s, pH: %.2f, Conductividad: %.2f, Turbidez: %.2f, Coliformes: %.2f\n", datos[i].parametros, datos[i].pH, datos[i].conductividad, datos[i].turbidez, datos[i].coliformes);
          }
        }
        if (encontrado==0) {
          printf("No se ha encontrado la fuente.\n");
        }
        break;
      }
      case 6: {
  		fentrada= fopen(filename, "r");
  		if (fentrada == NULL) {
    		printf("No se pudo abrir el archivo.\n");
   			break;
  		}

  		// Leer la primera fila del archivo y almacenarla en una variable separada
  		char header[100];
  		fgets(header, sizeof(header), fentrada);

  		// Mostrar la cabecera de las columnas
  		printf("%-20s%-20s%-20s%-20s%-20s\n", "Parametros", "pH", "Conductividad", "Turbidez", "Coliformes");

  		// Leer los datos del archivo y almacenarlos en un arreglo de estructuras
  		while (fscanf(fentrada, "%s\t%f\t%f\t%f\t%f\n", datos[num_rows].parametros, &datos[num_rows].pH, &datos[num_rows].conductividad, &datos[num_rows].turbidez, &datos[num_rows].coliformes) !=EOF){
    		num_rows++;
    		printf("%-20s%-20.2f%-20.2f%-20.2f%-20.2f\n", datos[num_rows-1].parametros, datos[num_rows-1].pH, datos[num_rows-1].conductividad, datos[num_rows-1].turbidez, datos[num_rows-1].coliformes);
  		}

  		fclose(fentrada);
  
  		printf("\n");
    	getchar();
  
  		break;
	}
	  case 7: {
        printf("Gracias por confiar en AquaLife\n");
        break;
      }
      
      default: {
        printf("Opcion invalida.\n");
        break;
      }
    }
  } while (opcion!= 7);

  return 0;
}


