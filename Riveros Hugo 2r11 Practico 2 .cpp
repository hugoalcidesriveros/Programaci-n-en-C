#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 3
#define NUM_ASIGNATURAS 7

struct Persona {
	char nombre[20];
	float notas[NUM_ASIGNATURAS];
};

void cargarAlumno(struct Persona alumnos[]);
void cargarNotasRandom(struct Persona alumnos[]);
void imprimirAlumno(struct Persona alumnos[]);
void ordenarAlumno(struct Persona alumnos[]);
void mostrarNombre(struct Persona alumnos[]);
float promedioAlumno(struct Persona alumnos[], int indice);
void mostrarPromedios(struct Persona alumnos[]);

int main() {
	struct Persona Alumnos[NUM_ALUMNOS];
	int opcion;
	int datosCargados = 0;
	
	srand(time(NULL));
	
	do {
		printf("\nMenu de opciones:\n");
		printf("1) Cargar los nombres y las notas de cada alumno\n");
		printf("2)  Cargar los nombres y las notas aleatoriamente\n");
		printf("3) Mostrar las notas cargadas\n");
		printf("4) Mostrar los nombres de los alumnos alfabeticamente\n");
		printf("5) Mostrar el promedio de cada alumno\n");
		printf("6)  Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch (opcion) {
		case 1:
			cargarAlumno(Alumnos);
			datosCargados = 1;
			break;
		case 2:
			cargarNotasRandom(Alumnos);
			datosCargados = 1;
			break;
		case 3:
			if (datosCargados) {
				imprimirAlumno(Alumnos);
			} else {
				printf("Las notas no han sido cargadas, seleccione opcion 1 o 2\n");
			}
			break;
		case 4:
			if (datosCargados) {
				ordenarAlumno(Alumnos);
				mostrarNombre(Alumnos);
			} else {
				printf("Las notas no han sido cargadas, seleccione opcion 1 o 2\n");
			}
			break;
		case 5:
			if (datosCargados) {
				mostrarPromedios(Alumnos);
			} else {
				printf("Las notas no han sido cargadas, seleccione opcion 1 o 2\n");
			}
			break;
		case 6:
			printf("Programa Finalizado.\n");
			break;
		default:
			printf("Opcion no valida. Intente de nuevo.\n");
		}
	} while (opcion != 6);
	
	return 0;
}

void cargarAlumno(struct Persona alumnos[]) {
	int i, j;
	for (i = 0; i < NUM_ALUMNOS; i++) {
		printf("\tEscribe el nombre del alumno %d: \n", i + 1);
		scanf("%s", alumnos[i].nombre);
		for (j = 0; j < NUM_ASIGNATURAS; j++) {
			printf("\tEscribe la nota de la asignatura %d: \n", j + 1);
			scanf("%f", &alumnos[i].notas[j]);
		}
	}
}

void cargarNotasRandom(struct Persona alumnos[]) {
	int i, j;
	for (i = 0; i < NUM_ALUMNOS; i++) {
		printf("\tEscribe el nombre del alumno %d: \n", i + 1);
		scanf("%s", alumnos[i].nombre);
		for (j = 0; j < NUM_ASIGNATURAS; j++) {
			alumnos[i].notas[j] = rand() % 10;
		}
	}
}

void imprimirAlumno(struct Persona alumnos[]) {
	int i, j;
	for (i = 0; i < NUM_ALUMNOS; i++) {
		printf("\tEl nombre del alumno %d es: %s\n", i + 1, alumnos[i].nombre);
		for (j = 0; j < NUM_ASIGNATURAS; j++) {
			printf("\tLa nota de la asignatura %d es: %.2f\n", j + 1, alumnos[i].notas[j]);
		}
		printf("\n");
	}
}

void ordenarAlumno(struct Persona alumnos[]) {
	struct Persona cambio;
	int i, j;
	for (i = 0; i < NUM_ALUMNOS - 1; i++) {
		for (j = 0; j < NUM_ALUMNOS - i - 1; j++) {
			if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
				cambio = alumnos[j];
				alumnos[j] = alumnos[j + 1];
				alumnos[j + 1] = cambio;
			}
		}
	}
}

void mostrarNombre(struct Persona alumnos[]) {
	int i;
	printf("\n\tLos nombres ordenados son:\n");
	for (i = 0; i < NUM_ALUMNOS; i++) {
		printf("%s\n", alumnos[i].nombre);
	}
}

float promedioAlumno(struct Persona alumnos[], int indice) {
	int i;
	float suma = 0;
	float prom=0;
	for (i = 0; i < NUM_ASIGNATURAS; i++) {
		suma = alumnos[indice].notas[i]+suma;
	}
	prom=suma / NUM_ASIGNATURAS;
	return prom;
}

void mostrarPromedios(struct Persona alumnos[]) {
	float Auxiliar;
	for (int i = 0; i < NUM_ALUMNOS; i++) {
		Auxiliar = promedioAlumno(alumnos, i);
		printf("\tEl promedio del alumno %s es: %f\n", alumnos[i].nombre, Auxiliar);
		printf("\n");
	}
}
