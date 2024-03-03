#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	std::string s, p;
	
	bool isSucces = false;	

	cin >> s >> p;	

	s = s + s;

	if (s.find(p)!=string::npos){
		isSucces = true;
	}
		
	if (isSucces){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}