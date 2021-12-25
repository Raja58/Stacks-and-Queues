// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Dec 2021
//  @Detail  :        Valid Parentheses (LeetCode)
//  ============================
//  -->

class Solution {
public:
    bool isValid(string str) {
        if(str.size() & 1)
            return false;
        unordered_map<char, char> match{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> cache;
        for(char &c : str)
        {
            if(c == '(' || c == '{' || c == '[')
                cache.push(c);
            else
            {
                if(cache.empty())
                    return false;
                else if(cache.top() != match[c])
                    return false;
                else
                    cache.pop();
            }
        }
        return cache.empty();
    }
};
