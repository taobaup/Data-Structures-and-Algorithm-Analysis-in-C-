英文链接: https://leetcode.com/problems/binary-tree-preorder-traversal/  
中文链接: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/  

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}

		preorder(result, root);

		return result;
	}

private:
	void preorder(vector<int> &result, TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}

		// 不要写成 result.push_back(root);
		result.push_back(root->val);
		preorder(result, root->left);
		preorder(result, root->right);
	}
};
```
 
```
class Solution {
 public:
	 vector<int> preorderTraversal(TreeNode* root) {
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
				 result.push_back(p->val);

				 p = p->left;
			 }
			 else
			 {
				 // 不要写成 front
				 const TreeNode *t = s.top();
				 s.pop();

				 p = t->right;
			 }
		 }

		 return result;
	 }
 };
```
