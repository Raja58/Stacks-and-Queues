// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Dec 2021
//  @Detail  :        Maximal Rectangle (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int largestHistogram(vector<int> &arr)
    {
        stack<int> cache;
        int result = 0, n = arr.size();
        for(int i = 0; i < n; i++)
        {
            while(!cache.empty() && arr[i] <= arr[cache.top()])
            {
                int tp = cache.top();   cache.pop();
                int cur = arr[tp] * (cache.empty() ? i : i - cache.top() - 1);
                if(cur > result)
                    result = cur;
            }
            cache.push(i);
        }
        
        while(!cache.empty())
        {
            int tp = cache.top();   cache.pop();
            int cur = arr[tp] * (cache.empty() ? n : n - cache.top() - 1);
            if(cur > result)
                result = cur;
        }
        return result;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int> arr(mat[0].size());
        int result = 0;
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < arr.size(); j++)
                if(mat[i][j] == '0')
                    arr[j] = 0;
                else
                    arr[j]++;
            int cur = largestHistogram(arr);
            if(cur > result)
                result = cur;
        }
        return result;
    }
};
