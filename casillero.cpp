/*
 * casillero.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#include "casillero.h"

Casillero::Casillero() {
	this -> fila = 0;
	this -> columna = 0;
	this -> esta_vacio = true;
}

Casillero::Casillero(int fila, int columna, string tipo_casillero) {

	this -> fila = fila;
	this -> columna = columna;

	if (tipo_casillero == "T") {
		Casillero_construible(fila, columna);
	}

	if (tipo_casillero == "C") {
		Casillero_transitable(fila, columna);
	}

}

Casillero_transitable::Casillero_transitable() : Casillero() {
	this -> fila = 0;
	this -> columna = 0;
	this -> esta_vacio = true;
	this -> material = Material();
}

Casillero_transitable::Casillero_transitable(int fila, int columna) : Casillero(fila, columna, tipo_casillero) {
	this -> fila = fila;
	this -> columna = columna;
	this -> esta_vacio = true;
	this -> material = Material();
}

Casillero_construible::Casillero_construible() : Casillero() {
	this -> fila = 0;
	this -> columna = 0;
	this -> esta_vacio = true;
	this -> edificio = Edificio();
}

Casillero_construible::Casillero_construible(int fila, int columna) : Casillero(fila, columna, tipo_casillero) {
	this -> fila = fila;
	this -> columna = columna;
	this -> esta_vacio = true;
	this -> edificio = Edificio();
}

Casillero_inacesible::Casillero_inacesible() : Casillero() {

}

Casillero_inacesible::Casillero_inacesible(int fila, int columna) : Casillero(fila, columna, tipo_casillero) {

}
