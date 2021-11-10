#include <iostream>
#include "utilidades.h"

int encontrar_edificio(Vector<Edificio> &vector_edificios) {

    string nombre_ingresado;
    int posicion_edificio = ERROR_NOMBRE_INCORRECTO;

    cout << ENTER_COLOR << "Ingrese el nombre del edificio deseado: " << END_COLOR << endl;
    
    getline(cin, nombre_ingresado);
    
    for (int i = 0; i < vector_edificios.obtener_largo() && posicion_edificio == ERROR_NOMBRE_INCORRECTO; i++) {
        if (vector_edificios.obtener_dato(i).obtener_nombre() == nombre_ingresado) {
            posicion_edificio = i;
        }
    }

    if (posicion_edificio == ERROR_NOMBRE_INCORRECTO) {
        cout << endl;
        cout << ERROR_COLOR << "-El nombre del edificio ingresado es incorrecto." << END_COLOR << endl;
    }
    
    return posicion_edificio;
}

void verificar_construccion(Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]) {
    int verificacion = 0;
    int posicion_edificio = encontrar_edificio(vector_edificios);

    if (posicion_edificio != ERROR_NOMBRE_INCORRECTO) {

        cout << endl;
        for (int i = 0; i < MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
            if (vector_edificios.obtener_dato(posicion_edificio).obtener_costo(i) > vector_materiales.obtener_dato(posiciones_materiales[i]).obtener_cantidad()) {
                cout << ERROR_COLOR << "-No hay suficiente " << vector_materiales.obtener_dato(posiciones_materiales[i]).obtener_nombre() << " para construir el edificio." << END_COLOR << endl;
                verificacion = ERROR_EXCEDENTE;
            }
        }

        Edificio edificio_a_construir = vector_edificios.obtener_dato(posicion_edificio);
        string nombre_edificio = edificio_a_construir.obtener_nombre();

        if (vector_edificios.obtener_dato(posicion_edificio).obtener_limite_construccion() == obtener_cantidad_edificio(vector_ubicaciones, nombre_edificio)) {
            cout << ERROR_COLOR << "-No se puede construir mas edificios de ese tipo." << END_COLOR << endl;
            verificacion = ERROR_EXCEDENTE;
        }

        int coordenadas[CANTIDAD_COORDENADAS];

        if (verificacion != ERROR_EXCEDENTE) {
            verificacion = verificar_coordenada_valida(mapa, vector_ubicaciones, coordenadas);
            
            if (coordenada_ocupada(vector_ubicaciones, coordenadas)) {
                cout << ERROR_COLOR << "-Las coordenadas ingresadas se encuentran ocupadas." << END_COLOR << endl;
                verificacion = false;
            }
        }

        int fila = coordenadas[FILA];
        int columna = coordenadas[COLUMNA]; 

        if (verificacion && verificacion != ERROR_EXCEDENTE) {
            if (confirmar_construccion(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales)) {

                Ubicacion ubicacion_edificio(edificio_a_construir.obtener_nombre(), fila + 1, columna + 1);
                mapa -> construir_edificio(fila, columna, edificio_a_construir);
                vector_ubicaciones.insertar_ultimo(ubicacion_edificio);
            }
        }
    }
}

bool verificar_coordenada_valida(Mapa* mapa, Vector<Ubicacion> &vector_ubicaciones, int* coordenadas) {
    
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

bool coordenada_ocupada(Vector<Ubicacion> &vector_ubicaciones, int* coordenadas) {

    for (int i = 0; i < vector_ubicaciones.obtener_largo(); i++) {
        if (vector_ubicaciones.obtener_dato(i).obtener_fila() -1 == coordenadas[FILA] &&
            vector_ubicaciones.obtener_dato(i).obtener_columna() -1 == coordenadas[COLUMNA]) {
            return true;
        }
    }
    return false;
}

void construir_edificio(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, int posicion_edificio, int posiciones_materiales[]) {
    for (int i = 0; i < MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
        Material material_utilizado = vector_materiales.obtener_dato(posiciones_materiales[i]);   
        material_utilizado.restar_costo(vector_edificios.obtener_dato(posicion_edificio).obtener_costo(i));
        vector_materiales.insertar_posicion(i, material_utilizado);    
    }
}

void mostrar_inventario(Vector<Material> &vector_materiales) {

    cout << ENTER_COLOR << "Se encuentran los siguientes materiales disponibles: " <<  END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;

    for (int i = 0; i < vector_materiales.obtener_largo(); i++) {
        vector_materiales.obtener_dato(i).mostrar_material();
    }
    cout << END_COLOR << endl;
}

bool confirmar_construccion(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, int posicion_edificio, int posiciones_materiales[]) {

    bool confirmacion = true;
    string respuesta;
    string nombre_edificio = vector_edificios.obtener_dato(posicion_edificio).obtener_nombre();

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea construir un/a '" << nombre_edificio << "'?" << END_COLOR << endl;;
    cout << SUCESS_COLOR << "Ingrese 'si' para confirmar." << END_COLOR << endl;
    mostrar_costo_edificio(vector_edificios, posicion_edificio);
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        construir_edificio(vector_materiales, vector_edificios, posicion_edificio, posiciones_materiales);
        cout << SUCESS_COLOR << "-Se ha construido exitosamente un/a '" << nombre_edificio << "'." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha construido el edificio." << END_COLOR << endl;
        confirmacion = false;
    }
    return confirmacion;
}

