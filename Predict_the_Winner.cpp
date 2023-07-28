//Predict the Winner

class Solution {
public:
    vector<vector<int>>dp;
    bool PredictTheWinner(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][i] = nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        int diff = dp[0][nums.size()-1];
        if(diff>=0) return true;
        return false;
    }

};
