#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string maxS;
	int maxI = -1;
	unordered_map<string,int> map;
	for(int i = 0; i < n; i++){
		string aux;
		cin >> aux;
		if(map.count(aux)){
			++map[aux];
		}
		else map[aux] = 1;
		if(map[aux] > maxI){
			maxI = map[aux];
			maxS = aux;
		}
	}
	if(maxI <= n - maxI)
		cout << "NONE\n";
	else cout << maxS << endl;
	return 0;
}