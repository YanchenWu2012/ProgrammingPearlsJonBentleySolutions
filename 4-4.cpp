
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int comparisons = 0;

    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return comparisons;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return comparisons;
}

int main() {
    std::vector<int> sizes = { 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384 };
    std::vector<int> comparisons_made;

    for (int n : sizes) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        int comps = binarySearch(arr, -1);
        comparisons_made.push_back(comps);
    }

    std::cout << "a = [";
    for (size_t i = 0; i < sizes.size(); ++i) {
        std::cout << sizes[i] << (i < sizes.size() - 1 ? ", " : "");
    }
    std::cout << "]\n";

    std::cout << "b = [";
    for (size_t i = 0; i < comparisons_made.size(); ++i) {
        std::cout << comparisons_made[i] << (i < comparisons_made.size() - 1 ? ", " : "");
    }
    std::cout << "]\n";

    return 0;
}
