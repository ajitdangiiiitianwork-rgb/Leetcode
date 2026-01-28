class Solution {
public:
    int profit = 0;
    int f(int idx, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){ // I can buy a stock if i want to  
            profit = max(-prices[idx] + f(idx+1, 0, n, prices, dp), f(idx+1, 1, n, prices, dp));
        }
        else{ // I have to sell a stock to buy another one
            profit = max(prices[idx] + f(idx + 1, 1, n, prices, dp), f(idx+1, 0, n, prices, dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};