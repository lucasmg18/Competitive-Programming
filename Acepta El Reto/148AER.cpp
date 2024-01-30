#include <iostream>
#include <string>
using namespace std;

int main() {
	string p;
	cin >> p;
	int min;
	while (p != "00:00") {
		min = 0;
		min += ((p[0] - '0') * 10 + p[1] - '0') * 60 + ((p[3] - '0') * 10 + p[4] - '0');
		cout << 1440- min << endl;
		cin >> p;
	}
	return 0;
}