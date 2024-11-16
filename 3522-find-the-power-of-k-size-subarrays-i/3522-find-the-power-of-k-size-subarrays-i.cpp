class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<=n-k;i++) {
            int val = -1;
            unordered_map<int,int> mp;
            for(int j=i;j<i+k;j++) {
                if(mp.find(nums[j] - 1) != mp.end() && val == nums[j] - 1) {
                    val = nums[j];
                }
                else if(mp.size()){ 
                    val = -1;
                    break;
                }
                else {
                    val = nums[j];
                }
                mp[nums[j]]++;
            }
            ans.push_back(val);
        }

        return ans;
    }
};