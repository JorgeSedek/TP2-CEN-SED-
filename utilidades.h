#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "archivos.h"
#include "edificio.h"

const int ERROR_EXCEDENTE = -1;
const int ERROR_NOMBRE_INCORRECTO = -2;
const int ERROR_DEMOLER = -3;
const int CANTIDAD_DEVUELTA = 2;

//pre: -
//post: Pide al usuario que ingrese el nombre de un edificio y devuelve su posición.
//      Si no se encuentra el edificio, devuelve un error.
int encontrar_edificio(Vector<Edificio> &vector_edificios);

//pre: -
//post: Imprime en pantalla el nombre y la cantidad de todos los materiales disponibles.
void mostrar_inventario(Vector<Material> &vector_materiales);

//pre: -
//post: Imprime el costo del edificio que se encuentra en la posición ingresada.
void mostrar_costo_edificio(Vector<Edificio> &vector_edificios, int posicion_edificio);

//pre: -
//post: Imprime en pantalla toda la informacion relacionada con cada tipo de edificio.
void mostrar_todos_edificios(Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones);

//pre: El vector 'posiciones_materiales[]' tiene una capacidad igual a 'MATERIALES_UTILIZADOS_EDIFICIOS'.
//post: Carga y ordena en 'posiciones_materiales[]' la posición de los materiales utilizados por
//      los edificios respecto del 'vector_materiales'.
void cargar_posicion_material_edificios(Vector<Material> &vector_materiales, int posiciones_materiales[]);

//pre: -
//post: Verifica si existen suficientes materiales para construir el edificio indicado, si este no ha
//      superado el límite de construcción ó si las coordenadas ingresadas son válidas.
//      Imprime distintos mensajes según cada caso.
void verificar_construccion(Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]);

//pre: -
//post: Pide una confirmación al usuario para construir el edificio.
bool confirmar_construccion(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, int posicion_edificio, int posiciones_materiales[]);

//pre: -
//post: Construye el edificio indicado y resta su costo de los materiales disponibles.
void construir_edificio(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, int posicion_edificio, int posiciones_materiales[]);

//pre: -
//post: Devuelve la cantidad de edificios construidos respecto al nombre del edificio ingresado.
int obtener_cantidad_edificio(Vector<Ubicacion> &vector_ubicaciones, string nombre_edificio);

//pre: -
//post: Imprime en pantalla la cantidad de edificios construidos de cada tipo.
void mostrar_edificios_construidos(Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones);

//pre: -
//post: Imprime las coordenadas de todos los edificios que coinciden con el 'nombre_edificio'.
void imprimir_coordenadas_edificio(Vector<Ubicacion> &vector_ubicaciones, string nombre_edificio, int cantidad_construidos);

//pre: -
//post: Verifica si las coordenadas ingresadas son válidas.
bool verificar_coordenada_valida(Mapa* mapa, Vector<Ubicacion> &vector_ubicaciones, int* coordenadas);

//pre: -
//post: Pide al usuario que ingrese coordenadas.
//      Actualiza 'coordenadas' con las coordenadas ingresadas.
void pedir_coordenadas(int* coordenadas);

//pre: -
//post: Pide al usuario que ingrese una fila.
void pedir_fila(int &fila);

//pre: -
//post: Pide al usuario que ingrese una columna.
void pedir_columna(int &columna);

//pre: -
//post: Verifica si las coordenadas están ocupadas.
bool coordenada_ocupada(Vector<Ubicacion> &vector_ubicaciones, int* coordenadas);

//pre: -
//post: Carga las ubicaciones ocupadas respecto del 'vector_ubicaciones' al 'mapa' en sus respectivas coordenadas.
void cargar_ubicaciones_mapa(Mapa* &mapa, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones);

//pre: -
//post: Verifica si existe un edificio en las coordenadas ingresadas. En ese caso, lo demuele.
//      Imprime un mensaje de error si la coordenada está vacía.
void verificar_demolicion(Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]);

//pre: -
//post: Pide una confirmación al usuario para demoler el edificio.
bool confirmar_demolicion(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, string nombre_edificio, int posiciones_materiales[]);

//pre: -
//post: Demuele el edificio indicado y suma un pocentaje de su costo a los materiales disponibles.
void demoler_edificio(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, string nombre_edificio, int posiciones_materiales[]);

//pre: -
//post: Recolecta e imprime todos los recursos producidos por los edificios de producción construidos.
//      Si no hay ningún edificio de producción construido, imprime un error.
void recolectar_recursos_producidos(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]);

#endif // UTILIDADES_H