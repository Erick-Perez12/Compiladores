#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    //problemaB
    string nombreArchivo = "codigo.txt";
    ifstream fe(nombreArchivo);
    string linea;
    while (!fe.eof()) {
        getline(fe, linea);
        int size = linea.size();
        for (int i = 0; i < size; i++) {
            cout << linea[i] << " ";
        }
        cout << endl;
    }
    fe.close();
}