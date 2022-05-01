#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
void abrirtext(vector<string>& arreglo, string nombreArchivo) {
    ifstream fe(nombreArchivo);
    string linea;
    while (!fe.eof()) {
        getline(fe, linea);
        arreglo.push_back(linea);
    }
    fe.close();
}

void cifrado(vector<string>& arreglo, int desp) {
    int aux = 0;
    ofstream guardar;
    guardar.open("cifrado.txt", ios::out);
    for (int i = 0; i < arreglo.size(); i++) {
        for (char& c : arreglo[i]) {
            aux = c;
            if (aux + desp > 255) {
                aux = ((aux + desp) - 255) + 1;
            }
            else {
                aux = aux + desp;
            }
            if (c != ' ' && c != '\t') {
                c = aux;
            }
            guardar << c;
        }
        guardar << endl;
    }
    guardar.close();
}

void descifrado(vector<string>& arreglo, int desp) {
    int aux = 0;
    ofstream guardar;
    guardar.open("descifrado.txt", ios::out);
    for (int i = 0; i < arreglo.size(); i++) {
        for (char& c : arreglo[i]) {
            aux = c;
            if (aux - desp < 2) {
                aux = 257 - (1 - (aux - desp));
            }
            else {
                aux = aux - desp;
            }
            if (c != ' ' && c != '\t') {
                c = aux;
            }
            cout << c;
            guardar << c;
        }
        cout << endl;
        guardar << endl;
    }
    guardar.close();
}

int main() {
    //problemaC
    vector<string> arreglo;
    string textC = "codigo.txt";
    string textD = "cifrado.txt";
    abrirtext(arreglo,textC);
    for (int j = 0; j < arreglo.size(); j++) {
        cout << arreglo[j]<<endl;
    }
    cifrado(arreglo, 1);
    arreglo.clear();
    abrirtext(arreglo, textD);
    for (int j = 0; j < arreglo.size(); j++) {
        cout << arreglo[j] << endl;
    }
    descifrado(arreglo, 1);
    return 0;
}