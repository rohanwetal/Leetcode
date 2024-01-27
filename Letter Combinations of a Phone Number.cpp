#include <vector>
#include <string>

class PhoneNumber {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty())
            return {};

        std::vector<std::string> combinations;
        dfs(digits, 0, "", combinations);
        return combinations;
    }

private:
    const std::vector<std::string> digitToLetters{
        "",     "",     "abc",  "def", "ghi",
        "jkl",  "mno",  "pqrs", "tuv", "wxyz"};

    void dfs(const std::string& digits, size_t idx, std::string path, std::vector<std::string>& combinations) {
        if (idx == digits.length()) {
            combinations.push_back(path);
            return;
        }

        for (char letter : digitToLetters[digits[idx] - '0']) {
            path.push_back(letter);
            dfs(digits, idx + 1, path, combinations);
            path.pop_back();
        }
    }
};
