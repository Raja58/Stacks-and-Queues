// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Design Browser History (LeetCode)
//  ============================
//  -->

class BrowserHistory {
public:
    
    vector<string> backSt, forwardSt;
    
    BrowserHistory(string homepage) {
        backSt.push_back(homepage);
    }
    
    void visit(string url) {
        backSt.push_back(url);
        forwardSt.clear();
    }
    
    string back(int steps) {
        while(!backSt.empty() && steps)
        {
            forwardSt.push_back(backSt.back());
            backSt.pop_back();
            steps--;
        }
        if(backSt.empty())
        {
            backSt.push_back(forwardSt.back());
            forwardSt.pop_back();
        }
        return backSt.back();
    }
    
    string forward(int steps) {
        while(!forwardSt.empty() && steps)
        {
            backSt.push_back(forwardSt.back());
            forwardSt.pop_back();
            steps--;
        }
        return backSt.back();
    }
};
