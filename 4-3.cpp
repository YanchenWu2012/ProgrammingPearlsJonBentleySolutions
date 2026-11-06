#include <iostream>
#include <vector>
#include <string>

int binarysearch(int low, int high, int target, const std::vector<int>& arr) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return binarysearch(mid + 1, high, target, arr);
        }
        else {
            return binarysearch(low, mid - 1, target, arr);
        }
    }
    return -1;
}

void run_test(const std::string& description, const std::vector<int>& arr, int target, int expected) {
    int actual = binarysearch(0, static_cast<int>(arr.size()) - 1, target, arr);

    std::cout << "Test: " << description << "\n";
    std::cout << "  Target:   " << target << "\n";
    std::cout << "  Expected: " << expected << "\n";
    std::cout << "  Actual:   " << actual << "\n";
    std::cout << "  Result:   " << (actual == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    std::vector<int> arr = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };

    run_test("Target in the middle", arr, 23, 5);
    run_test("Target at the start", arr, 2, 0);
    run_test("Target at the end", arr, 91, 9);
    run_test("Target smaller than all elements", arr, 1, -1);
    run_test("Target larger than all elements", arr, 100, -1);
    run_test("Target not found (in range)", arr, 15, -1);

    std::vector<int> single = { 42 };
    run_test("Single element (found)", single, 42, 0);
    run_test("Single element (not found)", single, 10, -1);

    std::vector<int> empty = {};
    run_test("Empty array", empty, 5, -1);

    return 0;
}
