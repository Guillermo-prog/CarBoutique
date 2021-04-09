#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coches.h"
#include "../funciones/funciones.h"

#define MAX_LINE 21

/*
 * MENU MARCAS y MENU USUARIO
 */
void menuMarca(Marca m) { //Pasamos marca (no puntero) para poder crear la marca antes de llamar a esta funcion y poder inciar sesion
	char opcion;
	do {
		printf("\n\n---------Has iniciado sesión con la marca %s-------\n\n",
				m.nombre);
		printf("1. Ver listado de modelos actuales de esta marca.\n");
		printf("2. Introducir nuevo modelo.\n");
		printf("3. Ver listado de usuarios registrados en el concesionario.\n");
		printf(
				"4. Ver listado de las marcas registradas en el concesionario.\n");
		printf("5. Pulse 'q' para cerrar sesión.\n");
		printf("Introduce la opción:");

		fflush(stdout);
		opcion = getchar();
		fflush(stdin);

		switch (opcion) {
		case '1': {
			listarCochesDeMarca(m); //De momento simplemente printea todos los coches del fichero
			break;
		}
		case '2': {
			Coche *c = menuIntroducirCoche(m);

			liberarCoche(c); //Se libera el puntero despues de guardar el coche en el fichero
			break;
		}
		case '3': {
			listarUsuarios();
			break;
		}
		case '4':
			listarMarcas();
			break;
		case 'q':
			seleccionInicioSesion();
			break;
		default:
			printf("\nOpción incorrecta.");
		}

	} while (opcion != 'q');
}

/*
 * MENU USUARIO
 */
void menuUsuario(Usuario *u) {
//	char opcion;
//		do {
//			printf("\n\n---------Has iniciado sesión con usuario %s-------\n\n",
//					u->nombre);
//			printf("1. Ver listado de usuarios actuales.\n");
//			printf("2. Introducir nuevo modelo\n");
//			printf("3. Pulse q para cerrar sesión\n");
//			printf("Introduce la opción:");
//
//			fflush(stdout);
//			opcion = getchar();
//			fflush(stdin);
//
//			switch (opcion) {
//			case '1':
//	//			listarCoches();
//	//			break;
//			case '2': {
//				Coche *c = malloc(sizeof(Coche));
//				memcpy(c->nombreMarca, m.nombre, strlen(m.nombre) + 1);
//				printf(c->nombreMarca);
//				menuIntroducirCoche(c);
//				guardarCocheFichero(c);
//				break;
//			}
//			case 'q':
//				seleccionInicioSesion();
//				break;
//
//			}
//
//		} while (opcion != 'q');
}

/*
 * CREAR COCHES DENTRO DE MENU MARCAS
 * INTRODUCIR ESOS COCHES AL FICHERO
 */

Coche* crearCoche() {
	Coche *c = malloc(sizeof(Coche));
	c->id = 0;
	c->modelo = NULL;
	c->nombreMarca = NULL;
	c->potencia = 0;
	c->color = NULL;
	return c;
}
void guardarCocheEnFichero(Coche *c) {
	CocheFichero save;
	save.id = c->id;
	save.potencia = c->potencia;
	strcpy(save.modelo, c->modelo);
	strcpy(save.color, c->color);
	strcpy(save.nombreMarca, c->nombreMarca);

	//DE FORMA BINARIA
	FILE *file;
	file = fopen("coches.dat", "ab");
	fputc(1, file);
	fwrite(&save, sizeof(CocheFichero), 1, file);
	fclose(file);

	fflush(stdin);
	printf("\nCoche registrado\n\n");

//	FILE *file;
//	file = fopen("coches.dat", "rb");
//	Coche *coches = malloc(sizeof(Coche) * (contadorCoches));
//	if(!contadorCoches <= 1){
//		fread(coches, sizeof(Coche), contadorCoches-1, file);
//	}
//
//	//fclose(file);
//
//	FILE *file2;
//	file2 = fopen("coches.dat", "wb");
//	coches[contadorCoches-1] = *c;
//	//memcpy(coches[contadorCoches], *c, sizeof(Coche));
//	fputc(contadorCoches, file);
//	fwrite(coches, sizeof(Coche), contadorCoches, file2);
//
//	//fclose(file);
}
Coche* menuIntroducirCoche(Marca m) {
	Coche *c = crearCoche();
	printf("\n\n------Introducción de un nuevo vehículo-------\n\n");

	printf("Introduce el id del vehículo:");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &c->id); //scanf recibe una direccion

	printf("\nIntroduce el nombre del modelo:");
	fflush(stdout);
	fflush(stdin);
	c->modelo = malloc(MAX_LINE * sizeof(char));
	fgets(c->modelo, MAX_LINE, stdin);

	printf("\nIntroduce el color del modelo:");
	fflush(stdout);
	fflush(stdin);
	c->color = malloc(MAX_LINE * sizeof(char));
	fgets(c->color, MAX_LINE, stdin);

	printf("\nIntroduce la potencia del modelo:");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &c->potencia);

	c->nombreMarca = malloc(MAX_LINE * sizeof(char));
	strcpy(c->nombreMarca, m.nombre);

	//Guardamos el coche que acabamos de crear en un fichero que contiene todos los coches
	guardarCocheEnFichero(c);
