#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>

void generate_file(const char* filename) {
    FILE* out = fopen(filename, "wb");
    if (!out) {
        std::cerr << "Failed to create file for writing.\n";
        return;
    }

    std::cout << "Generating 4.3 billion ints (17.2 GB)...\n";

    const size_t BUFFER_SIZE = 1024 * 1024;
    std::vector<uint32_t> buffer(BUFFER_SIZE);

    const uint64_t total_ints = 4300000000ULL;
    uint32_t counter = 0;
    uint64_t written = 0;

    while (written < total_ints) {
        size_t to_write = std::min((uint64_t)BUFFER_SIZE, total_ints - written);
        for (size_t i = 0; i < to_write; ++i) {

            buffer[i] = counter++;
        }
        fwrite(buffer.data(), sizeof(uint32_t), to_write, out);
        written += to_write;

        if (written % (BUFFER_SIZE * 100) == 0) {
            std::cout << "Written " << written << " / " << total_ints << " integers...\r" << std::flush;
        }
    }

    std::cout << "\nFile generation complete.\n";
    fclose(out);
}

void find_duplicate(const char* filename) {
    FILE* in = fopen(filename, "rb");
    if (!in) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    std::cout << "Allocating 512 MB bitfield...\n";

    uint8_t* bitfield = (uint8_t*)calloc(1ULL << 29, 1);
    if (!bitfield) {
        std::cerr << "Memory allocation failed. You need 512 MB of free RAM.\n";
        fclose(in);
        return;
    }

    std::cout << "Scanning file for duplicates...\n";
    const size_t BUFFER_SIZE = 1024 * 1024;
    std::vector<uint32_t> buffer(BUFFER_SIZE);

    bool found = false;
    while (!found) {
        size_t read_count = fread(buffer.data(), sizeof(uint32_t), BUFFER_SIZE, in);
        if (read_count == 0) break; 

        for (size_t i = 0; i < read_count; ++i) {
            uint32_t num = buffer[i];

            size_t byte_idx = num / 8;
            size_t bit_idx = num % 8;

            if (bitfield[byte_idx] & (1 << bit_idx)) {
                std::cout << "Found duplicate! The number is: " << num << "\n";
                found = true;
                break;
            }

            bitfield[byte_idx] |= (1 << bit_idx);
        }
    }

    if (!found) {
        std::cout << "No duplicates found\n";
    }

    free(bitfield);
    fclose(in);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <generate|find> <filename>\n";
        return 1;
    }

    std::string command = argv[1];
    const char* filename = argv[2];

    if (command == "generate") {
        generate_file(filename);
    }
    else if (command == "find") {
        find_duplicate(filename);
    }
    else {
        std::cerr << "Unknown command. Use 'generate' or 'find'.\n";
        return 1;
    }

    return 0;
}
