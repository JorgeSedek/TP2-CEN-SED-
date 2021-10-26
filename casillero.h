/*
 * casillero.h
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_

#include <iostream>
#include <string>
#include "material.h"
#include "edificio.h"

class Casillero{
	protected:
	//atributos
	int fila;
	int columna;
	string tipo_casillero;
	bool esta_vacio;

	public:
	//constructor sin parametros
	//pre:
	//post: construye un objeto casillero sin parametros
	Casillero();


	//constructor con parametros fila, columna y esta_vacio
	//pre:
	//post: construye un objeto casillero con parametros
	Casillero(int fila, int columna, string tipo_casillero);

	//pre:
	//post: devuelve fila
	int obtener_fila();

	//pre:
	//post: devuelve columna
	int obtener_columna();

	//pre:
	//post: muestra que tipo de casillero es y si esta vacio
	virtual void mostrar() = 0;
};

class Casillero_transitable: public Casillero {
	private:
	//atributos
	Material material;

	public:
	//constructor sin parametros
	//pre:
	//post: construye un objeto casillero sin parametros
	Casillero_transitable();

	//constructor con parametros fila, columna y esta_vacio
	//pre:
	//post: construye un objeto casillero con parametros
	Casillero_transitable(int fila, int columna);

	//pre:
	//post: muestra mensaje correspodiente a casillero
	void mostrar(){
		if (esta_vacio){
			cout << "soy un casillero transitable y me encuentro vacio" << endl;
			}
		else{
			cout << "soy un casillero transitable y no me encuentro vacio" << endl;
			//cout << material.mostrar() << endl;
		}
	}
};

class Casillero_construible: public Casillero{
	private:
	//atributos
	Edificio edificio;

	public:
	//constructor sin parametros
	//pre:
	//post: construye un objeto casillero sin parametros
	Casillero_construible();

	//constructor con parametros fila, columna y esta_vacio
	//pre:
	//post: construye un objeto casillero con parametros
	Casillero_construible(int fila, int columna);


	void mostrar(){
		if (esta_vacio){
			cout << "soy un casillero construible y me encuentro vacio" << endl;
			}
		else{
			cout << "soy un casillero construible y no me encuentro vacio" << endl;
			//cout << edificio.mostrar() << endl;
		}
	}
};

class Casillero_inacesible: public Casillero{

	//metodos

	public:

	//constructor sin parametros
	//pre:
	//post: construye un objeto casillero sin parametros
	Casillero_inacesible();

	//constructor con parametros fila, columna y esta_vacio
	//pre:
	//post: construye un objeto casillero con parametros
	Casillero_inacesible(int fila, int columna);

	void mostrar(){
		cout << "soy un casillero inacesible y me encuentro vacio" << endl;
	}

};


#endif /* CASILLERO_H_ */
