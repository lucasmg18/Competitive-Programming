// Lucas Martin Garcia
#include <iostream>

using namespace std;

void solucion() {
	int lados[3], aux;
	for (int i = 0; i < 3; i++) {
		cin >> lados[i];
	}
	for (int i = 0; i < 2; i++) {
		if (lados[2] < lados[i]) {
			aux = lados[2];
			lados[2] = lados[i];
			lados[i] = aux;
		}
	}
	if (lados[1] + lados[0] <= lados[2]) {
		cout << "IMPOSIBLE\n";
	}
	else {
		int cuad[3];
		for (int i = 0; i < 3; i++) {
			cuad[i] = lados[i] * lados[i];
		}
		int suma = cuad[0] + cuad[1];
		if (suma > cuad[2])
			cout << "ACUTANGULO\n";
		else if (suma == cuad[2])
			cout << "RECTANGULO\n";
		else 	cout << "OBTUSANGULO\n";
	}
}
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		solucion();
	}
	return 0;
}