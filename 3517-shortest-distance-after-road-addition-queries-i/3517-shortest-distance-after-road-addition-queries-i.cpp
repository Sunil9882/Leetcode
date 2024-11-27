class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;

        for(int i=0;i<n-1;i++) mp[i].push_back(i+1);

        for(auto &road : queries) {
            int u = road[0];
            int v = road[1];

            mp[u].push_back(v);

            vector<int> dp(n);
            dp[n-1] = 0;

            for(int j=n-2;j>=0;j--) {
                int minDistance = n;

                for(auto neighbor : mp[j]) {
                    minDistance = min(minDistance, dp[neighbor] + 1);
                }

                dp[j] = minDistance;
            }

            ans.push_back(dp[0]);
        }

        return ans;
    }
};