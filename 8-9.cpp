#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

int closestToZeroSubarray(const std::vector<int>& x) {
    int n = static_cast<int>(x.size());
    if (n == 0) return 0;

    std::vector<int> cumarr(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cumarr[i + 1] = cumarr[i] + x[i];
    }

    std::sort(cumarr.begin(), cumarr.end());

    int bestSum = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        int diff = cumarr[i + 1] - cumarr[i];
        if (diff < bestSum) {
            bestSum = diff;
        }
    }

    return bestSum;
}

int main() {
    std::vector<int> x = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

    std::cout << "Closest to zero non-empty subarray sum (abs): "
        << closestToZeroSubarray(x) << '\n';
    return 0;
}
