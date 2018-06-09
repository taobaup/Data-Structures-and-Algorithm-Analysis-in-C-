1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1)
        	return len;

        int index = 1;
        for(int i = 1; i < len; ++i)
        {
        	if(nums[i] != nums[i - 1])
        	{
        		nums[index] = nums[i];
        		++index;
        	}
        }

        return index;
    }
};




2)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1)
        	return len;

        int index = 1;
        for(int i = 1; i < len; ++i)
        {
        	if(nums[i] != nums[index - 1])
        	{
        		nums[index] = nums[i];
        		++index;
        	}
        }

        return index;
    }
};




3)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	auto last = unique(nums.begin(), nums.end());
        return distance(nums.begin(), last);
    }
};




4)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	auto last = removeDuplicates(nums.begin(), nums.end(), nums.begin());
        return distance(nums.begin(), last);
    }

    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
        while(first != last)
        {
        	*output++ = *first;
        	first = upper_bound(first, last, *first);
        }

        return output;
    }
};
