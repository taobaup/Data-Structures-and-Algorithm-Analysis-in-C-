英文链接: https://leetcode.com/problems/implement-strstr/  
中文链接: https://leetcode-cn.com/problems/implement-strstr/


>实现 strStr () 返回匹配串在原串中第一次出现的下标，不存在则返回-1

>采用算法导论中的朴素字符串匹配算法   
假设原串的长度是m，匹配串的长度是n   
在原串中每一个长度为n的子串，都判断是否跟匹配串一致   
总共有m-n+1个子串，所以算法的时间复杂度是O((m-n+1)*n)=O(m*n)   
空间复杂度是O(1)

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
            return 0;
        }

        int m = haystack.size();
        int n = needle.size();

        // 不要遗漏这一步
        if (m < n)
        {
            return -1;
        }

        for (int i = 0; i <= m - n; ++i)
        {
            int j = 0;
            for (j = 0; j < n; ++j)
            {
                // 不要写成 if (needle[j] != needle[i + j])
                if (needle[j] != haystack[i + j])
                {
                    break;
                }
            }

            if (j == n)
            {
                return i;
            }
        }

        return - 1;
    }
};
```
