//Lucas Martin Garcia
#include <iostream>
#include <vector>
using namespace std;

void resuelveCaso() {
	int N, act, cont = 0;
	cin >> N;
	vector<int> lista(N), lista2(N);
	//vector<bool> visit(N+1, false);
	for (int i = 0; i < N; i++) {
		cin >> lista[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> lista2[i];
	}
	int i1 = N - 1, i2 = N - 1;
	while (i1 >= 0) {

		if (lista[i1] == lista2[i2]) {
			int a = lista[i1], b = lista2[i2];
			i1--;
			cont++;
			i2--;
		}
		else {
			i1--;
		}
	}

	//int index = 0;
	//for (int i = 0; i < N; i++) {
	//	cin >> act;
	//	while (index < N && visit[lista[index]])
	//		index++;

	//	if (lista[index] == act) {
	//		index++;
	//	}
	//	else {
	//		cont++;
	//		visit[act] = true;
	//	}
	//}
	cout << N - cont << "\n";
}

int main() {
	int numc;
	cin >> numc;
	for (int i = 0; i < numc; i++) {
		resuelveCaso();
	}
	return 0;
}