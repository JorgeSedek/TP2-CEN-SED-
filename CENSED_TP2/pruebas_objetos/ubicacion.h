

#ifndef UBICACION_H_
#define UBICACION_H_

#include <string>

class Ubicacion{
	private:
	//atributos
	std::string nombre_edificio;
	int fila;
	int columna;

	public:
	//metodos

	//constructor sin parametros
	//pre:
	//post: crea un objeto tipo ubicacion sin parametros
	Ubicacion();

	//constructor con parametros fila, columna y nombre
	//pre:
	//post: crea un objeto con parametros fila,columna y nombre
	Ubicacion(std::string nombre_edificio, std::string fila, std::string columna);

	//pre:
	//post: devuelve el nombre del edificio
	std::string obtener_nombre_edificio();

	//pre:
	//post: devuelve la cantidad de filas
	int obtener_fila();

	//pre:
	//post: devuelve la cantidad de columnas
	int obtener_columna();

	//ṕre:
	//post: pasa una cadena de caracteres a integer
	int limpiar_string(std::string cadena, int posicion_inicial, char str_tope);

};



#endif /* UBICACION_H_ */
