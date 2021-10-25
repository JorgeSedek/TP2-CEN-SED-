/*
 * mapa.h
 *
 *  Created on: 25 oct. 2021
 *      Author: jorge
 */

#ifndef MAPA_H_
#define MAPA_H_

#include "ubicacion.h"
#include "casillero.h"
#include "matriz.h"
#include "vector.h"
#include "material.h"
#include "edificio.h"




class Mapa{
	private:
	//atributos
	char** tipo_terrenos;
	//Vector<Ubicacion> ubicaciones;
	Matriz<Casillero> casilleros;
	int fila;
	int columna;
	public:

	//constructor sin parametros
	//pre:
	//post: construye un mapa sin parametros
	Mapa();

	//constructor con parametros tipo_terrenos y ubicaciones
	//pre:
	//post: construye un Mapa con las coordenadas de ubicaciones y tipo_terrenos
	//Mapa(char** tipo_terrenos, Vector<Ubicacion> ubicaciones, int fila, int columna);

	//destructor
	//pre:
	//post: libera memoria
	~Mapa();

	//pre:
	//post: muestra el mapa
	void mostrar();

	int obtener_fila();

	int obtener_columna();

	private:
	//pre:
	//post: inicializa los casilleros
	Casillero inicializar_casillero(char tipo_terreno, int fila, int columna);

	void inicializar_casilleros(char** tipo_terrenos);

	string convertir_caracter_a_palabra(string letra);

	//pre:
	//post:indica si hay un edificio en el casillero
	bool esta_vacio(string nombre_edificio);

	//pre: fila> fila > 0, columna > columna > 0, largo >posicion > 0
	//post: indica si las coordenadas del mapa coinciden con las coordenadas de un edificio o material

};




#endif /* MAPA_H_ */
