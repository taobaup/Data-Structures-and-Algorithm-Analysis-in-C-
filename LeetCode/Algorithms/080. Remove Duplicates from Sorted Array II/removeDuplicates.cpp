1）
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
		if(len <= 2)
			return len;
		
		int index = 2;
		for(int i = 2; i < len; ++i)
		{
			if(nums[i] != nums[index - 2])
			{
				// 不要写成 nums[index - 2] = nums[i];
				nums[index] = nums[i];
				++index;
			}
		}
		
		return index;
    }
};




2）
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		int index = 0;
		
		for(int i = 0; i < n; ++i)
		{
			// 注意不要把 continue 跟赋值语句的顺序写反
			if(i > 0 && i < n - 1 && nums[i] == nums[i + 1] && nums[i] == nums[i - 1])
			{
				continue;
			}
			
			nums[index] = nums[i];
			++index;
		}
		
		return index;
    }
};
