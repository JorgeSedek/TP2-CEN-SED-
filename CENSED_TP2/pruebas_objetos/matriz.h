/*
 * matriz.h
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#ifndef _MATRIZ_TEMPLATE_
#define _MATRIZ_TEMPLATE_

#include <iostream>

template < typename Dato>



class Matriz {
    // Atributos
private:
    int fila;
    int columna;
    Dato** datos;



    // Metodos
public:

    //Constructor con un parametro (largo inicial)
    //PRE: fila > 0, columna > 0
    //POS: construye una Matriz de objetos fila y columna inicializa en NULO
    Matriz(int fila, int columna);

    //Destructor
    //PRE: -
    //POS: libera la memoria utilizada
    ~Matriz();

    //pre:
    //post: devuelve la cantidad de filas
    int obtener_filas();

    //pre:
    //post: devuelve la cantidad de columnas
    int obtener_columnas();

    //consultar
    //PRE: 0 <= posicion_x < fila , 0 <= posicion_y < columna
    //POS: devuelve el valor que esta en la posicion posicion
    Dato consultar(int posicion_x, int posicion_y);

    //cambiar
    //PRE: 0 <= posicion < largo
    //POS: cambia el valor que esta en la posicion posicion por v
    void cambiar(int posicion_x, int posicion_y, Dato valor);

    //PRE: cantidad_x > 0, cantidad_y > 0
    //POS: extiende la matriz en cantidad de lugares
    void agrandar(int cantidad_x, int cantidad_y);

private:

    //PRE: Dato tiene que ser un objeto
    //POS: pone en nulos los valores desde, desde, hasta, hasta - 1
    void inicializar(int desde_x, int hasta_x, int desde_y, int hasta_y);

    void copiar(Dato** pd, int desde_x, int hasta_x, int desde_y, int hasta_y);
};

template < typename Dato>

Matriz<Dato>::Matriz(int fila, int columna) {

	this -> fila = fila;
	this -> columna = columna;

	datos = new Dato* [columna];
	for (int i = 0 ; i < columna; i++){
		datos[i] = new Dato[fila];
	}
	 inicializar(0, fila, 0, columna);
}

template < typename Dato>

int Matriz<Dato>::obtener_filas(){
	return fila;
}

template < typename Dato>

int Matriz<Dato>::obtener_columnas(){
	return columna;
}

template < typename Dato>

Matriz<Dato>::~Matriz(){

	for(int i = 0; i < fila; i++){
		delete [] datos[i];
	}
	delete [] datos;
}

template < typename Dato>

void Matriz<Dato>::inicializar(int desde_x, int hasta_x, int desde_y, int hasta_y) {

    for (int j = desde_y; j < hasta_y; j++){
    	for(int i = desde_x; i < hasta_x; i++){
    		datos[i][j] = Dato();
    	}
    }

}

template < typename Dato>

Dato Matriz<Dato>::consultar(int posicion_x, int posicion_y) {

	return datos[posicion_x][posicion_y];

    }

template < typename Dato>

void Matriz<Dato>::cambiar(int posicion_x, int posicion_y, Dato valor) {

    datos[posicion_x][posicion_y] = valor;
}

template < typename Dato>

void Matriz<Dato>::agrandar(int cantidad_x, int cantidad_y) {

    int nueva_longitud_y = columna + cantidad_y;
    int nueva_longitud_x = fila + cantidad_x;
    Dato** aux = new Dato* [nueva_longitud_y];
    for (int i = 0; i < nueva_longitud_y; i++){
    	datos[i] = new Dato[nueva_longitud_x];
    }
    copiar(aux, 0, fila, 0, columna);
	for(int k = 0; k < fila; k++){
		delete [] datos[k];
	}
	delete [] datos;
    datos = aux;
    inicializar(fila, nueva_longitud_x, columna, nueva_longitud_y);
    fila = nueva_longitud_x;
    columna = nueva_longitud_y;
}

template < typename Dato>

void Matriz<Dato>::copiar(Dato** pd, int desde_x, int hasta_x, int desde_y, int hasta_y) {
    for (int j = desde_y; j < hasta_y; j++){
    	for (int i = desde_x; i < hasta_x; i++){
    		pd[i] = datos[i][j];
    	}
    }

}


#endif /* _MATRIZ_TEMPLATE_ */
