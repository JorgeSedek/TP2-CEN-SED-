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

		for (int j = 0; j < columnas; j++) {
			delete matriz[i][j];
		}

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

void Mapa::generar_lluvia_materiales() {

	cout << SUCESS_COLOR << "Se ha generado una lluvia de materiales." << END_COLOR << endl;
	cout << endl;
		
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			
			if (matriz[i][j] -> obtener_tipo_casillero() == TRANSITABLE && !matriz[i][j] -> obtener_cantidad_contenida()) {

				borrar_casillero(matriz[i][j]);
				
				Material nuevo_material = Material();
				nuevo_material.llover_material_aleatorio();

				Casillero_transitable* transitable = new Casillero_transitable(i, j, TRANSITABLE);
				transitable -> asignar_material(nuevo_material);

				matriz[i][j] = transitable;
			}	
		}
	}
}

void Mapa::borrar_casillero(Casillero* casillero) {
	delete casillero;
}