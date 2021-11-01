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

void Material::mostrar_informacion() {
	cout << SUCESS_COLOR << "-Soy un/a " << obtener_nombre() << " y me encuentro en el casillero consultado." << END_COLOR << endl;
}

int Material::llover_material_aleatorio() {

	int tipo_material = rand() % CANT_MATERIALES;
	string nombre_material_aleatorio = obtener_tipo_material(tipo_material);
		
	if (nombre_material == VACIO || cantidad_material) {
		this -> nombre_material = nombre_material_aleatorio;
		this -> cantidad_material = MATERIAL_CONTENIDO_POR_CASILLERO;
	}
	return tipo_material;
}

string Material::obtener_tipo_material(int tipo_material){
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

void Material::producir_material(string nombre_edificio){
	string nombre_material = devolver_nombre_material_producido(nombre_edificio);
	if (this -> nombre_material == nombre_material){
		cantidad_material += asignar_cantidad_recolectada(nombre_edificio);
	}
	}


string Material::devolver_nombre_material_producido(string nombre_edificio){
	string nombre_material = VACIO;
	if (nombre_edificio == "mina"){
		nombre_material = S;
	}
	else
	if (nombre_edificio == "aserradero"){
		nombre_material = W;
	}
	else
	if (nombre_edificio == "fabrica"){
		nombre_material = I;
	}
	else
	if (nombre_edificio == "escuela"){
		nombre_material == VACIO;
	}
	else
	if (nombre_edificio == "obeliscio"){
		nombre_material == VACIO;
	}
	else
	if (nombre_edificio == "planta electrica"){
		nombre_material == VACIO;
	}
	return nombre_material;
}

int Material::asignar_cantidad_recolectada(string nombre_edificio){
	int cantidad_material = SIN_MATERIAL;
	if (nombre_edificio == "mina"){
		cantidad_material = PRODUCCION_MINA;
	}
	else
	if (nombre_edificio == "aserradero"){
		cantidad_material = PRODUCCION_ASERRADERO;
	}
	else
	if (nombre_edificio == "fabrica"){
		cantidad_material = PRODUCCION_FABRICA;
	}
	else
	if (nombre_edificio == "escuela"){
		cantidad_material == SIN_MATERIAL;
	}
	else
	if (nombre_edificio == "obeliscio"){
		cantidad_material == SIN_MATERIAL;
	}
	else
	if (nombre_edificio == "planta electrica"){
		cantidad_material == SIN_MATERIAL;
	}
	return cantidad_material;

}

