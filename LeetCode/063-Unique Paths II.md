英文链接: https://leetcode.com/problems/unique-paths-ii/  
中文链接: https://leetcode-cn.com/problems/unique-paths-ii/


Time Limit Exceeded

```
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		int res = dfs(obstacleGrid, m, n);
		
		return res;
	}

private:
	int dfs(vector<vector<int>>& obstacleGrid, int m, int n)
	{
		if (m < 1 || n < 1)
		{
			return 0;
		}

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}

		if (m == 1 && n == 1)
		{
			return 1;
		}
	
		return dfs(obstacleGrid, m - 1, n) + dfs(obstacleGrid, m, n - 1);
	}
};
```

深搜+缓存，即备忘录法

```
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		f = vector<vector<int>>(m, vector<int>(n, 0));
		f[0][0] = 1;
		int res = dfs(obstacleGrid, m - 1, n - 1);
		
		return res;
	}

private:
	vector<vector<int>> f;

	int dfs(vector<vector<int>>& obstacleGrid, int x, int y)
	{
		// 不要写成 if (x < 1 || y < 1)
		if (x < 0 || y < 0)
		{
			return 0;
		}

		if (obstacleGrid[x][y] == 1)
		{
			return 0;
		}

		if ((x > 0 || y > 0) && f[x][y] == 0)
		{
			f[x][y] = dfs(obstacleGrid, x - 1, y) + dfs(obstacleGrid, x, y - 1);
		}
	
		return f[x][y];
	}
};
```

动态规划
```
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();

		if (m <= 0 || n <= 0)
		{
			return 0;
		}

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}

		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;

		for (int i = 1; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 1)
			{
				dp[i][0] = 0;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
		}

		//	for (int j = 1; j < m; ++j) Runtime Error
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[0][j] == 1)
			{
				dp[0][j] = 0;
			}
			else
			{
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}

		return dp[m - 1][n - 1];
	}
};
```


动态规划+滚动数组
```
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();

		if (m <= 0 || n <= 0)
		{
			return 0;
		}

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}

		vector<int> dp(n, 0);
		dp[0] = 1;

		// 注意 i,j 都是从 0 开始
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[j] = 0;
				}
				else if (j > 0)
				{
					dp[j] = dp[j] + dp[j - 1];
				}
			}
		}

		return dp[n - 1];
	}
};
```
