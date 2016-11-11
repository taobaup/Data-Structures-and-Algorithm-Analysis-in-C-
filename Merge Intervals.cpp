//Merge Intervals 
//先对集合进行排序 
//若当前区间的end大于下一区间的start，则合并两区间 
//否则，继续遍历集合
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;

		if (intervals.empty())
			return result;

		sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
			return a.start < b.start; 
		});

		int start = intervals[0].start;
		int end = intervals[0].end;

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (end >= intervals[i].start)
				end = max(end, intervals[i].end);
			else
			{
				result.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		result.push_back(Interval(start, end));

		return result;
	}
};
//另：
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;

		if (intervals.empty())
			return result;

		sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
			return a.start < b.start;
		});

		for (auto &temp : intervals)
		{
			if (result.empty() || temp.start > result.back().end)
				result.push_back(temp);
			else
			{
				auto &mid = result.back();
				mid.start = min(mid.start, temp.start);
				mid.end = max(mid.end, temp.end);
			}
		}

		return result;
	}
};
