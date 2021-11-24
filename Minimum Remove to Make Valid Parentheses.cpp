// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Minimum Remove to Make Valid Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int n = str.size(), open = 0;
        vector<bool> pre(n, true);
        for(int i = 0; i < n; i++)
        {
            char &c = str[i];
            if(c == '(')
                open++;
            else if(c == ')')
            {
                open--;
                if(open < 0)
                {
                    pre[i] = false;
                    open = 0;
                }
            }
        }
        
        open = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(!pre[i])
                continue;
            char &c = str[i];
            if(c == ')')
                open++;
            else if(c == '(')
            {
                open--;
                if(open < 0)
                {
                    pre[i] = false;
                    open = 0;
                }
            }
        }
        
        int j = 0;
        for(int i = 0; i < n; i++)
            if(pre[i])
                str[j++] = str[i];
        return str.substr(0, j);
    }
};
