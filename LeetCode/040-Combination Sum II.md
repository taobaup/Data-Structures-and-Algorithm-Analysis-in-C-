英文链接: https://leetcode.com/problems/combination-sum-ii/  
中文链接: https://leetcode-cn.com/problems/combination-sum-ii/


```
Combination Sum的扩展 
只需先将数组排序，递归过程中去除重复即可
```

```
class Solution {
public:
    	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> out;

		// 一定要先排序
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0, out, res);

		return res;
	}

private:
	void dfs(vector<int>& candidates, int target,
			int start, vector<int> &out, vector<vector<int>> &res) {
		if (target < 0)
		{
			return;
		}
		else if (target == 0)
		{
			res.push_back(out);
			return;
		}
		else
		{
			for (int i = start; i < candidates.size(); ++i)
			{
				if (i > start && candidates[i] == candidates[i - 1])
				{
					continue;
				}

				out.push_back(candidates[i]);
				// i + 1 而不是 i
				dfs(candidates, target - candidates[i], i + 1, out, res);
				out.pop_back();
			}
		}
	}
};
```
