/*
 * main.cpp
 *
 *  Created on: 22 oct. 2021
 *      Author: jorge
 */

#include <string>
#include <iostream>
#include "ubicacion.h"
#include "vector.h"
#include "edificio.h"
#include "casillero.h"
#include "matriz.h"

using namespace std;

int main(){
	Ubicacion u1("escuela", "(1234,", "56789)");
	Ubicacion u2("aserradero", "(0000,", "100)");
	Ubicacion u3("torre", "(3000,", "4000)");

	Material mat_1("piedra",300);
	Material mat_2("oro", 500);
	Material mat_3("madera",200);
	Material mat_4("piedra",300);
	Material mat_5("oro", 500);
	Material mat_6("madera",200);
	Material mat_7("piedra",300);
	Material mat_8("oro", 500);
	Material mat_9("madera",200);

	Matriz<Material> m1(3,3);
	m1.cambiar(0,0, mat_1);
	m1.cambiar(1,0, mat_2);
	m1.cambiar(2,0, mat_3);
	m1.cambiar(0,1, mat_4);
	m1.cambiar(1,1, mat_5);
	m1.cambiar(2,1, mat_6);
	m1.cambiar(0,1, mat_7);
	m1.cambiar(1,1, mat_8);
	m1.cambiar(2,1, mat_9);



	cout << "este es el material de la fila 1 y columna 1: " << m1.consultar(1, 1).obtener_nombre() << endl;



	Vector<Material> v1(3);
	v1.cambiar(0, mat_1);
	v1.cambiar(1, mat_2);
	v1.cambiar(2, mat_3);



	for (int j = 0; j < 3; j++){
		cout << v1.consultar(j).obtener_nombre() << endl;

		}
	cout <<""<<endl;
	Edificio e1("escuela",mat_1,mat_2,mat_3,2);
	Edificio e2("torre",mat_1,mat_2,mat_3,3);
	Edificio e3("yacimiento",mat_1,mat_2,mat_3,4);

	Vector<Edificio> v2(3);
	v2.cambiar(0, e1);
	v2.cambiar(1, e2);
	v2.cambiar(2, e3);

	for (int k = 0; k < 3; k++){
			cout << v2.consultar(k).obtener_nombre()<< endl;
			cout << "limite construccion: " << v2.consultar(k).obtener_limite_construccion()<< endl;

		}

	cout <<""<<endl;
	cout << "nombre: " << u1.obtener_nombre_edificio() << endl;
	cout << "fila: " << u1.obtener_fila() << endl;
	cout << "columna: " << u1.obtener_columna() << endl;

	Vector<Ubicacion> vc(3);
	vc.cambiar(0, u1);
	vc.cambiar(1, u2);
	vc.cambiar(2, u3);



	for (int i = 0; i < 3; i++){
		cout << vc.consultar(i).obtener_nombre_edificio() << endl;

	}

	Casillero_construible c1(2, 3, false, e1);
	Casillero_transitable t1(8, 5, false, mat_1);
	Casillero_construible c2(2, 3, true);
	Casillero_transitable t2(8, 5, true);

	c1.mostrar();
	t1.mostrar();
	c2.mostrar();
	t2.mostrar();

	return 0;
}

