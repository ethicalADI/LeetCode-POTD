//Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int i=0;
        while(i!=k){
            if(i==k-1)
            { return pq.top();
            }
            else
            {pq.pop();
            i++;}
        }
        return -1;
    }
};
