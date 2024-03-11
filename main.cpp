#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string s;
	int count = 0;
	int loop = 0;

	vector<string> stringBox;

	string end = "-";	

	while (true){
		int i = 0;
		cin >> s;
		if (s == end) {
			break;
		}
		cin >> loop;
		while (i < loop) {
			cin >> count;
			for (int j = 0; j < count; j++){
				char c = s[0];
				s.push_back(c);
				s.erase(0, 1);
			}
			i++;
		}

		stringBox.push_back(s);
	}
	
	for (size_t i = 0; i < stringBox.size(); i++){
		cout << stringBox[i] << endl;
	}

	return 0;
}