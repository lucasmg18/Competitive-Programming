//Lucas Martin Garcia
#include <iostream>
#include <vector>

// Solo puedes estar menos que 2 de bateria al restar, asi que al restar tienes que ver si lo que has sumado antes lo contrarresta
// Cada vez que restas vuelves a empezar a contar a ver si antes has sumado, y esto se hace con max(-,2).

using namespace std;

using vii = vector<long long>;

bool resuelveCaso() {
    int F, C;
    cin >> C >> F;
    if (!cin) return false;
    if (F == 0 || C == 0) {
        cout << 2 << '\n';
    }
    else {
        vii din(C);
        long long int aux;
        vector<vector<long long int>> bat(F, vector<long long int>(C));
        for ( int i = 0; i < F ; i++)
            for (int j = 0; j < C; j++) {
                cin >> bat[i][j];
            }

        din[C - 1] = 0; 

        for (int j = C-2; j >= 0; --j) {
            din[j] = min(din[j + 1] + bat[F-1][j],(long long) 0);
        }
        for (int i = F-2; i >= 0; --i) {
            din[C - 1] = min(din[C - 1] + bat[i][C-1], (long long)0);
            for (int j = C - 2; j >= 0; --j) {
                aux = max(din[j + 1], din[j]);
                din[j] = min(aux + bat[i][j], (long long)0);
            }
        }
        cout << 2- din[0] << '\n';
    }
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}