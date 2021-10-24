/*
 * casillero.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#include "casillero.h"

Casillero::Casillero(){
	this -> fila = 0;
	this -> columna = 0;
	this -> esta_vacio = false;
}

Casillero::Casillero(int fila, int columna, bool esta_vacio){
	this -> fila = fila;
	this -> columna = columna;
	this -> esta_vacio = esta_vacio;
}

Casillero_transitable::Casillero_transitable() : Casillero() {

	Material material();

}

Casillero_transitable::Casillero_transitable(int fila, int columna, bool esta_vacio, Material material) : Casillero(fila, columna, esta_vacio){

	this -> material = material;
}

Casillero_transitable::Casillero_transitable(int fila, int columna, bool esta_vacio) : Casillero(fila, columna, esta_vacio){

	Material material();

}

Casillero_construible::Casillero_construible() : Casillero() {

	Edificio edificio();
}

Casillero_construible::Casillero_construible(int fila, int columna, bool esta_vacio) : Casillero(fila, columna, esta_vacio) {

	Edificio edificio();

}


Casillero_construible::Casillero_construible(int fila, int columna, bool esta_vacio, Edificio edificio) : Casillero(fila, columna, esta_vacio) {

	this -> edificio = edificio;
}

Casillero_inacesible::Casillero_inacesible() : Casillero() {

}

Casillero_inacesible::Casillero_inacesible(int fila, int columna, bool esta_vacio) : Casillero(fila, columna, esta_vacio) {

}
