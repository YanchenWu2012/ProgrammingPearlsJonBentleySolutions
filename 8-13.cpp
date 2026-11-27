#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 3;
    vector<vector<double>> matrix = {
        { 1, -2, -1 },
        { -3, 4,  2 },
        { 2,  1, -3 }
    };

    double maxSum = -1e18;

    for (int left = 0; left < n; ++left) {
        vector<double> temp(n, 0.0);
        for (int right = left; right < n; ++right) {
            for (int row = 0; row < n; ++row) {
                temp[row] += matrix[row][right];
            }

            double currentSum = temp[0];
            double maxSoFar = temp[0];

            for (int i = 1; i < n; ++i) {
                currentSum = max(temp[i], currentSum + temp[i]);
                maxSoFar = max(maxSoFar, currentSum);
            }

            maxSum = max(maxSum, maxSoFar);
        }
    }

    cout << "Result" << endl;
    cout << "Maximum rectangular subarray sum: " << maxSum << endl;

    return 0;
}
