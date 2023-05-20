#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_ROWS 1000
#define M 50
#define N 20

struct TDatos {
  char parametros[20];
  float pH;
  float conductividad;
  float turbidez;
  float coliformes;
};

//DECLARACION FUNCIONES
float calcularMediaPH1(struct TDatos datos1[], int num_rows1);
float calcularMediaPH2(struct TDatos datos2[], int num_rows2);
float calcularMediaConductividad1(struct TDatos datos1[], int num_rows1);
float calcularMediaConductividad2(struct TDatos datos2[], int num_rows2);
float calcularMediaTurbidez1(struct TDatos datos1[], int num_rows1);
float calcularMediaTurbidez2(struct TDatos datos2[], int num_rows2);
float calcularMediaColiformes1(struct TDatos datos1[], int num_rows1);
float calcularMediaColiformes2(struct TDatos datos2[], int num_rows2);


int main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Almacena identificador de la consola
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo; // Almacena información de la consola
  WORD saved_attributes; // Almacenar los atributos originales de la consola
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Obtener información de la consola
  saved_attributes = consoleInfo.wAttributes; // Almacenar los atributos originales de la consola

  	// Modificar los atributos de la consola
  	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Azul claro
	
	//Declaración de variables
	struct TDatos datos1[MAX_ROWS];
	struct TDatos datos2[MAX_ROWS];
	char filename1[100];
	char filename2[100]; 
  	int num_rows1 = 0;
  	int num_rows2 = 0;
  	
  	printf("--------------------BIENVENID@ A AQUALIFE-------------------\n");
  	//Abrimos el fichero
	FILE* fentrada;
	FILE* fsalida;
	
  	//Se abrirá el fichero que el usuario introduzca entre los distintos ficheros con datos de fuentes que el programa puede ofrecer

  	printf("Por favor, introduzca el nombre del archivo con el que desea trabajar: \n");//Imprime texto en la consola para que el usuario sepa lo que le está pidiendo el programa
	printf("Arganzuela.txt\n");
	printf("Barajas.txt\n");
	printf("Carabanchel.txt\n");
	printf("Chamartin.txt\n");
	printf("Lavapies.txt\n");
	printf("RoquetasDeMar.txt\n\n"); 
  	scanf("%s", filename1); //Captura lo que ha escrito el usuario y le asigna una variable

  	fentrada= fopen(filename1, "r");
  	if(fentrada== NULL){
    	printf("ERROR, no se pudo abrir el archivo.\n");
    	return 0;
  	}

  	//Leer los datos del archivo y almacenarlos en un arreglo de estructuras
  	while (fscanf(fentrada, "%s\t%f\t%f\t%f\t%f\n", datos1[num_rows1].parametros, &datos1[num_rows1].pH, &datos1[num_rows1].conductividad, &datos1[num_rows1].turbidez, &datos1[num_rows1].coliformes) !=EOF){
    	num_rows1++;
  	}
	//Cerramos el fichero
  	fclose(fentrada);

  	int opcion1,opcion2;
  	do {//El bucle do-while se ejecutara al menos una vez antes de verificar la opcion es valida
  		
  		printf("\n---MENU---\n");
  		printf("Por favor, introduzca la opcion que desea realizar: \n");
    	printf("1. Realizar la media del pH del agua de las fuentes.\n");
    	printf("2. Realizar la media de la conductividad del agua de las fuentes.\n");
    	printf("3. Realizar la media de la turbidez del agua de las fuentes.\n");
    	printf("4. Realizar la media de los coliformes presentes en el agua de las fuentes.\n");
    	printf("5. Buscar los datos de una fuente.\n");
    	printf("6. Imprimir los datos de las fuentes.\n");
    	printf("7. Imprimir los datos de la fuente con el ph mas alto.\n");
    	printf("8. Imprimir los datos de la fuente con el ph mas bajo.\n");
    	printf("9. Cual es la fuente con el agua menos turbia?. Conozca sus datos.\n");
    	printf("10.Comparar con otro archivo.\n");
		printf("11. Salir.\n\n");
    	scanf("%d", &opcion1);
    	printf("\n");

	switch (opcion1) {
		 	
      case 1: {
      	float media_pH1 = calcularMediaPH1(datos1, num_rows1);
    	
    	printf("La media del dato pH es: %.2f\n", media_pH1);

    	if (media_pH1 < 7.0) {
        	printf("El valor medio del ph medido en el agua de las fuentes indica que esta es acida.\n");
    	} else if (media_pH1 > 7.0) {
        	printf("El valor medio del ph medido en el agua de las fuentes indica que esta es basica.\n");
    	} 
    	break;
      	}
      	
      case 2: {
      	float media_conductividad1 = calcularMediaConductividad1(datos1, num_rows1);
        printf("La media del dato conductividad es: %.2f\n", media_conductividad1);
        break;
      }
      
      case 3: {
      	float media_turbidez1 = calcularMediaTurbidez1(datos1, num_rows1);
        printf("La media del dato turbidez es: %.2f\n", media_turbidez1);
        break;
      }
      
      case 4: {
      	float media_coliformes1 = calcularMediaColiformes1(datos1, num_rows1);
        printf("La media del dato coliformes es: %.2f\n", media_coliformes1);
        break;
      }
      
      case 5: { //Esta opción permite al usuario buscar un parámetro específico en la estructura de datos e imprime la información asociada al parámetro que se encuentra
        char fuente[20]; //Arreglo de caracteres con tamaño 20
        printf("Ingrese el nombre del parametro (fuente): "); //Se le pide al usuario que introduzca el nombre de la fuente de la que quiere saber información
        scanf("%s", fuente);
        int encontrado = 0; //Declaramos una variable bandera para que determine si se ha encontrado o no el nomre de la fuente que el usuario ha indicado
        for (int i = 0; i < num_rows1; i++) {
          if (strcmp(datos1[i].parametros, fuente) == 0) { //En cada iteración se van comparando los distintos parámetros con el parámetro ingresado con la función strcmp
        	encontrado = 1;
            printf("Parametro: %s, pH: %.2f, Conductividad: %.2f, Turbidez: %.2f, Coliformes: %.2f\n", datos1[i].parametros, datos1[i].pH, datos1[i].conductividad, datos1[i].turbidez, datos1[i].coliformes);
          }
        }
        if (encontrado==0) { //Si el valor que devuelve es un cero, es que no se encontró la fuente
          printf("No se ha encontrado la fuente.\n");
        }
        break;
      }
      
      case 6: {
  		fentrada= fopen(filename1, "r");
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
  		while (fscanf(fentrada, "%s\t%f\t%f\t%f\t%f\n", datos1[num_rows1].parametros, &datos1[num_rows1].pH, &datos1[num_rows1].conductividad, &datos1[num_rows1].turbidez, &datos1[num_rows1].coliformes) !=EOF){
    		num_rows1++;
    		printf("%-20s%-20.2f%-20.2f%-20.2f%-20.2f\n", datos1[num_rows1-1].parametros, datos1[num_rows1-1].pH, datos1[num_rows1-1].conductividad, datos1[num_rows1-1].turbidez, datos1[num_rows1-1].coliformes);
  		}

  		fclose(fentrada);
  
  		printf("\n");
    	getchar();
  
  		break;
	}
	
	  case 7: {
	  	printf("\nLos datos de la fuente con el pH mas alto son:\n");
    	float max_pH = datos1[0].pH;
    	int max_index = 0;
    	for (int i = 1; i < num_rows1; i++) {
        	if (datos1[i].pH > max_pH) {
            	max_pH = datos1[i].pH;
            	max_index = i;
        	}
    	}

    	printf("Nombre: %s\n", datos1[max_index].parametros);
    	printf("pH: %.2f\n", datos1[max_index].pH);
    	printf("Conductividad: %.2f\n", datos1[max_index].conductividad);
    	printf("Turbidez: %.2f\n", datos1[max_index].turbidez);
    	printf("Coliformes: %.2f\n", datos1[max_index].coliformes);
	  	
		break;
	  }
	  
	  case 8: {
	  	printf("\nLos datos de la fuente con el pH mas bajo son:\n");

    float min_pH = 0;
    int min_index = -1;

    for (int i = 0; i < num_rows1; i++) {
        if (datos1[i].pH != 0 && strcmp(datos1[i].parametros, "Parametros") != 0) {
            if (min_index == -1 || datos1[i].pH < min_pH) {
                min_pH = datos1[i].pH;
                min_index = i;
            }
        }
    }

    if (min_index != -1) {
        printf("Nombre: %s\n", datos1[min_index].parametros);
        printf("pH: %.2f\n", datos1[min_index].pH);
        printf("Conductividad: %.2f\n", datos1[min_index].conductividad);
        printf("Turbidez: %.2f\n", datos1[min_index].turbidez);
        printf("Coliformes: %.2f\n", datos1[min_index].coliformes);
    } else {
        printf("No se encontraron fuentes con pH distinto de cero y con campo Parametros informado.\n");
    }
    break;
}	  
	  	
	  case 9: {
	  	printf("\nLos datos de la fuente con el agua menos turbia es: \n");

    	float min_turbidez = 0;
    	int min_index = -1;

    	for (int i = 0; i < num_rows1; i++) {
        	if (datos1[i].turbidez!= 0 && strcmp(datos1[i].parametros, "Parametros") != 0) {
            	if (min_index == -1 || datos1[i].turbidez < min_turbidez) {
                	min_turbidez= datos1[i].turbidez;
                	min_index = i;
            	}
        	}
    	}

    	if (min_index != -1) {
        	printf("Nombre: %s\n", datos1[min_index].parametros);
        	printf("pH: %.2f\n", datos1[min_index].pH);
        	printf("Conductividad: %.2f\n", datos1[min_index].conductividad);
        	printf("Turbidez: %.2f\n", datos1[min_index].turbidez);
        	printf("Coliformes: %.2f\n", datos1[min_index].coliformes);
    	}else {
        	printf("No se encontraron fuentes con pH distinto de cero y con campo Parametros informado.\n");
    	}
	  	
		break;
	  }
	  
	  case 10: {
		printf("Arganzuela.txt\n");
		printf("Barajas.txt\n");
		printf("Carabanchel.txt\n");
		printf("Chamartin.txt\n");
		printf("Lavapies.txt\n");
		printf("RoquetasDeMar.txt\n\n"); 
  		scanf("%s", filename2); //Captura lo que ha escrito el usuario y le asigna una variable
		printf("\n");
		
  		fentrada= fopen(filename2, "r");
  		if(fentrada== NULL){
    		printf("ERROR, no se pudo abrir el archivo.\n");
    		return 0;
  		}

  		//Leer los datos del archivo y almacenarlos en un arreglo de estructuras
  		while (fscanf(fentrada, "%s\t%f\t%f\t%f\t%f\n", datos2[num_rows2].parametros, &datos2[num_rows2].pH, &datos2[num_rows2].conductividad, &datos2[num_rows2].turbidez, &datos2[num_rows2].coliformes) !=EOF){
    	num_rows2++;
  		}
		//Cerramos el fichero
  		fclose(fentrada);
		
		do{
			printf("\n");
		printf("Por favor, introduzca el nombre del archivo con el que desea trabajar: \n");
		printf("1. Realizar las medias del ph de las fuentes de cada fichero y compararlas.\n");
		printf("2. Realizar las medias de la conductividad de las fuentes de cada fichero y compararlas.\n");
		printf("3. Realizar las medias de la turbidez de las fuentes de cada fichero y compararlas.\n");
		printf("4. Realizar las medias de los coliformes presentes en las fuentes de cada fichero y compararlos.\n");
		printf("5. Salir.\n\n");
		scanf("%d",&opcion2);
		printf("\n");
		
    	
		switch (opcion2) {
			case 1: {
				float media_pH1 = calcularMediaPH1(datos1, num_rows1);
				float media_pH2 = calcularMediaPH2(datos2, num_rows2);
				
				printf("La media del ph de %s es %f.\n",filename1,media_pH1);
				printf("La media del ph de %s es %f.\n",filename2,media_pH2);
				
				if(media_pH1>media_pH2){
					printf("El pH de %s es mas acido que el pH de %s.\n",filename1,filename2);
				} else{
					printf("El pH de %s es mas acido que el pH de %s.\n",filename2,filename1);
				}
				
				break;
			}
			
			case 2: {
				float media_conductividad1 = calcularMediaConductividad1(datos1, num_rows1);
				float media_conductividad2 = calcularMediaConductividad2(datos2, num_rows2);
        		printf("La media de la conductividad de %s es %.2f.\n",filename1 , media_conductividad1);
        		printf("La media de la conductividad de %s es %.2f.\n", filename2, media_conductividad2);
        		
        		if(media_conductividad1>media_conductividad2){
					printf("El valor de la conductividad de %s es mayor que el de %s.\n",filename1,filename2);
				} else{
					printf("El valor de la conductividad de %s es mayor que el de %s.\n",filename2,filename1);
				}
        		
				break;
			}
			
			case 3: {
				float media_turbidez1 = calcularMediaTurbidez1(datos1, num_rows1);
				float media_turbidez2 = calcularMediaTurbidez2(datos2, num_rows2);
        		printf("La media de la turbidez de %s es %.2f.\n", filename1, media_turbidez1);
        		printf("La media de la turbidez de %s es %.2f.\n", filename2, media_turbidez2);
        		
        		if(media_turbidez1>media_turbidez2){
					printf("El valor de la turbidez de %s es mayor que el de %s.\n",filename1,filename2);
				} else{
					printf("El valor de la turbidez de %s es mayor que el de %s.\n",filename2,filename1);
				}
				
				break;
			}
			
			case 4: {
				float media_coliformes1 = calcularMediaColiformes1(datos1, num_rows1);
				float media_coliformes2 = calcularMediaColiformes2(datos2, num_rows2);
        		printf("La media del dato coliformes de %s es %.2f.\n", filename1, media_coliformes1);
        		printf("La media del dato coliformes de %s es %.2f.\n", filename2, media_coliformes2);
        		
        		if(media_coliformes1>media_coliformes2){
					printf("El valor de los coliformes de %s es mayor que el de %s.\n",filename1,filename2);
				} else{
					printf("El valor de los coliformes de %s es mayor que el de %s.\n",filename2,filename1);
				}
        		
				break;
			}
			
			case 5: {
				printf("Volviendo a Menu Principal...\n");
        		break;
      		}
      
      		default: {
        	printf("Opcion invalida.\n");
        	break;
      		}
		}
	} while (opcion2<=4);
		
		break;
	}
	  case 11: {
        printf("Gracias por confiar en AquaLife.\n");
        break;
      }
      
      default: {
        printf("Opcion invalida.\n");
        break;
      }
	}
  } while (opcion1<= 10);

  return 0;
}

