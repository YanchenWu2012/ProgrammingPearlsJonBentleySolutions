#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

const uint32_t TOTAL_NUMBERS = 4000000000;
const uint32_t MISSING_NUMBER = 123456789; // number we skip 
const string FILENAME = "numbers.bin";
const size_t BUFFER_SIZE = 250000;

void generateFile() {
    cout << "Generating 4 billion integers (skipping " << MISSING_NUMBER << ")...\n";
    cout << "creating file\n";

    ofstream outfile(FILENAME, ios::binary);
    if (!outfile) {
        cerr << "Error opening file for writing!\n";
        exit(1);
    }

    vector<uint32_t> buffer;
    buffer.reserve(BUFFER_SIZE);

    for (uint32_t i = 0; i <= TOTAL_NUMBERS; ++i) {
        if (i == MISSING_NUMBER) {
            continue;
        }

        buffer.push_back(i);

        if (buffer.size() == BUFFER_SIZE) {
            outfile.write(reinterpret_cast<const char*>(buffer.data()), buffer.size() * sizeof(uint32_t));
            buffer.clear();
        }
    }

    if (!buffer.empty()) {
        outfile.write(reinterpret_cast<const char*>(buffer.data()), buffer.size() * sizeof(uint32_t));
    }

    outfile.close();
    cout << "Generation complete.\n\n";
}

uint32_t findMissingNumber() {
    cout << "Starting binary search on the file...\n";

    ifstream infile(FILENAME, ios::binary);
    if (!infile) {
        cerr << "Error opening file for reading!\n";
        exit(1);
    }

    vector<uint32_t> buffer(BUFFER_SIZE);

    uint32_t low = 0;
    uint32_t high = TOTAL_NUMBERS;
    uint32_t missing_number = 0;

    int pass = 1;

    while (low <= high) {
        if (low == high) {
            missing_number = low;
            break;
        }

        uint32_t mid = low + (high - low) / 2;
        uint32_t left_count = 0;

        infile.clear();
        infile.seekg(0, ios::beg);

        cout << "Pass " << pass++ << " | Searching range: [" << low << ", " << high << "] | Mid: " << mid << "\n";

        while (infile.read(reinterpret_cast<char*>(buffer.data()), BUFFER_SIZE * sizeof(uint32_t))) {
            size_t elements_read = infile.gcount() / sizeof(uint32_t);
            for (size_t i = 0; i < elements_read; ++i) {
                if (buffer[i] >= low && buffer[i] <= mid) {
                    left_count++;
                }
            }
        }

        if (infile.gcount() > 0) {
            size_t elements_read = infile.gcount() / sizeof(uint32_t);
            for (size_t i = 0; i < elements_read; ++i) {
                if (buffer[i] >= low && buffer[i] <= mid) {
                    left_count++;
                }
            }
        }

        uint32_t expected_left_count = mid - low + 1;

        if (left_count < expected_left_count) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    infile.close();
    return missing_number;
}

int main() {
    generateFile();

    uint32_t result = findMissingNumber();

    cout << "\n====================================\n";
    cout << "The missing number is: " << result << "\n";
    cout << "====================================\n";

    return 0;
}
