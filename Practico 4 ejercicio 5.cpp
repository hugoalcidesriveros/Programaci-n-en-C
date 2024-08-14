#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define XOR_KEY 0xAA // Clave para el cifrado XOR

void xorEncrypt(char *texto, size_t length);
void guardarTextoEncriptado(const char *filename, char *texto, size_t length);
void recuperarTextoEncriptado(const char *filename, char *buffer, size_t buffer_size);
void crearArchivoEntrada(const char *filename);

int main() {
	char texto[BUFFER_SIZE];
	char archivoEntrada[100], archivoSalida[100];
	
	printf("Ingrese el nombre del archivo de entrada: ");
	scanf("%s", archivoEntrada);
	printf("Ingrese el nombre del archivo de salida: ");
	scanf("%s", archivoSalida);
	
	// Verificar si el archivo de entrada existe
	FILE *fileEntrada = fopen(archivoEntrada, "r");
	if (fileEntrada == NULL) {
		printf("El archivo de entrada no existe. Creando un nuevo archivo...\n");
		crearArchivoEntrada(archivoEntrada);
		fileEntrada = fopen(archivoEntrada, "r");
		if (fileEntrada == NULL) {
			perror("Error al crear el archivo de entrada");
			return 1;
		}
	}
	
	// Leer texto del archivo de entrada
	size_t bytesRead = fread(texto, sizeof(char), BUFFER_SIZE, fileEntrada);
	fclose(fileEntrada);
	
	// Encriptar el texto
	xorEncrypt(texto, bytesRead);
	
	// Guardar el texto encriptado en el archivo de salida
	guardarTextoEncriptado(archivoSalida, texto, bytesRead);
	
	// Recuperar el texto encriptado desde el archivo de salida
	char textoRecuperado[BUFFER_SIZE];
	recuperarTextoEncriptado(archivoSalida, textoRecuperado, bytesRead);
	
	// Desencriptar el texto recuperado
	xorEncrypt(textoRecuperado, bytesRead);
	
	printf("Texto desencriptado recuperado del archivo: \n%s\n", textoRecuperado);
	
	return 0;
}

void xorEncrypt(char *texto, size_t length) {
	for (size_t i = 0; i < length; i++) {
		texto[i] ^= XOR_KEY; // Aplicar XOR con la clave
	}
}

void guardarTextoEncriptado(const char *filename, char *texto, size_t length) {
	FILE *fileSalida = fopen(filename, "wb");
	if (fileSalida == NULL) {
		perror("Error al abrir el archivo de salida");
		return;
	}
	
	fwrite(texto, sizeof(char), length, fileSalida);
	fclose(fileSalida);
}

void recuperarTextoEncriptado(const char *filename, char *buffer, size_t buffer_size) {
	FILE *fileEntrada = fopen(filename, "rb");
	if (fileEntrada == NULL) {
		perror("Error al abrir el archivo para recuperar el texto encriptado");
		return;
	}
	
	fread(buffer, sizeof(char), buffer_size, fileEntrada);
	fclose(fileEntrada);
}

void crearArchivoEntrada(const char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		perror("Error al crear el archivo de entrada");
		return;
	}
	
	printf("Ingrese el texto para el archivo de entrada (Ctrl+D para terminar):\n");
	char c;
	while ((c = getchar()) != EOF) {
		fputc(c, file);
	}
	
	fclose(file);
}
