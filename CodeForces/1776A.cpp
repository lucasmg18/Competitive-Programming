//Lucas Martin Garcia
#include <iostream>
using namespace std;

void resuelveCaso() {
	int N, ant = 0, act, cont = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> act;
		if (act - ant >= 120) {
			cont++;
			if (act - ant >= 240)
				cont++;
		}
		ant = act;
	}
	act = 1440;
	if (act - ant >= 120) {
		cont++;
		if (act - ant >= 240)
			cont++;
	}
	if (cont >= 2) {
		cout << "YES\n";
	}
	else
		cout << "NO\n";
}

int main() {
	int numc;
	cin >> numc;
	for (int i = 0; i < numc; i++) {
		resuelveCaso();
	}



	return 0;
}