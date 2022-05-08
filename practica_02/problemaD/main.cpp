#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void leerTabla(string nombre, int matriz[5][4]) {
	ifstream file(nombre);
	string palabra;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			file >> palabra;
			matriz[i][j] = stoi(palabra);
		}
	}
}

int main() {
	int matriz[5][4];
	leerTabla("tabla.txt", matriz);
	cout << "TABLA: " << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	string entrada;
	cout << "ingresar numero: ";
	cin >> entrada;
	char simbolo;
	int i = -1, estado = 0, var;
	do {
		i++;
		simbolo = entrada[i];
		if (isdigit(simbolo)) {
			var = 0;
		}
		else if (simbolo == '.') {
			var = 1;
		}
		else if (simbolo == '-' || simbolo == '+') {
			var = 2;
		}
		else if (simbolo == '\0') {
			var = 3;
		}
		else {
			cout << "error";
			break;
		}
		switch (var) {
		case 0:
			var = 0;
			break;
		case 1:
			var = 1;
			break;
		case 2:
			var = 2;
			break;
		case 3:
			var = 3;
			break;
		default:
			cout << "error";
		}
		estado = matriz[estado][var];
		if (estado == -1) {
			cout << "error";
			break;
		}
	} while (estado != 100);
	if (estado == 100) {
		cout << "cadena aceptada";
	}
	return 0;
}