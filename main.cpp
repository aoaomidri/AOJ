#include<iostream>
#include<string>

using namespace std;

int main() {
	string s, p;
	int hanakoP = 0, taroP = 0;
	int count = 0, i = 0;
	cin >> count;
	while (i < count) {
		cin >> s >> p;
		if (s > p) {
			taroP += 3;
		}
		else if (s < p) {
			hanakoP += 3;
		}
		else if (s == p) {
			taroP++;
			hanakoP++;
		}

		i++;
	}
	cout << taroP << ' ' << hanakoP << endl;

	return 0;
}