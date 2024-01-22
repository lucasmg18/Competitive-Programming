// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <vector>
#include <list>


long long int mcd(int a, int b) {
    if (b == 0) return a;
    else return mcd(b, a % b);
}

bool resuelveCaso() {
    long long int aux, min;
    cin >> aux;
    if (aux == 0)
        return false;
    long long int sum = 0, maxCD = aux;
    sum += aux;
    cin >> aux;
    while (aux != 0) {
        sum += aux;
        maxCD = mcd(maxCD, aux);
        cin >> aux;
    }
    cout << sum / maxCD << "\n";
    return true;
}
int main() {
    while (resuelveCaso()) {
    }

    return 0;
}