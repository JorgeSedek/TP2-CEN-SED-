#include <iostream>
#include "menu.h"

void mostrar_bienvenida() {
    system(CLR_SCREEN);
    cout << SUCESS_COLOR;
    cout << "Bienvenido al sistema de construccion de edificios de Andypolis." << endl;
    cout << "El siguiente menu lo guiara a traves de las operaciones disponibles." << endl;
    cout << "Debe ingresar los numeros correspondientes a las operaciones requeridas." << endl;
    cout << END_COLOR << endl; 
}

void mostrar_menu() {
    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;
    cout << "1. Construir edificio por nombre." << endl;
    cout << "2. Listar los edificios construidos." << endl;
    cout << "3. Listar todos los edificios." << endl;
    cout << "4. Demoler un edificio por coordenada." << endl;
    cout << "5. Mostrar mapa." << endl;
    cout << "6. Consultar coordenada." << endl;
    cout << "7. Mostrar inventario." << endl;
    cout << "8. Recolectar recursos producidos." << endl;
    cout << "9. Lluvia de recursos." << endl;
    cout << "10. Guardar y salir." << endl;
    cout << END_COLOR;
}

void procesar_opcion(int opcion_elegida, Mapa* &mapa, Material* &vector_materiales, int &tipos_de_materiales, Edificio* &vector_edificios, int &cantidad_edificios, Ubicacion* &vector_ubicaciones, int &edificios_construidos) {

    int posiciones_materiales[MATERIALES_UTILIZADOS_EDIFICIOS];
    cargar_posicion_material_edificios(vector_materiales, tipos_de_materiales, posiciones_materiales);

    switch (opcion_elegida) {
        case 1:
            system(CLR_SCREEN);
            verificar_edificio(mapa, vector_materiales, vector_edificios, cantidad_edificios, vector_ubicaciones, edificios_construidos, posiciones_materiales);
            cout << endl;
            break;
        case 2:
            system(CLR_SCREEN);
            mostrar_edificios_construidos(vector_edificios, cantidad_edificios, vector_ubicaciones, edificios_construidos);
            break;
        case 3:
            system(CLR_SCREEN);
            mostrar_todos_edificios(vector_edificios, cantidad_edificios, vector_ubicaciones, edificios_construidos);
            break;
        case 4:
            system(CLR_SCREEN);
            break;
        case 5:
            system(CLR_SCREEN);
            mapa -> imprimir_mapa();
            break;
        case 6:
            system(CLR_SCREEN);
            mapa -> consultar_casillero();
            break;
        case 7:
            system(CLR_SCREEN);
            mostrar_inventario(vector_materiales, tipos_de_materiales);
            break;
        case 8:
            system(CLR_SCREEN);
            break;
        case 9:
            system(CLR_SCREEN);
            mapa -> generar_lluvia_materiales();
            break;
        case 10:
            system(CLR_SCREEN);
            mapa -> borrar();
    }
}

bool es_opcion_valida(int opcion_elegida) {
    return (opcion_elegida >= OPCION_MINIMA && opcion_elegida <= OPCION_MAXIMA);
}