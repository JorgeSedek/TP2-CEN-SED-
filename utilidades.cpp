#include <iostream>
#include "utilidades.h"

int encontrar_edificio(Edificio* vector_edificios, int cantidad_edificios) {

    string nombre_ingresado;
    int posicion_edificio = ERROR_NOMBRE_INCORRECTO;

    cout << ENTER_COLOR << "Ingrese el nombre del edificio deseado: " << END_COLOR << endl;
    cin >> nombre_ingresado;

    for (int i = 0; i < cantidad_edificios && posicion_edificio == ERROR_NOMBRE_INCORRECTO; i++) {
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

void verificar_construccion(Mapa* &mapa, Material* &vector_materiales, Edificio* &vector_edificios, int cantidad_edificios, Ubicacion* &vector_ubicaciones, int &edificios_construidos, int posiciones_materiales[]) {

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

        Edificio edificio_a_construir = vector_edificios[posicion_edificio];
        string nombre_edificio = edificio_a_construir.obtener_nombre();

        if (vector_edificios[posicion_edificio].obtener_limite_construccion() == obtener_cantidad_edificio(vector_ubicaciones, edificios_construidos, nombre_edificio)) {
            cout << ERROR_COLOR << "-No se puede construir mas edificios de ese tipo." << END_COLOR << endl;
            verificacion = ERROR_EXCEDENTE;
        }

        int coordenadas[CANTIDAD_COORDENADAS];

        if (verificacion != ERROR_EXCEDENTE) {
            verificacion = verificar_coordenada_valida(mapa, vector_ubicaciones, edificios_construidos, coordenadas);
            
            if (coordenada_ocupada(vector_ubicaciones, edificios_construidos, coordenadas)) {
                cout << ERROR_COLOR << "-Las coordenadas ingresadas se encuentran ocupadas." << END_COLOR << endl;
                verificacion = false;
            }
        }

        int fila = coordenadas[FILA];
        int columna = coordenadas[COLUMNA]; 

        if (verificacion && verificacion != ERROR_EXCEDENTE) {
            if (confirmar_construccion(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales)) {

                Ubicacion ubicacion_edificio(edificio_a_construir.obtener_nombre(), fila, columna);
                mapa -> construir_edificio(fila, columna, edificio_a_construir);
                agregar_ubicacion(vector_ubicaciones, ubicacion_edificio, edificios_construidos);
            }
        }
    }
}

bool verificar_coordenada_valida(Mapa* mapa, Ubicacion* vector_ubicaciones, int edificios_construidos, int* coordenadas) {

    pedir_coordenadas(coordenadas);
    int filas = mapa -> obtener_filas();
    int columnas = mapa -> obtener_columnas();
    bool verificacion = true;

    int fila = coordenadas[FILA];
    int columna = coordenadas[COLUMNA];

    if (fila > filas - 1 || columna > columnas - 1) {
        cout << ERROR_COLOR << "-Las coordenadas ingresadas estan fuera del mapa." << END_COLOR << endl;
        verificacion = false;
    }
    else if (mapa -> obtener_tipo_casillero(fila, columna) != CONSTRUIBLE) {
        cout << ERROR_COLOR << "-Las coordenadas no pertenecen a un casillero construible." << END_COLOR << endl;
        verificacion = false;
    }

    return verificacion;
}

void pedir_coordenadas(int* coordenadas) {
    
    int fila;
    int columna;

    pedir_fila(fila);

    while (fila <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    pedir_columna(columna);

    while (columna <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
        cout << endl;
        pedir_columna(columna);
    }
    cout << endl;
    
    coordenadas[FILA] = fila - 1;
    coordenadas[COLUMNA] = columna - 1;
}

void pedir_fila(int &fila) {
    cout << ENTER_COLOR << "Ingrese la fila deseada: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna deseada: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

bool coordenada_ocupada(Ubicacion* vector_ubicaciones, int edificios_construidos, int* coordenadas) {

    for (int i = 0; i < edificios_construidos; i++) {
        if (vector_ubicaciones[i].obtener_fila() -1 == coordenadas[FILA] && vector_ubicaciones[i].obtener_columna() -1 == coordenadas[COLUMNA]) {
            return true;
        }
    }
    return false;
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

bool confirmar_construccion(Material* vector_materiales, Edificio* vector_edificios, int posicion_edificio, int posiciones_materiales[]) {

    bool confirmacion = true;
    string respuesta;

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea construir un/a '" << vector_edificios[posicion_edificio].obtener_nombre() << "'?" << END_COLOR;
    cout << SUCESS_COLOR << " Ingrese 'si' para confirmar." << END_COLOR << endl;
    mostrar_costo_edificio(vector_edificios, posicion_edificio);
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        construir_edificio(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales);
        cout << SUCESS_COLOR << "-Se ha construido exitosamente un/a '" << vector_edificios[posicion_edificio].obtener_nombre() << "'." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha construido el edificio." << END_COLOR << endl;
        confirmacion = false;
    }
    return confirmacion;
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

void cargar_ubicaciones_mapa(Mapa* &mapa, Ubicacion* vector_ubicaciones, int edificios_construidos, Edificio* vector_edificios, int cantidad_edificios) {

    for (int i = 0; i < edificios_construidos; i++) {

		string nombre_edificio = vector_ubicaciones[i].obtener_nombre();
        int posicion_edificio = -1;

        for (int j = 0; j < cantidad_edificios && posicion_edificio == -1; j++) {
            if (vector_edificios[j].obtener_nombre() == nombre_edificio) {
                posicion_edificio = j;
            }
        }
    
        Edificio edificio = vector_edificios[posicion_edificio];

		int fila = vector_ubicaciones[i].obtener_fila() -1;
		int columna = vector_ubicaciones[i].obtener_columna() - 1;

        Casillero* casillero_vacio = mapa -> obtener_casillero(fila, columna);
        mapa -> borrar_casillero(casillero_vacio);

		Casillero_construible* construible = new Casillero_construible(fila, columna, CONSTRUIBLE);
		construible -> asignar_edificio(edificio);
        construible -> ocupar_casillero();

	    mapa -> cargar_casillero(fila, columna, construible);

		mapa -> sumar_casillero_por_tipo(CONSTRUIBLE);
	}
}

void verificar_demolicion(Mapa* &mapa, Material* &vector_materiales, Edificio* &vector_edificios, int cantidad_edificios, Ubicacion* &vector_ubicaciones, int &edificios_construidos, int posiciones_materiales[]) {

    int verificacion = 0;
    int coordenadas[CANTIDAD_COORDENADAS];

    verificacion = verificar_coordenada_valida(mapa, vector_ubicaciones, edificios_construidos, coordenadas);
        
    if (!coordenada_ocupada(vector_ubicaciones, edificios_construidos, coordenadas)) {
        cout << ERROR_COLOR << "-No se encuentra ningun edificio construido en las coordenadas ingresadas." << END_COLOR << endl;
        cout << endl;
        verificacion = ERROR_DEMOLER;
    }

    Edificio edificio_vacio = Edificio();
    int fila = coordenadas[FILA];
    int columna = coordenadas[COLUMNA];

    Casillero* casillero_encontrado = mapa -> obtener_casillero(fila, columna);
    string nombre_edificio = casillero_encontrado -> obtener_nombre_contenido();
    
    if (verificacion != ERROR_DEMOLER) {
        if (confirmar_demolicion(vector_materiales, vector_edificios, cantidad_edificios, nombre_edificio, posiciones_materiales)) {

            Casillero* casillero_anterior = mapa -> obtener_casillero(fila, columna);
            mapa -> borrar_casillero(casillero_anterior);

            Casillero_construible* construible = new Casillero_construible(fila, columna, CONSTRUIBLE);
            construible -> asignar_edificio(edificio_vacio);
            construible -> desocupar_casillero();

            mapa -> cargar_casillero(fila, columna, construible);

            bool encontrado = false;
            
            for (int i = 0; i < edificios_construidos && !encontrado; i++) {
                if (vector_ubicaciones[i].obtener_fila() - 1 == fila && vector_ubicaciones[i].obtener_columna() - 1 == columna) {
                    vector_ubicaciones[i].cambiar_a_ubicacion_vacia();
                    encontrado = true;
                }
            }
        }
    }
}

bool confirmar_demolicion(Material* vector_materiales, Edificio* vector_edificios, int cantidad_edificios, string nombre_edificio, int posiciones_materiales[]) {

    bool confirmacion = true;
    string respuesta;

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea demoler un/a '" << nombre_edificio << "'?" << END_COLOR;
    cout << SUCESS_COLOR << " Ingrese 'si' para confirmar." << END_COLOR << endl;
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        demoler_edificio(vector_materiales, vector_edificios, cantidad_edificios, nombre_edificio, posiciones_materiales);
        cout << SUCESS_COLOR << "-Se ha demolido exitosamente un/a '" << nombre_edificio << "'." << endl;
        cout << "-Se han devuelto un porcentaje del costo de los materiales." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha demolido el edificio." << END_COLOR << endl;
        confirmacion = false;
    }
    cout << endl;
    return confirmacion;
}

void demoler_edificio(Material* &vector_materiales, Edificio* &vector_edificios, int cantidad_edificios, string nombre_edificio, int posiciones_materiales[]) {
    
    Edificio edificio;
    bool encontrado = false;

    for (int i = 0; i < cantidad_edificios && !encontrado; i++) {
        if (vector_edificios[i].obtener_nombre() == nombre_edificio) {
            edificio = vector_edificios[i];
            encontrado = true;
        }
    }
    
    for (int i = 0; i != MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
        vector_materiales[posiciones_materiales[i]].sumar_costo(edificio.obtener_costo(i) / CANTIDAD_DEVUELTA);
    }
}