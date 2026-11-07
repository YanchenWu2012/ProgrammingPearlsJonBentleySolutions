#include <iostream>
#include <vector>
#include <cassert>

int binary_search(const std::vector<int>& x, int target) {
    int low = 0;
    int high = static_cast<int>(x.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (x[mid] < target) {
            low = mid + 1;
        }
        else if (x[mid] > target) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

void run_scaffolding() {
    for (int n = 0; n <= 50; ++n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = 2 * i;
        }

        for (int i = 0; i < n; ++i) {
            assert(binary_search(arr, 2 * i) == i);
        }

        for (int i = 0; i <= n; ++i) {
            assert(binary_search(arr, 2 * i - 1) == -1);
        }
    }
    std::cout << "All scaffolding tests passed successfully!\n";
}

int main() {
    run_scaffolding();
    return 0;
}
