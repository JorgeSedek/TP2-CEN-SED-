#include "casillero.h"

Casillero::Casillero() {}

Casillero* Casillero::crear_subcasillero(int fila, int columna, string tipo_casillero) {

	Casillero* casillero_devuelto;

    if (tipo_casillero == "T") {
		casillero_devuelto = new Casillero_construible(fila, columna, tipo_casillero);
	}

	if (tipo_casillero == "C") {
		casillero_devuelto = new Casillero_transitable(fila, columna, tipo_casillero);
	}

    if (tipo_casillero == "L") {
        casillero_devuelto = new Casillero_inaccesible(fila, columna, tipo_casillero);
    }

    return casillero_devuelto;
}

void Casillero::ocupar_casillero() {
	esta_vacio = false;
}

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

void Casillero_transitable::asignar_material(Material material) {
	this -> material = material;
}

Casillero_construible::Casillero_construible(int fila, int columna, string tipo_casillero) : Casillero() {
	this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = tipo_casillero;
	this -> esta_vacio = true;
	this -> edificio = Edificio();
}

void Casillero_construible::asignar_edificio(Edificio edificio) {
	this -> edificio = edificio;
}

Casillero_inaccesible::Casillero_inaccesible(int fila, int columna, string tipo_casillero) : Casillero() {
	this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = tipo_casillero;
	this -> esta_vacio = true;
}