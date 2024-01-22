// Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int solucion(int N, int tot) {
	vector<int> racimos(N);
	//int actual;
	for (int i = 0; i < N; i++) {
		cin >> racimos[i];
	}
	int delante = 0, detras = 0, sumaAct = 0, sumaMejor = INT_MAX;

	while (sumaAct > tot || delante < N) {
		while (sumaAct < tot && delante < N) {
			sumaAct += racimos[delante];
			delante++;
		}
		while (sumaAct > tot) {
			if (sumaAct < sumaMejor)
				sumaMejor = sumaAct;
			sumaAct -= racimos[detras];
			detras++;
		}
		if (sumaAct == tot)
			return tot;
	}
	if (sumaMejor == INT_MAX) {
		return -1;
	}
	return sumaMejor;

}

int main() {
	int N, t, sol;
	cin >> N >> t;
	while (N != 0 || t != 0) {
		sol = solucion(N, t);
		if (sol > -1)
			cout << sol << '\n';
		else cout << "IMPOSIBLE\n";
		cin >> N >> t;
	}
	return 0;
}