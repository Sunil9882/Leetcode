class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = INT_MIN;
        int n = nums.size();
        
        int i = 0, j = 0;
        unordered_map<int,int> mp;

        while(j<n) {
            
            while(mp.find(nums[j]) != mp.end()) {
                mp[nums[i]]--;
                sum -= nums[i];
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            mp[nums[j]]++; //1
            sum+=nums[j];
            
            while(mp.size() > k) {
                mp[nums[i]]--;
                sum -= nums[i];
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size() == k) ans = max(sum,ans);
            
            j++;
        }

        if(mp.size() == k) ans = max(sum,ans);

        return ans==INT_MIN?0:ans;
    }
};