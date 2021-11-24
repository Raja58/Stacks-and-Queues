// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Minimum Add to Make Parentheses Valid (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int minAddToMakeValid(string str) {
        int result = 0;
        stack<char> st;
        for(char &c : str)
        {
            if(c == '(')
                st.push(c);
            else if(st.empty())
                result++;
            else
                st.pop();
        }
        return result + st.size();
    }
};
