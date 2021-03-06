英文链接: https://leetcode.com/problems/n-queens/  
中文链接: https://leetcode-cn.com/problems/n-queens/



在一个 N*N 的棋盘上放置N个皇后，每行一个并使其不能互相攻击（同一行、同一列、同一斜线上的皇后都会自动攻击）

经典的N皇后问题 
经典解法为回溯递归，一层层向下扫描 
使用pos数组，pos[i]表示第i行皇后所在的列，初始值为-1 
从0开始递归，每一行都遍历一次各列，判断如果在该位置放置皇后会不会有冲突。当最后一行皇后放好后，得到一种可能的结果，存入res

```
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<int> pos(n, -1);

		dfs(pos, 0, res);

		return res;
	}

private:
	// vector<vector<string>> &res 要用引用
	void dfs(vector<int> &pos, int row, vector<vector<string>> &res)
	{
		int n = pos.size();
		if (row == n)
		{
			vector<string> out(n, string(n, '.'));
			for (int i = 0; i < n; ++i)
			{
				out[i][pos[i]] = 'Q';
			}

			// 注意不要错写在 for 内
			res.push_back(out);
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{
				if (isValid(pos, row, j))
				{
					pos[row] = j;
					dfs(pos, row + 1, res);
					pos[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int> &pos, int row, int j)
	{
		// 不要写成两重循环
		for (int i = 0; i < row; ++i)
		{
			if (pos[i] == j || abs(j - pos[i]) == abs(row - i))
			{
				return false;
			}
		}

		return true;
	}
};
```
