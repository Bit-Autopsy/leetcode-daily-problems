class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        auto last = points[0];
        int ans=0;
        for(int i=1;i<points.size();i++) {
            int x = abs(points[i][0]-last[0]);
            int y = abs(points[i][1] - last[1]);
            ans += max(x, y);
            last = points[i];
        }

        return ans;
    }
};
