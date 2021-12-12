// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Evaluate Reverse Polish Notation (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int eval(int &a, int &b, string &x)
    {
        char c = x[0];
        switch(c)
        {
            case '+' :
                return a + b;
            case '-' :
                return a - b;
            case '*' :
                return a * b;
            case '/' :
                return a / b;
        }
        return -1;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> cache;
        
        for(string &x : tokens)
        {
            if(x.size() == 1 && !('0' <= x[0] && x[0] <= '9'))
            {
                int back = cache.top(); cache.pop();
                int front = cache.top();    cache.pop();
                cache.push(eval(front, back, x));
            }
            else
                cache.push(stoi(x));
        }
        return cache.top();
    }
};
