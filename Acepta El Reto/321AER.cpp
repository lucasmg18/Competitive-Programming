// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


void resuelveCaso() {
    //ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, d, t;
    cin >> u >> d;
    t = u + d;
    cout << (t + 1) * (t) / 2 + u + 1 << "\n";

}
int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        resuelveCaso();

    return 0;
}