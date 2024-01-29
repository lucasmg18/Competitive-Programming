#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int choque(pair<int, int> c1, pair<int, int> c2) {
	int totV = c1.second - c2.second;
	if (c1.first == c2.first)
		return 0;
	if (totV <= 0)
		return -1;
	return (c2.first - c1.first) / totV;
}

void resuelvecaso(int N){
	vector<pair<int, int>> ciclistas(N);
	for (int i = 0; i < N; i++) {
		cin >> ciclistas[i].first >> ciclistas[i].second;
	}
	sort(ciclistas.begin(), ciclistas.end());

	//for (int i = 0; i < N; i++) {
	//	cout << ciclistas[i].first <<" "<< ciclistas[i].second;
	//}
	int t = INT_MAX, nt;
	for (int i = 0; i < N-1; i++) {
		nt = choque(ciclistas[i], ciclistas[i + 1]);
		if (nt != -1 && nt < t)
			t = nt;
	}
	if (t == INT_MAX)
		cout << "SIN COLISION\n";
	else cout << t << endl;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		resuelvecaso(n);
		cin >> n;
	}
	return 0;
}