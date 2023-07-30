//Strange Printer

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 1; l <= n; ++l) {
            // i represents the starting index of the substring.
            // j represents the ending index of the substring.
            // The substring is s[i...j].

            for (int i = 0; i <= n - l; ++i) {
                int j = i + l - 1;

                // Base case: Single character substring requires one operation.
                if (i == j) {
                    dp[i][j] = 1;
                } 
                else
                 {
                    // Check if the characters at positions i and j are the same.
                    // If they are the same, we can print the substring with the same
                    // number of operations as s[i...j-1].
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                        // If the characters at positions i and j are different,
                        // calculate the minimum number of operations required to
                        // print the substring s[i...j].

                        // Initialize dp[i][j] to a large value (INT_MAX).
                        dp[i][j] = INT_MAX;

                        // Loop over all possible partitions (k) within the substring
                        // s[i...j] and find the minimum number of operations.
                        for (int k = i; k < j; ++k) {
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                        }
                    }
                }
            }
        }

        // The result is stored in dp[0][n-1], which represents the whole string s[0...n-1].
        return dp[0][n - 1];
    }
};
