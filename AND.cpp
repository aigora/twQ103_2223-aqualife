#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_ROWS 1000

struct TFuente{   //Creamos una estructura que nos permita tener acceso a todos los todos los campos de las fuentes
	char nombre[50];
	float ph;
	float turbidez;
	float conductividad;
	int coliformes;
};

