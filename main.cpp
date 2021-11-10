#include <iostream>
#include "menu.h"
#include "ctime"

using namespace std;

int main() {

    srand((unsigned)time(NULL)); // Semilla para generar números aleatorios.
    
    Vector<Material> vector_materiales;
    Vector<Edificio> vector_edificios;
    Vector<Ubicacion> vector_ubicaciones;
    Mapa* mapa;
    
    int opcion_elegida;

    if (!(cargar_materiales(vector_materiales) && 
        cargar_edificios(vector_edificios) &&
        cargar_ubicaciones(vector_ubicaciones) && 
        cargar_mapa(mapa))) {
        return 0;
    }

    cargar_ubicaciones_mapa(mapa, vector_edificios, vector_ubicaciones);
    
    mostrar_bienvenida();

    do {
        mostrar_menu();
        cin >> opcion_elegida;
        cin.clear();
        cin.ignore(100, '\n');

        while (!es_opcion_valida(opcion_elegida)) {
            system(CLR_SCREEN);
            cout << ERROR_COLOR << "La opcion elegida es invalida. Intente de nuevo." << END_COLOR << endl;
            cout << endl;
            mostrar_menu();
            cin >> opcion_elegida;
            cin.clear();
            cin.ignore(100, '\n');
        }

        procesar_opcion(opcion_elegida, mapa, vector_materiales, vector_edificios, vector_ubicaciones);
        
    } while (opcion_elegida != 10);

    return 0;
}