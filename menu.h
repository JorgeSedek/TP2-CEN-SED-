#ifndef MENU_H
#define MENU_H

#include "utilidades.h"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;

//pre: -
//post: Imprime un mensaje de bienvenida.
void mostrar_bienvenida();

//pre: -
//post: Imprime un menú de opciones.
void mostrar_menu();

//pre: -
//post: Procesa la opción elegida y realiza la operación requerida.
void procesar_opcion(int opcion_elegida, Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones);

//pre: -
//post: Devuelve True o False dependiendo si la opción elegida es válida o no.
bool es_opcion_valida(int opcion_elegida);

#endif // MENU_H