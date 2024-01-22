// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


bool resuelveCaso() {
    int n, v, s, e, saltos, a1, a2, k;
    cin >> n >> k >> s >> e;
    v = n * n;
    saltos = s + e;
    if (n == 0 && k == 0 && s == 0 && e == 0)
        return false;
    vector<bool> marked(v, false);
    vector<int> salto(v, -1);
    for (int i = 0; i < saltos; i++) {
        cin >> a1 >> a2;
        salto[a1 - 1] = a2 - 1;
    }

    if (v == 1) {//caso solo una casilla
        cout << "0\n";
        return true;
    }

    int nivel = 1, numNodNiv = 1, casilla = 0, sig;
    bool enc = false, primerSinSalto;
    queue<int> cola;

    cola.push(casilla);// se empiza en el 0
    while (!cola.empty() && !enc) { //(BFS)
        casilla = cola.front();
        sig = casilla + k;
        primerSinSalto = false;
        if (sig >= v - 1) // ya ha llegado
            enc = true;
        else {
            while (sig > casilla) { // se comprueban todos los saltos posibles y la casilla mas alejada sin salto
                if (!marked[sig]) {
                    if (salto[sig] != -1) {
                        if (!marked[salto[sig]]) { // si no, se ha llegado a esa casilla ya sin usar este salto
                            cola.push(salto[sig]);
                            marked[salto[sig]] = true;
                        }
                    }
                    else if (!primerSinSalto) { // si todavia no se ha encontrado el mas alejado sin salto
                        cola.push(sig);
                        marked[sig] = true;
                        primerSinSalto = true;
                    }
                }
                sig--;
            }

            cola.pop();
            numNodNiv--;
            if (numNodNiv == 0) {
                nivel++;
                numNodNiv = cola.size();
            }
        }
    }
    cout << nivel << '\n';
    return true;
}
int main() {

    while (resuelveCaso());

    return 0;
}