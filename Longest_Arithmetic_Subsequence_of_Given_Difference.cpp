 //Longest Arithmetic Subsequence of Given Difference(LEETCODE)
 
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(mp.count(arr[i]-diff)) mp[arr[i]] = 1 + mp[arr[i]-diff];
            else mp[arr[i]] = 1;
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};
