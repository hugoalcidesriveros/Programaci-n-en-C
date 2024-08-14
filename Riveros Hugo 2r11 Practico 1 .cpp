#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Maxf 10
#define Maxc 10
#define Max 10



void MatrizRellenar(int Matriz[Maxf][Maxc],int dim);
void MatrizMostrar(int Matriz[Maxf][Maxc],int dim);
void MatrizSuma(int Matriz[Maxf][Maxc],int Matriz2[Maxf][Maxc],int Matriz3[Maxf][Maxc],int dim);
void VectorRellenar(int Vector[Max],int dim);
void VectorMostrar(int Vector[Max],int dim);
void MatrizRamdon(int Matriz[Maxf][Maxc],int dim);
void VectorRamdon(int Vector[Max],int dim);
void MatrizVectorMultiplicar(int Matriz[Maxf][Maxc],int Vector[Max],int Vector2[Max],int dim);
	

int main(){
	
	int Matriz [Maxf][Maxc];
	int Matriz2 [Maxf][Maxc];
	int Matriz3 [Maxf][Maxc];
	int MatrizRand [Maxf][Maxc];
	int Vector [Max];
	int Vector2 [Max];
	int VectorRand [Max];
	int dim=12;
	int opc;
	int opc1;
	int opc2;
	int a=1; // variables que me permiten saber si pasaron por una opcion
	int b=1; // variables que me permiten saber si pasaron por una opcion

	srand(time(NULL));	
	printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
	
	
	do{
		printf("\n\n1) Ingresar la dimension de la Matriz y Vector la dimension no deben ser mayores a 10\n\n");
		printf("2) Ingresar los datos de los elementos de las matrices y del vector para operar\n\n");
		printf("3) Generar aleatoriamente los datos de los elementos de la matriz y del\n vector\n\n");
		printf("4) Visualizar Matriz\n\n");
		printf("5) Visualizar Vector\n\n");
		printf("6) Suma y Resta de Matrices\n\n");
		printf("7) Multiplicacion de Matriz por el vector\n\n"); //opcion de matriz A o B por el Vector
		printf("8) Salir\n\n");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
			
		case 1: // ingresar dimensiones 
			
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			printf ("\ningrese la cantidad de dimensiones: ");
			scanf("%d",&dim);
			while(dim>10||dim<0){
				printf ("\n Error al ingresar, dimension Maxima 10\n ");
				printf ("\ningrese la cantidad de dimensiones: ");
				scanf("%d",&dim);
				
			};
			break;
		case 2: // datos de matrices y vector
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			printf ("\nRellene la matriz A\n");
			MatrizRellenar(Matriz,dim);
			printf ("\nRellene la matriz B\n");
			MatrizRellenar(Matriz2,dim);
			printf ("\nRellene El Vector A\n");
			VectorRellenar(Vector,dim);
			a++;
			break;
		case 3: // cargar datos de Matriz y Vector con numeros aleatorios del -100 al 100
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			printf ("\nLa Matriz C ha sido rellenada aleatoriamente");
			MatrizRamdon(MatrizRand,dim);
			printf ("\nEl Vector B ha sido rellenado aleatoriamente");
			VectorRamdon(VectorRand,dim);
			b++;
			break;
		case 4:
			if(dim<10&&a>1){
			
			printf ("\nLa matriz A es: \n ");
			MatrizMostrar(Matriz,dim);
			printf ("\nLa matriz B es: \n ");
			MatrizMostrar(Matriz2,dim);

			
			}else
		{
				printf("\n\n¡¡La dimension o las Matrices no estan cargadas!!\nDebe cargarlas para operar, con la opcion 2\n");
			}
			if(dim<10&&b>1){
				printf ("\nLa Matriz aletoria C  es: \n ");
				MatrizMostrar(MatrizRand,dim);
			}else{
				printf("\n\n¡¡¡No genero la Matriz y Vector aleatorios, debe seleccionar opcion 3!!!\n");
			}
			
			break;
		case 5:
			if(dim<10&&a>1){
			printf ("El vector A es\n ");
			VectorMostrar(Vector,dim);
			}else {
				printf("\n\n¡¡El Vector no esta cargado!!\nDebe cargarlas para operar, con la opcion 2\n");
			}
			break;
		case 6:
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			if(dim<10&&a>1){
			do{
				printf("\n\nElegir Matrices para sumar\n");
				printf("8-  Matriz A + Matriz B\n");
				printf("9-  Matriz A + Matric C\n");
				printf("10-  Matriz B + Matriz C\n");
				printf("11-  Salir\n");
				scanf("%d",&opc1);
				system("cls");
				switch(opc1){
					
			case 8:
			MatrizSuma(Matriz,Matriz2,Matriz3, dim);
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			printf ("La suma de la matriz A y matriz B es: \n ");
			MatrizMostrar(Matriz3,dim);
				break;
			case 9:
				printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
				MatrizSuma(Matriz,MatrizRand,Matriz3, dim);
				printf ("La suma de la matriz A y matriz C es: \n ");
				MatrizMostrar(Matriz3,dim);
				break;
			case 10:
				printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
				MatrizSuma(Matriz2,MatrizRand,Matriz3, dim);
				printf ("La suma de la matriz B y matriz C es: \n ");
				MatrizMostrar(Matriz3,dim);
				break;
			case 11:
					
				default:
					;
			}
			}
			while(opc1!=11);
			}else{
				printf("\n\n¡¡La dimension o las Matrices no estan cargadas!!\nDebe cargarlas para operar, con la opcion 2\n");
			}
			break;
			
		case 7:  // Multiplicacion y division de Matrices por vector
			printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
			if(dim<10&&a>1){
			do{
			printf("Elegir Matrices A o B para Multiplicar por Vector A\n");
			printf("12-  Matriz A X Vector A\n");
			printf("13-  Matriz B X Vector A\n");
			printf("14-  salir\n");
			scanf("%d",&opc2);
				system("cls");
				switch(opc2){
					
				case 12:
					printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
					
							MatrizVectorMultiplicar(Matriz,Vector,Vector2,dim);
							printf ("\nla multiplicacion de la matriz A y el vector A es\n ");
							VectorMostrar(Vector2,dim);
							break;
				case 13:
					printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
							MatrizVectorMultiplicar(Matriz2,Vector,Vector2,dim);
							printf ("\nla multiplicacion de la matriz B y el vector A es\n ");
							VectorMostrar(Vector2,dim);
							break;	
				case 14: printf("salir\n");
				printf("-----------------------TRABAJO PRACTICO INFORMATICA II-------------------------\n\n\n");
						default:
							;
						}
					}
					while(opc2!=14);
			}else{
				printf("\n\n¡¡La dimension o las Matrices no estan cargadas!!\nDebe cargarlas para operar, con la opcion 2\n");
			}
					break;
				case 8:
			break;
		default:
			printf("\nrror en el ingreso, vuelva a elegir Opcion\n\n");
			break;
		}
	}while(opc!=8);
	
	return 0;
}

