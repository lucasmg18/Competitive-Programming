// Lucas Martin Garcia
#include <iostream>
#include <vector>
using namespace std;

using tM = vector<vector<int>>;
const pair<int, int> dirs4[4] = { {-1,0},{0,1}, {1,0}, {0,-1} };


void resuelveCaso() {
	int F, C, n;
	cin >> F >> C >> n;
	tM m(F, vector<int>(C, 0));
	int f, c, p, d, np, cicl, ciclM, ncicl;
	char aux;
	for (int i = 0; i < n; i++) {
		cin >> f >> c >> aux >> p;
		np = -1;
		cicl = 0;
		ciclM = 1;
		ncicl = 0;
		f--; c--;
		switch (aux) {
		case 'N': d = 0; break;
		case 'E': d = 1; break;
		case 'S': d = 2; break;
		case 'W': d = 3;
		}
		while (np < p && c < C && f < F && f >= 0 && c >= 0) {
			m[f][c]++;
			f += dirs4[d].first; c += dirs4[d].second;
			cicl++;
			if (cicl == ciclM) {//ha llegado al borde
				ciclM += ncicl; // cada dos veces que llegue al borde se suma uno al numero de pasos del ciclo
				ncicl = (ncicl + 1) % 2;
				cicl = 0;
				d = (d + 1) % 4;
			}
			np++;
		}
	}
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			cout << m[i][j];
			if (j < C - 1) cout << " ";
		}
		cout << "\n";
	}
	cout << "---\n";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}
	return 0;
}

/*void resuelveCaso() {
	int F, C, n;
	cin >> F >> C >> n;
	tM m(F, vector<int>(C, 0));
	tM mC(F, vector<int>(C, -1));
	int f, c, p, d, np, faux, caux;
	char aux;
	for (int i = 0; i < n; i++) {
		cin >> f >> c >> aux >> p;
		np = -1;
		f--; c--;
		switch (aux) {
			case 'N': d = 0;break;
			case 'E': d = 1; break;
			case 'S': d = 2; break;
			case 'W': d = 3;
		}
		while (np < p && c < C && f < F && f >= 0 && c >= 0) {
			m[f][c]++;
			mC[f][c] = i;
			f += dirs4[d].first; c += dirs4[d].second;
			faux = f + dirs4[(d + 1) % 4].first; caux = c + dirs4[(d + 1) % 4].second;
			if (caux < C && faux < F && faux >= 0 && caux >= 0 &&
				mC[faux][caux] < i)
				d = (d + 1) % 4;
			np++;
		}
	}
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			cout << m[i][j];
			if(j < C - 1) cout << " ";
		}
		cout << "\n";
	}
}*/