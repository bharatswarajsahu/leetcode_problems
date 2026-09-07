class Solution {
private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void dfs(int i, const string& s, vector<string>& path, vector<vector<string>>& result) {
        if (i == s.length()) {
            result.push_back(path);
            return;
        }
        for (int j = i; j < s.length(); ++j) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(0, s, path, result);
        return result;
    }
};