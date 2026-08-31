class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: The first row only has '0'
        if (n == 1) return 0;
        
        // Find the length of the previous row (which acts as our midpoint)
        // 1 << (n - 2) is a fast way to calculate 2^(n-2) using bitwise shifts
        int mid = 1 << (n - 2); 
        
        if (k <= mid) {
            // k is in the first half: it perfectly matches the previous row
            return kthGrammar(n - 1, k);
        } else {
            // k is in the second half: it is the inverted value of the previous row
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};