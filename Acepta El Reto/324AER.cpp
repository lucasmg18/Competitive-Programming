// Lucas Martin Garcia
using namespace std;
#include <iostream>
#include <vector>
#include <list>


int mcd(int a, int b) {
	if (b == 0) return a;
	else return mcd(b, a % b);
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int> v(n);
	vector<bool> m(n, false);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
	}
	long long int mc = 1;
	for (int i = 0; i < n; i++) {
		if (!m[i]) {
			m[i] = true;
			int e = v[i], cont = 1;
			while (e != i) {
				m[e] = true;
				cont++;
				e = v[e];
			}
			mc = mc * cont / mcd(mc, cont);
		}
	}
	cout << mc << "\n";
	return true;
}
int main() {
	while (resuelveCaso()) {
	}

	return 0;
}