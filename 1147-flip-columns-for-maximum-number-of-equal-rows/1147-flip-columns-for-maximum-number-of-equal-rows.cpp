class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;

        for(auto m  : matrix) {
            string str1 = "";
            string str2 = "";
            for(int i=0;i<m.size();i++) {
                str1+=to_string(m[i]);
                str2+=to_string(m[i]==1?0:1);
            }
            mp[str1]++;
            mp[str2]++;
        }

        int ans = 0;

        for(auto m : mp) {
            ans = max(ans,m.second);
        }

        return ans;
    }
};