#include "mapa.h"

Mapa::Mapa() {}

Mapa::Mapa(int filas, int columnas) {

	this -> filas = filas;
	this -> columnas = columnas;
	this -> transitables_disponibles = 0;
	this -> construibles_disponibles = 0;
	this -> inaccesibles_disponibles = 0;
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

void Mapa::cargar_casillero(int posicion_fila, int posicion_columna, Casillero* casillero) {
	matriz[posicion_fila][posicion_columna] = casillero;
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

					Casillero_transitable* transitable = new Casillero_transitable(i, j, TRANSITABLE);
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
		cout << ENTER_COLOR << "Se ha generado una lluvia de materiales." << endl;
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
		inaccesibles_disponibles++;
	}
}

void Mapa::consultar_casillero() {
	int fila_ingresada, columna_ingresada;
	pedir_coordenadas_casillero(fila_ingresada, columna_ingresada);
	matriz[fila_ingresada - 1][columna_ingresada - 1] -> mostrar();
}

void Mapa::pedir_coordenadas_casillero(int &fila_ingresada, int &columna_ingresada) {
	cout << SUCESS_COLOR <<"Por favor, ingrese la fila del casillero que desea consultar: " << END_COLOR << endl;
	cin >> fila_ingresada;
	cout << SUCESS_COLOR << "Por favor, ingrese la columna del casillero que desea consultar: " << END_COLOR << endl;
	cin >> columna_ingresada;
}