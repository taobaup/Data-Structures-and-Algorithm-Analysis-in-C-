英文链接: https://leetcode.com/problems/binary-tree-inorder-traversal/  
中文链接: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/  


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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}

		inorder(result, root);

		return result;
	}

private:
	void inorder(vector<int> &result, TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}

		inorder(result, root->left);
		result.push_back(root->val);
		inorder(result, root->right);
	}
};
```

```
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;

		if (root == NULL)
		{
			return result;
		}

		stack<const TreeNode*> s;
		const TreeNode *p = root;

		while (!s.empty() || p != NULL)
		{
			if (p != NULL)
			{
				s.push(p);
				
				p = p->left;
			}
			else
			{
				const TreeNode *t = s.top();
				s.pop();

				// not other->val
				result.push_back(t->val);

				p = t->right;
			}
		}

		return result;
	}
};

```
