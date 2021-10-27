#ifndef MENU_H
#define MENU_H

#include "archivos.h"
#include "utilidades.h"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;

void mostrar_bienvenida();
void mostrar_menu();
void procesar_opcion(int opcion_elegida, Material* &vector_materiales, int &tipos_de_materiales, Edificio* &vector_edificios, int &cantidad_edificios, Ubicacion* &vector_ubicaciones, int &edificios_construidos, Mapa &mapa);
bool es_opcion_valida(int opcion_elegida);
void mostrar_costo_edificio(Edificio* vector_edificio, int posicion_edificio);

#endif // MENU_H