#include <iostream>
#include <string>
#include <map>

std::string generateLetter(std::string tmpl, const std::map<std::string, std::string>& schema) {
    for (const auto& pair : schema) {
        std::string placeholder = "[" + pair.first + "]";
        size_t pos = 0;

        while ((pos = tmpl.find(placeholder, pos)) != std::string::npos) {
            tmpl.replace(pos, placeholder.length(), pair.second);
            pos += pair.second.length();
        }
    }
    return tmpl;
}

int main() {
    std::string tmpl = "dear [NAME],\n\n"
        "Thank you for joining us on [DATE]. Regarding project\n"
        "[PROJECT], blah blah blah you forgot your \n"
        "[ITEM]. best regards, \n"
        "[SENDER]";

    std::map<std::string, std::string> schema = {
        {"NAME", "Alex"},
        {"DATE", "10/7/2025"},
        {"PROJECT", "alpha"},
        {"ITEM", "laptop"},
        {"SENDER", "the management team"}
    };

    std::string result = generateLetter(tmpl, schema);
    std::cout << result << std::endl;

    return 0;
}