//	FILE *ficheroContador;
//	char ch;
//	ficheroContador = fopen("contador.txt", "r");
//	putchar(ch);
//	contadorCoches = (int) ch;
//	fclose(ficheroContador);
//
//	contadorCoches++;
//	printf("Contador : %i", contadorCoches); //para saber cuantos lleva
//
//	FILE *file2;
//	file2 = fopen("contador.txt", "w");
//	fprintf(file2, "%c", (char) contadorCoches);
//	fclose(file2);
	return c;
}
void liberarCoche(Coche *c) {
	free(c->color);
	free(c->modelo);
	free(c->nombreMarca);
	free(c);
	c = NULL;
}

/*
 * LISTAR DATOS DE LOS FICHEROS COCHES, MARCAS, USUARIOS
 */
void listarCochesDeMarca(Marca m) {
	CocheFichero coches[MAX_CARS];
	int i;
	printf("-----------Coches registrados de la marca-------------\n");

	FILE *file;
	file = fopen("coches.dat", "rb");
	for (i = 0; i < MAX_CARS; i++) {
		int num = fgetc(file);
		fread(&coches[i], sizeof(CocheFichero), num, file);
	}
	fclose(file);

	for (i = 0; i < MAX_CARS; i++) {
		//if(coches[i].nombreMarca == m.nombre){
		printCocheFichero(&coches[i]);
		//}
	}
	return;
}
void listarUsuarios() {
	UsuarioFichero usuarios[MAX_USERS];
	int i;
	printf(
			"-----------Usuarios registrados en el concesionario-------------\n");

	FILE *file;
	file = fopen("usuarios.dat", "rb");
	for (i = 0; i < MAX_USERS; i++) {
		int num = fgetc(file);
		fread(&usuarios[i], sizeof(UsuarioFichero), num, file);
	}
	fclose(file);

	for (i = 0; i < MAX_USERS; i++) {
		printUsuarioFichero(&usuarios[i]);
	}
	return;
}
void listarMarcas() {
	MarcaFichero marcas[MAX_MARCAS];
	int i;
	printf("-----------Marcas registradas en el concesionario-------------\n");

	FILE *file;
	file = fopen("marcas.dat", "rb");
	for (i = 0; i < MAX_MARCAS; i++) {
		int num = fgetc(file);
		fread(&marcas[i], sizeof(MarcaFichero), num, file);
	}
	fclose(file);

	for (i = 0; i < MAX_MARCAS; i++) {
		printMarcaFichero(&marcas[i]);
	}
	return;
}
void printCocheFichero(CocheFichero *c) {
	printf("%i : %s %s, %s (%i)\n", c->id, c->modelo, c->nombreMarca, c->color,
			c->potencia);
}
void printCoche(Coche *c) {
	printf("%i : %s %s, %s (%i)\n", c->id, c->modelo, c->nombreMarca, c->color,
			c->potencia);
}

/*
 * RECUPERAR DE LOS FICHEROS COCHES, USUARIOS, MARCAS
 * UTIL PARA COTEJAR INICIOS DE SESION
 */
Coche* recuperarCoches() {
	CocheFichero temp[MAX_CARS];
	int i;

	FILE *file;
	file = fopen("coches.dat", "rb");
	for (i = 0; i < MAX_CARS; i++) {
		int num = fgetc(file);
		fread(&temp[i], sizeof(CocheFichero), num, file);
	}
	fclose(file);

	Coche *c = malloc(MAX_CARS * sizeof(Coche));
	for (i = 0; i < MAX_CARS; i++) {
		c[i].id = temp[i].id;
		c[i].modelo = temp[i].modelo;
		c[i].nombreMarca = temp[i].nombreMarca;
		c[i].color = temp[i].color;
		c[i].potencia = temp[i].potencia;
	}
	return c;
}
Usuario* recuperarUsuarios() {
	UsuarioFichero temp[MAX_USERS];
	int i;

	FILE *file;
	file = fopen("usuarios.dat", "rb");
	for (i = 0; i < MAX_USERS; i++) {
		int num = fgetc(file);
		fread(&temp[i], sizeof(UsuarioFichero), num, file);
	}
	fclose(file);

	Usuario *u = malloc(MAX_USERS * sizeof(Usuario));
	for (i = 0; i < MAX_USERS; i++) {
		u[i].id = temp[i].id;
		u[i].nombre = temp[i].nombre;
		u[i].apellido = temp[i].apellido;
		u[i].nombreUsuario = temp[i].nombreUsuario;
		u[i].contrasena = temp[i].contrasena;
	}
	return u;
}
Marca* recuperarMarca() {
	MarcaFichero temp[MAX_MARCAS];
	int i;

	FILE *file;
	file = fopen("marcas.dat", "rb");
	for (i = 0; i < MAX_MARCAS; i++) {
		int num = fgetc(file);
		fread(&temp[i], sizeof(MarcaFichero), num, file);
	}
	fclose(file);

	Marca *m = malloc(MAX_MARCAS * sizeof(Marca));
	for (i = 0; i < MAX_MARCAS; i++) {
		m[i].id = (int) temp[i].id;
		m[i].nombre = (char*) temp[i].nombre;
		m[i].contrasena = (char*) temp[i].contrasena;
	}
	return m;
}

