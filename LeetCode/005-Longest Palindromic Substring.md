英文链接: https://leetcode.com/problems/longest-palindromic-substring/  
中文链接: https://leetcode-cn.com/problems/longest-palindromic-substring/


```
class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.size();
        int dp[sLen][sLen] = {0};
        // vector<vector<int>> dp(sLen, vector<int>(sLen, 0));

        int left = 0;
        int right = 0;
        int maxLen = 1;

        for(int i = 0; i < sLen; ++i)
        {
            dp[i][i] = 1;

            for(int j = 0; j < i; ++j)
            {
                // dp[j + 1][i - 1] not s[j + 1][i - 1]
                dp[j][i] = s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]);

                if(dp[j][i] && i - j + 1 > maxLen)
                {
                    maxLen = i - j + 1;
                    left = j;
                    right = i;
                }       
            }
        }

        return s.substr(left, maxLen);
    }
};
```
