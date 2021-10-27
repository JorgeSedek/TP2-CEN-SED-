#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include <iostream>
#include <string>
#include "edificio.h"

using namespace std;

class Casillero {
	
	protected:
	//atributos
	int fila;
	int columna;
	string tipo_casillero;
	bool esta_vacio;

	public:
	//metodos
	Casillero();
	int obtener_fila();
	int obtener_columna();

	//pre:
	//post:devuelve el tipo de casillero("T", "C" y "L")
	string obtener_tipo_casillero();

	virtual void mostrar() = 0;
	virtual void imprimir_casillero() = 0;
};

class Casillero_transitable: public Casillero {
	private:
	Material material;

	public:
	Casillero_transitable(int fila, int columna, string tipo_casillero);

	//pre:
	//post: devuelve el material
	Material obtener_material(){
		return material;
	}

	void mostrar() {
		if (esta_vacio){
			cout << "soy un casillero transitable y me encuentro vacio" << endl;
		}
		else{
			cout << "soy un casillero transitable y no me encuentro vacio" << endl;
			material.mostrar();
	    }
	}

	void imprimir_casillero() {
		cout << CAMINO << "C";
	}

};

class Casillero_construible: public Casillero {
	private:
	Edificio edificio;

	public:
	Casillero_construible(int fila, int columna, string tipo_casillero);
	void mostrar() {
		if (esta_vacio){
			cout << "soy un casillero construible y me encuentro vacio" << endl;
			}
		else{
			cout << "soy un casillero construible y no me encuentro vacio" << endl;
			edificio.mostrar();
		}
	}

	void imprimir_casillero() {
		cout << TERRENO << "T";
	}
};

class Casillero_inaccesible: public Casillero {
	public:
	Casillero_inaccesible(int fila, int columna, string tipo_casillero);
	void mostrar() {
		cout << "soy un casillero inacesible y me encuentro vacio" << endl;
	    }

	void imprimir_casillero() {
		cout << LAGO << "L";
	}
};

#endif // CASILLERO_H_INCLUDED
