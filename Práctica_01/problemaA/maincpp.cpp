#include <iostream>
#include <string>
using namespace std;
int main() {
    //problemaA
    string text;
    cout << "Texto: ";
    getline(cin, text);

    int size = text.size();
    for (int i = 0; i < size; i++) {
        cout << text[i] << " ";
    }
    return 0;
}