/*
 * main.c
 *
 *  Created on: 24 mar. 2021
 *      Author: guill
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones/funciones.h"

int main(void) {
	seleccionInicioSesion();
}


void seleccionInicioSesion() {

	char opcion;
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
		opcion = getchar();
		fflush(stdin);

		switch( opcion ) {


		case '1':
			inicioSesionUsuario();
			break;
		case '2':
			inicioSesionMarca();
			break;
		case '3':
			inicioSesionAdministrador();
			break;
		case '4':
			seleccionRegistro();
			break;
		case 'q':
			printf("Has salido del sistema");
			break;
		default:
			printf("Opcion no valida");
		}


	} while (opcion != 'q');


}
