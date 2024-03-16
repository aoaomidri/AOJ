#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>

int main() {
	int count = 0, s = 0;
	double m = 0, a = 0;
	std::vector<int> score;
	std::vector<double> result;
	while (true){
		std::cin >> count;
		if (count == 0)
		break;
		for (int i = 0; i < count; i++){
			std::cin >> s;
			m += s;
			score.push_back(s);

		}
		m /= count;
		for (int i = 0; i < count; i++){
			a += pow((score[i] - m), 2.0f);
		}
		a = std::sqrt(a / count);
		result.push_back(a);

		score.clear();
		m = 0;
		a = 0;
	}
	for (size_t i = 0; i < result.size(); i++){
		std::cout << std::fixed << result[i] << std::endl;
	}
	

	return 0;
}