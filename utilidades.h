#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "edificio.h"

const int ERROR_EXCEDENTE = -1;
const int ERROR_NOMBRE_INCORRECTO = -2;
const int ERROR_DEMOLER = -3;
const int CANTIDAD_DEVUELTA = 2;

int encontrar_edificio(Edificio* vector_edificios, int cantidad_edificios);
void mostrar_inventario(Material* vector_materiales, int tipos_de_materiales);
string obtener_nombre_material(int posicion);
void mostrar_costo_edificio(Edificio* vector_edificio, int posicion_edificio);
void mostrar_todos_edificios(Edificio* vector_edificios, int cantidad_edificios);
void cargar_posicion_material_edificios(Material* vector_materiales, int tipos_de_materiales, int posiciones_materiales[]);
void verificar_edificio(Material* &vector_materiales, Edificio* &vector_edificios, int posicion_edificio, int posiciones_materiales[]);
void construir_edificio(Material* &vector_materiales, Edificio* &vector_edificios, int posicion_edificio, int posiciones_materiales[]);
void confirmar_construccion(Material* vector_materiales, Edificio* vector_edificios, int posicion_edificio, int posiciones_materiales[]);

#endif // UTILIDADES_H