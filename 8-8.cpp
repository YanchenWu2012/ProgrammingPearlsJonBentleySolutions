#include <iostream>
#include <vector>
#include <algorithm>

struct SubarrayInfo {
    int maxSum;     // Maximum subarray sum in [l, u]
    int maxPrefix;  // Maximum prefix sum starting at l
    int maxSuffix;  // Maximum suffix sum ending at u
    int totalSum;   // Total sum of elements in [l, u]
};

SubarrayInfo maxSubarrayLinearDC(const std::vector<int>& x, int l, int u) {
    if (l > u) {
        return { 0, 0, 0, 0 };
    }

    if (l == u) {
        int maxVal = std::max(0, x[l]);
        return { maxVal, maxVal, maxVal, x[l] };
    }

    int m = l + (u - l) / 2;

    SubarrayInfo L = maxSubarrayLinearDC(x, l, m);
    SubarrayInfo R = maxSubarrayLinearDC(x, m + 1, u);

    SubarrayInfo res;
    res.totalSum = L.totalSum + R.totalSum;
    res.maxPrefix = std::max(L.maxPrefix, L.totalSum + R.maxPrefix);
    res.maxSuffix = std::max(R.maxSuffix, R.totalSum + L.maxSuffix);
    res.maxSum = std::max({ L.maxSum, R.maxSum, L.maxSuffix + R.maxPrefix });

    return res;
}

int main() {
    std::vector<int> x = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

    SubarrayInfo result = maxSubarrayLinearDC(x, 0, x.size() - 1);
    std::cout << "Maximum subarray sum: " << result.maxSum << '\n';

    return 0;
}
