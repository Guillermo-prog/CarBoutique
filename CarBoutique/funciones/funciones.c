/*
 * funciones.c
 *
 *  Created on: 26 mar. 2021
 *      Author: guill
 */
#include <stdio.h> //para stdin y stdout
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_LINE 20

//INICIOS DE SESION
void inicioSesionUsuario() {

	char str[MAX_LINE];

	printf("\n\n-----Inicia sesion como usuario------\n");

	printf("Nombre de usuario:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *nom_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", nom_fmt);

	printf("Contraseña:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *con_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", con_fmt);

	/* REVISAR!! EL DE USUARIOS Y EL DE MARCAS
	 int num;
	 Marca *marcas;

	 FILE *file;
	 file = fopen("marcas.dat", "rb");
	 num = fgetc(file);
	 marcas = (Marca*) malloc(num * sizeof(Marca));
	 fread(marcas, sizeof(Marca), num, file);
	 fclose(file);
	 for(int i = 0; i<num; i++){
	 printf("%i : %s (%s)\n", marcas[i].id, marcas[i].nombre, marcas[i].contrasena);
	 }

	 free(marcas);
	 */

}

void printMarca(Marca *m) {
	printf("%i : %s (%s)\n", m->id, m->nombre, m->contrasena);
}

void inicioSesionMarca() {

//	char str[MAX_LINE];
//
//	printf("\n\n-----Inicia sesion como marca------\n");
//
//	printf("1.Nombre de marca:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	char *nom_fmt = malloc(MAX_LINE * sizeof(char));
//	sscanf(str, "%s", nom_fmt);
//
//	printf("\n2.Contraseña de la marca:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	char *con_fmt = malloc(MAX_LINE * sizeof(char));
//	sscanf(str, "%s", con_fmt);

//	int num;
//	int i;
//	Marca *marcas;
//
//	FILE *file;
//	file = fopen("marcas.dat", "rb");
//	num = fgetc(file);
//
//	//fread(marcas, sizeof(Marca), num, file);
//	marcas = (Marca*) malloc(num * sizeof(Marca));
//	for (i = 0; i < num; i++) {
//		Marca m;
//		fread(m.id, sizeof(int), 1, file);
//		fread(m.nombre, sizeof(m.nombre), 1, file);
//		fread(m.contrasena, sizeof(m.contrasena), 1, file);
//
//		marcas[i] = m;
//	}
//
//	fclose(file);
//
//	for (i = 0; i < num; i++) {
//		printf("%i : %s (%s)\n", marcas[i].id, marcas[i].nombre, marcas[i].contrasena);
//	}
//
//	free(marcas);





	/*
	if ((file = fopen("marcas.dat", "rb")) == NULL) {
		printf("Error al abrir el archivo\n\n");
	} else {
		fread(&m, sizeof(m), 1, file);
		while (!feof(file)) {
			printf("%i : %s (%s)\n", m.id, m.nombre, m.contrasena);
			fread(&m, sizeof(m), 1, file);
		}
	}
	fclose(file);
	*/

	/*REVISAR!! PARA INDIVIDUALMENTE
	 while(1){
	 if(fgetc(file) == '\n'){
	 num++;
	 }
	 if(feof(file) == EOF){
	 break;
	 }
	 }
	 */

	/*COMPROBACION DE MARCA EXISTENTE --> REVISAR
	 for(int i = 0; i<num; i++){
	 if(marcas[i].nombre == nom_fmt && marcas[i].contrasena == com_fmt){
	 printf("Has iniciado sesion con %s", marcas[i].nombre);
	 menuMarca();
	 }
	 }
	 */

}



void inicioSesionAdministrador() {
}

//REGISTRO
void seleccionRegistro() {
	char select;
	do {

		printf("\n\n------Resgistro de CarBoutique------\n");
		printf("1.Registrarse como usuario.\n");
		printf("2.Registrarse como marca.\n");
		printf("Pulsa 'q' para volver.\n");
		printf("\nElija una opción:");
		fflush(stdout);

		select = getchar();

		switch (select) {
		case '1': {
			Usuario *u = (Usuario*) malloc(sizeof(Usuario));
			registroUsuario(u);
			free(u);
			break;
		}

		case '2':

		{
			Marca *m = (Marca*) malloc(sizeof(Marca));
			registroMarca(m);
			free(m);
			break;
		}

		case 'q':
			seleccionInicioSesion();
			break;

		default:
			printf("\n\n Opcion no valida");
		}

	} while (select != 'q');

}

