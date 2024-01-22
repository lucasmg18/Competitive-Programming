// Lucas Martin Garcia
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


long long int cubi(long long int num, const vector<int>& exp) {
	long long int sol = 0;
	while (num != 0) {
		sol += exp[num % 10];
		num = num / 10;
	}
	return sol;
}

void resuelve() {
	long long int num;
	cin >> num;
	vector<int> exp(10);
	bool fin, escub;
	long long int sol;
	if (num != 0) {
		for (int i = 0; i < 10; i++)
			exp[i] = i * i * i;
	}
	while (num != 0) {
		unordered_set<long long int> c;
		fin = false;
		escub = false;
		if (num == 1)
			cout << "1 -> cubifinito.\n";
		else {
			c.insert(num);
			cout << num;
			while (!fin) {
				sol = 0;
				while (num != 0) {
					sol += exp[num % 10];
					num = num / 10;
				}
				num = sol;
				auto aux = c.insert(num);
				if (!aux.second)
					fin = true;
				if (num == 1) {
					escub = true;
					fin = true;
				}
				cout << " - " << num;
			}

			if (escub)
				cout << " -> cubifinito.\n";
			else cout << " -> no cubifinito.\n";
		}

		cin >> num;
	}
}

int main() {
	resuelve();
	return 0;
}