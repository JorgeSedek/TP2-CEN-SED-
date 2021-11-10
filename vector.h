#ifndef _VECTOR_TEMPLATE_
#define _VECTOR_TEMPLATE_

#include <iostream>

template <typename Dato>

class Vector {
    
    private:

    Dato* datos;
    int largo;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un Vector "vacío" con todos sus atributos nulos.
    Vector();

    // Destructor.
    //pre: -
    //post: Libera toda la memoria dinámica utilizada por el Vector.
    ~Vector();

    //pre: La 'posicion' se encuentra en el intervalo que va desde 0 hasta (largo - 1).
    //     No se puede usar en un Vector "vacío".
    //post: Devuelve el dato en la posición ingresada.
    Dato obtener_dato(int posicion);

    //pre: -
    //post: Devuelve el largo del Vector.
    int obtener_largo();

    //pre: La 'posicion' se encuentra en el intervalo que va desde 0 hasta (largo - 1).
    //     No se puede usar en un Vector "vacío".
    //post: Inserta el 'dato' en la posición ingresada.
    void insertar_posicion(int posicion, Dato dato);

    //pre: -
    //post: Inserta el 'dato' al final del Vector. Reserva memoria para el 'dato' y actualiza el valor de su largo.
    void insertar_ultimo(Dato dato);

    //pre: La 'posicion' se encuentra en el intervalo que va desde 0 hasta (largo - 1).
    //     No se puede usar en un Vector "vacío".
    //post: Borra el 'dato' ubicado en la posición ingresada.
    //      Modifica la memoria utilizada y actualiza el valor de su largo.
    void borrar_posicion(int posicion);
};

template <typename Dato>

Vector<Dato>::Vector() {
    this -> largo = 0;
    this -> datos = nullptr;
}

template <typename Dato>

Vector<Dato>::~Vector() {
    delete[] datos;
}

template <typename Dato>

Dato Vector<Dato>::obtener_dato(int posicion) {
    return datos[posicion];
}

template <typename Dato>

int Vector<Dato>::obtener_largo() {
	return largo;
}

template <typename Dato>

void Vector<Dato>::insertar_posicion(int posicion, Dato dato) {
    datos[posicion] = dato;
}

template <typename Dato>

void Vector<Dato>::insertar_ultimo(Dato dato) {
    
    Dato* nuevos_datos = new Dato [largo + 1];

    for (int i = 0; i < largo; i++) {
        nuevos_datos[i] = datos[i];
    }

    nuevos_datos[largo] = dato;

    if (largo != 0) {
        delete[] datos;
    }
    
    datos = nuevos_datos;
    largo++;
}

template <typename Dato>

void Vector<Dato>::borrar_posicion(int posicion) {

    Dato* nuevos_datos = new Dato [largo - 1];

    for (int i = 0; i < posicion; i++) {
        nuevos_datos[i] = datos[i];
    }

    for (int i = posicion; i < largo - 1; i++) {
        nuevos_datos[i] = datos[i + 1];
    }

    delete[] datos;
    
    datos = nuevos_datos;
    largo--;
}

#endif // _VECTOR_TEMPLATE_