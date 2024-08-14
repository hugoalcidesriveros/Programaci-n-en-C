#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void crearArchivoOrigen(const char *nombre);
void escribirEnArchivo(const char *nombreArchivo, const char *contenido);

int main() {
	char origen[MAX_LEN];
	char destino[MAX_LEN];
	char texto[MAX_LEN];
	
	// Pedir al usuario que ingrese el nombre del archivo de origen (sin extensión)
	printf("Ingrese el nombre del archivo de origen (sin extensión): ");
	scanf("%s", origen);
	
	// Añadir la extensión .txt al archivo de origen
	strcat(origen, ".txt");
	
	// Crear el archivo de origen con contenido de ejemplo si no existe
	crearArchivoOrigen(origen);
	
	// Pedir al usuario que ingrese el nombre del archivo de destino (sin extensión)
	printf("Ingrese el nombre del archivo de destino (sin extensión): ");
	scanf("%s", destino);
	
	// Añadir la extensión .txt al archivo de destino
	strcat(destino, ".txt");
	
	// Mostrar opciones para escribir en archivos
	printf("\nEscriba el texto que desea guardar:\n");
	scanf(" %[^\n]", texto);
	
	// Escribir en el archivo de origen
	escribirEnArchivo(origen, texto);
	printf("Texto guardado en el archivo de origen %s.\n", origen);
	
	// Escribir en el archivo de destino
	escribirEnArchivo(destino, texto);
	printf("Texto guardado en el archivo de destino %s.\n", destino);
	
	return 0;
}

void crearArchivoOrigen(const char *nombre) {
	FILE *archivo = fopen(nombre, "r");
	if (archivo == NULL) {
		archivo = fopen(nombre, "w");
		if (archivo == NULL) {
			printf("No se pudo crear el archivo de origen %s.\n", nombre);
			perror("Error");
			exit(1);
		}
		const char *contenido = "Este es un archivo de ejemplo.\nEsta es una segunda línea.";
		fprintf(archivo, "%s", contenido);
		fclose(archivo);
		printf("Se ha creado el archivo de origen %s con contenido de ejemplo.\n\t", nombre);
	} else {
		fclose(archivo);
	}
}

void escribirEnArchivo(const char *nombreArchivo, const char *contenido) {
	FILE *archivo = fopen(nombreArchivo, "a");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo %s para escritura.\n", nombreArchivo);
		perror("Error");
		return;
	}
	
	fprintf(archivo, "%s\n", contenido);
	fclose(archivo);
}
