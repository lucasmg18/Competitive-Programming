// Lucas Martin Garcia
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int  ab, ig, i = 0;
	vector<int> abu, igl;
	cin >> ab >> ig;
	abu.push_back(ab);
	igl.push_back(ig);
	while (abu[i] > 0 || igl[i] > 0) {
		i++;
		cin >> ab >> ig;
		abu.push_back(ab);
		igl.push_back(ig);
	}
	for (short int F = 0; F < i; F++) {
		if (abu[F] >= igl[F]) cout << "CUERDO" << endl;
		else cout << "SENIL" << endl;
	}
	return 0;
}