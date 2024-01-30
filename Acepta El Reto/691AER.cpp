#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;


bool resuelvecaso() {
	int F, A, C;
	cin >> F >> A >> C;
	if (!cin) return false;
	vector<int> filas(F);
	for (int i = 0; i < F; i++) {
		cin >> filas[i];
	}
	sort(filas.begin(), filas.end());
	filas.push_back(A);
	long long int sigFil = 1, asienAct = A - filas[0], asienSig, numFilAct = 1, precio = 0;
	while (C > 0 && asienAct > 0) {
		while ( A - filas[sigFil] == asienAct) {
			sigFil++;
			numFilAct++;
		}
		asienSig = A - filas[sigFil];
		long long int difSigAs = asienAct - asienSig;
		if (C > numFilAct * difSigAs) {
			precio += numFilAct * (asienAct + (asienSig + 1)) * (difSigAs) / 2;

			asienAct = A - filas[sigFil];
			C -= numFilAct * difSigAs;
		}
		else {
			long long int entera = C / numFilAct, resto = C % numFilAct;
			difSigAs = entera;
			precio += numFilAct * (asienAct + (asienAct - difSigAs + 1)) * (entera) / 2;
			precio += resto * (asienAct - difSigAs);
			C = 0;
		}
	}
	cout << precio << endl;
	return true;
}

int main() {
	while (resuelvecaso()) {
	}
	return 0;
}