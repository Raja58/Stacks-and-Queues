// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Remove Duplicate Letters (LeetCode)
//  ============================
//  -->

class Solution {
public:
    string removeDuplicateLetters(string str) {
        vector<int> freq(26);
        for(char &c : str)
            freq[c - 'a']++;
      
        vector<bool> isPart(26, false);
        string result = "";
      
        for(char &c : str)
        {
            if(isPart[c - 'a'])
            {
                freq[c - 'a']--;
                continue;
            }
            
            while(!result.empty() && result.back() >= c && freq[result.back() - 'a'] > 0)
            {
                isPart[result.back() - 'a'] = false;
                result.pop_back();
            }
          
            result = result + c;
            isPart[c - 'a'] = true;
            freq[c - 'a']--;
        }
        return result;
    }
};
