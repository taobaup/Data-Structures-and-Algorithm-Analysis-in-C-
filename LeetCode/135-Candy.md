
英文链接: https://leetcode.com/problems/candy/  
中文链接: https://leetcode-cn.com/problems/candy/

```
class Solution {
public:
	int candy(vector<int>& ratings) {
		int res = 0;
		int n = ratings.size();
		vector<int> nums(n, 1);
		
		for (int i = 0; i < n - 1; ++i) 
		{
			if (ratings[i + 1] > ratings[i]) 
			{
				nums[i + 1] = nums[i] + 1;
			}
		}

		for (int i = n - 1; i > 0; --i) 
		{
			if (ratings[i - 1] > ratings[i]) 
			{
				nums[i - 1] = max(nums[i - 1], nums[i] + 1);
			}
		}

		for (int num : nums) 
		{
			res += num;
		}

		return res;
	}
};
```
