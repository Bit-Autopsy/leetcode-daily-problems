class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int mx = INT_MIN;
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                mx = max(mx, nums1[i]*nums2[j]);
                dp[i+1][j+1] = max(dp[i][j]+nums1[i]*nums2[j], max(dp[i][j+1], dp[i+1][j]));
            }
        }
        if(dp[nums1.size()][nums2.size()]>0) {
            return dp[nums1.size()][nums2.size()];
        }
        return mx;
    }
};
