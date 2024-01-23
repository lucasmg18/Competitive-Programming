// Lucas Martin Garcia
#include <iostream>

using namespace std;

void resuelve() {
	long long int m, d, n;
	cin >> m >> d >> n;
	while (m + d + n > 0) {
		int a, b, aux;
		if (m < d) { a = d; b = m; }
		else { a = m; b = d; }
		while (b != 0) {
			aux = b;
			b = a % b;
			a = aux;
		}
		cout << n / (m * d / a) << endl;
		cin >> m >> d >> n;
	}
}

int main() {
	resuelve();
	return 0;
}