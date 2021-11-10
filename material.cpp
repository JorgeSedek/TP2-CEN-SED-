#include <iostream>
#include "material.h"

Material::Material() {
    this -> nombre_material = "";
    this -> cantidad_material = 0;
}

Material::Material(string nombre_material, int cantidad_material) {
    this -> nombre_material = nombre_material;
    this -> cantidad_material = cantidad_material;
}

string Material::obtener_nombre() {
    return nombre_material;
}

int Material::obtener_cantidad() {
    return cantidad_material;
}

void Material::mostrar_material() {
    cout << '-' << obtener_cantidad() << " unidades de " << obtener_nombre() << '.' << endl;
}

void Material::sumar_costo(int costo) {
	cantidad_material += costo;
}

void Material::restar_costo(int costo) {
    cantidad_material -= costo;
}

void Material::mostrar_informacion() {
	cout << SUCESS_COLOR << "-Soy un/a " << obtener_nombre() << " y me encuentro en el casillero consultado." << END_COLOR << endl;
}

int Material::llover_material_aleatorio() {

	int tipo_material = rand() % CANT_MATERIALES;
	string nombre_material_aleatorio = obtener_tipo_material(tipo_material);
		
	if (nombre_material == VACIO) {
		nombre_material = nombre_material_aleatorio;
		cantidad_material = MATERIAL_CONTENIDO_POR_CASILLERO;
	}
	return tipo_material;
}

string Material::obtener_tipo_material(int tipo_material) {
	
	string nombre_material;

	switch(tipo_material) {
		case PIEDRA:
			nombre_material = "piedra";
			break;
		case MADERA:
			nombre_material = "madera";
			break;
		case METAL:
			nombre_material = "metal";
	}
	return nombre_material;
}