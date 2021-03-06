英文链接: https://leetcode.com/problems/insert-interval/  
中文链接: https://leetcode-cn.com/problems/insert-interval/


若newInterval.end < it->start，则插入it之前   
若newInterval.start > it->end，则继续遍历   
否则，取min左跟max右取代原先区间


```
// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
```

```
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto it = intervals.begin();

		while (it != intervals.end())
		{
			if (newInterval.end < it->start)
			{
				intervals.insert(it, newInterval);
				return intervals;
			}
			else if (newInterval.start > it->end)
				++it;
			else
			{
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}
		intervals.insert(intervals.end(), newInterval);

		return intervals;
	}
};
```


```
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result(1, newInterval);

		if (intervals.empty())
			return result;

		for (auto &temp : intervals)
		{
			newInterval = result.back();

			if (newInterval.start > temp.end)
			{
				result.back() = temp;
				result.push_back(newInterval);
			}

			else if (newInterval.end < temp.start)
				result.push_back(temp);
			else
			{
				result.back().start = min(temp.start, newInterval.start);
				result.back().end = max(temp.end, newInterval.end);
			}
		}

		return result;
	}
};
```
