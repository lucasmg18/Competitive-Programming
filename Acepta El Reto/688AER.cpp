#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;


bool resuelvecaso() {
	int c,m,n;
	cin >> c >> m >> n;
	if (!cin) return false;
	int act, ant, tam, tamAnt;
	cin >> ant >> act;
	tam = act - ant;
	int min, max;
	min = tam;
	max = tam;
	bool ok = true;
	for (int i = 0; i < n-1; i++) {
		tamAnt = tam;
		ant = act;
		cin >> act;
		tam = act - ant;
		if (tam < min)
			min = tam;
		else if (tam > max)
			max = tam;
		if (abs(tam - tamAnt) > c)
			ok = false;
		if (max - min > m)
			ok = false;
	}
	if (ok)
		cout << "Ok\n";
	else cout << "Tropiezo\n";
	return true;
}

int main() {
	while (resuelvecaso()) {
	}
	return 0;
}