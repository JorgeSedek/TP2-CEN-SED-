#ifndef UBICACION_H_INCLUDED
#define UBICACION_H_INCLUDED

#include <string>

using namespace std;

const int CANTIDAD_COORDENADAS = 2;
const int FILA = 0;
const int COLUMNA = 1;

<<<<<<< HEAD
const char TOPE_CADENA_FILA = ',';
const char TOPE_CADENA_COLUMNA = ')';
const int ASCII_NUM_ZERO = 48;
const int ASCII_NUM_NUEVE = 57;
const int POSICION_INICIAL_FILA = 1;
const int POSICION_INICIAL_COLUMNA = 0;

=======
>>>>>>> 6d37fb58a82d55530f82141e1956555915b71330
class Ubicacion {
	private:
	string nombre;
	int fila;
	int columna;

	public:
	Ubicacion();
	Ubicacion(string nombre, string fila, string columna);
	string obtener_nombre();
	int obtener_fila();
	int obtener_columna();
	int limpiar_string(string cadena, int posicion_inicial, char str_tope);
};

#endif // UBICACION_H_INCLUDED
