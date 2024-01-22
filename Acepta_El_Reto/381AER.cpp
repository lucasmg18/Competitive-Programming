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
	int n, d;
	cin >> n;
	if (n == 0)
		return false;
	long long int mcm = 1;
	vector<int> marc(70, false);
	for (int i = 0; i < n; i++) {
		cin >> d;
		if (!marc[d - 1]) {
			marc[d - 1] = true;
			mcm = mcm * d / mcd(d, mcm);
		}
	}
	cout << mcm << "\n";
	return true;
}
int main() {
	while (resuelveCaso()) {
	}

	return 0;
}