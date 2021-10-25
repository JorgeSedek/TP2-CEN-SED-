/*
 * mapa.h
 *
 *  Created on: 24 oct. 2021
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

//agregar a edificio.h
const string M = "mina";
const string A = "aserradero";
const string F = "fabrica";
const string E = "escuela";
const string O = "obelisco";
const string P = "planta electrica";
const string M = "madera";
const string S = "piedra";
const string I = "metal";


class Mapa{
	private:
	//atributos
	Matriz<char> tipo_terrenos;
	Vector<Ubicacion> ubicaciones;

	public:

	//constructor sin parametros
	//pre:
	//post: construye un mapa sin parametros
	Mapa();

	//constructor con parametros tipo_terrenos y ubicaciones
	//pre:
	//post: construye un Mapa con las coordenadas de ubicaciones y tipo_terrenos
	Mapa(Matriz<char> matriz_tipo_terreno, Vector<Ubicacion> ubicaciones);

	//destructor
	//pre:
	//post: libera memoria
	~Mapa();

	//pre:
	//post: muestra el mapa
	void mostrar();

	private:
	//pre:
	//post: inicializa los casilleros
	void inicializar_casilleros(char tipo_terreno, int fila, int columna);

	//pre:
	//post:indica si hay un edificio en el casillero
	bool esta_vacio(string nombre_edificio);
};




#endif /* MAPA_H_ */
