#include "mapa.h"

Mapa::Mapa() {}

Mapa::Mapa(int filas, int columnas) {

	this -> filas = filas;
	this -> columnas = columnas;
	this -> matriz = new Casillero** [filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Casillero* [columnas];
    }
}

void Mapa::borrar() {

	for (int i = 0; i < filas; i++) {
		delete[] matriz[i];
	}

	delete[] matriz;
	this -> matriz = nullptr;
}

int Mapa::obtener_filas() {
	return filas;
}

int Mapa::obtener_columnas() {
	return columnas;
}

void Mapa::cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero) {
	matriz[posicion_fila][posicion_columna] = casillero;
}

void Mapa::imprimir_mapa() {

	string coordenas_columnas = "    ";
	string lineas_columnas = "  -";

	cout << SUCESS_COLOR << "Este es el mapa de la ciudad: " << endl;
	cout << END_COLOR << endl;

	for (int c = 0; c < columnas; c++) {
		coordenas_columnas += to_string(c + 1) + "   ";
		lineas_columnas += "----";
	}

	cout << ENTER_COLOR << coordenas_columnas << endl;
	cout << ENTER_COLOR << lineas_columnas << endl;

	for (int i = 0; i < filas; i++) {
		cout << ENTER_COLOR << i + 1 << " |" << END_COLOR;
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] -> imprimir_casillero();
			cout << ENTER_COLOR << "|" << END_COLOR;
		}
		cout << endl;
		cout << ENTER_COLOR << lineas_columnas << endl;
	}
	cout << END_COLOR << endl;
}