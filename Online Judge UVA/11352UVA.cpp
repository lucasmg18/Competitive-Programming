//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const double EPS = 1e-9;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
int INF = 1000000000;

const pair<int, int> tdirs8[8] = { { 0, -1 }, {0, 1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
const pair <int, int > dirs4[4] = { { -1 ,0} ,{1 ,0} ,{0 ,1} ,{0 , -1} };


bool dentro(int M, int N, int i, int j) {
	return i >= 0 && j >= 0 && i < M&& j < N;
}

void saltos(vvi& mat, int M, int N, int f, int c) {
	int fn = f, cn = c, cas = -1;

	fn += 2; cn += 1; //avajo der
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;
	fn = f; cn = c;
	fn += 2; cn -= 1; //avajo izq
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;

	fn -= 2; cn += 1; //arriba der
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;
	fn -= 2; cn -= 1; //arriba izq
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;
	cn += 2; fn += 1; //avajo der
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;
	cn += 2; fn -= 1; //avajo izq
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;
	cn -= 2; fn += 1; //arriba der
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;

	fn = f; cn = c;
	cn -= 2; fn -= 1; //arriba izq
	if (dentro(M, N, fn, cn) && mat[fn][cn] == 0)
		mat[fn][cn] = cas;
}


void crearGrafo(const vvi& mat, vvi& adj) {
	int M = mat.size();
	int N = mat[0].size();
	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			if(mat[i][k] != -1)
				for (auto a : tdirs8) {
					int in = i + a.first, kn = k + a.second;
					if (dentro(M, N, in, kn)&& mat[in][kn] != -1) {
						adj[i * N + k].push_back(in * N + kn);
						//adj[in * N + kn].push_back(i * N + k);
					}
				}
		}
	}
}

int dijkstra( vvi& adj, int ini, int fin) {
	int s = ini;
	int K = adj.size();
	vi dist(K, INF); dist[s] = 0; // INF = 1B to avoid overflow
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
	while (!pq.empty()) { // main loop
		ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
		int d = front.first, u = front.second;
		if (d > dist[u]) continue; // this is a very important check
		for (int j = 0; j < (int)adj[u].size(); j++) {
			int v = adj[u][j]; // all outgoing edges from u
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1; // relax operation
				pq.push(ii(dist[v], v));
			}
		}
	}
	return dist[fin];
}


void resuelveCaso() {
	int N,M, act, cont = 0;
	cin >> M>> N;
	vector<int> lista(N), lista2(N);
	vvi mat(M, vi(N,0)), adj(M*N);
	char aux;
	int ini, fin;
	//vector<bool> visit(N+1, false);
	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			cin >> aux;
			if (aux == 'Z') {
				mat[i][k] = -1;
				saltos(mat, M, N, i, k);
			}
			if (aux == 'A') {
				mat[i][k] = 1;
				ini = i * N + k;
				//cout << "ini" << ini;
			} 
			if (aux == 'B') {
				mat[i][k] = 2;
				fin = i * N + k;
			}
		}
	}
	/*for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			cout << mat[i][k] << " ";
		}
		cout << '\n';
	}*/
	crearGrafo(mat, adj);
	int d = dijkstra(adj, ini, fin);
	if (d != INF) {
		cout << "Minimal possible length of a trip is " << d << '\n';
	}
	else	cout << "King Peter, you can't go now!\n";

	//for (int i = 0; i < N; i++) {
	//	cin >> lista2[i];
	//}
	//int i1 = N - 1, i2 = N - 1;
	//while (i1 >= 0) {

	//	if (lista[i1] == lista2[i2]) {
	//		int a = lista[i1], b = lista2[i2];
	//		i1--;
	//		cont++;
	//		i2--;
	//	}
	//	else {
	//		i1--;
	//	}
	//}

	////int index = 0;
	////for (int i = 0; i < N; i++) {
	////	cin >> act;
	////	while (index < N && visit[lista[index]])
	////		index++;

	////	if (lista[index] == act) {
	////		index++;
	////	}
	////	else {
	////		cont++;
	////		visit[act] = true;
	////	}
	////}
	//cout << N - cont << "\n";
}

int main() {
	int numc;
	cin >> numc;
	for (int i = 0; i < numc; i++) {
		resuelveCaso();
	}
	return 0;
}