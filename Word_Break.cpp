//Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            for (const auto& w : wordDict) {
                if (!dp[i]) {
                    continue;
                }
                if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
                    dp[i + w.size()] = true;
                }
            }
        }

        return dp[s.size()];
    }
};
