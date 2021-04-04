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

void inicioSesionMarca() {


	char str[MAX_LINE];

	printf("\n\n-----Inicia sesion como marca------\n");

	printf("1.Nombre de marca:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *nom_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", nom_fmt);

	printf("\n2.Contraseña de la marca:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *con_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", con_fmt);




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

	/*
	for(int i = 0; i<num; i++){
		if(marcas[i].nombre == nom_fmt && marcas[i].contrasena == com_fmt){
			printf("Has iniciado sesion con %s", marcas[i].nombre);
			menuMarca();
		}
	}
	*/



}


void menuMarca(){

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
		case '1':
		{
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

	char str[11];
	int id;

	printf("\n\n------Resgistro de un nuevo usuario------\n");


	printf("ID: ");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &id);
	clearIfNeeded(str, MAX_LINE);
	u->id = id;

	printf("Nombre de usuario:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *str_fmt = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", str_fmt);
	u->nombreUsuario = malloc(sizeof(char) * (strlen(str_fmt) + 1));
	strcpy(u->nombreUsuario, str_fmt);
	free(str_fmt);

	printf("Nombre:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *str_fmt1 = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", str_fmt1);
	u->nombre = malloc(sizeof(char) * (strlen(str_fmt1) + 1));
	strcpy(u->nombre, str_fmt1);
	free(str_fmt1);

	printf("Apellido:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, MAX_LINE, stdin);
	char *str_fmt2 = malloc(MAX_LINE * sizeof(char));
	sscanf(str, "%s", str_fmt2);
	u->apellido = malloc(sizeof(char) * (strlen(str_fmt2) + 1));
	strcpy((*u).nombre, str_fmt2);
	free(str_fmt2);

	printf("Contraseña:");
	fflush(stdout);
	fflush(stdin);
	fgets(str, 11, stdin);
	char *str_fmt3 = malloc(11 * sizeof(char));
	sscanf(str, "%s", str_fmt3);
	u->contrasena = malloc(sizeof(char) * (strlen(str_fmt3) + 1));
	strcpy((*u).nombre, str_fmt3);
	free(str_fmt3);

	/*
	 char repet[11];
	 printf("Repetir contraseña:\n");
	 fgets(repet, sizeof(repet), stdin);
	 scanf(repet, "%s", repet);
	 if(!strcmp(repet,str) == 0) {
	 printf("Las contraseñas no coinciden")
	 }
	 */

	//Guardamos el usuario que hemos creado
	FILE *file;
	file = fopen("usuarios.dat", "ab");
	fputc(1, file);
	fwrite(u, sizeof(*u), 1, file);
	fclose(file);

	fflush(stdin);
	printf("\nUsuario registrado\n\n");
	seleccionInicioSesion();



}

void clearIfNeeded(char *str, int max_line) {
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == MAX_LINE - 1) && (str[MAX_LINE - 2] != '\n'))
		while (getchar() != '\n')
			;
}

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

	FILE *file2;
	file2 = fopen("marcas.dat", "ab");
	fputc(1, file2);
	fwrite(m, sizeof(*m), 1, file2);
	fclose(file2);

	printf("\Marca registrado\n\n");
	seleccionInicioSesion();
}

