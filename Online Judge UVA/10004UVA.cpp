//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int v, vector<int>& vis, const vector <vector<int>>& grafo) {
	bool posible = true;
	for (int i = 0; i < grafo[v].size() && posible; i++) {
		int w = grafo[v][i];
		if (!vis[w]){
			if (vis[v] == 1)
				vis[w] = 2;
			else vis[w] = 1;
			posible = dfs(w, vis, grafo);
		}
		else if(vis[w] == vis[v])posible = false;
	}
	return posible;
}

bool resuelve() {
	vector <vector<int>> grafo;
	vector <int> vis;
	int v, e;
	bool posible = true;
	cin >> v >> e;
	if (!cin) return false;
	grafo.assign(v, {});
	int a, b;
	while (e--) {
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	vis.assign(v, 0);
	vis[0] = 1; 
	if (dfs(0, vis, grafo)) cout << "BICOLORABLE.\n";
	else	cout << "NOT BICOLORABLE.\n";
	return true;
}

int main() {
	while(resuelve());
	return 0;
}