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
void comparar(vector<string>& arreglo) {
    char PR[4] = { 'int','cout','char','endl' };
    char ID[4] = { '+','´-','/','=' };
    char PyC[1] = { ';' };
    vector<char> aux;
    string espacio = " ";
    vector<string>t;
    size_t pos = 0;
    for (int i = 0; i < arreglo.size(); i++) {
        while ((pos = arreglo[i].find(espacio)) != string::npos) {
            t.push_back(arreglo[i].substr(0, pos));
            arreglo[i].erase(0, pos + espacio.size());
        }
        for (int h = 0; h < t.size(); h++) {
            cout << t[h] << endl;
        }
        t.clear();
        /*for (char& c : arreglo[i]) {
            aux.push_back(c);
        }
        for (int j = 0; j < aux.size(); j++) {
            if (aux[j] != ' ') {
                string h(1, aux[j]);
                t.push_back(h);

            }
            for (int u = 0; u < t.size(); u++) {
                cout << t[u];
            }
            t.clear();
        }
        aux.clear();*/
    }
}

int main() {
    vector<string> arreglo;
    string textC = "codigo.txt";
    abrirtext(arreglo, textC);

    for (int j = 0; j < arreglo.size(); j++) {
        cout << arreglo[j] << endl;
    }
    comparar(arreglo);
}
