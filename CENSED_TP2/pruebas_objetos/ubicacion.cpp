#include "ubicacion.h"

const char TOPE_CADENA_FILA = ',';
const char TOPE_CADENA_COLUMNA = ')';
const int ASCII_NUM_ZERO = 48;
const int ASCII_NUM_NUEVE = 57;
const int POSICION_INICIAL_FILA = 1;
const int POSICION_INICIAL_COLUMNA = 0;

Ubicacion::Ubicacion(){
	this -> nombre = "";
	this -> fila = 0;
	this -> columna = 0;
	}

Ubicacion::Ubicacion(std::string nombre, std::string str_fila, std::string str_columna){
	this -> nombre = nombre;
	this -> fila = limpiar_string(str_fila, POSICION_INICIAL_FILA, TOPE_CADENA_FILA);
	this -> columna = limpiar_string(str_columna, POSICION_INICIAL_COLUMNA, TOPE_CADENA_COLUMNA);
}

std::string Ubicacion::obtener_nombre(){
	return nombre;
}

int Ubicacion::obtener_columna(){
	return columna;
}

int Ubicacion::obtener_fila(){
	return fila;
}

int Ubicacion::limpiar_string(std::string cadena, int posicion_inicial, char str_tope){

	std::string numero ;
	std::string cifra;

	numero = cadena[posicion_inicial];

	int i = posicion_inicial;
	while(cadena[i + 1] != str_tope){
	    i++;
	    if (cadena[i] >= ASCII_NUM_ZERO || cadena[i] <= ASCII_NUM_NUEVE){
	    		cifra = cadena[i];
	    		numero = numero + cifra ;
	    	}
	    }
	return stoi(numero);
}
