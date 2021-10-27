#include "casillero.h"

Casillero::Casillero() {}

string Casillero::obtener_tipo_casillero() {
	return tipo_casillero;
}

Casillero_transitable::Casillero_transitable(int fila, int columna, string tipo_casillero) : Casillero() {
	this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = tipo_casillero;
	this -> esta_vacio = true;
	this -> material = Material();
}

Casillero_construible::Casillero_construible(int fila, int columna, string tipo_casillero) : Casillero() {
	this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = tipo_casillero;
	this -> esta_vacio = true;
	this -> edificio = Edificio();
}

Casillero_inaccesible::Casillero_inaccesible(int fila, int columna, string tipo_casillero) : Casillero() {
	this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = tipo_casillero;
	this -> esta_vacio = true;
}



