/*
 * materiales.h
 *
 *  Created on: 24 oct. 2021
 *      Author: jorge
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>

using namespace std;

class Material {

    private:
    string nombre_material;
    int cantidad_material;

    public:
    Material();
    Material(string nombre_material, int cantidad_material);
    string obtener_nombre();
    int obtener_cantidad();
    void mostrar_material();
    void restar_costo(int costo);
};



#endif /* MATERIAL_H_ */
