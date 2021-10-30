#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "casillero.h"

const int TIPOS_MATERIALES_LLUVIA = 3;

class Mapa {
	private:
	int filas;
	int columnas;
	int transitables_disponibles;
	int construibles_disponibles;
	int inaccesibles_disponibles;
	Casillero*** matriz;

	public:
	Mapa();
	Mapa(int filas, int columnas);
	void borrar();
	int obtener_filas();
	int obtener_columnas();
	void cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero);
	void imprimir_mapa();
	void generar_lluvia_materiales();
	void borrar_casillero(Casillero* casillero);
	void sumar_casillero_por_tipo(string tipo_casillero);
	void consultar_casillero();
	
	private:
	bool puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int material_llovido);
	void imprimir_mensaje_lluvia(int piedra_llovida, int madera_llovida, int metal_llovido, int &total_llovido);
	void pedir_coordenadas_casillero(int &fila_ingresada, int &columna_ingresada);
};

#endif // MAPA_H_INCLUDED