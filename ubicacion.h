#ifndef UBICACION_H_INCLUDED
#define UBICACION_H_INCLUDED

#include <string>

using namespace std;

const int CANTIDAD_COORDENADAS = 2;
const int FILA = 0;
const int COLUMNA = 1;

class Ubicacion {
	private:
	string nombre;
	int fila;
	int columna;

	public:
	Ubicacion();
	Ubicacion(string nombre, int fila, int columna);
	Ubicacion(string nombre, string fila, string columna);
	string obtener_nombre();
	int obtener_fila();
	int obtener_columna();
	int limpiar_string(string cadena, int posicion_inicial, char str_tope);
};

#endif // UBICACION_H_INCLUDED
