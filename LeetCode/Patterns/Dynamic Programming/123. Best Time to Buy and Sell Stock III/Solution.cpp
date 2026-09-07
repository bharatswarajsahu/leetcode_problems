class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdOne = INT_MIN;
        int sellOne = 0;
        int holdTwo = INT_MIN;
        int sellTwo = 0;

        for (int price : prices) {
            holdOne = max(holdOne, -price);
            sellOne = max(sellOne, holdOne + price);
            holdTwo = max(holdTwo, sellOne - price);
            sellTwo = max(sellTwo, holdTwo + price);
        }

        return sellTwo;
    }
};