#include <iostream>
#include <vector>
#include <cmath>

static double minkowskiDistance(const std::vector<int>& x, const std::vector<int>& y, int p) {
    double sum = 0.0;
    if (p == 1) {
        for (size_t i = 0; i < x.size(); ++i) {
            sum += std::abs(x[i] - y[i]);
        }
    }
    else if (p == 2) {
        for (size_t i = 0; i < x.size(); ++i) {
            sum += std::pow(std::abs(x[i] - y[i]), 2);
        }
        sum = std::sqrt(sum);
    }
    else if (p == 3) {
        for (size_t i = 0; i < x.size(); ++i) {
            sum += std::pow(std::abs(x[i] - y[i]), 3);
        }
        sum = std::pow(sum, 1.0 / 3.0);
    }
    else if (p == std::numeric_limits<int>::max()) {
        for (size_t i = 0; i < x.size(); ++i) {
            sum = std::max(sum, static_cast<double>(std::abs(x[i] - y[i])));
        }
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> y[i];
    }

    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << minkowskiDistance(x, y, 1) << std::endl;
    std::cout << minkowskiDistance(x, y, 2) << std::endl;
    std::cout << minkowskiDistance(x, y, 3) << std::endl;
    std::cout << minkowskiDistance(x, y, std::numeric_limits<int>::max()) << std::endl;

    return 0;
}