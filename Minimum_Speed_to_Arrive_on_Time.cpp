//Minimum Speed to Arrive on Time

class Solution {
public:
    double solve(vector<int> &dist, int &val) {
        double sum = 0.0;
        for(int i = 0; i < dist.size() - 1; i++) {
            sum += ceil(1.0 * dist[i] / val);
        }
        return sum + (1.0 * dist[dist.size() - 1] / val);
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(solve(dist, mid) > hour) {
                low = mid + 1;
            }
            else if(solve(dist, mid)<= hour) {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        if(ans == INT_MAX) 
        return -1;
        else
        return ans;
    }
};
