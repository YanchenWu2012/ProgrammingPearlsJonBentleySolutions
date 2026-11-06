#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

unordered_map<string, vector<string>> buildAnagramMap(const string& dictFileName) {
    unordered_map<string, vector<string>> anagramMap;
    ifstream file(dictFileName);

    if (!file.is_open()) {
        cerr << "Error: Could not open " << dictFileName << endl;
        return anagramMap;
    }

    string word;
    while (file >> word) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramMap[sortedWord].push_back(word);
    }
    file.close();

    return anagramMap;
}

vector<string> findAnagrams(const string& targetWord, const unordered_map<string, vector<string>>& anagramMap) {
    string sortedTarget = targetWord;
    sort(sortedTarget.begin(), sortedTarget.end());

    auto it = anagramMap.find(sortedTarget);
    if (it != anagramMap.end()) {
        return it->second;
    }

    return {}; 
}

int main() {
    unordered_map<string, vector<string>> dictionaryMap = buildAnagramMap("dict.txt");

    if (dictionaryMap.empty()) {
        return 1;
    }

    string target1 = "stop";
    vector<string> result1 = findAnagrams(target1, dictionaryMap);

    cout << "Anagrams for '" << target1 << "':\n";
    for (const string& w : result1) {
        cout << w << " ";
    }
    cout << "\n\n";

    string target2 = "act";
    vector<string> result2 = findAnagrams(target2, dictionaryMap);

    cout << "Anagrams for '" << target2 << "':\n";
    for (const string& w : result2) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
