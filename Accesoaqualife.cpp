#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_USERS 100

struct Usuario {
  char nombre[MAX_LENGTH];
  char contrasena[MAX_LENGTH];
};

int main() {
  FILE* fichero;
  
  char filename[] = "usuario.txt";
  struct Usuario usuarios[MAX_USERS];
  int num_usuarios = 0;

  // Abrir el archivo de usuarios
  fichero = fopen(filename, "r");
  if (fichero == NULL) {
    printf("No se pudo abrir el archivo de usuarios.\n");
    return 0;
  }

  // Leer los datos del archivo y almacenarlos en un arreglo de estructuras
  while (fscanf(fichero, "%s\t %s\n", usuarios[num_usuarios].nombre, usuarios[num_usuarios].contrasena) != EOF) {
    num_usuarios++;
  }

  fclose(fichero);

  // Solicitar el nombre de usuario y contraseña al usuario
  char nombre_ingresado[MAX_LENGTH];
  char contrasena_ingresada[MAX_LENGTH];

  printf("Introduzca su nombre de usuario: \n");
  scanf("%s", nombre_ingresado);

  printf("Introduzca su contrasena: \n");
  scanf("%s", contrasena_ingresada);

  // Verificar si el nombre de usuario y la contraseña coinciden con los datos del archivo
  int acceso_permitido = 0;
  for (int i = 0; i < num_usuarios; i++) {
    if (strcmp(nombre_ingresado, usuarios[i].nombre) == 0 && strcmp(contrasena_ingresada, usuarios[i].contrasena) == 0) {
      acceso_permitido = 1;
      break;
    }
  }

  // Mostrar el resultado del acceso
  if (acceso_permitido) {
    printf("ACCESO PERMITIDO. BIENVENIDO\n");

    // Llamar al programa existente
    system("AND");
  } else {
    printf("ACCESO DENEGADO. Nombre de usuario o contrasena incorrecta.\n");
  }

  return 0;
}
