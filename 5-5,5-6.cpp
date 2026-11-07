#include <iostream>
#include <vector>
#include <cassert>

int checked_binary_search(const std::vector<int>& x, int target) {
    int n = static_cast<int>(x.size());
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        assert(x[low] <= x[mid] && x[mid] <= x[high]);
        if (mid > 0) assert(x[mid - 1] <= x[mid]);
        if (mid + 1 < n) assert(x[mid] <= x[mid + 1]);

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

void visual_binary_search(const std::vector<int>& x, int target) {
    int low = 0, high = static_cast<int>(x.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        for (int i = 0; i < static_cast<int>(x.size()); ++i) {
            if (i == mid) std::cout << "[" << x[i] << "] ";
            else if (i >= low && i <= high) std::cout << x[i] << " ";
            else std::cout << ". ";
        }
        std::cout << "\n";

        if (x[mid] < target) low = mid + 1;
        else if (x[mid] > target) high = mid - 1;
        else return;
    }
}

void test_checked_binary_search() {
    // 1. Empty array
    std::vector<int> empty;
    assert(checked_binary_search(empty, 5) == -1);

    // 2. Single element
    std::vector<int> single = { 10 };
    assert(checked_binary_search(single, 10) == 0);
    assert(checked_binary_search(single, 5) == -1);

    // 3. Multiple elements, even length
    std::vector<int> even = { 2, 4, 6, 8 };
    assert(checked_binary_search(even, 2) == 0);
    assert(checked_binary_search(even, 8) == 3);
    assert(checked_binary_search(even, 6) == 2);
    assert(checked_binary_search(even, 5) == -1);
    assert(checked_binary_search(even, 0) == -1);
    assert(checked_binary_search(even, 10) == -1);

    // 4. Multiple elements, odd length
    std::vector<int> odd = { 1, 3, 5, 7, 9 };
    assert(checked_binary_search(odd, 5) == 2);
    assert(checked_binary_search(odd, 1) == 0);
    assert(checked_binary_search(odd, 9) == 4);
    assert(checked_binary_search(odd, 4) == -1);

    // 5. Duplicates
    std::vector<int> dups = { 1, 2, 2, 2, 3 };
    int dup_idx = checked_binary_search(dups, 2);
    assert(dup_idx >= 1 && dup_idx <= 3);
}

void test_visual_binary_search() {
    std::vector<int> arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    std::cout << "--- Visual Test 1: Target 70 (Present) ---\n";
    visual_binary_search(arr, 70);

    std::cout << "\n--- Visual Test 2: Target 25 (Missing) ---\n";
    visual_binary_search(arr, 25);

    std::cout << "\n--- Visual Test 3: Target 95 (Out of Bounds) ---\n";
    visual_binary_search(arr, 95);
}

int main() {
    test_checked_binary_search();
    std::cout << "checked_binary_search: All assertions passed.\n\n";

    test_visual_binary_search();

    return 0;
}
