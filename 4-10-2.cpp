#include <iostream>
#include <vector>
#include <string>

int binarySearch(const std::vector<int>& arr, int target, int& iterations) {
    int low = 0;
    int high = arr.size() - 1;
    iterations = 0;

    while (low < high) {
        if (++iterations > 100) return -2;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = { 2,4,6,8,10 };
    int iterations = 0;
    std::string diagnosis = "PASS";

    int result = binarySearch(arr, 7, iterations);
    if (result == -2 || iterations > 100) {
        diagnosis = "Infinite Loop (likely 'low = mid' or 'high = mid').";
    }
    else {
        result = binarySearch(arr, 10, iterations);
        if (result == -1) {
            diagnosis = "Strict Inequality (likely 'while(low < high)' instead of '<=').";
        }
        else {
            result = binarySearch(arr, 99, iterations);
            if (result != -1) {
                diagnosis = "False Positive (Returns an index for a non-existent element).";
            }
        }
    }

    std::cout << "result: " << diagnosis;

    return 0;
}
