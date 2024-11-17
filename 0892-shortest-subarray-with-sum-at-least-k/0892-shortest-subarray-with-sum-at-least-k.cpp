#include <deque>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

        // Calculate prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Use deque to store indices of prefix sums
        deque<int> dq;
        int minLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Maintain deque to ensure prefixSum[j] - prefixSum[dq.front()] >= k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity of deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
