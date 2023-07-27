//Maximum Running Time of N Computers

class Solution {
public:
    typedef long long ll;
    bool canRun(int n, vector<int>& batteries, ll stime, ll tsm){
        ll target = n*stime; ll took = 0;
        for(int i = 0; i < batteries.size(); i++){
            took += min((ll)batteries[i], stime);
        } if(target > took) return false;
        return true;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll s = 0, e = 0; ll ans = -1;
        for(auto &x : batteries) e += x;
        ll tsm = e; e = e/n;
        while(s <= e){
            ll mid = (s+e)/2;
            if(canRun(n, batteries, mid, tsm)){
                ans = mid; s = mid + 1;
            } else e = mid - 1;
        } return ans;
    } };
