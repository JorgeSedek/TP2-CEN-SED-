#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include <iostream>
#include <string>
#include "edificio.h"

const string TRANSITABLE = "C";
const string CONSTRUIBLE = "T";
const string INACCESIBLE = "L";

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
	virtual int obtener_cantidad_contenida() = 0; 
};

class Casillero_transitable: public Casillero {
	private:
	Material material;

	public:
	Casillero_transitable(int fila, int columna, string tipo_casillero);
	void asignar_material(Material material);
	
	void mostrar() {
		cout << "Holiss" << endl; // DEBERIA MOSTRAR INFORMACION DEL CASILLERO
	}

	void imprimir_casillero() {

		string material_contenido = "   ";

		if (material.obtener_nombre() == S && material.obtener_cantidad()) {
			material_contenido = " S ";
		}

		if (material.obtener_nombre() == W && material.obtener_cantidad()) {
			material_contenido = " W ";
		}

		if (material.obtener_nombre() == I && material.obtener_cantidad()) {
			material_contenido = " I ";
		}

		cout << CAMINO << NEGRO << material_contenido << END_COLOR;
	}

	int obtener_cantidad_contenida() {
		return material.obtener_cantidad();
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

	int obtener_cantidad_contenida() {
		
		int existe_edificio = 0;

		if (edificio.obtener_nombre() != "") {
			existe_edificio = 1;
		}

		return existe_edificio;
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

	int obtener_cantidad_contenida() {
		return 0;
	}
};

#endif // CASILLERO_H_INCLUDED