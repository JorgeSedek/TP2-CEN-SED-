#include <iostream>
#include <fstream>
#include "archivos.h"

using namespace std;

bool cargar_materiales(Vector<Material> &vector_materiales) {

    ifstream archivo(PATH_MATERIALES);
    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de materiales." << END_COLOR << endl;
        return false;
    }
    else {

        while (archivo >> nombre_material) {
            archivo >> cantidad_material;

            Material material(nombre_material, cantidad_material);

            vector_materiales.insertar_ultimo(material);
        }
    };
    archivo.close();
    return true;
}

bool cargar_edificios(Vector<Edificio> &vector_edificios) {

    ifstream archivo(PATH_EDIFICIOS);
    string nombre_edificio;
    int limite_construccion;

    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de edificios." << END_COLOR << endl;
        return false;
    }
    else {
        while (archivo >> nombre_edificio) {

            cantidad_material = stoi(leer_palabra_compuesta(archivo, nombre_edificio, OPCION_NUMEROS));
            Material piedra(S, cantidad_material);

            archivo >> cantidad_material;
            Material madera(W, cantidad_material);

            archivo >> cantidad_material;
            Material metal(I, cantidad_material);
        
            archivo >> limite_construccion;

            Edificio edificio(nombre_edificio, piedra, madera, metal, limite_construccion);

            vector_edificios.insertar_ultimo(edificio);
        }
    };
    archivo.close();
    return true;
}

bool cargar_ubicaciones(Vector<Ubicacion> &vector_ubicaciones) {
    
    ifstream archivo(PATH_UBICACIONES);
    string nombre_edificio;
    string fila;
    string columna;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de ubicaciones." << END_COLOR << endl;
        return false;
    }
    else {

        while (archivo >> nombre_edificio) {
            
            fila = leer_palabra_compuesta(archivo, nombre_edificio, OPCION_PARENTESIS);
            
            archivo >> columna;

            Ubicacion ubicacion(nombre_edificio, fila, columna);

            if (!ubicacion.obtener_fila() || !ubicacion.obtener_columna()) {
                cout << endl;
                cout << ERROR_COLOR << "ERROR: El programa no acepta coordenadas con ceros." << END_COLOR << endl;
                return false;
            }

            vector_ubicaciones.insertar_ultimo(ubicacion);
        }
    };
    archivo.close();
    return true;
}

bool cargar_mapa(Mapa* &mapa) {

    ifstream archivo(PATH_MAPA);
    int filas;
    int columnas;
    string tipo_casillero;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de mapa." << END_COLOR << endl;
        return false;
    }
    else {

        archivo >> filas;
        archivo >> columnas;

        mapa = new Mapa(filas, columnas);
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                
                archivo >> tipo_casillero;
                Casillero* casillero;
                casillero = casillero -> crear_subcasillero(i, j, tipo_casillero);
                mapa -> cargar_casillero(i, j, casillero);
                mapa -> sumar_casillero_por_tipo(tipo_casillero);
            }
        }
    };
    archivo.close();
    return true;
}

void guardar_materiales(Vector<Material> &vector_materiales) {

    ofstream archivo_salida(PATH_MATERIALES);

    for (int i = 0; i < vector_materiales.obtener_largo(); i++) {
        archivo_salida << vector_materiales.obtener_dato(i).obtener_nombre() << " " << vector_materiales.obtener_dato(i).obtener_cantidad() << endl;
    }

    archivo_salida.close();
}

void guardar_ubicaciones(Vector<Ubicacion> &vector_ubicaciones) {

    ofstream archivo_salida(PATH_UBICACIONES);

    for (int i = 0; i < vector_ubicaciones.obtener_largo(); i++) {
        archivo_salida << vector_ubicaciones.obtener_dato(i).obtener_nombre() << " (";
        archivo_salida << vector_ubicaciones.obtener_dato(i).obtener_fila();
        archivo_salida << ", " <<vector_ubicaciones.obtener_dato(i).obtener_columna() << ")" << endl;
    }

    archivo_salida.close();
}

string leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion) {
	
    string palabra_edificio = "";
	archivo >> palabra_edificio;

	while (!verificar_tipo_caracter(palabra_edificio, opcion)) {
		nombre_edificio = nombre_edificio + " " + palabra_edificio;
		archivo >> palabra_edificio;
	}
	return palabra_edificio;
}

bool verificar_tipo_caracter(string palabra, int tipo_caracter) {
	
    bool es_caracter_evaluado = false;

	if (tipo_caracter == OPCION_NUMEROS) {
		es_caracter_evaluado = es_numero(palabra);
	}
	else {
		if (palabra[POSICION_INICIAL] == PARENTESIS_CHAR) {
			es_caracter_evaluado = true;
		}
	}
	return es_caracter_evaluado;
}

bool es_numero(string palabra) {
	return (ASCII_NUM_CERO <= palabra[POSICION_INICIAL] && palabra[POSICION_INICIAL] <= ASCII_NUM_NUEVE);
}