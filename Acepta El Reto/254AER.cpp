// Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelve() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<int> esqui(n), part(n);

	for (int i = 0; i < n; i++) {
		cin >> part[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> esqui[i];
	}
	sort(part.begin(), part.end());
	sort(esqui.begin(), esqui.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(part[i] - esqui[i]);
	}
	cout << sum << "\n";
	return true;
}

int main() {
	while (resuelve()) {

	}
	return 0;
}