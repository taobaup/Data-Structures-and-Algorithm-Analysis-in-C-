英文链接: https://leetcode.com/problems/sum-root-to-leaf-numbers/  
中文链接: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

```
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```


```
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		return dfs(root, 0);
	}

	int dfs(TreeNode *root, int sum) 
	{
		if (root == NULL)
		{
			return 0;
		}

		sum = sum * 10 + root->val;
		
		if (root->left == NULL && root->right == NULL) 
		{
			return sum;
		}

		return dfs(root->left, sum) + dfs(root->right, sum);
	}
};
```
