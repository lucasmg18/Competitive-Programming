//Lucas Martin Garcia
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int D, A, B, aux;
	cin >> D >> A >> B;
	if (!cin) return false;
	//priority_queue<int, vector<int>, greater<int>> prA, prB;
	priority_queue<int> prA, prB;
	for (int i = 0; i < A; i++) {
		cin >> aux;
		prA.push(aux);
	}
	for (int i = 0; i < B; i++) {
		cin >> aux;
		prB.push(aux);
	}
	int pilA, pilB, i, horas, hAct;
	bool primero = true;
	while (!prA.empty() && !prB.empty()) {
		vector<int> gastadasA, gastadasB;
		i = 0;
		horas = 0;
		while (!prA.empty() && !prB.empty() && i < D) {
			pilA = prA.top();
			pilB = prB.top();
			prA.pop();
			prB.pop();
			hAct = min(pilA, pilB);
			horas += hAct;
			pilA -= hAct;
			pilB -= hAct;
			if (pilA > 0) {
				gastadasA.push_back(pilA);
			}
			else if (pilB > 0) {
				gastadasB.push_back(pilB);
			}
			i++;
		}

		for (int p : gastadasA)
			prA.push(p);
		for (int p : gastadasB)
			prB.push(p);

		if (!primero)
			cout << " ";
		else primero = false;
		cout << horas;
	}
	cout << endl;


	return true;
}



int main() {
	while (resuelveCaso()) {

	}
	return 0;
}
