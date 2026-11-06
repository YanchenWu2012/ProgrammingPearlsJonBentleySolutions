#include <iostream>
#include <cctype>
#include <vector>

const char* alphabet[26][5] = {
    // A
    { "  ###  ", " #   # ", " ##### ", " #   # ", " #   # " },
    // B
    { " ###### ", " #    # ", " ###### ", " #    # ", " ###### " },
    // C
    { "  ##### ", " #      ", " #      ", " #      ", "  ##### " },
    // D
    { " #####  ", " #    # ", " #    # ", " #    # ", " #####  " },
    // E
    { " #######", " #      ", " #####  ", " #      ", " #######" },
    // F
    { " #######", " #      ", " #####  ", " #      ", " #      " },
    // G
    { "  ##### ", " #      ", " #  ####", " #    # ", "  ##### " },
    // H
    { " #   # ", " #   # ", " ####### ", " #   # ", " #   # " },
    // I
    { " ##### ", "   #   ", "   #   ", "   #   ", " ##### " },
    // J
    { "   ####", "     # ", "     # ", " #   # ", "  ###  " },
    // K
    { " #   # ", " #  #  ", " ###   ", " #  #  ", " #   # " },
    // L
    { " #      ", " #      ", " #      ", " #      ", " #######" },
    // M
    { " #   # ", " ## ## ", " # # # ", " #   # ", " #   # " },
    // N
    { " #   # ", " ##  # ", " # # # ", " #  ## ", " #   # " },
    // O
    { "  ###  ", " #   # ", " #   # ", " #   # ", "  ###  " },
    // P
    { " ###### ", " #    # ", " ###### ", " #      ", " #      " },
    // Q
    { "  ###  ", " #   # ", " #   # ", " # # # ", "  #### " },
    // R
    { " ###### ", " #    # ", " ###### ", " #  #  ", " #   # " },
    // S
    { "  ##### ", " #      ", "  ###   ", "      # ", " #####  " },
    // T
    { " ##### ", "   #   ", "   #   ", "   #   ", "   #   " },
    // U
    { " #   # ", " #   # ", " #   # ", " #   # ", "  ###  " },
    // V
    { " #   # ", " #   # ", " #   # ", "  # #  ", "   #   " },
    // W
    { " #   # ", " #   # ", " # # # ", " ## ## ", " #   # " },
    // X
    { " #   # ", "  # #  ", "   #   ", "  # #  ", " #   # " },
    // Y
    { " #   # ", " #   # ", "  ###  ", "   #   ", "   #   " },
    // Z
    { "#######", "     # ", "    #  ", "   #   ", "#######" }
};

std::vector<std::string> getBanner(char letter) {
    letter = std::toupper(letter);
    std::vector<std::string> bannerLines;

    if (letter >= 'A' && letter <= 'Z') {
        int index = letter - 'A';
        for (int row = 0; row < 5; ++row) {
            bannerLines.push_back(alphabet[index][row]);
        }
    }
    else {
        bannerLines.push_back("[Character not supported]");
    }
    return bannerLines;
}

int main() {
    std::vector<std::string> letterA = getBanner('A');

    std::cout << "Printing banner from returned array:\n";
    for (const std::string& line : letterA) {
        std::cout << line << "\n";
    }

    return 0;
}
