#include <stdio.h>
#include <stdlib.h>
#include "funciones/funciones.h"
#include "coches/coches.h"

int main(void) {
	seleccionInicioSesion();
}

void seleccionInicioSesion() {
	int i;
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

		switch (opcion) {

		case '1': {
			Usuario *u = inicioSesionUsuario();
			menuUsuario(u);
			break;
		}
		case '2': {
			//Inicio de sesion directamente
									Marca m = {123, "Mercedes Benz", "merc"};
			//						menuMarca(m);

			//Inicio de sesion con credenciales
			Marca *lista = recuperarMarca();
//			for (i = 0; i<MAX_MARCAS;i++){
//				printMarca(&lista[i]);
//			}
			Marca *entry = &m;

			for (i = 0; i < MAX_MARCAS; i++) {
				if (strcmp(entry->nombre, lista[i].nombre) == 0) {
					if (strcmp(entry->contrasena, lista[i].contrasena) == 0) {
						menuMarca(*entry);
						break;
					}
				}
			}
			printf("Marca no accesible.\n");



			//free(entry);
			//free(lista);
			break;
		}
		case '3':
//			inicioSesionAdministrador();
//			break;
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
