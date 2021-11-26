// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        The Number of Weak Characters in the Game (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    static bool myComp(vector<int> &x, vector<int> &y)
    {
        if(x[0] == y[0])
            return x[1] > y[1];
        return x[0] < y[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), myComp); //sorting in the correct way is very important
        
        int result = 0;
        stack<int> cache;
        for(int i = prop.size() - 1; i >= 0; i--)
        {
            while(!cache.empty() && cache.top() <= prop[i][1])
                cache.pop();
            if(!cache.empty())
                result++;
            cache.push(prop[i][1]);
        }
        return result;
    }
};
