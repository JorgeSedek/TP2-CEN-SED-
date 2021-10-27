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


void Mapa::cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero) {
	matriz[posicion_fila][posicion_columna] = casillero;
}

void Mapa::imprimir_mapa() {

	string espacios = "          ";

	cout << SUCESS_COLOR << "Este es el mapa de la ciudad: " << endl;
	cout << END_COLOR << endl;

	for (int i = 0; i < filas; i++) {
		cout << espacios;
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] -> imprimir_casillero();
		}
		cout << END_COLOR << endl;
	}
	cout << END_COLOR << endl;
}

void Mapa::consultar_casillero(){
	int fila_ingresada, columna_ingresada;
	pedir_coordenadas_casillero(fila_ingresada, columna_ingresada);
	matriz[fila_ingresada][columna_ingresada]->mostrar();
}

void Mapa::pedir_coordenadas_casillero(int &fila_ingresada, int &columna_ingresada){
	cout << "Por favor, ingrese la fila de la casilla que desea consultar: " << endl;
	cin >> fila_ingresada;
	cout << "Por favor, ingrese la columna de la casilla que desea consultar: " << endl;
	cin >> columna_ingresada;
}

/*
void Mapa::lluvia_materiales(){
		for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j]->obtener_tipo_casillero() == "T"){
				matriz[i][j]->obtener_material()->generar_material();

			}
		}
		cout << END_COLOR << endl;
	}

}
*/
