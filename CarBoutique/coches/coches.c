/*
 * coches.c
 *
 *  Created on: 7 abr. 2021
 *      Author: guill
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coches.h"


void menuMarca(Marca m) { //Pasamos marca (no puntero) para poder crear la marca antes de llamar a esta funcion y poder inciar sesion
	char opcion;
	do {
		printf("\n\n---------Has iniciado sesión con la marca %s-------\n\n",
				m.nombre);
		printf("1. Ver listado de modelos actuales.\n");
		printf("2. Introducir nuevo modelo\n");
		printf("3. Pulse q para cerrar sesión\n");
		printf("Introduce la opción:");

		fflush(stdout);
		opcion = getchar();
		fflush(stdin);

		switch (opcion) {
		case '1':
			listarCoches();
			break;
		case '2': {
			Coche *c = malloc(sizeof(Coche));
			memcpy(c->nombreMarca, m.nombre, strlen(m.nombre) + 1);
			printf(c->nombreMarca);
			menuIntroducirCoche(c);
			guardarCocheFichero(c);
			break;
		}
		case 'q':
			seleccionInicioSesion();
			break;

		}

	} while (opcion != 'q');
}

int contadorCoches;
void menuIntroducirCoche(Coche *c) {
	printf("\n\n------Introducción de un nuevo vehículo-------\n\n");

	printf("Introduce el id del vehículo:");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &c->id); //scanf recibe una direccion

	printf("\nIntroduce el nombre del modelo:");
	fflush(stdout);
	fflush(stdin);
	gets(c->modelo);

	printf("\nIntroduce el color del modelo:");
	fflush(stdout);
	fflush(stdin);
	gets(c->color);

	printf("\nIntroduce la potencia del modelo:");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &c->potencia);

	FILE *ficheroContador;
	char ch;
	ficheroContador = fopen("contador.txt", "r");
	putchar(ch);
	contadorCoches = (int)ch;
	fclose(ficheroContador);

	contadorCoches++;
	printf("Contador : %i", contadorCoches); //para saber cuantos lleva


	FILE* file2;
	file2 = fopen("contador.txt", "w");
	fprintf(file2, "%c", (char)contadorCoches);
	fclose(file2);

}

void guardarCocheFichero(Coche *c) {
	FILE *file;
	file = fopen("coches.dat", "rb");
	Coche *coches = malloc(sizeof(Coche) * (contadorCoches));
	if(!contadorCoches <= 1){
		fread(coches, sizeof(Coche), contadorCoches-1, file);
	}

	//fclose(file);

	FILE *file2;
	file2 = fopen("coches.dat", "wb");
	coches[contadorCoches-1] = *c;
	//memcpy(coches[contadorCoches], *c, sizeof(Coche));
	fputc(contadorCoches, file);
	fwrite(coches, sizeof(Coche), contadorCoches, file2);

	//fclose(file);
}

void listarCoches(Marca m) {
	printf("-----------Coches registrados de la marca-------------\n");
	FILE *file;
	Coche *coches;

	file = fopen("coches.dat", "rb");
	int num = fgetc(file);

	coches = (Coche*) malloc(num * sizeof(Coche));
	fread(coches, sizeof(Coche), num, file);
	//fclose(file);

	for (int i = 0;i < num; i++) {
		//if(coches[i].nombreMarca == m.nombre){
			printf("%i : %s (%i CV)\n", coches[i].id, coches[i].modelo, coches[i].potencia);
		//}
	}


}
