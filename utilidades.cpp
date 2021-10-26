#include <iostream>
#include "utilidades.h"

int encontrar_edificio(Edificio* vector_edificios, int cantidad_edificios) {

    string nombre_ingresado;
    int posicion_edificio = ERROR_NOMBRE_INCORRECTO;

    cout << ENTER_COLOR << "Ingrese el nombre del edificio deseado: " << END_COLOR << endl;
    cin >> nombre_ingresado;

    for (int i = 0; i != cantidad_edificios && posicion_edificio == ERROR_NOMBRE_INCORRECTO; i++) {
        if (vector_edificios[i].obtener_nombre() == nombre_ingresado) {
            posicion_edificio = i;
        }
    }

    if (posicion_edificio == ERROR_NOMBRE_INCORRECTO) {
        cout << endl;
        cout << ERROR_COLOR << "-El nombre del edificio ingresado es incorrecto." << END_COLOR << endl;
    }
    
    return posicion_edificio;
}

void verificar_edificio(Material* &vector_materiales, Edificio* &vector_edificios, int cantidad_edificios, int posiciones_materiales[]) {

    int verificacion = 0;
    int posicion_edificio = encontrar_edificio(vector_edificios, cantidad_edificios);

    if (posicion_edificio != ERROR_NOMBRE_INCORRECTO) {
        cout << endl;
        for (int i = 0; i != MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
            if (vector_edificios[posicion_edificio].obtener_costo(i) > vector_materiales[posiciones_materiales[i]].obtener_cantidad()) {
                cout << ERROR_COLOR << "-No hay suficiente " << vector_materiales[posiciones_materiales[i]].obtener_nombre() << " para construir el edificio." << END_COLOR << endl;
                verificacion = ERROR_EXCEDENTE;
            }
        }

        if (verificacion != ERROR_EXCEDENTE) {
        confirmar_construccion(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales);
        }
    }

}

void construir_edificio(Material* &vector_materiales, Edificio* &vector_edificios, int posicion_edificio, int posiciones_materiales[]) {
    for (int i = 0; i != MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
        vector_materiales[posiciones_materiales[i]].restar_costo(vector_edificios[posicion_edificio].obtener_costo(i));             
    }
}

void mostrar_inventario(Material* vector_materiales, int tipos_de_materiales) {

    cout << ENTER_COLOR << "Se encuentran los siguientes materiales disponibles: " <<  END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;

    for (int i = 0; i != tipos_de_materiales; i++) {
        vector_materiales[i].mostrar_material();
    }
    cout << END_COLOR << endl;
}

void confirmar_construccion(Material* vector_materiales, Edificio* vector_edificios, int posicion_edificio, int posiciones_materiales[]) {

    string respuesta;

    cout << ENTER_COLOR << "Esta seguro que desea construir un/a '" << vector_edificios[posicion_edificio].obtener_nombre() << "'?" << END_COLOR;
    cout <<  SUCESS_COLOR <<" Ingrese 'si' para confirmar." << END_COLOR << endl;
    mostrar_costo_edificio(vector_edificios, posicion_edificio);
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        construir_edificio(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales);

        cout << SUCESS_COLOR << "-Se ha construido exitosamente un/a '" << vector_edificios[posicion_edificio].obtener_nombre() << "'." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha construido el edificio." << END_COLOR << endl;
    }
}

void mostrar_costo_edificio(Edificio* vector_edificio, int posicion_edificio) {
    cout << endl;
    cout << ENTER_COLOR << "Costos de construccion: " << END_COLOR << endl;
    cout << SUCESS_COLOR;
    cout << "-" << vector_edificio[posicion_edificio].obtener_costo(PIEDRA) << " unidades de piedra." << endl;
    cout << "-" << vector_edificio[posicion_edificio].obtener_costo(MADERA) << " unidades de madera." << endl;
    cout << "-" << vector_edificio[posicion_edificio].obtener_costo(METAL) << " unidades de metal." << endl;
    cout << END_COLOR << endl;
}

