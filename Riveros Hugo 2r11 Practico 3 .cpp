#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encriptar (char *frase,char *encripfrase, char *pass);
void desencriptar (char *frase,char *encripfrase, char *pass);

int main(){
	
	char frase[100];
	char clave[100];
	char frase_guardada[100];
	char frase_desencriptada[100];
	int opcion;

	
	do {
		// Mostrar el menú
		printf("\nMenu:\n");
		printf("1. Ingrese una frase y clave para encriptar\n");
		printf("2. Desencriptar frase 2\n");
		printf("3. Salir\n");
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		system("cls");
		// Limpiar el buffer de entrada
		while (getchar() != '\n');
		
		// Procesar la opción seleccionada
		switch (opcion) {
		case 1:
		
			printf("Ha seleccionado la Opción 1.\n");
			printf("ingrese frase para que luego sea encriptada\n");
			fgets(frase,sizeof(frase),stdin);
			frase[strcspn(frase,"\n")]='\0';
			
			
			printf("ingrese clave\n");
			fgets(clave,sizeof(clave),stdin);
			clave[strcspn(clave,"\n")]='\0';
			
			encriptar (frase,frase_guardada,clave);
			printf("la frase ha sido encriptada");
			printf("\n la frase quedo guardada: %s\n",frase_guardada);
		
			break;
		case 2:
			printf("Ha seleccionado la Opción 2.\n");
			desencriptar(frase_guardada,frase_desencriptada,clave);
			printf("la frase desencriptada es: %s\n",frase_desencriptada);
			break;
		case 3:
			printf("Saliendo del programa.\n");
			break;
		default:
			printf("Opción no válida. Por favor, seleccione una opción del 1 al 4.\n");
			break;
		}
		
	} while (opcion != 3);
	
	
	
	
		
	
	
	
	
	
	
	
	return 0;
}
void encriptar (char *frase,char *encripfrase, char *pass){
	int i;
	int pass_largo;
	int largo;
	largo=strlen(frase);
	pass_largo=strlen(pass); 

		for(i=0;i<largo;i++){		
		encripfrase[i]= frase[i]^pass[i%pass_largo];  //Aor
	}
	encripfrase[largo]='\0';
	
	
}
void desencriptar (char *frase,char *encripfrase, char *pass){
	int i;
	int pass_largo;
	int largo;
	largo=strlen(frase);
	pass_largo=strlen(pass); 
	
	for(i=0;i<largo;i++){		
		encripfrase[i]= frase[i]^pass[i%pass_largo];  //Aor
	}
	encripfrase[largo]='\0';
		
		
}

