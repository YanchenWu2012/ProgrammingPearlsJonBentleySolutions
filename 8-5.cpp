#include <algorithm>
#include <iostream>
#include <vector>

int maxSubarray2b(const std::vector<int>& x) {
    int n = static_cast<int>(x.size());

    std::vector<int> cumarr(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cumarr[i + 1] = cumarr[i] + x[i];
    }

    int maxsofar = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = cumarr[j + 1] - cumarr[i];
            maxsofar = std::max(maxsofar, sum);
        }
    }

    return maxsofar;
}

int main() {
    std::vector<int> x = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

    std::cout << "Maximum subarray sum: " << maxSubarray2b(x) << '\n';
    return 0;
}