void mostrar_costo_edificio(Vector<Edificio> &vector_edificios, int posicion_edificio) {
    cout << endl;
    cout << ENTER_COLOR << "Costos de construccion: " << END_COLOR << endl;
    cout << SUCESS_COLOR;
    cout << "-" << vector_edificios.obtener_dato(posicion_edificio).obtener_costo(PIEDRA) << " unidades de piedra." << endl;
    cout << "-" << vector_edificios.obtener_dato(posicion_edificio).obtener_costo(MADERA) << " unidades de madera." << endl;
    cout << "-" << vector_edificios.obtener_dato(posicion_edificio).obtener_costo(METAL) << " unidades de metal." << endl;
    cout << END_COLOR << endl;
}

void cargar_posicion_material_edificios(Vector<Material> &vector_materiales, int posiciones_materiales[]) {

    for (int i = 0; i < vector_materiales.obtener_largo(); i++) {
        if (vector_materiales.obtener_dato(i).obtener_nombre() == "piedra") {
            posiciones_materiales[PIEDRA] = i;
        }
        if (vector_materiales.obtener_dato(i).obtener_nombre() == "madera") {
            posiciones_materiales[MADERA] = i;
        }
        if (vector_materiales.obtener_dato(i).obtener_nombre() == "metal") {
            posiciones_materiales[METAL] = i;
        }
    }
}

void mostrar_todos_edificios(Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones) {

    cout << ENTER_COLOR << "Esta es la informacion de todos los edificios: " << END_COLOR << endl;
    cout << endl;

    for (int i = 0; i != vector_edificios.obtener_largo(); i++) {
        cout << ENTER_COLOR;
        cout << "Se requieren los siguientes materiales para construir un/a '" << vector_edificios.obtener_dato(i).obtener_nombre() << "': ";
        cout << END_COLOR << endl;

        for (int j = 0; j < MATERIALES_UTILIZADOS_EDIFICIOS; j++) {
            cout << SUCESS_COLOR << "-" << vector_edificios.obtener_dato(i).obtener_costo(j) << " unidades de ";
            cout << vector_edificios.obtener_dato(i).obtener_nombre_material(j) << "." << END_COLOR << endl;
        }

        Material materiales_producidos = vector_edificios.obtener_dato(i).obtener_materiales_producidos();
        string nombre_material = materiales_producidos.obtener_nombre();
        int cantidad_material = materiales_producidos.obtener_cantidad();

        cout << endl;

        if (materiales_producidos.obtener_cantidad() != SIN_MATERIAL) {
            cout << SUCESS_COLOR << "-Produce " << cantidad_material << " de " << nombre_material << " cuando se recolecta." << endl;
        }

        string nombre_edificio = vector_edificios.obtener_dato(i).obtener_nombre();
        int cantidad_construidos = obtener_cantidad_edificio(vector_ubicaciones, nombre_edificio);

        cout << SUCESS_COLOR << "-Construidos: " << cantidad_construidos << "/";
        cout << vector_edificios.obtener_dato(i).obtener_limite_construccion() << "." << endl;
        cout << END_COLOR << endl;
    }
}

int obtener_cantidad_edificio(Vector<Ubicacion> &vector_ubicaciones, string nombre_edificio) {

    int cantidad = 0;

    for (int i = 0; i < vector_ubicaciones.obtener_largo(); i++) {

        if (vector_ubicaciones.obtener_dato(i).obtener_nombre() == nombre_edificio) {
            cantidad++;
        }
    }
    return cantidad;
}

