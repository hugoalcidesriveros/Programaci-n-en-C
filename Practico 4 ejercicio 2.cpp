#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearArchivoOrigen(const char *nombre) {
	FILE *archivo = fopen(nombre, "wt");
	if (archivo == NULL) {
		printf("No se pudo crear el archivo de origen %s.\n", nombre);
		perror("Error");
		exit(1);
	}
	
	const char *contenido = "Este es un archivo de ejemplo.\nEsta es una segunda línea.";
	fprintf(archivo, "%s", contenido);
	
	fclose(archivo);
	printf("Se ha creado el archivo de origen %s con contenido de ejemplo.\n", nombre);
}

int main() {
	char origen[100];
	char destino[100];
	FILE *archivoOrigen, *archivoDestino;
	char buffer[1024]; // Buffer para leer bloques de datos
	size_t bytes;
	
	// Pedir al usuario que ingrese el nombre del archivo de origen (sin extensión)
	printf("Ingrese el nombre del archivo de origen (sin extensión): ");
	scanf("%s", origen);
	
	// Añadir la extensión .txt al archivo de origen
	strcat(origen, ".txt");
	
	// Crear el archivo de origen con contenido de ejemplo
	crearArchivoOrigen(origen);
	
	// Pedir al usuario que ingrese el nombre del archivo de destino (sin extensión)
	printf("Ingrese el nombre del archivo de destino (sin extensión): ");
	scanf("%s", destino);
	
	// Añadir la extensión .txt al archivo de destino
	strcat(destino, ".txt");
	
	// Abrir el archivo de origen en modo lectura de texto
	archivoOrigen = fopen(origen, "rt");
	if (archivoOrigen == NULL) {
		printf("No se pudo abrir el archivo de origen %s.\n", origen);
		perror("Error");
		return 1;
	}
	
	// Abrir el archivo de destino en modo escritura de texto
	archivoDestino = fopen(destino, "wt");
	if (archivoDestino == NULL) {
		printf("No se pudo crear el archivo de destino %s.\n", destino);
		perror("Error");
		fclose(archivoOrigen);
		return 1;
	}
	
	// Copiar el contenido del archivo de origen al archivo de destino
	while ((bytes = fread(buffer, 1, sizeof(buffer), archivoOrigen)) > 0) {
		fwrite(buffer, 1, bytes, archivoDestino);
	}
	
	// Cerrar ambos archivos
	fclose(archivoOrigen);
	fclose(archivoDestino);
	
	printf("El archivo %s ha sido copiado a %s exitosamente como archivos de texto.\n", origen, destino);
	
	return 0;
}
