class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char>st;
        for(int a=0;a<n;a++){
            if(isalpha(s[a])){
                st.push(s[a]);
            }
            else if(isdigit(s[a])&&!st.empty()){
                st.pop();
            }
            
        }
        string v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};