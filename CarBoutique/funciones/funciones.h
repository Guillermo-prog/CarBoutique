/*
 * funciones.h
 *
 *  Created on: 26 mar. 2021
 *      Author: guill
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//static int contador = 0;

//ESTRUCTURAS
typedef struct{
	int id;
	char *nombre;
	char *apellido;
	char *nombreUsuario;
	char *contrasena;
}Usuario;

//MENU
void seleccionInicioSesion();

//INICIOS DE SESION
void inicioSesionUsuario();
void inicioSesionMarca();
void inicioSesionAdministrador();

//REGISTRO
void seleccionRegistro();
void registroUsuario();
void registroMarca();
void registroAdministrador(); //





#endif /* FUNCIONES_H_ */
