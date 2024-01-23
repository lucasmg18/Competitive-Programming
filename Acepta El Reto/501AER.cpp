// Lucas Martin Garcia
#include <iostream>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;

bool resuelve() {
	int td, ta, dd, da, no, mina, mind, aux;
	cin >> td >> ta >> dd >> da >> no;
	if (!cin) return false;
	for (int i = 0; i < no; i++) {
		vector <int> va, vd;
		mina = min(ta, da);
		mind = min(td, dd);
		for (int j = 0; j < mind; j++) {
			cin >> aux;
			vd.push_back(aux);
		}
		for (int j = 0; j < mina; j++) {
			cin >> aux;
			va.push_back(aux);
		}
		sort(vd.begin(), vd.end(), greater<int>());
		sort(va.begin(), va.end(), greater<int>());
		for (int k = 0; k < min(mina, mind); k++) {
			if (vd[k] < va[k]) td--;
			else ta--;
		}
	}
	cout << td << " " << ta << endl;
	return true;
}

int main() {
	while (resuelve());

	return 0;
}