//Coin Change II

class Solution {
public:

    int change(int sum, vector<int>& coins) {
        int n = (int)coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j >= coins[i-1])
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
