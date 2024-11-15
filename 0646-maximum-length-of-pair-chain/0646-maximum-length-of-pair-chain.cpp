class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(pairs.size(),1);

        //LIS 
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(pairs[i][0] > pairs[j][1] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return dp[pairs.size()-1];
    }
};