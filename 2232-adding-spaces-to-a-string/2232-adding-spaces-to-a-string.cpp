class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str="";
        int cnt = 0;
        for(int i=0;i<s.size();i++) {
            if(cnt < spaces.size() && i == spaces[cnt]) {
                cnt++;
                str+=" ";
                i--;
            }
            else{
                str+=s[i];
            }
        }

        return str;
    }
};