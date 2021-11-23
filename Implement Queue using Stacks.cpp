// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Implement Queue using Stacks (LeetCode)
//  ============================
//  -->

class MyQueue {
public:
    
    stack<int> in, out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty())
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        int result = out.top(); out.pop();
        return result;
    }
    
    int peek() {
        if(out.empty())
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
