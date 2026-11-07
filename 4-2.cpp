#include <iostream>
#include <vector>

using namespace std;

int binarySearchFirst(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int firstOccurrence = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            high = mid - 1;       
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return firstOccurrence;
}

int main() {
    vector<int> numbers = { 2, 4, 6, 10, 10, 10, 14, 16 };
    int target = 10;

    int result = binarySearchFirst(numbers, target);

    if (result != -1) {
        cout << "First occurrence of element found at index: " << result << endl;
    }
    else {
        cout << "Element not found." << endl;
    }

    return 0;
}
