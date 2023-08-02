//Permutations
class Solution {
public:
    void helper(int idx, vector<vector<int>> &ans, vector<int> v){
        if(idx == v.size()){
            ans.push_back(v);
            return;
        }
        for(int i = idx;i < v.size();i++){
            swap(v[i], v[idx]);
            helper(idx+1, ans, v);
            swap(v[i], v[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, ans, nums);
        return ans;    
    }
};
