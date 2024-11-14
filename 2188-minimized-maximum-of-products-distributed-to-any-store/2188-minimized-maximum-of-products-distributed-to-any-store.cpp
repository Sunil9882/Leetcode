class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxNumber = INT_MIN;
        for(auto q : quantities) maxNumber = max(maxNumber, q);

        int start = 1, end = maxNumber;
        int ans = INT_MAX;
        while(end > start) {
            int mid = start + (end - start)/2;
            int qa = 0;
            for(auto q : quantities) {
                qa += (q+mid-1)/mid;
                if(qa > n) break;
            }
            if(qa<=n) {
                end = mid;
            }
            else start=mid+1;
        }

        return start;
    }
};