// Lucas Martin Garcia
#include <iostream>
#include <string>
using namespace std;

bool resuelve() {
	int s1, s2, s3, r1, r2, r3;
	cin >> s1 >> s2 >> s3;
	if (!cin)
		return false;
	int i = 0, sol = 0, pot = 1;
	bool RC = false;
	while ((s1 + s2 + s3 != 0) && !RC) {
		r1 = s1 % 10; r2 = s2 % 10; r3 = s3 % 10;
		s1 = s1 / 10; s2 = s2 / 10; s3 = s3 / 10;
		if (r1 == r2)
			sol += r1 * pot;
		else if (r2 == r3)
			sol += r2 * pot;
		else {
			if (r3 == r1) {
				sol += r1 * pot;
			}
			else RC = true;
		}
		pot = pot * 10;
	}
	if (!RC)
		cout << sol << "\n";
	else cout << "RUIDO COSMICO\n";
	return true;
}

int main() {
	while (resuelve()) {

	}
	return 0;
}