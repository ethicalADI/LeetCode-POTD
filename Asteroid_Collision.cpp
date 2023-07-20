// Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        // Considering only -ve elements causes collision
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]>0 || st.empty()) // for 1st -ve element nothing will happen so
                st.push(nums[i]);       //just push it or if +ve element comes, keep 
                                        // pushing it.
            else{ // when found -ve, check for collisions
                while(!st.empty() && st.top()>0 && st.top() < abs(nums[i]))
                    st.pop();
                if(!st.empty() && st.top() == abs(nums[i]))
                    st.pop();
                else{
                    if(st.empty() || st.top()<0) st.push(nums[i]); // if only -ve elements are coming i.e. all in left direction
                }
            }
        }

        // push elements in ans vector & return
        vector<int> ans(st.size());
        for(int i = st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
