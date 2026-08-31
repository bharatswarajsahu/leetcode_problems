class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // Variables to store the previous two Fibonacci numbers
        int prev2 = 0; // Represents F(0)
        int prev1 = 1; // Represents F(1)
        
        // Iterate from 2 up to n
        for (int i = 2; i <= n; i++) {
            // The current Fibonacci number is the sum of the last two
            int current = prev1 + prev2;
            
            // Shift variables forward for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};