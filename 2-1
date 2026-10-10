#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> findAnagrams(const string& targetWord, const string& dictFileName) {
    vector<string> anagrams;

    string sortedTarget = targetWord;
    sort(sortedTarget.begin(), sortedTarget.end());

    ifstream file(dictFileName);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << dictFileName << "!" << endl;
        return anagrams;
    }

    string word;
    while (file >> word) {
        if (word.length() == targetWord.length()) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());

            if (sortedWord == sortedTarget) {
                anagrams.push_back(word);
            }
        }
    }
    file.close();

    return anagrams;
}

int main() {
    string targetWord = "organ";

    vector<string> result = findAnagrams(targetWord, "dict.txt");

    cout << "Anagrams for '" << targetWord << "':\n";
    for (const string& w : result) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
