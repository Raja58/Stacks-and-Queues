// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Score of Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> st;
        int open = 0, result = 0;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == '(')
                open++;
            else
            {
                open--;
                if(str[i - 1] == '(')
                    result += (1 << open);
            }
        return result;
    }
};
