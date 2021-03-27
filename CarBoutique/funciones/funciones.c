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
char seleccionInicioSesion() {
	printf("--------Bienvenido a CarBoutique---------\n");
	printf("Inicio de sesion:\n");
	printf("1.Usuario\n");
	printf("2.Marca\n");
	printf("3.Administrador\n");
	printf("4.Registro\n");
	printf("Pulse 'q' para salir\n");
	printf("\n\nElija una opcion:");
	fflush(stdout);
	char c = getchar();
	fflush(stdin);
	return c;
}

//INICIOS DE SESION
void inicioSesionUsuario() {
	printf("·Nombre de usuario:");
	fflush(stdout);
	char nom[20]; //Aqui se guarda el nombre de usuario
	fgets(nom, sizeof(nom), stdin);
	sscanf(nom, "%s", nom);

	printf("·Contraseña:");
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
char seleccionRegistro() {
	printf("------Resgistro de CarBoutique------\n");
	printf("1.Registrarse como usuario.\n");
	printf("2.Registrarse como marca.\n");
	printf("3.Registrarse como Administrador.\n"); //
	printf("Pulsa 'q' para volver.\n");
	printf("\n\nElija una opcion:");
	fflush(stdout);
	char select;
	select = getchar();
	return select;
}
void registroUsuario() {
}
void registroMarca() {
}
void registroAdministrador(){
}

