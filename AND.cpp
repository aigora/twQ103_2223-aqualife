#include <stdio.h>
#define NUM_FUENTES 25

struct TFuente{   //Creamos una estructura que nos permita tener acceso a todos los todos los campos de las fuentes
	char nombre[50];
	float ph;
	float turbidez;
	float conductividad;
	int coliformes;
};

