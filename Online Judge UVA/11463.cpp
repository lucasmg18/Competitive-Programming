#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000000

vector <int> bfs(int v, const vector <vector<int>>& grafo) {
	vector<int> dist(grafo.size(), INF);
	queue<int> q;
	dist[v] = 0;
	q.push(v);
	while (!q.empty()) {
		int w = q.front(); q.pop();
		for(int x: grafo[w])
			if (dist[x] == INF) {
				dist[x] = dist[w] + 1;
				q.push(x);
			}
	}
	return dist;
}

void resuelve(int caso) {
	vector <vector<int>> grafo;
	vector <bool> vis;
	int v, e;
	cin >> v >> e;
	grafo.assign(v, {});
	int a, b;
	while (e--) {
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	int o, d;
	cin >> o >> d;

	auto ida = bfs(o, grafo);
	auto vuelta = bfs(d, grafo);
	int mayor = 0;
	for (int i = 0; i < v; i++) {
		mayor = max(mayor, ida[i] + vuelta[i]);
	}
	cout << "Case " << caso << ": " << mayor << '\n' ;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelve(i +1);
	return 0;
}