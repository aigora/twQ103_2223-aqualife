#include <stdio.h>
int main (){
	//Declaración de variables 
	int opcion;
	
	do{
		
	printf("Bienvenidos a AquaLife\n");
	printf("Seleccione la opcion que desee: \n");
	printf("1-Buscar las fuentes mas destacadas con agua potable \n");
	printf("2-Buscar las fuentes mas cercanas a mi ubicacion\n");
	printf("3-Buscar fuentes con espectaculo de agua\n");
	printf("4-Buscar informacion acerca de la fuente que desee\n");
	
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			printf("\n");
			break;
			
		case 2:
			printf("\n");
			break;
			
		case 3:
			printf("");
			break;
			
		case 4: 
			printf("");
			break;
			
		default:
			printf("");
			break;
	}

	}while(opcion>4);


return 0;
}
