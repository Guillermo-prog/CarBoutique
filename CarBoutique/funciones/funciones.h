/*
 * funciones.h
 *
 *  Created on: 26 mar. 2021
 *      Author: guill
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


//ESTRUCTURAS
typedef struct{
	int id;
	char *nombre;
	char *contrasena;
}Usuario;

//MENU
char seleccionInicioSesion();

//INICIOS DE SESION
void inicioSesionUsuario();
void inicioSesionMarca();
void inicioSesionAdministrador();

//REGISTRO
char seleccionRegistro();
void registroUsuario();
void registroMarca();
void registroAdministrador(); //





#endif /* FUNCIONES_H_ */
