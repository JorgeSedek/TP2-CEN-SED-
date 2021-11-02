#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "mapa.h"
#include "ubicacion.h"
#include "edificio.h"

const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";

//pre: -
//post: Carga el archivo de materiales al 'vector_materiales' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_materiales(Material* &vector_materiales, int &tipos_de_materiales);

//pre: -
//post: Agrega el 'material' al 'vector_materiales' de forma dinámica.
//      Actualiza el valor de 'tipos_de_materiales'.
void agregar_material(Material* &vector_materiales, Material material, int &tipos_de_materiales);

//pre: -
//post: Carga el archivo de edificios al 'vector_edificios' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_edificios(Edificio* &vector_edificios, int &cantidad_edificios);

//pre: -
//post: Agrega el 'edificio' al 'vector_edificios' de forma dinámica.
//      Actualiza el valor de 'cantidad_edificios'.
void agregar_edificio(Edificio* &vector_edificios, Edificio edificio, int &cantidad_edificios);

bool cargar_ubicaciones(Ubicacion* &vector_ubicaciones, int &edificios_construidos);
void agregar_ubicacion(Ubicacion* &vector_ubicaciones, Ubicacion ubicacion, int &edificios_construidos);
bool cargar_mapa(Mapa* &mapa);
void guardar_materiales(Material* &vector_materiales, int tipos_de_materiales);
void borrar_vector_edificios(Edificio* &vector_edificios);
void guardar_ubicaciones(Ubicacion* vector_ubicaciones, int edificios_construidos);

#endif // ARCHIVOS_H