// Lucas Martin Garcia
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


bool resuelve() {
	int num, k, aux;
	cin >> num >> k;
	if (num == 0 && k == 0)
		return false;
	//numero y orden
	list<pair<int, int>> sob;
	cin >> aux;
	sob.push_back({ aux, 0 });
	for (int i = 1; i < k; i++) {
		cin >> aux;
		while (!sob.empty() && sob.back().first < aux)
			sob.pop_back();
		sob.push_back({ aux, i });
	}
	cout << sob.front().first;
	for (int i = k; i < num; i++) {
		cin >> aux;
		while (!sob.empty() && sob.back().first < aux)
			sob.pop_back();
		sob.push_back({ aux, i });
		if (sob.front().second == i - k)
			sob.pop_front();
		cout << " " << sob.front().first;
	}
	cout << "\n";
	return true;
}

int main() {
	while (resuelve()) {

	}
	return 0;
}