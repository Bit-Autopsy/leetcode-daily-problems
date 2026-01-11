class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows==0) {
            return 0;
        }
        int cols = matrix[0].size();
        vector<vector<int>> ones(rows+1, vector<int>(cols, 0));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(matrix[i][j]=='0') {
                    ones[i+1][j]=0;
                } else {
                    ones[i+1][j] = ones[i][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=rows;i++) {
            for(int j=0;j<cols;j++) {
                int mn = ones[i][j];
                for(int k=j;k>=0;k--) {
                    mn = min(ones[i][k], mn);
                    ans = max(ans, (j-k+1)*mn);
                }
            }
        }
        return ans;
    }
};
