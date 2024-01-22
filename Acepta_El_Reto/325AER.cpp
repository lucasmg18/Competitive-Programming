// Lucas Martin Garcia
#include <iostream>
#include <string>
using namespace std;


void comb(int c, int v, string& pal, bool& pr) {
	if (c == 0 && v == 0) {
		if (!pr)cout << " ";
		else pr = false;
		cout << pal;
		return;
	}
	if (c != 0) {
		pal.push_back('C');
		comb(c - 1, v, pal, pr);
		pal.pop_back();
	}

	if (v != 0) {
		pal.push_back('V');
		comb(c, v - 1, pal, pr);
		pal.pop_back();
	}
}


void resuelve() {
	int c, v;
	cin >> c >> v;
	string pal;
	bool pr = true;
	comb(c, v, pal, pr);
	cout << "\n";

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelve();
	}
	return 0;
}