/*
 * mapa.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#include "mapa.h"


Mapa::Mapa(Matriz<char> matriz_tipo_terreno, Vector<Ubicacion> ubicaciones){
	char tipo_terreno;
	for (int j = 0; j < matriz_tipo_terreno.obtener_columnas(); j++){
		for(int i = 0; i < matriz_tipo_terreno.obtener_filas(); i++){
			tipo_terreno = matriz_tipo_terreno.consultar(i, j);
			ubicaciones.consultar(i).obtener_nombre()

		}
	}
}

void Mapa::inicializar_casilleros(char tipo_terreno, int fila, int columna){
	switch(tipo_terreno){
	case 'L':
		Casillero_inacesible(fila, columna, true);
		break;
	case 'T':
		Casillero_construible(fila, columna, )
	}
}

/*
bool Mapa::esta_vacio(string nombre_edificio){
	return true;

} */
