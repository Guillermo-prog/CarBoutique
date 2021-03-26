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




char seleccionInicioSesion();

//INCIOS DE SESION
void inicioSesionUsuario();
void inicioSesionMarca();
void inicioSesionAdministrador();

//Registro
char seleccionRegistro();







#endif /* FUNCIONES_H_ */
