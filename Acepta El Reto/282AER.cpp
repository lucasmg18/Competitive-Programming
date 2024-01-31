//Lucas Martin Garcia
#include <iostream>
#include <vector>
using namespace std;


bool resuelveCaso() {
	int N, A;
	cin >> N >> A;
	if (!cin) return false;
	vector<int> aguj(N);
	for (int i = 0; i < N; i++) {
		cin >> aguj[i];
	}
	int cont = 0, agAct = 0, posAct;
	while (agAct < N) {
		posAct = aguj[agAct];
		while (agAct < N &&aguj[agAct] <= posAct + A) {
			agAct++;
		}
		cont++;
	}
	cout << cont << endl;


	return true;
}

int main() {
	while (resuelveCaso()) {

	}
}