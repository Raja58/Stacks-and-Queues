// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Number of Visible People in a Queue (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> cache;
        int n = heights.size();
        vector<int> result(n);
        result[n - 1] = 0;
        cache.push(n - 1);
        for(int i = n - 2; i >= 0; i--)
        {
            int cnt = 0;
            while(!cache.empty() && heights[i] > heights[cache.top()])
                cache.pop(), cnt++;
            if(!cache.empty())
                cnt++;
            result[i] = cnt;
            cache.push(i);
        }
        return result;
    }
};
