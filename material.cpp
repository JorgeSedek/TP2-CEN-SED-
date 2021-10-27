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

void Material::restar_costo(int costo) {
    cantidad_material -= costo;
}

void Material::mostrar(){
	cout << "Soy una " << obtener_nombre() << " y me encuentro en el casillero consultado" << endl;
}

void Material::generar_material(){

		int tipo_material = (rand() % CANT_MATERIALES - 1) + 1 ;
		int cant_aleatoria = generar_cant_aleatoria(tipo_material);
		string nombre_material_aleatorio = convertir_num_aleatorio_a_string(tipo_material);
		if (nombre_material == VACIO || (nombre_material == nombre_material_aleatorio && cantidad_material == SIN_MATERIAL)){
		Material Material(nombre_material_aleatorio, cant_aleatoria);
		}
}

int Material::generar_cant_aleatoria(int tipo_material){
	int cant_material;

	switch(tipo_material){
		case PIEDRA:
			cant_material = (rand() % CANT_MAX_PIEDRA) + CANT_MIN_PIEDRA;
			break;
		case MADERA:
			cant_material = (rand() % CANT_MAX_MADERA) + CANT_MIN_MADERA;
			break;
		case METAL:
			cant_material = (rand() % CANT_MAX_METAL) + CANT_MIN_METAL;
			break;

	}

	return cant_material;
}

string Material::convertir_num_aleatorio_a_string(int tipo_material){
	string nombre_material;

	switch(tipo_material){
		case PIEDRA:
			nombre_material = "piedra";
			break;
		case MADERA:
			nombre_material = "madera";
			break;
		case METAL:
			nombre_material = "metal";
			break;

	}

	return nombre_material;

}
