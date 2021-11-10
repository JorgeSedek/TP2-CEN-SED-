#ifndef UBICACION_H_INCLUDED
#define UBICACION_H_INCLUDED

#include <string>
#include "vector.h"

using namespace std;

const char TOPE_CADENA_FILA = ',';
const char TOPE_CADENA_COLUMNA = ')';
const int ASCII_NUM_CERO = 48;
const int ASCII_NUM_NUEVE = 57;
const int POSICION_INICIAL_FILA = 1;
const int POSICION_INICIAL_COLUMNA = 0;

const int CANTIDAD_COORDENADAS = 2;
const int FILA = 0;
const int COLUMNA = 1;

class Ubicacion {
	
	private:
	
	string nombre;
	int fila;
	int columna;

	public:

	// Constructor sin parámetros.
	//pre: -
    //post: Instancia una Ubicacion "vacía" con todos sus atributos nulos.
	Ubicacion();

	// Constructor con parámetros.
	//pre: -
    //post: Instancia una Ubicacion según los valores ingresados.
	Ubicacion(string nombre, int fila, int columna);

	// Constructor con parámetros, construcción basada en el formato del archivo de ubicaciones.
	//pre: Los valores ingresados se leen directamente del archivo de ubicaciones, y deben respetar su formato.
    //post: Instancia una Ubicacion según los valores ingresados.
	Ubicacion(string nombre, string fila, string columna);

	//pre: -
    //post: Devuelve el nombre del contenido de la Ubicacion.
	string obtener_nombre();

	//pre: -
    //post: Devuelve la coordenada fila de la Ubicacion.
	int obtener_fila();

	//pre: -
    //post: Devuelve la coordenada columna de la Ubicacion.
	int obtener_columna();

	private:

	//pre: Los valores ingresados respetan el formato del archivo de ubicaciones.
    //post: Limpia el string ingresado para convertirlo correctamente en un número.
	int limpiar_string(string cadena, int posicion_inicial, char str_tope);
};

#endif // UBICACION_H_INCLUDED