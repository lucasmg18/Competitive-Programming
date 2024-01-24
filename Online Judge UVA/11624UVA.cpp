//Lucas Martin Garcia
//ACCEPTED

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const pair<int, int> tdirs4[4] = { {0,-1},{0,1},{-1,0},{1,0} };

struct tPos {
	int f, c, inst;
};

bool dentroMatriz(int maxF, int maxC, int f, int c) {
	return f > -1 && c > -1 && f < maxF && c < maxC;
}

int solucion() {
	int R, C, JF, JC;
	cin >> R >> C;
	vector<vector<char>> mapa(R, vector<char>(C));
	vector<vector<int>> mapaFuegos(R, vector<int>(C,-1));
	vector<vector<bool>> mapaVisitados(R, vector<bool>(C, false));
	queue<tPos> colaF, colaJ;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mapa[i][j];
			if (mapa[i][j] == 'F') {
				colaF.push({ i, j, 0 });
			}
			else if (mapa[i][j] == 'J') {
				JF = i;
				JC = j;
				colaJ.push({ i, j, 0 });
			}
		}
	}
	tPos actual;
	pair<int,int> newDir;
	while (!colaF.empty()) {
		actual = colaF.front();
		colaF.pop();
		for (pair<int, int> dir : tdirs4) {
			newDir = { actual.f + dir.first,actual.c + dir.second };
			if (dentroMatriz(R, C, newDir.first, newDir.second) && mapa[newDir.first][newDir.second] != '#'  && mapaFuegos[newDir.first][newDir.second] < 0 ) {
				colaF.push({ newDir.first, newDir.second, actual.inst + 1 });
				mapaFuegos[newDir.first][newDir.second] = actual.inst + 1;
			}
		}
	}

	while (!colaJ.empty()) {
		actual = colaJ.front();
		colaJ.pop();
		for (pair<int, int> dir : tdirs4) {
			newDir = { actual.f + dir.first,actual.c + dir.second };
			if (!dentroMatriz(R, C, newDir.first, newDir.second)) {
				return actual.inst + 1;
			}
			else if (!mapaVisitados[newDir.first][newDir.second] && mapa[newDir.first][newDir.second] == '.' && (mapaFuegos[newDir.first][newDir.second] == -1 || mapaFuegos[newDir.first][newDir.second] > actual.inst + 1) ) {
				colaJ.push({ newDir.first, newDir.second, actual.inst + 1 });
				mapaVisitados[newDir.first][newDir.second] = true;
			}
		}
	}
	return -1;
}


int main() {
	int numcas, sol;
	cin >> numcas;
	for (int i = 0; i < numcas; i++) {
		sol = solucion();
		if (sol == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {

			cout << sol << "\n";
		}
	}
	return 0;
}
