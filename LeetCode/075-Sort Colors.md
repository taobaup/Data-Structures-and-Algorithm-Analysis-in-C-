英文链接: https://leetcode.com/problems/sort-colors/  
中文链接: https://leetcode-cn.com/problems/sort-colors/


```
class Solution {
public:
	void sortColors(vector<int>& nums) {
		// 记得初始化为0
		int count[3] = {0};
		for (int i = 0; i < nums.size(); ++i)
		{
			++count[nums[i]];
		}

		int index = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < count[i]; ++j)
			{
				nums[index++] = i;
			}
		}

	}
};
```


```
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0;
		int blue = nums.size() - 1;

        	// not for (int i = 0; i < nums.size(); ++i)
        	// not for (int i = 0; i < blue; ++i)
		for (int i = 0; i <= blue; ++i)
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[red]);
				++red;
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[blue]);
				--blue;
				--i;
			}
		}

	}
};
```