void registroUsuario(Usuario *u) {
//
//	char str[11];
//	int id;
//
//	printf("\n\n------Resgistro de un nuevo usuario------\n");
//
//	printf("ID: ");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	sscanf(str, "%i", &id);
//	clearIfNeeded(str, MAX_LINE);
//	u->id = id;
//
//	printf("Nombre de usuario:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	char *str_fmt = malloc(MAX_LINE * sizeof(char));
//	sscanf(str, "%s", str_fmt);
//	u->nombreUsuario = malloc(sizeof(char) * (strlen(str_fmt) + 1));
//	strcpy(u->nombreUsuario, str_fmt);
//	free(str_fmt);
//
//	printf("Nombre:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	char *str_fmt1 = malloc(MAX_LINE * sizeof(char));
//	sscanf(str, "%s", str_fmt1);
//	u->nombre = malloc(sizeof(char) * (strlen(str_fmt1) + 1));
//	strcpy(u->nombre, str_fmt1);
//	free(str_fmt1);
//
//	printf("Apellido:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, MAX_LINE, stdin);
//	char *str_fmt2 = malloc(MAX_LINE * sizeof(char));
//	sscanf(str, "%s", str_fmt2);
//	u->apellido = malloc(sizeof(char) * (strlen(str_fmt2) + 1));
//	strcpy((*u).nombre, str_fmt2);
//	free(str_fmt2);
//
//	printf("Contraseña:");
//	fflush(stdout);
//	fflush(stdin);
//	fgets(str, 11, stdin);
//	char *str_fmt3 = malloc(11 * sizeof(char));
//	sscanf(str, "%s", str_fmt3);
//	u->contrasena = malloc(sizeof(char) * (strlen(str_fmt3) + 1));
//	strcpy((*u).nombre, str_fmt3);
//	free(str_fmt3);
//
//	//Guardamos el usuario que hemos creado
//	/* DE FORMA BINARIA
//	 FILE *file;
//	 file = fopen("usuarios.dat", "ab");
//	 fputc(1, file);
//	 fwrite(u, sizeof(*u), 1, file);
//	 fclose(file);
//
//	 fflush(stdin);
//	 printf("\nUsuario registrado\n\n");
//	 seleccionInicioSesion();
//	 */

}

void clearIfNeeded(char *str, int max_line) {
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == MAX_LINE - 1) && (str[MAX_LINE - 2] != '\n'))
		while (getchar() != '\n')
			;
}

#define NUM 1
void registroMarca(Marca *m) {
	printf("\n\n-------Registrar marca--------\n\n");

//	char* nombre = (char*) malloc(sizeof(char) * 20);
//	char* contra = (char*) malloc(sizeof(char) * 20);

	char str[MAX_LINE];
	int id;

	printf("ID: ");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &id);
	clearIfNeeded(str, MAX_LINE);

	m->id = id;

	printf("Nombre de la marca:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *str_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", str_fmt);
	m->nombre = malloc((strlen(str_fmt) + 1) * sizeof(char));
	strcpy(m->nombre, str_fmt);
	free(str_fmt);

	printf("Contraseña:");
	fflush(stdin);
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	char *str_fmt2 = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", str_fmt2);
	m->contrasena = malloc((strlen(str_fmt2) + 1) * sizeof(char));
	strcpy(m->contrasena, str_fmt2);
	free(str_fmt2);


	//METERLOS INDIVIDUALMENTE
	FILE *file2;
	file2 = fopen("marcas.dat", "ab");
	fputc(1, file2);
	fwrite(m->id, sizeof(int), 1, file2);
	fwrite(m->nombre, sizeof(m->nombre), 1, file2);
	fwrite(m->contrasena, sizeof(m->contrasena), 1, file2);
	//fputc('\n', file2);
	fclose(file2);

	printf("\nMarca registrado\n\n");
	seleccionInicioSesion();

	/*
	 //METERLOS EN UN ARRAY
	 FILE *file2;
	 file2 = fopen("marcas.bin", "w");
	 int num;


	 if (file2 == NULL){
	 printf("Error al abrir el fichero de marcas\n");
	 exit(1);
	 }



	 //Para saber si el fichero esta vacio

	 fseek(file2, 0L, SEEK_END);
	 int empty = ftell(file2) == 0L;

	 if(feof(file2) == EOF){  //si está vacio --> crear el array //feof(file2) == EOF

	 Marca arrayMarca[1];
	 arrayMarca[0] = *m;
	 fputc(NUM, file2);
	 fwrite(arrayMarca, sizeof(Marca), NUM, file2);
	 fclose(file2);
	 free(arrayMarca);

	 } else{
	 fclose(file2); //cerramos el abierto antes

	 FILE *file3;
	 file3 = fopen("marcas.bin", "r+");
	 num = fgetc(file3);
	 Marca  *marcas;
	 marcas = malloc((num + 1) * sizeof(Marca));
	 fread(marcas, sizeof(Marca), num, file3);

	 marcas[num] = *m; //num, no num +1 porque empieza en 0

	 fputc(num + 1, file3);
	 fwrite(marcas, sizeof(marcas), num + 1, file3);
	 fclose(file3);

	 }
	 */

}

