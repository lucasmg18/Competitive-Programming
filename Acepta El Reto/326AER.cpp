//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cmath>
using namespace std;

vector <int> parent;
bool comprobarDentroArb(const pair<int, int>& puesto, const pair<int, int>& nuevo, int K) {
	int a = abs(puesto.first - nuevo.first), b = abs(puesto.second - nuevo.second);
	return a * a + b * b <= K * K;
}

int uFind(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = uFind(parent[x]);
}
void uMerge(int a, int b) { //b se una al arbol de a
	int pa = uFind(a), pb = uFind(b);
	if (pa != pb) 
		parent[pb] = pa;
}


bool resuelveCaso() {
	int F, C, K, n, x, y;
	if (scanf("%d %d %d %d", &F, &C, &K, &n) != 4) return false; 
	stack<pair<int, int>> arboles;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		arboles.push({ x,y });
	}
	int men = -1;
	vector<vector<int>> mapa(F+1, vector<int>(C+1, -1));
	mapa[0][0] = 0; mapa[F][C] = 1;
	parent = vector<int>(n+2);
	parent[0] = 0;
	parent[1] = 1;
	pair<int, int> act, sol = { -1,-1 }, posAct;
	bool final = false;
	int idAct = 2;
	while (!final && !arboles.empty()) {
		act = arboles.top();
		arboles.pop();
		int  idPunt;
		int ant = -1;
		bool enc = false, enc0 = false, enc1 = false;
		for (int i = -K ; i <= K && !final; ++i) {
			for (int j = -K; j <= K && !final; ++j) {
				posAct = { act.first + i, act.second + j };
				if (posAct.first >= 0 && posAct.second >= 0 && posAct.first <= F && posAct.second <= C &&
					mapa[posAct.first][posAct.second] > -1 && comprobarDentroArb(posAct, act, K)) {
					idPunt = uFind(mapa[posAct.first][posAct.second]);
					if (idPunt == 0) enc0 = true;
					else if (idPunt == 1) enc1 = true;
					if (ant > -1) {
						if (enc0 && enc1) {
							final = true;
							sol = act;
						}
						else {
							if (idPunt == 0 || idPunt == 1) {
								uMerge(idPunt, ant);
								mapa[act.first][act.second] = idPunt;
								ant = idPunt;
							}
							else {
								uMerge(ant, idPunt);
								mapa[act.first][act.second] = ant;
							}
						}
					}
					else {
						int pAux = uFind(idPunt);
						mapa[act.first][act.second] = pAux;
						ant = pAux;
					}
					enc = true;
				}
			}
		}
		if (!enc) {
			parent[idAct] = idAct;
			mapa[act.first][act.second] = idAct;
			idAct++;
		}
	}
	if (final) {
		printf("%d %d\n", sol.first, sol.second);
	}
	else {
		printf("NUNCA SE PUDO\n");
	}
	return true;
}


int main() {
	while (resuelveCaso()) {

	}
	return 0;
}
