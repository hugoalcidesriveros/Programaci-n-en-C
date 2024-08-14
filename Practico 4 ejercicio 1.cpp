#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void reemplazarPalabras(const char *archivoOrigen, const char *archivoDestino, const char *palabra1, const char *palabra2);
int verificarArchivo(const char *nombreArchivo);

int main() {
	char nombreOrigen[MAX_LEN];
	char nombreDestino[MAX_LEN];
	char palabra1[MAX_LEN];
	char palabra2[MAX_LEN];
	
	// Entrada del nombre del archivo de origen
	printf("Ingrese el nombre del archivo de origen (con extensión .txt): ");
	scanf("%s", nombreOrigen);
	
	// Verificar si el archivo de origen existe y es válido
	if (!verificarArchivo(nombreOrigen)) {
		printf("El archivo de origen no existe o no es válido.\n");
		return 1;
	}
	
	// Entrada del nombre del archivo de destino
	printf("Ingrese el nombre del archivo de destino (con extensión .txt): ");
	scanf("%s", nombreDestino);
	
	// Verificar si el archivo de destino existe y es válido
	if (!verificarArchivo(nombreDestino)) {
		printf("El archivo de destino no existe o no es válido.\n");
		return 1;
	}
	
	// Entrada de las palabras para reemplazo
	printf("Ingrese la primera palabra a reemplazar: ");
	scanf("%s", palabra1);
	
	printf("Ingrese la segunda palabra de reemplazo: ");
	scanf("%s", palabra2);
	
	// Copiar y reemplazar palabras en el archivo destino
	reemplazarPalabras(nombreOrigen, nombreDestino, palabra1, palabra2);
	
	printf("Se ha completado el proceso de reemplazo.\n");
	
	return 0;
}

void reemplazarPalabras(const char *archivoOrigen, const char *archivoDestino, const char *palabra1, const char *palabra2) {
	FILE *origen = fopen(archivoOrigen, "rt");
	FILE *destino = fopen(archivoDestino, "wt");
	
	if (origen == NULL || destino == NULL) {
		printf("Error abriendo archivos.\n");
		if (origen) fclose(origen);
		if (destino) fclose(destino);
		return;
	}
	
	char buffer[1024];
	size_t longitudPalabra1 = strlen(palabra1);
	size_t longitudPalabra2 = strlen(palabra2);
	
	while (fgets(buffer, sizeof(buffer), origen) != NULL) {
		char *pos = buffer;
		while ((pos = strstr(pos, palabra1)) != NULL) {
			fwrite(buffer, 1, pos - buffer, destino);
			fwrite(palabra2, 1, longitudPalabra2, destino);
			pos += longitudPalabra1;
		}
		fwrite(pos, 1, strlen(pos), destino);
	}
	
	fclose(origen);
	fclose(destino);
}

int verificarArchivo(const char *nombreArchivo) {
	FILE *archivo = fopen(nombreArchivo, "rt");
	if (archivo == NULL) {
		return 0; // El archivo no existe o no se pudo abrir
	}
	fclose(archivo);
	return 1; // El archivo existe y se pudo abrir correctamente
}
