#include <iostream>

typedef int DataType;

DataType t;

int binarysearch(DataType x[], int n) {
    if (n <= 0) {
        return -1;
    }

    int mid = n / 2;

    if (x[mid] == t) {
        return mid;
    }
    else if (x[mid] > t) {
        return binarysearch(x, mid);
    }
    else {
        int result = binarysearch(x + mid + 1, n - mid - 1);

        if (result == -1) {
            return -1;
        }

        return mid + 1 + result;
    }
}

int main() {
    DataType arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test Case 1: Target exists in the array
    t = 14;
    std::cout << "Searching for " << t << "... Found at index: "
        << binarysearch(arr, n) << std::endl;

    // Test Case 2: Target does not exist in the array
    t = 7;
    std::cout << "Searching for " << t << "... Found at index: "
        << binarysearch(arr, n) << std::endl;

    return 0;
}
