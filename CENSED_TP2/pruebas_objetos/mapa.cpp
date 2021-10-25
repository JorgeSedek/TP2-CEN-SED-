/*
 * mapa.cpp
 *
 *  Created on: 25 oct. 2021
 *      Author: jorge
 */



/*
 * mapa.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#include "mapa.h"



int Mapa::obtener_fila(){
	return fila;
}

int Mapa::obtener_columna(){
	return columna;
}

void Mapa::inicializar_casilleros(char** tipo_terrenos){
	Casillero casillero();
	for( int j = 0; j < obtener_columna(); j++){
		for( int i = 0; i < obtener_fila(); i++){
			casillero = inicializar_casillero(tipo_terrenos[i][j], fila, columna);
			casilleros.cambiar(i, j, casillero);

		}
	}

	}


Casillero Mapa::inicializar_casillero(char tipo_terreno, int fila, int columna){
	Casillero casillero();
	switch(tipo_terreno){
	case 'L':
		Casillero_inacesible casillero_inacesible(fila, columna, true);
		casillero = casillero_inacesible;
		break;
	case 'T':
		/*
		 Aca hay que agrega un booleano que diga si hay un edificio en el casillero
		 y dividir en 2 constructores de Casiller_construible
		 */

		Casillero_construible casillero_construible(fila, columna, true);
		casillero = casillero_construible;
		break;
	case 'C':
		/*
		Aca hay que agrega un booleano que diga si hay un material en el casillero
		y dividir en 2 constructores de Casiller_construible
		*/

		Casillero_transitable casillero_transitable(fila, columna, true);
		casillero = casillero_transitable;
	}
	return casillero;
}

/*
//Debe haber una mejor manera de hacer esto
string convertir_caracter_a_palabra(string letra){

	string palabra;
	switch(letra){
	case 'M':
		palabra = "Mina";
		break;
	case 'A':
		palabra = "Aserradero";
		break;
	case 'F':
		palabra = "Fabrica";
		break;
	case 'E':
		palabra = "Escuela";
		break;
	case 'O':
		palabra = "Obelisco";
		break;
	case 'P':
		palabra = "Planta electrica";
		break;
	case 'W':
		palabra = "Madera";
		break;
	case 'S':
		palabra = "Piedra";
		break;
	case 'I':
		palabra = "Metal";
		break;
	default:
		palabra = "Entrada invalida";

	}
	return palabra;
}*/

