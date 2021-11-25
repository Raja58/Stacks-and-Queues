// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Asteroid Collision (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int &x : asteroids)
        {
            if(result.empty())
            {
                result.push_back(x);
                continue;
            }
            
            if(result.back() > 0 && x < 0)
            {
                if(result.back() == -x)
                {
                    result.pop_back();
                    continue;
                }
                
                if(result.back() > -x)
                    continue;
                
                bool blasted = false;
                while(!result.empty() && result.back() > 0)
                {
                    if(result.back() == -x)
                    {
                        result.pop_back();
                        blasted = true;
                        break;
                    }
                    else if(result.back() > -x)
                    {
                        blasted = true;
                        break;
                    }
                    else
                        result.pop_back();
                }
                
                if(!blasted)
                    result.push_back(x);
            }
            else
                result.push_back(x);
        }
        return result;
    }
};
