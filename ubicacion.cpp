#include "ubicacion.h"

using namespace std;

const char TOPE_CADENA_FILA = ',';
const char TOPE_CADENA_COLUMNA = ')';
const int ASCII_NUM_ZERO = 48;
const int ASCII_NUM_NUEVE = 57;
const int POSICION_INICIAL_FILA = 1;
const int POSICION_INICIAL_COLUMNA = 0;

Ubicacion::Ubicacion() {
	this -> nombre = "";
	this -> fila = 0;
	this -> columna = 0;
}

Ubicacion::Ubicacion(string nombre, int fila, int columna) {
	this -> nombre = nombre;
	this -> fila = fila;
	this -> columna = columna;
}

Ubicacion::Ubicacion(string nombre, string str_fila, string str_columna){
	this -> nombre = nombre;
	this -> fila = limpiar_string(str_fila, POSICION_INICIAL_FILA, TOPE_CADENA_FILA);
	this -> columna = limpiar_string(str_columna, POSICION_INICIAL_COLUMNA, TOPE_CADENA_COLUMNA);
}

string Ubicacion::obtener_nombre() {
	return nombre;
}

int Ubicacion::obtener_columna() {
	return columna;
}

int Ubicacion::obtener_fila() {
	return fila;
}

int Ubicacion::limpiar_string(string cadena, int posicion_inicial, char str_tope) {

	string numero;
	string cifra;

	numero = cadena[posicion_inicial];

	while (cadena[posicion_inicial + 1] != str_tope) {
	    posicion_inicial++;
	    if (ASCII_NUM_ZERO <= cadena[posicion_inicial] && cadena[posicion_inicial] <= ASCII_NUM_NUEVE) {
	    		cifra = cadena[posicion_inicial];
	    		numero = numero + cifra;
	    }
	}
	return stoi(numero);
}