void mostrar_edificios_construidos(Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones) {

    cout << ENTER_COLOR << "Estos son todos los edificios construidos: " << END_COLOR << endl;
    cout << endl;

    for (int i = 0; i < vector_edificios.obtener_largo(); i++) {
        
        string nombre_edificio = vector_edificios.obtener_dato(i).obtener_nombre();
        int cantidad_construidos = obtener_cantidad_edificio(vector_ubicaciones, nombre_edificio); 
        
        if (cantidad_construidos != NO_HAY_CONSTRUIDO) {
            cout << SUCESS_COLOR;
            cout << "-Hay " << cantidad_construidos << " '"<< nombre_edificio << "' construidos/as";
            cout << " en las coordenadas: ";
            imprimir_coordenadas_edificio(vector_ubicaciones, nombre_edificio, cantidad_construidos);
            cout << "." << endl;
            cout << endl;
        }
    }
    cout << END_COLOR << endl;
}

void imprimir_coordenadas_edificio(Vector<Ubicacion> &vector_ubicaciones, string nombre_edificio, int cantidad_construidos) {

    int contador_de_comas = 0;

    for (int i = 0; i < vector_ubicaciones.obtener_largo(); i++) {

        if (vector_ubicaciones.obtener_dato(i).obtener_nombre() == nombre_edificio) {

            cout << "(" << vector_ubicaciones.obtener_dato(i).obtener_fila() << ", ";
            cout << vector_ubicaciones.obtener_dato(i).obtener_columna() << ")";

            if (contador_de_comas < cantidad_construidos - 1) {
                cout << ", ";
                contador_de_comas++;
            }
        }
    }
}

void cargar_ubicaciones_mapa(Mapa* &mapa, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones) {

    for (int i = 0; i < vector_ubicaciones.obtener_largo(); i++) {

		string nombre_edificio = vector_ubicaciones.obtener_dato(i).obtener_nombre();
        int posicion_edificio = -1;

        for (int j = 0; j < vector_edificios.obtener_largo() && posicion_edificio == -1; j++) {
            if (vector_edificios.obtener_dato(j).obtener_nombre() == nombre_edificio) {
                posicion_edificio = j;
            }
        }
    
        Edificio edificio = vector_edificios.obtener_dato(posicion_edificio);

		int fila = vector_ubicaciones.obtener_dato(i).obtener_fila() -1;
		int columna = vector_ubicaciones.obtener_dato(i).obtener_columna() - 1;

        Casillero* casillero_vacio = mapa -> obtener_casillero(fila, columna);
        mapa -> borrar_casillero(casillero_vacio);

		Casillero_construible* construible = new Casillero_construible(fila, columna);
		construible -> asignar_edificio(edificio);
        construible -> ocupar_casillero();

	    mapa -> cargar_casillero(fila, columna, construible);

		mapa -> sumar_casillero_por_tipo(CONSTRUIBLE);
	}
}

void verificar_demolicion(Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]) {

    int verificacion = 0;
    int coordenadas[CANTIDAD_COORDENADAS];

    verificacion = verificar_coordenada_valida(mapa, vector_ubicaciones, coordenadas);
        
    if (verificacion) {
        if (!coordenada_ocupada(vector_ubicaciones, coordenadas)) {
            cout << ERROR_COLOR << "-No se encuentra ningun edificio construido en las coordenadas ingresadas." << END_COLOR << endl;
            verificacion = ERROR_DEMOLER;
        }
    }
    
    if (verificacion && verificacion != ERROR_DEMOLER) {

        Edificio edificio_vacio = Edificio();
        int fila = coordenadas[FILA];
        int columna = coordenadas[COLUMNA];

        Casillero* casillero_construible = mapa -> obtener_casillero(fila, columna);
        string nombre_edificio = casillero_construible -> obtener_nombre_contenido();

        if (confirmar_demolicion(vector_materiales, vector_edificios, nombre_edificio, posiciones_materiales)) {

            Casillero* casillero_anterior = mapa -> obtener_casillero(fila, columna);
            mapa -> borrar_casillero(casillero_anterior);
            mapa -> sumar_construibles_disponibles();

            Casillero_construible* construible = new Casillero_construible(fila, columna);
            construible -> asignar_edificio(edificio_vacio);
            construible -> desocupar_casillero();

            mapa -> cargar_casillero(fila, columna, construible);

            bool encontrado = false;
            
            for (int i = 0; i < vector_ubicaciones.obtener_largo() && !encontrado; i++) {
                if (vector_ubicaciones.obtener_dato(i).obtener_fila() - 1 == fila &&
                    vector_ubicaciones.obtener_dato(i).obtener_columna() - 1 == columna) {
                    
                    vector_ubicaciones.borrar_posicion(i);
                    encontrado = true;
                }
            }
        }
    }
}

