#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED

#include "edificio.h"
#include <fstream>

class Ciudad {

    private:
    Edificio* vector_edificios;
    int cantidad_edificios;

    public:
    
    // Constructor sin parametros
    Ciudad();

    Edificio* obtener_vector_edificios();
    int obtener_cantidad_edificios();
    bool cargar_edificios();
    void agregar_edificio(Edificio edificio);
};

#endif // CIUDAD_H_INCLUDED