//DESARROLLO FUNCIONES
float calcularMediaPH1(struct TDatos datos1[], int num_rows1) { //La función realiza el cálculo de la media y devuelve la operación ya calculada
	
    float media_pH1 = 0;
    for (int i = 0; i < num_rows1; i++) {
        media_pH1 += datos1[i].pH;
    }
    media_pH1 /= num_rows1;
    return media_pH1;
}

float calcularMediaPH2(struct TDatos datos2[], int num_rows2) { 
	
    float media_pH2 = 0;
    for (int i = 0; i < num_rows2; i++) {
        media_pH2 += datos2[i].pH;
    }
    media_pH2 /= num_rows2;
    return media_pH2;
}

float calcularMediaConductividad1(struct TDatos datos1[], int num_rows1) { //Los datos para realizar la media se encuntran en una estructura de datos a la cual hay que hacer referencia, asi como al números de columnas que tiene el ficheros donde están los parámetros

	
    float media_conductividad1 = 0;
    for (int i = 0; i < num_rows1; i++) {
        media_conductividad1 += datos1[i].conductividad;
    }
    media_conductividad1 /= num_rows1;
    return media_conductividad1;
}

float calcularMediaConductividad2(struct TDatos datos2[], int num_rows2) {
	
    float media_conductividad2 = 0;
    for (int i = 0; i < num_rows2; i++) {
        media_conductividad2 += datos2[i].conductividad;
    }
    media_conductividad2 /= num_rows2;
    return media_conductividad2;
}