string obtener_nombre_material(int posicion) {
    
    string nombre_material;
    
    switch (posicion) {
        case PIEDRA:
        nombre_material = "piedra";
        break;
        case MADERA:
        nombre_material = "madera";
        break;
        case METAL:
        nombre_material = "metal";
    }

    return nombre_material;
}

void cargar_posicion_material_edificios(Material* vector_materiales, int tipos_de_materiales, int posiciones_materiales[]) {

    for (int i = 0; i < tipos_de_materiales; i++) {
        if (vector_materiales[i].obtener_nombre() == "piedra") {
            posiciones_materiales[PIEDRA] = i;
        }
        if (vector_materiales[i].obtener_nombre() == "madera") {
            posiciones_materiales[MADERA] = i;
        }
        if (vector_materiales[i].obtener_nombre() == "metal") {
            posiciones_materiales[METAL] = i;
        }
    }
}

void mostrar_todos_edificios(Edificio* vector_edificios, int cantidad_edificios, Ubicacion* vector_ubicaciones, int edificios_construidos) {

    cout << ENTER_COLOR << "Esta es la informacion de todos los edificios: " << END_COLOR << endl;
    cout << endl;

    for (int i = 0; i != cantidad_edificios; i++) {
        cout << ENTER_COLOR;
        cout << "Se requieren los siguientes materiales para construir un/a '" << vector_edificios[i].obtener_nombre() << "': ";
        cout << END_COLOR << endl;

        for (int j = 0; j < MATERIALES_UTILIZADOS_EDIFICIOS; j++) {

            cout << SUCESS_COLOR << "-" << vector_edificios[i].obtener_costo(j) << " unidades de ";
            cout << vector_edificios[i].obtener_nombre_material(j) << "." << END_COLOR << endl;
        }

        Material materiales_producidos = vector_edificios[i].obtener_materiales_producidos();
        string nombre_material = materiales_producidos.obtener_nombre();
        int cantidad_material = materiales_producidos.obtener_cantidad();

        cout << endl;
        if (materiales_producidos.obtener_cantidad() != SIN_MATERIAL) {
            cout << SUCESS_COLOR << "-Produce " << cantidad_material << " de " << nombre_material << " cuando se recolecta." << endl;
        }

        string nombre_edificio = vector_edificios[i].obtener_nombre();
        int cantidad_construidos = obtener_cantidad_edificio(vector_ubicaciones, edificios_construidos, nombre_edificio);

        cout << SUCESS_COLOR << "-Construidos: " << cantidad_construidos << "/";
        cout << vector_edificios[i].obtener_limite_construccion() << "." << endl;
        cout << END_COLOR << endl;
    }
}

int obtener_cantidad_edificio(Ubicacion* vector_ubicaciones, int edificios_construidos, string nombre_edificio) {

    int cantidad = 0;

    for (int i = 0; i < edificios_construidos; i++) {

        if (vector_ubicaciones[i].obtener_nombre() == nombre_edificio) {
            cantidad++;
        }
    }
    return cantidad;
}

void mostrar_edificios_construidos(Edificio* vector_edificios, int cantidad_edificios, Ubicacion* vector_ubicaciones, int edificios_construidos) {

    cout << ENTER_COLOR << "Estos son todos los edificios construidos: " << END_COLOR << endl;
    cout << endl;

    for (int i = 0; i < cantidad_edificios; i++) {
        
        string nombre_edificio = vector_edificios[i].obtener_nombre();
        int cantidad_construidos = obtener_cantidad_edificio(vector_ubicaciones, edificios_construidos, nombre_edificio); 
        
        if (cantidad_construidos != NO_HAY_CONSTRUIDO) {
            cout << SUCESS_COLOR;
            cout << "-Hay " << cantidad_construidos << " '"<< nombre_edificio << "' construidos/as." << endl;
        }
    }
    cout << END_COLOR << endl;
}