void MatrizRellenar(int Matriz[Maxf][Maxc],int dim){
	int i=0;
	int j=0;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			scanf("%d",&Matriz[i][j]);
			while(Matriz[i][j]>100|| Matriz[i][j]< -100){
			printf("error, el valor a ingresar van del -100 a 100, vuelva a ingresar\n");
			scanf("%d",&Matriz[i][j]);
			};
		}
	}
}
void MatrizMostrar(int Matriz[Maxf][Maxc],int dim){
	int i=0;
	int j=0;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("%d\t",Matriz[i][j]);
		}
		printf("\n");
	}
}
void MatrizSuma(int Matriz[Maxf][Maxc],int Matriz2[Maxf][Maxc],int Matriz3[Maxf][Maxc],int dim){
	int i=0;
	int j=0;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			Matriz3[i][j]=Matriz[i][j]+ Matriz2[i][j];
		}
	}
}
void VectorRellenar(int Vector[Max],int dim){
	int j=0;
	for(j=0;j<dim;j++){
		scanf("%d",&Vector[j]);
	}
}
void VectorMostrar(int Vector[Max],int dim){
	int j=0;
		for(j=0;j<dim;j++){
		printf("%d\t",Vector[j]);
		printf("\n");
	}
}
void MatrizRamdon(int Matriz[Maxf][Maxc],int dim){
	int i=0;
	int j=0;
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			Matriz[i][j]=-100 +rand()%(100+1 -(-100)); //  numero inferior+rand()%(numero superior+1-numeroinferior
		}
	}
}
void VectorRamdon(int Vector[Max],int dim){
	int j=0;
	for(j=0;j<dim;j++){
		Vector[j]=rand()%100;
	}
}

void MatrizVectorMultiplicar(int Matriz[Maxf][Maxc],int Vector[Max],int Vector2[Max], int dim){
	int i=0;
	int j=0;
	int aux=0;
	int a=0;
	int b=0;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			a=(Matriz[i][j]*Vector[j]);	// fila*culmas mxn*nx1=mx1 otro vector fila
			aux=aux+a;
			Vector2[b]=aux;
		}
		a=0;
		aux=0;
		b++;
	}
}

