// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>
#include <memory>
#include <stack>
#include <climits>
#include <unordered_map>

bool resuelveCaso() {
    int n, kMin;
    cin >> n >> kMin;
    if (!cin)
        return false;

    vector<int> dist(n), ben(n), anterior(n, -1), mat(n, 0);
    int aux;
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ben[i];
    }
    aux = n - 2;
    for (int i = n - 1; i >= 0 && aux >= 0; i--) {
        while (aux >= 0 && dist[i] < dist[aux] + kMin)
            aux--;
        anterior[i] = aux;
    }

    mat[0] = ben[0];
    for (int d = 1; d < n; d++) {
        if (anterior[d] != -1)
            mat[d] = max(mat[anterior[d]] + ben[d], mat[d - 1]);
        else
            mat[d] = max(ben[d], mat[d - 1]);
    }
    cout << mat[n - 1] << '\n';
    return true;
}


int main() {
//
//#ifndef DOMJUDGE
//    std::ifstream entrada("casos.txt");
//    auto cinbuf = cin.rdbuf(entrada.rdbuf());
//#endif

    while (resuelveCaso());

//
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif
    return 0;
}