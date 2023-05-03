#include <stdio.h>
#define NUM_FUENTES 25

struct TFuente{   //Creamos una estructura que nos permita tener acceso a todos los todos los campos de las fuentes
	char nombre[50];
	float ph;
	float turbidez;
	float conductividad;
	int coliformes;
};

float  mediaPh(struct TFuente[]);

int main(){
	
	FILE *fichero=fopen("DATOS.txt", "r"); //Los datos est�n guardados en un fichero, queremos abrir el fichero para poder hacer referencia a ellos
	if(fichero==NULL){
		printf("ERROR, no se pudo abrir el fichero correctamente\n");
		return 0;
	}
	char nombre[50];
	float ph;
	float turbidez;
	float conductividad;
	float coliformes;
	
	while(fscanf("%s %f %f %f %d"))
	struct TFuente barrio[NUM_FUENTES];
	
	
	
	int opcion;
	do{
	printf("Bienvenidos a AquaLife\n");
	printf("Seleccione la opcion que desee\n");
	printf("1-Buscar las fuentes mas destacadas con agua potable\n");
	printf("2-Buscar las fuentes mas cercanas a mi ubicacion\n");
	printf("3-Buscar fuentes con espectaculo de agua\n");
	printf("4-Buscar fuentes emblematicas\n");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			printf("1\n");
			break;
		
		case 2:
			printf("2\n");
			break;
		
		case 3:
			printf("3\n");
			break;
		
		case 4: 
			printf("4\n");
			break;
		default:
			printf("Error. No se ha encontrado ningun resultado\n");
			
	}
	} while(0<opcion<4);
}
