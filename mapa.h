#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "casillero.h"

class Mapa {

	private:
	//atributos
	int filas;
	int columnas;
	Casillero*** matriz;

	public:
	//metodos

	//constructor sin parametros
	//pre:
	//post: construye un objeto Mapa sin parametros
	Mapa();

	//constructor de parametros (filas, columnas)
	//pre: filas del archivo > filas > 0, columnas del archivo > columnas > 0
	//post:construye un objeto Mapa con parametros filas y columnas
	Mapa(int filas, int columnas);

	//pre:
	//post:inicializa los casilleros sin parametros
	void inicializar_casilleros();

	//pre: filas > posicion_fila > 0, columnas > posicion_columna
	//post: carga los parametros de casillero
	void cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero);

	//pre:
	//post: imprime el mapa
	void imprimir_mapa();

	//pre:
	//post:Devuelve informacion sobre el casillero, si es un casillero valido
	void consultar_casillero();

	//pre:
	//post: Genera aleatoriamente materiales en los casilleros validos vacios del mapa
	void lluvia_materiales();

	private:
	//pre:filas > fila_ingresada > 0, columnas > columna_ingresada > 0
	//post:le pide al usuario las coordenadas de la casilla que quiere consultar
	void pedir_coordenadas_casillero(int &fila_ingresada, int &columna_ingresada);

};

#endif // MAPA_H_INCLUDED
