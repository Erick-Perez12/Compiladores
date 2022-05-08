#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string entrada;
	vector<char> prueba;
	int estado=1, i = 0;
	char simbolo;
	std::cout << "palabra: ";
	cin>>entrada;
	for (char& c : entrada) {
		prueba.push_back(c);
	}
	simbolo = prueba[0];
	while(simbolo!=prueba[prueba.size()-1]) {
		switch(estado){
		case 1:
			if (isdigit(simbolo)) {
				estado = 2;
			}
			else if (isalpha(simbolo)) {
				estado = 3;
			}
			else {
				break;
			}
		case 2:
			break;
		case 3:
			if (isalpha(simbolo)) {
				estado = 3;
			}
			else if (isdigit(simbolo)) {
				estado = 3;
			}
			else {
				break;
			}
		}
		i++;
		simbolo = prueba[i];
	}
	if (estado != 3) {
		std::cout << "error ";
	}
	else {
		std::cout << "leido ID";
	}
	return 0;
}