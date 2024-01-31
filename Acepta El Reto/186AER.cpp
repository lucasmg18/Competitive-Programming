//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N, G, aux, max, posMax;
	string desc;
	bool empate;
	cin >> N >> G;
	while (N != 0 || G != 0) {
		vector<int> eq(N,0);
		for (int i = 0; i < G; i++){
			cin >> aux >> desc;
			eq[aux - 1]++;
		}
		posMax = 0;
		max = eq[posMax];
		empate = false;
		for (int i = 1; i < N; i++) {
			if (max < eq[i]) {
				max = eq[i];
				empate = false;
				posMax = i;
			}
			else if (max == eq[i])
				empate = true;
		}
		if (empate)
			cout << "EMPATE\n";
		else cout << posMax+1 << endl;
		cin >> N >> G;
	}
}