// Lucas Martin Garcia
#include <iostream>
#include <vector>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int sol = 1, max = v[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		if (v[i] > max) {
			sol++;
			max = v[i];
		}
	}
	cout << sol << "\n";
	return true;
}

int main() {
	while (resuelveCaso()) {

	}
	return 0;
}