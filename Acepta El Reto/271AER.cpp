// Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool resuelveCaso() {
	int e, n, aux;
	cin >> e >> n;
	if (n == 0 && e == 0)
		return false;
	priority_queue<int> pi;
	priority_queue<int, vector<int>, greater<int>>  pd;
	pd.push(e);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> aux;
			if (aux < pd.top())
				pi.push(aux);
			else pd.push(aux);

			if (pd.size() < pi.size()) {
				pd.push(pi.top());
				pi.pop();
			}
			else if (pd.size() > pi.size() + 1) {
				pi.push(pd.top());
				pd.pop();
			}
		}
		cout << pd.top();
		if (i < n - 1)
			cout << " ";
	}
	cout << "\n";
	return true;
}

int main() {
	while (resuelveCaso()) {

	}
	return 0;
}