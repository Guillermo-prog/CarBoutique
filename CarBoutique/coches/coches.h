
#ifndef COCHES_H_
#define COCHES_H_
#include "../funciones/funciones.h"
#define MAX_TAM_MOD 20
#define MAX_TAM_COL	20
#define MAX_TAM_MAR 20
#define MAX_CARS 5

//ESTRUCTURAS
typedef struct{
	int id;
	char nombreMarca[MAX_TAM_MAR];
	char modelo[MAX_TAM_MOD];
	int potencia;
	char color[MAX_TAM_COL];
}CocheFichero;

typedef struct{
	int id;
	char *nombreMarca;
	char *modelo;
	int potencia;
	char *color;
}Coche;

//MENUS

Coche* menuIntroducirCoche(Marca);

void listarCochesDeMarca(Marca);
CocheFichero* listarCoches();

void guardarCocheEnFichero(Coche *);
void printCocheFichero(CocheFichero *c);
void printCoche(Coche *c);
void liberarCoche(Coche *);

#endif /* COCHES_H_ */
