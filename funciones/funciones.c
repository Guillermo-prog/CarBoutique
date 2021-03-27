/*
 * funciones.c
 *
 *  Created on: 26 mar. 2021
 *      Author: guill
 */
#include <stdio.h> //para stdin y stdout
#include <stdlib.h>
#include <string.h>

char seleccionInicioSesion(){

	printf("--------Bienvenido a CarBoutique---------");
	printf("Inicio de sesion:\n");
	printf("1.Usuario\n");
	printf("2.Marca\n");
	printf("3.Administrador\n");
	printf("4.Registro\n");
	printf("Pulse q para salir\n");
	printf("\n\nElija una opcion:");
	fflush(stdout);
	char c = getchar();
	fflush(stdin);

	return c;
}

void inicioSesionUsuario(){
	printf("·Nombre de usuario:");
	fflush(stdout);
	char nom[20]; //Aqui se guarda el nombre de usuario
	fgets(nom, sizeof(nom), stdin);
	scanf(nom, "%s", nom);



	printf("·Contraseña:");
	fflush(stdout);
	char cont[20]; //Aqui se guarda el nombre de usuario
	fgets(cont, sizeof(cont), stdin);
	scanf(cont, "%s", cont);
}

//REGISTRO
char seleccionRegistro(){
	printf("------Resgistro de CarBoutique------");
	printf("1.Registrarse como usuario.");
	printf("2.Registrarse como marca.");
	printf("Pulsa q para volver");
}


