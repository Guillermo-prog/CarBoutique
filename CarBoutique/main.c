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
	char select;

	do {
		select = seleccionInicioSesion();
		if (select == 1) {
			inicioSesionUsuario();
		} else if (select == 2) {
			inicioSesionMarca();
		} else if (select == 3) {
			inicioSesionAdministrador();
		} else if (select == 3) {

			char select3 = seleccionRegistro();
			if (select3 == 1) {
				registroUsuario();
			} else if (select3 == 2) {
				registroMarca();
			} else if (select3 == 3) {
				registroAdministrador();
			}

		} else if (select != 'q') {
			printf("\n\nOpcion no valida.\n\n");
		}
	} while (select != 'q'); // Se desea salir al pulsar la 'q'
	return 0;
}
