class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap the characters at the two pointers
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            // Move the pointers towards the middle
            left++;
            right--;
        }
    }
};