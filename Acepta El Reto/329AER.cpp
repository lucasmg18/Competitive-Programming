//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void resuelveCaso(int N) {
	vector<pair<int,int>> edif(N);
	for (int i = 0; i < N; i++) {
		cin >> edif[i].second >> edif[i].first;
	}
	sort(edif.begin(), edif.end());

	int cont = 0, act = 0, ant;
	while (act < N) {
		ant = act;
		while (act < N && edif[act].second < edif[ant].first) {
			act++;
		}
		cont++;
	}
	cout << cont << endl;
}

int main() {
	int N;
	cin >> N;
	while (N != 0) {
		resuelveCaso(N);
		cin >> N;
	}
}