/*
 * main.c
 *
 *  Created on: 24 mar. 2021
 *      Author: guill
 */


#include <stdio.h>
#include <stdlib.h>
#include "funciones/funciones.h"




//MAIN
int main(void){
	char c = seleccionInicioSesion();

	while(1){
		if(c == 1){
			inicioSesionUsuario();
		}else if(c == 2){
			incioSesionMarca();
		}else if(c == 3){
			incioSesionAdministrador();
		}else if(c == 3){

			char c3 = seleccionRegistro();
			if(c3 == 1){
				registroUsuario();
			}else if(c3 == 2){
				registroMarca();
			}else if(c3 == 3){

			}

		}else if(c=="q"){
			break;
		}else{
			printf("\n\nOpcion no valida");
		}
	}

}
