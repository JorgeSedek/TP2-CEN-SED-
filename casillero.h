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

	// Constructor sin parámetros. No se puede instanciar.
	//pre: -
	//post: -
	Casillero();

	//pre: -
	//post: Devuelve la fila del Casillero.
	int obtener_fila();

	//pre: -
	//post: Devuelve la columna del Casillero.
	int obtener_columna();

	//pre: -
	//post: Devuelve el tipo de casillero del Casillero.
	string obtener_tipo_casillero();

	//pre: -
	//post: Devuelve un puntero a un subcasillero (Clase hija de Casillero) según el tipo de casillero ingresado.
	//		Le asigna su correspondiente fila y columna.
	Casillero* crear_subcasillero(int fila, int columna, string tipo_casillero);

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void ocupar_casillero();

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void desocupar_casillero();

	//pre: -
	//post: Muestra información sobre el Casillero y sobre lo que contiene.
	virtual void mostrar() = 0;

	//pre: -
	//post: Imprime el Casillero.
	virtual void imprimir_casillero() = 0;

	//pre: -
	//post: Devuelve 1 si el Casillero contiene algo, ó 0 si no contiene nada.
	virtual int obtener_cantidad_contenida() = 0;

	//pre: -
	//post: Devuelve el nombre de lo que contiene el Casillero.
	virtual string obtener_nombre_contenido() = 0;

	// Destructor.
	//pre: -
	//post: -
	virtual ~Casillero() {}
};

class Casillero_transitable: public Casillero {
	
	private:

	Material material;

	public:
	
	// Constructor con parámetros.
    //pre: -
    //post: Instancia un Casillero_transitable según los valores ingresados.
	Casillero_transitable(int fila, int columna);

	//pre: -
	//post: Actualiza el material con el 'material' ingresado.
	void asignar_material(Material material);
	
	void mostrar() {
		if (esta_vacio) {
			cout << SUCESS_COLOR << "-Soy un casillero transitable y me encuentro vacio." << END_COLOR << endl;
		}
		else {
			cout << SUCESS_COLOR << "-Soy un casillero transitable y no me encuentro vacio." << END_COLOR << endl;
			material.mostrar_informacion();
	    }
		cout << endl;
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

	string obtener_nombre_contenido() {
		return material.obtener_nombre();
	}

	~Casillero_transitable() {}
};

class Casillero_construible: public Casillero {
	
	private:

	Edificio edificio;

	public:

	// Constructor con parámetros.
    //pre: -
    //post: Instancia un Casillero_construible según los valores ingresados.
	Casillero_construible(int fila, int columna);

	//pre: -
	//post: Actualiza el edificio con el 'edificio' ingresado.
	void asignar_edificio(Edificio edificio);
	
	void mostrar() {
		if (esta_vacio) {
			cout << SUCESS_COLOR << "-Soy un casillero construible y me encuentro vacio." << END_COLOR << endl;
		}
		else {
			cout << SUCESS_COLOR << "-Soy un casillero construible y no me encuentro vacio." << END_COLOR << endl;
			edificio.mostrar_informacion();
		}
		cout << endl;
	}

	void imprimir_casillero() {

		string edificio_contenido = "   ";

		if (edificio.obtener_nombre() == M) {
			edificio_contenido = " M ";
		}

		if (edificio.obtener_nombre() == A) {
			edificio_contenido = " A ";
		}

		if (edificio.obtener_nombre() == F) {
			edificio_contenido = " F ";
		}

		if (edificio.obtener_nombre() == E) {
			edificio_contenido = " E ";
		}

		if (edificio.obtener_nombre() == O) {
			edificio_contenido = " O ";
		}

		if (edificio.obtener_nombre() == P) {
			edificio_contenido = " P ";
		}

		cout << TERRENO << NEGRO << edificio_contenido << END_COLOR;
		
	}

	int obtener_cantidad_contenida() {
		
		int existe_edificio = 0;

		if (edificio.obtener_nombre() != "") {
			existe_edificio = 1;
		}

		return existe_edificio;
	}

	string obtener_nombre_contenido() {
		return edificio.obtener_nombre();
	}

	~Casillero_construible() {}

};

class Casillero_inaccesible: public Casillero {
	
	public:

	// Constructor con parámetros.
    //pre: -
    //post: Instancia un Casillero_inaccesible según los valores ingresados.
	Casillero_inaccesible(int fila, int columna);
	
	void mostrar() {
		cout << SUCESS_COLOR << "-Soy un casillero inaccesible y me encuentro vacio." << END_COLOR << endl;
		cout << endl;
	}

	void imprimir_casillero() {
		cout << LAGO << NEGRO << "   " << END_COLOR;
	}

	int obtener_cantidad_contenida() {
		return 0;
	}

	string obtener_nombre_contenido() {
		return "";
	}

	~Casillero_inaccesible() {}
};

#endif // CASILLERO_H_INCLUDED