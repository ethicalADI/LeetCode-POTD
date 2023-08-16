// Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        int i = 0;
        d.push_back(i);
        for(i = 1;i < k;i++){
            while(!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        for(i = k;i < nums.size();i++){
            while(!d.empty() && d.front() <= i-k)
                d.pop_front();
            while(!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};
