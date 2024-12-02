class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stack<pair<int,string>> st;
        string str = "";
        int word = 1;
        for(int i=0;i<sentence.size();i++) {
            if(sentence[i] == ' '){
                st.push({word,str});
                word++;
                str="";
            }
            else if(sentence.size()-1==i){
                str+=sentence[i];
                st.push({word,str});
                word++;
                str="";
            }
            else {
                str+=sentence[i];
            }
        }

        stack<pair<int,string>> sts;

        while(st.size()) {
            sts.push(st.top());
            st.pop();
        }

        st=sts;

        while(st.size()) {
            string temp = st.top().second;
            int word = st.top().first;
            st.pop();
            if(temp.size() >= searchWord.size() && temp.substr(0,searchWord.size()) == searchWord) return word;
        }

        return -1;
    }
};