#include<iostream>
#include<math.h>

using namespace std;

int main() {
	double x1 = 0, y1 = 0;
	double x2 = 0, y2 = 0;

	double result = 0.0f;

	cin >> x1 >> y1 >> x2 >> y2;

	result = static_cast<double>(sqrt((pow((x2 - x1), 2.0f) + pow((y2 - y1), 2.0f))));

	cout << std::fixed << result << endl;
	return 0;
}