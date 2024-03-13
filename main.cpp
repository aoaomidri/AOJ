#include<iostream>
#include<string>

using namespace std;

int main() {
	string base, order;
	int count = 0, i = 0;
	int a = 0, b = 0;
	cin >> base;
	cin >> count;
	while (i < count) {
		cin >> order;
		if (order == "replace"){
			string change;
			cin >> a >> b >> change;
			for (int i = a; i <= b; ++i) {
				base[i] = change[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) - a];
			}

		}
		else if (order == "reverse") {
			cin >> a >> b;
			while (a < b) {
				swap(base[a], base[b]);
				++a;
				--b;
			}
			
		}
		else if (order == "print") {
			cin >> a >> b;
			for (int i = a; i <= b; ++i) {
				cout << base[i];
			}
			cout << endl;
		}
		
		i++;
	}
	

	return 0;
}