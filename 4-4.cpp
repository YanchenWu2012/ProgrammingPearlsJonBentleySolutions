#include <iostream>
#include <vector>
#include <chrono>

struct SearchResult {
    int index;
    int comparisons;
    double duration_nanoseconds;
};

SearchResult binarySearchInstrumented(const std::vector<int>& arr, int target) {
    auto start_time = std::chrono::high_resolution_clock::now();

    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    int comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if (arr[mid] == target) {
            auto end_time = std::chrono::high_resolution_clock::now();
            double elapsed = std::chrono::duration<double, std::nano>(end_time - start_time).count();
            return { mid, comparisons, elapsed };
        }

        comparisons++;
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double, std::nano>(end_time - start_time).count();
    return { -1, comparisons, elapsed };
}

int main() {
    std::vector<int> data = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int target = 23;

    SearchResult res = binarySearchInstrumented(data, target);

    std::cout << "Target index: " << res.index << "\n";
    std::cout << "Comparisons: " << res.comparisons << "\n";
    std::cout << "Elapsed time: " << res.duration_nanoseconds << " ns\n";

    return 0;
}
