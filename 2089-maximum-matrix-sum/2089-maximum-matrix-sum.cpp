class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum  = 0;
        int neg = 0;
        int least = INT_MAX;
        int n = matrix.size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) neg++;
                least = min(least, abs(matrix[i][j]));
            }
        }
        // cout<<least<<" "<<sum<<endl;
        if(neg % 2 == 0) return sum;
        return sum-2*least;
    }
};