/*
 * coches.h
 *
 *  Created on: 7 abr. 2021
 *      Author: guill
 */

#ifndef COCHES_H_
#define COCHES_H_
#include "../funciones/funciones.h"
#define MAX_TAM_MOD 20
#define MAX_TAM_COL	20
#define MAX_TAM_MAR 20

//ESTRUCTURAS
typedef struct{
	int id;
	char nombreMarca[MAX_TAM_MAR];
	char modelo[MAX_TAM_MOD];
	int potencia;
	char color[MAX_TAM_COL];
}Coche;

//MENUS
void menuMarca(Marca m);
void menuIntroducirCoche(Coche *c);
void menuUsuarios();
void listarCoches();

void guardarCocheFichero(Coche *c);

#endif /* COCHES_H_ */
