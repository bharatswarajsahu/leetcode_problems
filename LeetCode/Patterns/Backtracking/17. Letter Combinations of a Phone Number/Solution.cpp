class Solution {
private:
    vector<string> result;
    // Map digits to their corresponding letters
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(const string& digits, int index, string& currentStr) {
        // Base case: combination is complete
        if (index == digits.length()) {
            result.push_back(currentStr);
            return;
        }
        
        // Loop through all letters for the current digit
        string letters = keypad[digits[index] - '0'];
        for (char letter : letters) {
            currentStr.push_back(letter);       // Choose
            backtrack(digits, index + 1, currentStr); // Explore
            currentStr.pop_back();              // Un-choose (backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        string currentStr = "";
        backtrack(digits, 0, currentStr);
        
        return result;
    }
};