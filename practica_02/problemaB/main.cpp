#include <iostream>
using namespace std;
int main() {
	int tabla[3][3] = { {1,2,-1},{-1,-1,-1},{2,2,100} };
	cout << "TABLA" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << tabla[i][j] << " ";
		}
		cout << endl;
	}
	string entrada;
	cout << "ingrese palabra: ";
	cin >> entrada;
	char simbolo;
	int i = -1, estado = 0, var;
	do {
		i++;
		simbolo = entrada[i];
		if (isdigit(simbolo)) {
			var = 0;
		}
		else if (isalpha(simbolo)) {
			var = 1;
		}
		else if (simbolo == '\0') {
			var = 2;
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
		default:
			cout << "error";
		}
		estado = tabla[estado][var];
		if (estado == -1) {
			cout << "error";
			break;
		}
	} while (estado != 100);
	if (estado == 100) {
		cout << "cadena aceptada";
	}
}