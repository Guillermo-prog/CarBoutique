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

//MENU
void seleccionInicioSesion() {

	char c;
	do {
		printf("\n\n--------Bienvenido a CarBoutique---------\n");
		printf("Inicio de sesion:\n");
		printf("1.Usuario\n");
		printf("2.Marca\n");
		printf("3.Administrador\n");
		printf("4.Registro\n");
		printf("Pulse 'q' para salir\n");
		printf("\n\nElija una opcion:");
		fflush(stdout);
		c = getchar();
		fflush(stdin);

		if (c == '1') {
			inicioSesionUsuario();
		} else if (c == '2') {
			inicioSesionMarca();
		} else if (c == '3') {
			inicioSesionAdministrador();
		} else if (c == '4') {
			seleccionRegistro();
		} else if (c == 'q') {
			printf("Has salido del sistema.");
			break;
		} else {
			printf("Opcion no valida");
		}

	} while (c != 'q');

}

//INICIOS DE SESION
void inicioSesionUsuario() {
	printf("Nombre de usuario:");
	fflush(stdout);
	char nom[20]; //Aqui se guarda el nombre de usuario
	fgets(nom, sizeof(nom), stdin);
	sscanf(nom, "%s", nom);

	printf("Contraseña:");
	fflush(stdout);
	char cont[20]; //Aqui se guarda la contraseña de usuario
	fgets(cont, sizeof(cont), stdin);
	sscanf(cont, "%s", cont);

	//devolver los datos del Usuario

}
void inicioSesionMarca() {
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
			registroUsuario();
			break;

		case '2':
			registroMarca();
			break;
		case 'q':
			seleccionInicioSesion();
			break;

		default:
			printf("\n\n Opcion no valida");
		}

	} while (select != 'q');

}

void registroUsuario() {
	Usuario u;
	char str[50];

	printf("\n\n------Resgistro de un nuevo usuario------\n");
	u.nombreUsuario = (char*) malloc(sizeof(char) * (strlen(str) + 1));

	do {

		printf("Nombre de usuario:");
		fflush(stdout);
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%s", str);

		if (strlen(str) < 4) {
			printf("Nombre de usuario no valido.");
		}
		//memset(str, 0, 11); //para limpiar el buffer

	} while (strlen(str) < 4);
	strcpy(u.nombreUsuario, str);


	do {

		printf("Nombre:");
		fflush(stdout);
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%s", str);
		u.nombre = (char*) malloc(sizeof(char) * (strlen(str) + 1));

		if (strlen(str) > 1) {
			strcpy(u.nombre, str);

		} else {
			printf("Nombre no válido");
		}
		//memset(str, 0, 11);

	} while (strlen(str) < 2);


	do {
		printf("Apellido:");
		fflush(stdout);
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%s", str);
		u.apellido = (char*) malloc(sizeof(char) * (strlen(str) + 1));
		if (strlen(str) > 1) {
			strcpy(u.apellido, str);

		} else {
			printf("Apellido no válido");
		}
		//memset(str, 0, 11);
	} while (strlen(str) < 2);


	do {
		printf("Contraseña:");
		fflush(stdout);
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%s", str);
		u.contrasena = (char*) malloc(sizeof(char) * (strlen(str) + 1));
		if (strlen(str) > 1) {
			strcpy(u.contrasena, str);

		} else {
			printf("Contraseña no válido");
		}
		//memset(str, 0, 11);
	} while (strlen(str) < 2);

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
	file = fopen("usuarios.dat", "wb");
	fputc(1, file);
	fwrite(&u, sizeof(Usuario), 1, file);
	fclose(file);

	fflush(stdin);
	fflush(stdout);
	printf("Usuario registrado.\n");
	//seleccionInicioSesion();

}
void registroMarca() {

}
void registroAdministrador() {

}

