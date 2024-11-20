class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> counter(3,0);

        for(char c : s) counter[c - 'a']++;

        for(int i=0;i<3;i++) {
            if(counter[i] < k) return -1;
        }

        vector<int> window(3,0);
        int left = 0, maxWindow = 0;

        for(int right = 0; right < s.size();right++) {
            window[s[right] - 'a']++;
            while(left <= right && (counter[0] - window[0] < k || counter[1] - window[1] < k || counter[2] - window[2] < k)){
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return s.size() - maxWindow;
    }
};