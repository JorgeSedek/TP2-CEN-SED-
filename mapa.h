#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "casillero.h"

class Mapa {
	private:
	int filas;
	int columnas;
	Casillero*** matriz;

	public:
	Mapa();
	Mapa(int filas, int columnas);
	void borrar();
	int obtener_filas();
	int obtener_columnas();
	void cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero);
	void imprimir_mapa();
};

#endif // MAPA_H_INCLUDED