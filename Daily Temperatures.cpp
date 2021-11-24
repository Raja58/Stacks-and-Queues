// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        24 Nov 2021
//  @Detail  :        Daily Temperatures (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> temp;
        temp.push(n - 1);
        for(int i = n - 2; i >= 0; i--)
        {
            while(!temp.empty() && temperatures[temp.top()] <= temperatures[i])
                temp.pop();
            result[i] = temp.empty() ? 0 : temp.top() - i;
            temp.push(i);
        }
        return result;
    }
};
