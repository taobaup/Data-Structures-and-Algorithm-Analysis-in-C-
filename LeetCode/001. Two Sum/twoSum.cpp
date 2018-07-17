1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int len = nums.size();
        if(len <= 1)
        	return result;

        unordered_map<int, int> map;
        for(int i = 0; i < len; ++i)
        	map[nums[i]] = i;

        for(int i = 0; i < len; ++i)
        {
        	int temp = target - nums[i];
        	if(map.find(temp) != map.end() && map[temp] > i)
        	{
        		result.push_back(i);
        		result.push_back(map[temp]);
        		break;
        	}
        }

        return result;
    }
};




2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int len = nums.size();
        if(len <= 1)
        	return result;

        unordered_map<int, int> map;
        for(int i = 0; i < len; ++i)
        {
        	int temp = target - nums[i];
        	if(map.find(temp) != map.end())
        	{
        		result.push_back(map[temp]);
        		result.push_back(i);
        		break;
        	}
            
        	map[nums[i]] = i;
        }

        return result;
    }
};