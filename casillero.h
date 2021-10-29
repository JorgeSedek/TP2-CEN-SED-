#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include <iostream>
#include <string>
#include "edificio.h"

class Casillero {
	
	protected:
	int fila;
	int columna;
	string tipo_casillero;
	bool esta_vacio;

	public:
	Casillero();
	int obtener_fila();
	int obtener_columna();
	string obtener_tipo_casillero();
	Casillero* crear_subcasillero(int fila, int columna, string tipo_casillero);
	virtual void mostrar() = 0;
	virtual void imprimir_casillero() = 0;
};

class Casillero_transitable: public Casillero {
	private:
	Material material;

	public:
	Casillero_transitable(int fila, int columna, string tipo_casillero);
	void mostrar() {
		cout << "Holiss" << endl; // DEBERIA MOSTRAR INFORMACION DEL CASILLERO
	}

	void imprimir_casillero() {
		cout << CAMINO << NEGRO << "   " << END_COLOR;
	}
};

class Casillero_construible: public Casillero {
	private:
	Edificio edificio;

	public:
	Casillero_construible(int fila, int columna, string tipo_casillero);
	void mostrar() {
		cout << "Holiss" << endl; // DEBERIA MOSTRAR INFORMACION DEL CASILLERO
	}

	void imprimir_casillero() {
		cout << TERRENO << NEGRO << "   " << END_COLOR;
		
	}
};

class Casillero_inaccesible: public Casillero {
	public:
	Casillero_inaccesible(int fila, int columna, string tipo_casillero);
	void mostrar() {
		cout << "Holiss" << endl; // DEBERIA MOSTRAR INFORMACION DEL CASILLERO
	}

	void imprimir_casillero() {
		cout << LAGO << NEGRO << "   " << END_COLOR;
	}
};

#endif // CASILLERO_H_INCLUDED