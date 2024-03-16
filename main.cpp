#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cmath>

int main() {
	double a = 0, b = 0, c = 0;
	double radA = 0, radB = 0, radC = 0, degC = 0;
	double S = 0, L = 0, h = 0, s = 0;

	std::cin >> a >> b >> degC;

	radC = degC * M_PI / 180.0;

	c = sqrt(pow(a, 2.0f) + pow(b, 2.0f) - 2.0f * a * b * cos(radC));

	L = a + b + c;

	S = (a * b * std::sin(radC)) / 2.0f;

	s = (a + b + c) / 2.0f;

	h = (sqrt(s * (s - a) * (s - b) * (s - c)) * 2.0f) / a;

	std::cout << std::fixed << S << std::endl;
	std::cout << std::fixed << L << std::endl;
	std::cout << std::fixed << h << std::endl;

	return 0;
}