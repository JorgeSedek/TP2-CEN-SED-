#include "mapa.h"

Mapa::Mapa() {}

Mapa::Mapa(int filas, int columnas) {

	this -> filas = filas;
	this -> columnas = columnas;
	this -> transitables_disponibles = 0;
	this -> construibles_disponibles = 0;
	this -> inaccesibles = 0;
	
	this -> matriz = new Casillero** [filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Casillero* [columnas];
    }
}

void Mapa::borrar() {

	for (int i = 0; i < filas; i++) {

		for (int j = 0; j < columnas; j++) {
			delete matriz[i][j];
		}

		delete[] matriz[i];
	}

	delete[] matriz;
	this -> matriz = nullptr;
}

int Mapa::obtener_filas() {
	return filas;
}

int Mapa::obtener_columnas() {
	return columnas;
}

Casillero* Mapa::obtener_casillero(int fila, int columna) {
	return matriz[fila][columna];
}

string Mapa::obtener_tipo_casillero(int fila, int columna) {
	return matriz[fila][columna] -> obtener_tipo_casillero();
}

void Mapa::cargar_casillero(int fila, int columna, Casillero* casillero) {
	matriz[fila][columna] = casillero;
}

void Mapa::imprimir_mapa() {

	string coordenas_columnas = "    ";
	string lineas_columnas = "  -";

	cout << SUCESS_COLOR << "Este es el mapa de la ciudad: " << endl;
	cout << END_COLOR << endl;

	for (int c = 0; c < columnas; c++) {
		coordenas_columnas += to_string(c + 1) + "   ";
		lineas_columnas += "----";
	}

	cout << ENTER_COLOR << coordenas_columnas << endl;
	cout << ENTER_COLOR << lineas_columnas << endl;

	for (int i = 0; i < filas; i++) {
		cout << ENTER_COLOR << i + 1 << " |" << END_COLOR;
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] -> imprimir_casillero();
			cout << ENTER_COLOR << "|" << END_COLOR;
		}
		cout << endl;
		cout << ENTER_COLOR << lineas_columnas << endl;
	}
	cout << END_COLOR << endl;
}

void Mapa::generar_lluvia_materiales() {

	int piedra_llovida = rand() % CANT_MAX_PIEDRA + CANT_MIN_PIEDRA;
	int madera_llovida = rand() % CANT_MAX_MADERA + CANT_MIN_MADERA;
	int metal_llovido = rand() % CANT_MAX_METAL + CANT_MIN_METAL;

	int total_llovido = piedra_llovida + madera_llovida + metal_llovido;
	int material_llovido;

	imprimir_mensaje_lluvia(piedra_llovida, madera_llovida, metal_llovido, total_llovido);
	
	for (int i = 0; i < filas && total_llovido; i++) {
		for (int j = 0; j < columnas && total_llovido; j++) {

			if (matriz[i][j] -> obtener_tipo_casillero() == TRANSITABLE && !matriz[i][j] -> obtener_cantidad_contenida()) {

				Material nuevo_material = Material();
				material_llovido = nuevo_material.llover_material_aleatorio();

				if (puede_llover_mas(piedra_llovida, madera_llovida, metal_llovido, material_llovido)) {

					borrar_casillero(matriz[i][j]);

					Casillero_transitable* transitable = new Casillero_transitable(i, j);
					transitable -> asignar_material(nuevo_material);

					matriz[i][j] = transitable;
					matriz[i][j] -> ocupar_casillero();

					transitables_disponibles--;
					total_llovido--;
				}
			}	
		}
	}
}

void Mapa::imprimir_mensaje_lluvia(int piedra_llovida, int madera_llovida, int metal_llovido, int &total_llovido) {

	if (transitables_disponibles) {
		cout << ENTER_COLOR << "Se ha generado una lluvia de materiales: " << endl;
		cout << SUCESS_COLOR << endl;
		cout << "-Han llovido " << piedra_llovida << " piedras." << endl;
		cout << "-Han llovido " << madera_llovida << " maderas." << endl;
		cout << "-Han llovido " << metal_llovido << " metales." << endl;
		cout << END_COLOR << endl;
	}
	else {
		cout << ERROR_COLOR << "-No ha llovido por falta de casilleros transitables libres." << END_COLOR << endl;
		cout << endl;
		total_llovido = 0;
	}
}

bool Mapa::puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int material_llovido) {

	bool puede_llover_mas = true;

	if (material_llovido == PIEDRA) {
		if ((piedra_llovida - 1) >= 0) {
			piedra_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == MADERA) {
		if ((madera_llovida - 1) >= 0) {
			madera_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == METAL) {
		if ((metal_llovido - 1) >= 0) {
			metal_llovido--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	return puede_llover_mas;
}

void Mapa::borrar_casillero(Casillero* casillero) {
	delete casillero;
}

void Mapa::sumar_casillero_por_tipo(string tipo_casillero) {

	if (tipo_casillero == TRANSITABLE) {
		transitables_disponibles++;
	}
	
	if (tipo_casillero == CONSTRUIBLE) {
		construibles_disponibles++;
	}
	
	if (tipo_casillero == INACCESIBLE) {
		inaccesibles++;
	}
}

void Mapa::consultar_casillero() {
	
	int fila;
	int columna;
	
	pedir_coordenadas(fila, columna);

	if (fila <= filas - 1 && columna <= columnas - 1) {
		system(CLR_SCREEN);
		cout << ENTER_COLOR << "El casillero de la coordenada (" << fila + 1 << ", " << columna + 1 << ") dice: " << END_COLOR << endl;
		cout << endl;
		matriz[fila][columna] -> mostrar();
	}
	else {
		cout << ERROR_COLOR << "-Las coordenadas ingresadas estan fuera del mapa." << END_COLOR << endl;
		cout << endl;
	}
}

void Mapa::pedir_coordenadas(int &fila, int &columna) {
	
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

	fila = fila -1;
	columna = columna - 1;
    cout << endl;
}

void Mapa::pedir_fila(int &fila) {
    cout << ENTER_COLOR << "Ingrese la fila del casillero que desea consultar: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void Mapa::pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna del casillero que desea consultar: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

void Mapa::construir_edificio(int fila, int columna, Edificio edificio_a_construir) {

	if (matriz[fila][columna] -> obtener_tipo_casillero() == CONSTRUIBLE && !matriz[fila][columna] -> obtener_cantidad_contenida()) {

		borrar_casillero(matriz[fila][columna]);

		Casillero_construible* construible = new Casillero_construible(fila, columna);
		construible -> asignar_edificio(edificio_a_construir);

		matriz[fila][columna] = construible;
		matriz[fila][columna] -> ocupar_casillero();

		construibles_disponibles--;
	}
}

void Mapa::sumar_construibles_disponibles() {
	construibles_disponibles++;
}