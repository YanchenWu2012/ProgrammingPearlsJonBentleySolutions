#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int findSubarrayNearestZero(const std::vector<double>& x, int m) {
    int n = x.size();

    if (m < 0 || n <= m) {
        return -1;
    }

    double current_sum = 0.0;
    for (int k = 0; k <= m; ++k) {
        current_sum += x[k];
    }

    int best_i = 0;
    double min_abs_sum = std::abs(current_sum);

    for (int i = 1; i < n - m; ++i) {
        current_sum = current_sum - x[i - 1] + x[i + m];
        double abs_sum = std::abs(current_sum);

        if (abs_sum < min_abs_sum) {
            min_abs_sum = abs_sum;
            best_i = i;
        }
    }

    return best_i;
}

int main() {
    std::vector<double> x = { 3.5, -2.0, -1.2, 4.0, -3.9, 1.0 };
    int m = 2;

    int best_index = findSubarrayNearestZero(x, m);

    if (best_index != -1) {
        std::cout << "Best starting index i: " << best_index << "\n";

        double sum = 0.0;
        std::cout << "Subarray elements: ";
        for (int k = best_index; k <= best_index + m; ++k) {
            std::cout << x[k] << " ";
            sum += x[k];
        }
        std::cout << "\nSum nearest to zero: " << sum << "\n";
    }
    else {
        std::cout << "Invalid values for n and m.\n";
    }

    return 0;
}
