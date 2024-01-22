// Lucas Martin Garcia
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using tMatriz = vector<vector<char>>;
const pair<int, int> d[4] = { {1, 0}, { 0, 1 }, {-1, 0}, {0, -1} };

void vueltAtras(tMatriz& mapa, int& min, int actual, int x, int y, bool& enc, pair<int, int>const& trofeo) {
	for (int i = 0; i < 4; ++i) {
		if (mapa[x + d[i].first][y + d[i].second] == 'T') {
			if (actual < min)
				min = actual;
			enc = true;
		}
		else if (mapa[x + d[i].first][y + d[i].second] != '#' && actual + abs(trofeo.first - x) + abs(trofeo.second - y) < min) {

			mapa[x + d[i].first][y + d[i].second] = '#';
			vueltAtras(mapa, min, actual + 1, x + d[i].first, y + d[i].second, enc, trofeo);
			mapa[x + d[i].first][y + d[i].second] = '.';
		}
	}
}

bool resuelveCaso() {
	int x, y, min = INT_MAX, numCas = 0, entrada, casX, casY, dir = 0;
	pair<int, int> trofeo;
	char aux;
	bool enc = false;
	cin >> x >> y;
	if (!cin)
		return false;
	tMatriz mapa(x, vector<char>(y));
	for (int j = 0; j < y; ++j)
		for (int i = 0; i < x; ++i) {
			cin >> mapa[i][j];
			if (mapa[i][j] == 'T') {
				trofeo.first = i;
				trofeo.second = j;
			}
		}

	for (int i = 1; i < x - 1; ++i)
		if (mapa[i][y - 1] != '#') {
			if (mapa[i][y - 1] == 'T') {
				cout << "IGUAL\n";
				return true;
			}
			if (mapa[i][y - 2] == 'T') {
				cout << "IGUAL\n";
				return true;
			}
			if (mapa[i][y - 2] == '#') {
				cout << "IMPOSIBLE\n";
				return true;
			}
			entrada = i;
		}
	mapa[entrada][y - 1] = '#';
	vueltAtras(mapa, min, 1, entrada, y - 2, enc, trofeo);
	mapa[entrada][y - 1] = '.';
	if (!enc) cout << "IMPOSIBLE\n";
	else {
		casX = entrada; casY = y - 2;
		enc = false;
		while (casY != y - 1 && !enc) {
			if (mapa[casX + d[dir].first][casY + d[dir].second] == '.') {
				numCas++;
				casX += d[dir].first;
				casY += d[dir].second;
				dir = (dir + 1) % 4;
			}
			else if (mapa[casX + d[dir].first][casY + d[dir].second] == 'T') {
				enc = true;
				numCas++;
			}
			else {
				while (mapa[casX + d[dir].first][casY + d[dir].second] == '#') {
					dir = (dir + 3) % 4;
				}
			}
		}
		if (enc) {
			if (numCas - min == 0)
				cout << "IGUAL\n";
			else cout << numCas - min << '\n';
		}
		else cout << "INF\n";
	}

	return true;
}

int main() {
	while (resuelveCaso()) {

	}
}