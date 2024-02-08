//Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool encontrar(string s, int l) {
	for (int i = l - 1; i < s.size(); i++) {
		int x = i - l + 1, y = i;
		while (x < y && s[x] == s[y]) {
			x++; y--;
		}
		if (x >= y)
			return true;
	}
	return false;
}

int busq_bin(string s) {
	int ini = 1, fin = s.size(), m, sol1, sol2;
	while (ini < fin-1) {
		m = (ini + fin) / 2;
		if (m % 2 != 0) {
			m++;
			if (encontrar(s, m)) {
				ini = m;
			}
			else fin = m-1;
		}
		else {
			if (encontrar(s, m)) {
				ini = m;
			}
			else fin = m;
		}
	}
	sol1 = ini;
	ini = 1, fin = s.size();
	while (ini < fin-1) {
		m = (ini + fin) / 2 ;
		if (m % 2 == 0) {
			m++;
			if (encontrar(s, m)) {
				ini = m;
			}
			else fin = m - 1;
		}
		else {
			if (encontrar(s, m)) {
				ini = m;
			}
			else fin = m;
		}
	}
	sol2 = ini;
	return max(sol1, sol2);
}

bool r() {
	string s;
	cin >> s;
	if (!cin) return false;
	cout << busq_bin(s) << endl;
	return true;
}


int main() {
	while (r()){

	}
	return 0;
}