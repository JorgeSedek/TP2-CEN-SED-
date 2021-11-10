#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "mapa.h"
#include "ubicacion.h"

const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";

const char PARENTESIS_CHAR = '(';
const int OPCION_PARENTESIS = 0;
const int OPCION_NUMEROS = 1;
const int POSICION_INICIAL = 0;

//pre: -
//post: Carga el archivo de materiales al 'vector_materiales' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_materiales(Vector<Material> &vector_materiales);

//pre: -
//post: Carga el archivo de edificios al 'vector_edificios' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_edificios(Vector<Edificio> &vector_edificios);

//pre: -
//post: Carga el archivo de ubicaciones al 'vector_ubicaciones' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_ubicaciones(Vector<Ubicacion> &vector_ubicaciones);

//pre: -
//post: Carga el archivo del mapa al 'mapa' y devuelve True.
//      Imprime un error y devuelve False si el archivo no existe.
bool cargar_mapa(Mapa* &mapa);

//pre: -
//post: Guarda los datos de los materiales al archivo de materiales.
void guardar_materiales(Vector<Material> &vector_materiales);

//pre: -
//post: Guarda los datos de las ubicaciones al archivo de ubicaciones.
void guardar_ubicaciones(Vector<Ubicacion> &vector_ubicaciones);

//pre: -
//post: Lee el 'archivo' hasta encontrarse con un número ó un parentesis según la opcion ingresada.
//      Actualiza el 'nombre_edificio' si este contiene más de una palabra. 
//      Devuelve el dato leido que no pertenece al nombre de un edificio.
string leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion);

//pre: -
//post: Devuelve True si la palabra es distinta de un número ó un parentesis.
//      En caso contrario, devuelve False.
bool verificar_tipo_caracter(string palabra, int tipo_caracter);

//pre: -
//post: Devuelve True si la 'palabra' es un número. En caso contrario, devuelve False.
bool es_numero(string palabra);

#endif // ARCHIVOS_H