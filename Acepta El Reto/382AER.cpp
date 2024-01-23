// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


struct compPair {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	}
};
void resuelveCaso() {
	int n, d, aux1, aux2;
	cin >> d >> n;
	int mcm = 1;
	//inicio, fin
	vector<pair<int, int>> m(n);

	for (int i = 0; i < n; i++) {
		cin >> aux1 >> aux2;
		m[i] = { aux1 - aux2, aux2 + aux1 };
	}
	sort(m.begin(), m.end(), compPair());
	bool cub = true;
	int j = 1, dist = m[0].second;
	if (m[0].first > 0)
		cub = false;
	while (cub && j < n) {
		if (dist < m[j].first)
			cub = false;
		if (dist < m[j].second)
			dist = m[j].second;
		j++;
	}
	if (dist < d)
		cub = false;
	if (cub) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		resuelveCaso();
	}

	return 0;
}