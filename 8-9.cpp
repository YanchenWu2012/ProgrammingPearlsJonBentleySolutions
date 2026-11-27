#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

int maxSubvectorNonEmpty(const std::vector<int>& x) {
    if (x.empty()) {
        throw std::invalid_argument("Input vector cannot be empty");
    }

    int premax = std::numeric_limits<int>::min();
    for (int i : x) {
        premax = std::max(premax, i);
    }
    if (premax < 0) {
        return premax;
    }

    int maxsofar = x[0];
    int maxendinghere = x[0];

    for (size_t i = 1; i < x.size(); ++i) {
        maxendinghere = std::max(maxendinghere + x[i], x[i]);
        maxsofar = std::max(maxsofar, maxendinghere);
    }

    return maxsofar;
}

int main() {
    std::vector<int> allNegative = { -8, -3, -10, -2, -5 };
    std::vector<int> mixed = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

    std::cout << "All negative result: " << maxSubvectorNonEmpty(allNegative) << '\n';
    std::cout << "Mixed result: " << maxSubvectorNonEmpty(mixed) << '\n';

    return 0;
}
