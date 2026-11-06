#include <iostream>

void set(int& arr, int i, bool val) {
    int temp = 1;
    temp = temp << i;
    if (val) {
        arr = arr | temp;
    }
    else {
        temp = ~temp;
        arr = arr & temp;
    }
}

bool get(int arr, int i) {
    int temp = 1 << i;
    return (arr & temp) != 0;
}

int main() {
    int arr = 0; 

    std::cout << "Testing bit operations:\n";

    std::cout << "Initial state of bit 2: " << get(arr, 2) << "\n";

    set(arr, 2, true);
    std::cout << "Bit 2 after setting to true: " << get(arr, 2) << "\n";

    set(arr, 5, true);
    std::cout << "Bit 5 after setting to true: " << get(arr, 5) << "\n";

    set(arr, 2, false);
    std::cout << "Bit 2 after setting back to false: " << get(arr, 2) << "\n";

    return 0;
}
