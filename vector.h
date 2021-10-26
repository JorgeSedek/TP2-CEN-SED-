/*
 * vector.h
 *
 *  Created on: 23 oct. 2021
 *      Author: jorge
 */

#ifndef _VECTOR_TEMPLATE_
#define _VECTOR_TEMPLATE_

#include <iostream>

//const int NULO = 0;

template < typename Dato>



class Vector {
    // Atributos
private:
    int largo;
    Dato* datos;

    // Metodos
public:

    //Constructor con un parametro (largo inicial)
    //PRE: l > 0
    //POS: construye un Vector de objetos de largo l e inicializa en NULO
    Vector(int l);

    //Destructor
    //PRE: -
    //POS: libera la memoria utilizada
    ~Vector();


    //consultar
    //PRE: 0 <= posicion < largo
    //POS: devuelve el valor que esta en la posicion posicion
    Dato consultar(int posicion);

    //cambiar
    //PRE: 0 <= posicion < largo
    //POS: cambia el valor que esta en la posicion posicion por v
    void cambiar(int posicion, Dato valor);

    //PRE: cantidad > 0
    //POS: extiende el vector en cantidad de lugares
    void agrandar(int cantidad);

    //pre:
	//post: devuelve el largo del vector
    int obtener_largo();

private:

    //PRE:
    //POS: pone en nulos los valores desde, desde, hasta, hasta - 1
    void inicializar(int desde, int hasta);

    void copiar(Dato* pd, int desde, int hasta);
};

template < typename Dato>

Vector<Dato>::Vector(int l) {
	largo = l;
	datos = new Dato[largo];
    inicializar(0, largo);
}

template < typename Dato>

void Vector<Dato>::inicializar(int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        datos[i] = Dato();
}

template < typename Dato>

Dato Vector<Dato>::consultar(int posicion) {
    return datos[posicion];
}

template < typename Dato>

int Vector<Dato>::obtener_largo(){
	return largo;

}

template < typename Dato>

void Vector<Dato>::cambiar(int posicion, Dato valor) {
    datos[posicion] = valor;
}


template < typename Dato>

Vector<Dato>::~Vector() {


    if (largo > 0)
        delete [] datos;
}

template < typename Dato>

void Vector<Dato>::agrandar(int cantidad) {
    int nueva_longitud = largo + cantidad;
    Dato* aux = new Dato[nueva_longitud];
    copiar(aux, 0, largo);
    delete [] datos;
    datos = aux;
    inicializar(largo, nueva_longitud);
    largo = nueva_longitud;
}

template < typename Dato>

void Vector<Dato>::copiar(Dato* pd, int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        pd[i] = datos[i];
}




#endif /* _VECTOR_ TEMPLATE_ */
