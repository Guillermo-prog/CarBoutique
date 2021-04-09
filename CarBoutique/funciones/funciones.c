#include <stdio.h> //para stdin y stdout
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_LINE 51
#define NUM 1

/*
 * REGISTRO
 */
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
			Usuario *u = registroUsuario();

			liberarUsuario(u); //Se libera el puntero después de guardarlo en el fichero
			break;
		}

		case '2': {
			Marca *m = registroMarca();

			liberarMarca(m); //Se libera el puntero después de guardarlo en el fichero
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

/*
 * REGISTRO USUARIO
 * CREAR EL USUARIO Y ESCRIBIRLO EN FICHERO
 */
Usuario* crearUsuario() {
	Usuario *u = malloc(sizeof(Usuario));
	u->id = 0;
	u->nombre = NULL;
	u->nombreUsuario = NULL;
	u->apellido = NULL;
	u->contrasena = NULL;
	return u;
}
void guardarUsuarioEnFichero(Usuario *u) {
	UsuarioFichero save;
	save.id = u->id;
	strcpy(save.nombre, u->nombre);
	strcpy(save.apellido, u->apellido);
	strcpy(save.nombreUsuario, u->nombreUsuario);
	strcpy(save.contrasena, u->contrasena);

	//DE FORMA BINARIA
	FILE *file;
	file = fopen("usuarios.dat", "ab");
	fputc(1, file);
	fwrite(&save, sizeof(UsuarioFichero), 1, file);
	fclose(file);

	fflush(stdin);
	printf("\nUsuario registrado\n\n");
}
Usuario* registroUsuario() {
	Usuario *u = crearUsuario();
	printf("\n\n------Resgistro de nuevo usuario------\n");

	printf("ID: ");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	scanf("%i", &u->id);

	printf("Nombre de usuario:");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	u->nombreUsuario = malloc(MAX_LINE * sizeof(char));
	fgets(u->nombreUsuario, MAX_LINE, stdin);

	printf("Nombre:");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	u->nombre = malloc(MAX_LINE * sizeof(char));
	fgets(u->nombre, MAX_LINE, stdin);

	printf("Apellido:");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	u->apellido = malloc(MAX_LINE * sizeof(char));
	fgets(u->apellido, MAX_LINE, stdin);

	printf("Contraseña:");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	u->contrasena = malloc(MAX_LINE * sizeof(char));
	fgets(u->contrasena, MAX_LINE, stdin);

	guardarUsuarioEnFichero(u);
	seleccionInicioSesion();
	return u;
}
void liberarUsuario(Usuario *u) {
	free(u->apellido);
	free(u->contrasena);
	free(u->nombre);
	free(u->nombreUsuario);
	free(u);
	u = NULL;
}

/*
 * REGISTRO MARCA
 * ESCRIBIR MARCA EN EL FICHERO
 */
Marca* crearMarca() {
	Marca *m = malloc(sizeof(Marca));
	m->id = 0;
	m->nombre = NULL;
	m->contrasena = NULL;
	return m;
}
void guardarMarcaEnFichero(Marca *m) {
	MarcaFichero save;
	save.id = m->id;
	strcpy(save.nombre, m->nombre);
	strcpy(save.contrasena, m->contrasena);

	//DE FORMA BINARIA
	FILE *file;
	file = fopen("marcas.dat", "ab");
	fputc(1, file);
	fwrite(&save, sizeof(MarcaFichero), 1, file);
	fclose(file);

	fflush(stdin);
	printf("\nMarca registrada\n\n");
}
Marca* registroMarca() {
	Marca *m = crearMarca();
	printf("\n\n-------Registrar marca--------\n\n");

	printf("ID: ");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	scanf("%i", &m->id);

	printf("Nombre de la marca:");
	fflush(stdout);
	fflush(stdin);
	//Alternativa
	m->nombre = malloc(MAX_LINE * sizeof(char));
	fgets(m->nombre, MAX_LINE, stdin);

	printf("Contraseña:");
	fflush(stdin);
	fflush(stdout);
	//Alternativa
	m->contrasena = malloc(MAX_LINE * sizeof(char));
	fgets(m->contrasena, MAX_LINE, stdin);

	//Guardamos el usuario que hemos creado
	guardarMarcaEnFichero(m);
	seleccionInicioSesion();
	return m;
}
void liberarMarca(Marca *m) {
	free(m->contrasena);
	free(m->nombre);
	free(m);
	m = NULL;
}
void printMarca(Marca *m) {
	printf("%i : %s (%s)\n", m->id, m->nombre, m->contrasena);
}
void printMarcaFichero(MarcaFichero *m) {
	printf("%i : %s (%s)\n", m->id, m->nombre, m->contrasena);
}
void printUsuario(Usuario *u) {
	printf("%i : %s %s, %s (%s)\n", u->id, u->nombre, u->apellido,
			u->nombreUsuario, u->contrasena);
}
void printUsuarioFichero(UsuarioFichero *u) {
	printf("%i : %s %s, %s (%s)", u->id, u->nombre, u->apellido,
			u->nombreUsuario, u->contrasena);
}

/*
 * INICIOS DE SESION de USUARIOS
 */

Usuario* inicioSesionUsuario() {
	int i;
	Usuario *u = crearUsuario();
	printf("\n\n-----Inicia sesion como usuario------\n");

	printf("Nombre de usuario:");
	fflush(stdout);
	fflush(stdin);
	u->nombreUsuario = malloc(MAX_LINE * sizeof(char));
	fgets(u->nombreUsuario, MAX_LINE, stdin);

	printf("Contraseña:");
	fflush(stdout);
	fflush(stdin);
	u->contrasena = malloc(MAX_LINE * sizeof(char));
	fgets(u->contrasena, MAX_LINE, stdin);

	//Comprobar credenciales
	Usuario *temp = recuperarUsuarios();
	Usuario *final = crearUsuario();
	for (i = 0; i < MAX_USERS; i++) {
		if (strcmp(u->nombreUsuario, temp[i].nombreUsuario) == 0) {
			if (strcmp(u->contrasena, temp[i].contrasena) == 0) {
				final->id = temp[i].id;
				final->nombre = temp[i].nombre;
				final->apellido = temp[i].apellido;
				final->nombreUsuario = temp[i].nombreUsuario;
				final->contrasena = temp[i].contrasena;

				for (i = 0; i < MAX_USERS; i++) {
					liberarUsuario(&temp[i]);
				}
				liberarUsuario(u);
				return final;
			}
		}
	}
	for (i = 0; i < MAX_USERS; i++) {
		liberarUsuario(&temp[i]);
	}
	liberarUsuario(u);
	return NULL;
}

/*
 * INICIO DE SESION DE MARCA
 */
Marca* inicioSesionMarca() {
	char nombre[MAX_LINE];
	char contrasena[MAX_LINE];
	int i;
	printf("\n\n-----Inicia sesion como Marca------\n");

	printf("Nombre de marca:");
	fflush(stdout);
	fflush(stdin);
	fgets(nombre, MAX_LINE, stdin);

	printf("Contraseña:");
	fflush(stdout);
	fflush(stdin);
	fgets(contrasena, MAX_LINE, stdin);

	//Comprobar credenciales
	Marca *temp = recuperarMarca();
	Marca *final = crearMarca();
	for (i = 0; i < MAX_MARCAS; i++) {
		if (strcmp(nombre, temp[i].nombre) == 0) {
			if (strcmp(contrasena, temp[i].contrasena) == 0) {
				//free(final);
				liberarMarca(final);
				final = &temp[i];

//				for (i = 0; i < MAX_MARCAS; i++) {
//					liberarMarca(&temp[i]);
//				}
//				ESTO ESTA MAL PORQUE HACE FREE EN EXCESO VECES

				liberarMarca(temp);
				return final;
			}
		}
	}
	liberarMarca(final);
	return NULL;
}
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


void inicioSesionAdministrador() {
}

void clearIfNeeded(char *str, int max_line) {
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == MAX_LINE - 1) && (str[MAX_LINE - 2] != '\n'))
		while (getchar() != '\n')
			;
}
