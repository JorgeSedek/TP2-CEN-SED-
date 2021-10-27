#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "system_clear.h"
#include "colores.h"
#include <string>
#include <cstdlib>

using namespace std;

const string VACIO = "";
const string S = "piedra";
const string W = "madera";
const string I = "metal";

const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const int CANT_MATERIALES = 3;
const int CANT_MAX_PIEDRA = 2;
const int CANT_MAX_MADERA = 1;
const int CANT_MAX_METAL = 4;
const int CANT_MIN_PIEDRA = 1;
const int CANT_MIN_MADERA = 0;
const int CANT_MIN_METAL = 2;



const int PRODUCCION_MINA = 15;
const int PRODUCCION_ASERRADERO = 25;
const int PRODUCCION_FABRICA = 40;
const int SIN_MATERIAL = 0;

class Material {

    private:
	//atributos
    string nombre_material;
    int cantidad_material;

    public:
    //metodos
    Material();
    Material(string nombre_material, int cantidad_material);
    string obtener_nombre();
    int obtener_cantidad();
    void mostrar_material();
    void restar_costo(int costo);

    //pre:
    //post:genera un material de forma aleatoria
    void generar_material();

    //pre:
    //post: muestra un mensaje con informacion del material
    void mostrar();

    private:
    //pre: tipo_material pertenece a [PIEDRA, MADERA, METAL],osea 1,2,3 respectivamente
    //post: devuelve la cantidad aleatoria según que material sea
    int generar_cant_aleatoria(int tipo_material);

    //pre: tipo_material pertenece a [PIEDRA, MADERA, METAL],osea 1,2,3 respectivamente
    //post: convierte numero aleatorio en el nombre del material(string)
    string convertir_num_aleatorio_a_string(int tipo_material);

};

#endif // MATERIAL_H_INCLUDED
