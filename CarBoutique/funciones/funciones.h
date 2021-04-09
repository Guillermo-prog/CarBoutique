#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "../coches/coches.h"
#define MAX 20
#define MAX_USERS 5
#define MAX_MARCAS 5
//static int contador = 0;

//ESTRUCTURAS
typedef struct{
	int id;
	char *nombre;
	char *apellido;
	char *nombreUsuario;
	char *contrasena;
}Usuario;

typedef struct{
	int id;
	char nombre[MAX];
	char apellido[MAX];
	char nombreUsuario[MAX];
	char contrasena[MAX];
}UsuarioFichero;

typedef struct{
	int id;
	char *nombre;
	char *contrasena;
}Marca;

typedef struct{
	int id;
	char nombre[MAX];
	char contrasena[MAX];
}MarcaFichero;

//MENU PRINCIPAL
void seleccionInicioSesion();

//INICIOS DE SESION
Usuario* inicioSesionUsuario();
Marca* inicioSesionMarca();
void inicioSesionAdministrador();

//REGISTRO
void seleccionRegistro();
Usuario* registroUsuario();
Marca* registroMarca();
void registroAdministrador();

void liberarUsuario(Usuario*);
void liberarMarca(Marca*);
void clearIfNeeded(char *str, int max_line);

void menuUsuario(Usuario*);
void menuMarca(Marca);
void listarUsuarios();
void listarMarcas();

void printMarca(Marca*);
void printMarcaFichero(MarcaFichero*);
void printUsuario(Usuario*);
void printUsuarioFichero(UsuarioFichero*);

#endif /* FUNCIONES_H_ */
