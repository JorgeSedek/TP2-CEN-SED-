#include <iostream>
#include "menu.h"
#include "ctime"

using namespace std;

int main() {

    srand(time(NULL));
    
    int tipos_de_materiales = 0;
    Material* vector_materiales = nullptr;
    
    int cantidad_edificios = 0;
    Edificio* vector_edificios = nullptr;

    int edificios_construidos = 0;
    Ubicacion* vector_ubicaciones = nullptr;

    Mapa* mapa;
    
    int opcion_elegida;

    if (!cargar_materiales(vector_materiales, tipos_de_materiales)) return 0;
    if (!cargar_edificios(vector_edificios, cantidad_edificios)) return 0;
    if (!cargar_ubicaciones(vector_ubicaciones, edificios_construidos)) return 0;
    if (!cargar_mapa(mapa)) return 0;

    cargar_ubicaciones_mapa(mapa, vector_ubicaciones, edificios_construidos, vector_edificios, cantidad_edificios);
    
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

        procesar_opcion(opcion_elegida, mapa, vector_materiales, tipos_de_materiales, vector_edificios, cantidad_edificios, vector_ubicaciones, edificios_construidos);
        
    } while (opcion_elegida != 10);
    
    return 0;
}