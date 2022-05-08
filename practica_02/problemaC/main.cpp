#include <iostream>
using namespace std;

enum class estado { INI, Q1, Q2, Q3, Q4 };
estado reconocerNum(string& entrada) {
	int i = 0;
	estado actual = estado::INI;
	bool rechazada = false;
	while (not rechazada and i < entrada.size()) {
		char simbolo = entrada[i];
		switch (actual) {
		case estado::INI:
			if (isdigit(simbolo)) {
				actual = estado::Q3;
			}
			else if (simbolo == '+' or simbolo == '-') {
				actual = estado::Q1;
			}
			else if (simbolo == '.') {
				actual = estado::Q2;
			}
			else {
				rechazada = true;
			}
			break;
		case estado::Q1:
			if (isdigit(simbolo)) {
				actual = estado::Q3;
			}
			else if (simbolo == '.') {
				actual = estado::Q2;
			}
			else {
				rechazada = true;
			}
			break;
		case estado::Q2:
			if (isdigit(simbolo)) {
				actual = estado::Q4;
			}
			else {
				rechazada = true;
			}
			break;
		case estado::Q3:
			if (isdigit(simbolo)) {
				actual = estado::Q3;
			}
			else if (simbolo == '.') {
				actual = estado::Q2;
			}
			else {
				rechazada = true;
			}
			break;
		case estado::Q4:
			if (isdigit(simbolo)) {
				actual = estado::Q4;
			}
			else {
				rechazada = true;
			}
			break;
		}
		i++;
	}
	if (rechazada) {
		cout << "cadena rechazada";
	}
	return actual;
}

int main() {
	string entrada;
	cout << "ingrese numero: ";
	cin >> entrada;
	estado aceptacion = reconocerNum(entrada);
	if (aceptacion == estado::Q3) {
		cout << "aceptado";
	}
	else if (aceptacion == estado::Q4) {
		cout << "aceptado";
	}
}