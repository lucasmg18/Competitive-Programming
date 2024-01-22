// Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int recorrer(const vector<vector<int>>& g, int e, int ant) {//DFS
	int visit = 1;
	//for (int i = 0; i < g[e].size(); i++) {
	for (int w : g[e]) {
		if (w != ant) {
			visit += recorrer(g, w, e);
		}
	}
	return visit;
}

bool resuelveCaso() {
	int a, n, aux1, aux2;
	cin >> n;
	if (n == 0)
		return false;
	cin >> a;
	vector<vector<int>> g(n);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2;
		aux1--; aux2--;
		g[aux1].push_back(aux2);
		g[aux2].push_back(aux1);
	}

	//vector<bool> visit(n, false);
	int visit = 0;
	visit = recorrer(g, 0, 0);
	if (visit == n) {
		cout << "TODAS\n";
	}
	else cout << "FALTA ALGUNA\n";
	return true;
}

int main() {
	while (resuelveCaso()) {

	}
	return 0;
}