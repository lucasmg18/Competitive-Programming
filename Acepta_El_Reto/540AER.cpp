// Lucas Martin Garcia
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
	int  num, ab, ig, i = 0, cont = 0, pisos, escalones, complet, adicional;
	vector<int> pis, esc, com, ad;
	cin >> num;
	for (short int h = 0; h < num; h++) {
		cin >> pisos >> escalones >> complet >> adicional;
		pis.push_back(pisos);
		esc.push_back(escalones);
		com.push_back(complet);
		ad.push_back(adicional);
	}
	for (short int f = 0; f < num; f++) {
		cout << com[f] * esc[f] + ad[f] << " " << com[f] * esc[f] + ad[f] + pis[f] * esc[f] << endl;
	}
	return 0;
}