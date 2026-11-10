class Solution {
public:
    int f(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy) {
            int buyCost = -prices[i] + f(i + 1, 0, prices, dp);
            int skip = f(i + 1, 1, prices, dp);
            return dp[i][canBuy] = max(buyCost, skip);
        } else {
            int sellProfit = prices[i] + f(i + 2, 1, prices, dp);
            int skip = f(i + 1, 0, prices, dp);
            return dp[i][canBuy] = max(sellProfit, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};