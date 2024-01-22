// Lucas Martin Garcia
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;


void resuelve() {
	int pm, n, aux;
	cin >> pm >> n;
	deque<int> dq;
	dq.push_back(0);
	int sm = 0, s = 0;
	for (int cont = 0; cont < n; cont++) {
		cin >> aux;
		if (aux >= pm) {
			if (dq.size() == 6) {
				dq.pop_front();
				s = cont - dq.front() + 1;
				dq.push_back(cont + 1);
			}
			else {
				s++;
				dq.push_back(cont + 1);
			}
		}
		else {
			s++;
		}
		if (sm < s)
			sm = s;
	}
	cout << sm << "\n";

	/*int pesoNieve, numPalmeras;   // otra forma de hacerlo
	int palmeras[100000];

	cin >> pesoNieve >> numPalmeras;

	int i = 0, j = 0, longitud = 0, contadorPalmeras = 0;
	while (numPalmeras--)
	{
		cin >> palmeras[j];
		if (palmeras[j] >= pesoNieve)
		{
			contadorPalmeras++;
			while (contadorPalmeras > 5)
			{
				if (palmeras[i] >= pesoNieve) contadorPalmeras--;
				i++;
			}
		}
		if (longitud < (j - i + 1))
			longitud = j - i + 1;
		j++;
	}
	cout << longitud << "\n";*/

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelve();
	}
	return 0;
}