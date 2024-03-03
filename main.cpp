#include<iostream>
#include<string>

using namespace std;

int main() {
	string s, p;

	string end = "END_OF_TEXT";
	
	size_t count = 0;

	cin >> p;
	while (true){
		getline(cin, s);
		string test;
		for (size_t i = 0; i < s.size(); i++){
			if (s[i] == ' ') {
				if (test == p) {
					count++;
				}
				test.clear();
			}
			else {
				test.push_back(tolower(s[i]));
			}
			if (i == s.size() - 1) {
				if (test == p) {
					count++;
				}
			}
		}

		if (s == end) {
			break;
		}
	}
	
	cout << count << endl;

	return 0;
}