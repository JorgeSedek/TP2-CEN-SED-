#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "ubicacion.h"
#include "casillero.h"

const int TIPOS_MATERIALES_LLUVIA = 3;

class Mapa {
	
	private:

	int filas;
	int columnas;
	int transitables_disponibles;
	int construibles_disponibles;
	int inaccesibles;
	Casillero*** matriz;

	public:

	// Constructor sin parámetros. Pensado para crear punteros a Mapa.
	//pre: -
    //post: Instancia un Mapa sin valor alguno.
	Mapa();

	// Constructor con parámetros.
	//pre: -
    //post: Instancia un Mapa de un tamaño que depende de los valores ingresados.
	Mapa(int filas, int columnas);

	//pre: -
    //post: Libera por completo toda la memoria dinámica utilizada por el Mapa y sus Casilleros.
	void borrar();

	//pre: -
    //post: Devuelve la cantidad de filas del Mapa.
	int obtener_filas();

	//pre: -
    //post: Devuelve la cantidad de columnas del Mapa.
	int obtener_columnas();

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Devuelve un puntero al Casillero ubicado en la fila y columna ingresadas.
	Casillero* obtener_casillero(int fila, int columna);

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Devuelve el tipo del Casillero ubicado en la fila y columna ingresadas.
	string obtener_tipo_casillero(int fila, int columna);

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Asigna el puntero a Casillero a la posición fila y columna ingresadas.
	void cargar_casillero(int fila, int columna, Casillero* casillero);

	//pre: -
    //post: Imprime el Mapa.
	void imprimir_mapa();

	//pre: -
    //post: Genera una lluvia de Materiales en el Mapa.
	void generar_lluvia_materiales();

	//pre: -
    //post: Libera la memoria dinámica utilizada para almacenar al Casillero ingresado.
	void borrar_casillero(Casillero* casillero);

	//pre: El 'tipo_casillero' es un tipo de Casillero válido.
    //post: Suma uno a los casilleros disponibles correspondientes al tipo ingresado.
	void sumar_casillero_por_tipo(string tipo_casillero);

	//pre: -
    //post: Pide al usuario que ingrese una fila y una columna, y muestra información del Casillero
	//		correspondiente a dichas coordenadas.
	void consultar_casillero();

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Construye el Edificio en la fila y columna ingresadas si esta no está ocupada.
	void construir_edificio(int fila, int columna, Edificio edificio_a_construir);

	//pre: -
    //post: Suma uno al atributo 'construibles_disponibles'.
	void sumar_construibles_disponibles();
	
	private:

	//pre: -
    //post: Verifica si puede llover más del 'material_llovido' y devuelve True.
	//		Devuelve False si no se pasa la verificación.
	bool puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int material_llovido);
	
	//pre: -
    //post: Pide coordenadas y actualiza los respectivos valores ingresados.
	void pedir_coordenadas(int &fila, int &columna);

	//pre: -
    //post: Pide una número y actualiza el valor de fila.
	void pedir_fila(int &fila);

	//pre: -
    //post: Pide una número y actualiza el valor de columna.
	void pedir_columna(int &columna);
};

#endif // MAPA_H_INCLUDED