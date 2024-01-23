// Lucas Martin Garcia
#include<iostream>
using namespace std;
void resuelveCaso() {
	int casos, num;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		cin >> num;
		cout << num / 100 << '\n';
	}
}

int main() {
	resuelveCaso();
}