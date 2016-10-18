//Longest Consecutive Sequence
//时间复杂度要求O(n)，因此不能直接排序
//可借助哈希表，以空间换时间
//在哈希表中查找每个元素的左右相邻数
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_map<int,bool> map;
        for(auto i:nums)
            map[i]=false;
        for(auto i:nums)
        {
            if(map[i])
                continue;
            int length=1;
            map[i]=true;
            for(int j=i-1;map.find(j)!=map.end();--j)
            {
                map[j]=true;
                ++length;
            }
            for(int j=i+1;map.find(j)!=map.end();++j)
            {
                map[j]=true;
                ++length;
            }
            
            longest=max(longest,length);
        }
        
        return longest;
    }
};
