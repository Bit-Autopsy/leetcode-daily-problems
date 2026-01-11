class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int j=1;j<=s2.size();j++) {
            dp[0][j] = dp[0][j-1] + int(s2[j-1]);
        }

        for(int i=1;i<=s1.size();i++) {
            dp[i][0] = dp[i-1][0] + int(s1[i-1]);
        }

        for(int i=0;i<s1.size();i++) {
            for(int j=0;j<s2.size();j++) {
                int takeOne = min(dp[i][j+1] + int(s1[i]), dp[i+1][j] + int(s2[j]));
                if(s1[i]==s2[j]) {
                    dp[i+1][j+1] = min(dp[i][j], takeOne);
                } else {
                    dp[i+1][j+1] = min(dp[i][j]+int(s1[i]) + int(s2[j]), takeOne);
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};
