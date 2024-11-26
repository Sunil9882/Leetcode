class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indgree(n,0);

        for(auto edge : edges) {
            indgree[edge[1]]++;
        }

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++) {
            mp[indgree[i]].push_back(i);
        }

        return mp[0].size()==1?mp[0][0]:-1;
    }
};