#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::string getSuffixHyphenation(const std::string& word) {
    if (word.empty() || word.back() != 'c') {
        return "";
    }

    std::vector<std::string> rules = {
        "et-ic", "al-is-tic", "s-tic", "p-tic", "-lyt-ic", "ot-ic", "an-tic",
        "n-tic", "c-tic", "at-ic", "h-nic", "n-ic", "m-ic", "l-lic", "b-lic",
        "-clic", "l-ic", "h-ic", "f-ic", "d-ic", "-bic", "a-ic", "-mac", "i-ac"
    };
    for (const std::string& rule : rules) {
        std::string raw_suffix = "";
        for (char ch : rule) {
            if (ch != '-') {
                raw_suffix += ch;
            }
        }

        if (word.length() >= raw_suffix.length()) {
            std::string word_ending = word.substr(word.length() - raw_suffix.length());
            if (word_ending == raw_suffix) {
                return rule;
            }
        }
    }

    return "no match";

}

struct TestCase {
    std::string word;
    std::string expected_output;
    std::string description;
};

int main() {
    std::vector<TestCase> tests = {
        {
            "test",
            "",
            "Test 1: Does not end in 'c' (early return)"
        },
        {
            "ethnic",
            "h-nic",
            "Test 2: Matches 'h-nic' rule"
        },
        {
            "clinic",
            "n-ic",
            "Test 3: Skips 'h-nic' and falls through to 'n-ic'"
        },
        {
            "plastic",
            "s-tic",
            "Test 4: Matches longer suffix 's-tic'"
        },
        {
            "zoc",
            "no match",
            "Test 5: Ends in 'c' but has no matching suffix rule"
        },
        {
            "ic",
            "no match",
            "Test 6: Shorter than any defined suffix pattern"
        }
    };

    std::cout << "Running Hyphenation Tests...\n\n";

    for (size_t i = 0; i < tests.size(); ++i) {
        std::string actual = getSuffixHyphenation(tests[i].word);
        bool passed = (actual == tests[i].expected_output);

        std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << tests[i].description << "\n";
        std::cout << "  Input:           \"" << tests[i].word << "\"\n";
        std::cout << "  Expected Output: \"" << tests[i].expected_output << "\"\n";
        std::cout << "  Actual Output:   \"" << actual << "\"\n\n";

        assert(passed);
    }

    std::cout << "All tests passed successfully!\n";
    return 0;
}