float calcularMediaTurbidez1(struct TDatos datos1[], int num_rows1) { //Cuando realizamos una función, dentro del paréntesis van los datos que necesita la funcón para realizar lo que se le pida y fuera del paréntesis se escribe el nombre de la variable de lo que queremos que devuelva
    float media_turbidez1 = 0;
    for (int i = 0; i < num_rows1; i++) {
        media_turbidez1 += datos1[i].turbidez;
    }
    media_turbidez1 /= num_rows1;
    return media_turbidez1;
}

float calcularMediaTurbidez2(struct TDatos datos2[], int num_rows2) {
    float media_turbidez2 = 0;
    for (int i = 0; i < num_rows2; i++) {
        media_turbidez2 += datos2[i].turbidez;
    }
    media_turbidez2 /= num_rows2;
    return media_turbidez2;
}

float calcularMediaColiformes1(struct TDatos datos1[], int num_rows1){
	float media_coliformes1 = 0;
	for (int i = 0; i < num_rows1; i++){
		media_coliformes1 += datos1[i].coliformes;
	}
	media_coliformes1 /= num_rows1;
	return media_coliformes1;
}

float calcularMediaColiformes2(struct TDatos datos2[], int num_rows2){
	float media_coliformes2 = 0;
	for (int i = 0; i < num_rows2; i++){
		media_coliformes2 += datos2[i].coliformes;
	}
	media_coliformes2 /= num_rows2;
	return media_coliformes2;
}

