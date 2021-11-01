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
	int inaccesibles_disponibles;
	Casillero*** matriz;

	public:
	Mapa();
	Mapa(int filas, int columnas);
	void borrar();
	int obtener_filas();
	int obtener_columnas();
	Casillero* obtener_casillero(int fila, int columna);
	string obtener_tipo_casillero(int fila, int columna);
	void cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero);
	void imprimir_mapa();
	void generar_lluvia_materiales();
	void borrar_casillero(Casillero* casillero);
	void sumar_casillero_por_tipo(string tipo_casillero);
	void consultar_casillero();
	void construir_edificio(int fila, int columna, Edificio edificio_a_construir);
	
	//pre:
	//post: recolecta recursos del mapa
	void recolectar_recursos(Material *vector_materiales, int tipos_materiales,  Ubicacion *vector_ubicaciones,int edificios_construidos);

	private:
	bool puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int material_llovido);
	void imprimir_mensaje_lluvia(int piedra_llovida, int madera_llovida, int metal_llovido, int &total_llovido);
	void pedir_coordenadas(int &fila_ingresada, int &columna_ingresada);
	void pedir_fila(int &fila);
	void pedir_columna(int &columna);
	string encontrar_edificio(Ubicacion *vector_ubicaciones,int fila, int columna, int edificios_construidos);

};

#endif // MAPA_H_INCLUDED