bool confirmar_demolicion(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, string nombre_edificio, int posiciones_materiales[]) {

    bool confirmacion = true;
    string respuesta;

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea demoler un/a '" << nombre_edificio << "'?" << END_COLOR << endl;;
    cout << SUCESS_COLOR << "Ingrese 'si' para confirmar." << END_COLOR << endl;
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        demoler_edificio(vector_materiales, vector_edificios, nombre_edificio, posiciones_materiales);
        cout << SUCESS_COLOR << "-Se ha demolido exitosamente un/a '" << nombre_edificio << "'." << endl;
        cout << "-Se han devuelto un porcentaje del costo de los materiales." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha demolido el edificio." << END_COLOR << endl;
        confirmacion = false;
    }
    return confirmacion;
}

void demoler_edificio(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, string nombre_edificio, int posiciones_materiales[]) {

    Edificio edificio;
    bool encontrado = false;

    for (int i = 0; i < vector_edificios.obtener_largo() && !encontrado; i++) {
        if (vector_edificios.obtener_dato(i).obtener_nombre() == nombre_edificio) {
            edificio = vector_edificios.obtener_dato(i);
            encontrado = true;
        }
    }
    
    for (int i = 0; i != MATERIALES_UTILIZADOS_EDIFICIOS; i++) {
        Material material_utilizado = vector_materiales.obtener_dato(posiciones_materiales[i]);
        material_utilizado.sumar_costo(edificio.obtener_costo(i) / CANTIDAD_DEVUELTA);
        vector_materiales.insertar_posicion(i, material_utilizado);
    }
}

void recolectar_recursos_producidos(Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones, int posiciones_materiales[]) {
    
    bool verificacion = false;

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Se han recolectado los siguientes recursos: " << END_COLOR << endl;
    cout << endl;

    for (int i = 0; i < vector_edificios.obtener_largo(); i++) {

        string nombre_edificio = vector_edificios.obtener_dato(i).obtener_nombre();
        int cantidad_edificio = obtener_cantidad_edificio(vector_ubicaciones, nombre_edificio);

        if (cantidad_edificio) {

            Material materiales_producidos = vector_edificios.obtener_dato(i).obtener_materiales_producidos();
            string nombre_material = materiales_producidos.obtener_nombre();
            int cantidad_material = materiales_producidos.obtener_cantidad();

            if (nombre_material == S) {
                
                Material material_utilizado = vector_materiales.obtener_dato(posiciones_materiales[PIEDRA]);
                material_utilizado.sumar_costo(cantidad_material * cantidad_edificio);
                vector_materiales.insertar_posicion(posiciones_materiales[PIEDRA], material_utilizado);
                
                cout << SUCESS_COLOR << "-Se han recolectado " << cantidad_material * cantidad_edificio << " unidades de piedra." << END_COLOR << endl;
                verificacion = true;
            }

            if (nombre_material == W) {
                Material material_utilizado = vector_materiales.obtener_dato(posiciones_materiales[MADERA]);
                material_utilizado.sumar_costo(cantidad_material * cantidad_edificio);
                vector_materiales.insertar_posicion(posiciones_materiales[MADERA], material_utilizado);
                
                cout << SUCESS_COLOR << "-Se han recolectado " << cantidad_material * cantidad_edificio << " unidades de madera." << END_COLOR << endl;
                verificacion = true;
            }

            if (nombre_material == I) {
                Material material_utilizado = vector_materiales.obtener_dato(posiciones_materiales[METAL]);
                material_utilizado.sumar_costo(cantidad_material * cantidad_edificio);
                vector_materiales.insertar_posicion(posiciones_materiales[METAL], material_utilizado);
                
                cout << SUCESS_COLOR << "-Se han recolectado " << cantidad_material * cantidad_edificio << " unidades de metal." << END_COLOR << endl;
                verificacion = true;
            }
        }
    }

    if (!verificacion) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-No se han recolectado recursos por falta de edificios de produccion." << END_COLOR << endl;
    }

}