英文链接: https://leetcode.com/problems/group-anagrams/  
中文链接: https://leetcode-cn.com/problems/group-anagrams/


```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> map;
        for(auto str : strs)
        {
            string t = str;
            sort(t.begin(), t.end());
            map[t].push_back(str);
        }

        for(auto t : map)
            res.push_back(t.second);
        
        return res;
    }
};
```
借助数组实现排序
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;

        for(auto str : strs)
        {
            vector<int> cnt(26, 0);

            for(auto c : str)
                ++cnt[c - 'a'];

            string t = "";
            // '/'可不加
            for(auto d : cnt)
                t += to_string(d) + '/';

            map[t].push_back(str);
        }

        for(auto t : map)
            res.push_back(t.second);

        return res;
    }
};
```
