// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Reverse Substrings Between Each Pair of Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string reverseParentheses(string str) {
        stack<char> st;
        for(char &c : str)
        {
            if(c != ')')
            {
                st.push(c);
                continue;
            }
            
            string temp = "";
            while(!st.empty() && st.top() != '(')
            {
                temp.push_back(st.top());
                st.pop();
            }
            st.pop();
            for(char &x : temp)
                st.push(x);
        }
        string result = "";
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
