// Lucas Martin Garcia
#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
using namespace std;

int main() {
	int h, m, s, num, got;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> got;
		s = got % 60;
		got = got / 60;
		m = got % 60;
		got = got / 60;
		h = got;
		cout << setfill('0') << setw(2) << h << ':' << setfill('0') << setw(2) << m << ':' << setfill('0') << setw(2) << s << endl;
	}
	return 0;
}