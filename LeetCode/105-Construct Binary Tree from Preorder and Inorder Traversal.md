英文链接: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/  
中文链接: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }

    template<typename MyIt>
    TreeNode* buildTree(MyIt pre_first, MyIt pre_last, MyIt in_first, MyIt in_last) {
        if(pre_first == pre_last)
            return NULL;

        if(in_first == in_last)
            return NULL;

        const int value = *pre_first;
        // MyIt, not TreeNode *
        MyIt in_mid = find(in_first, in_last, value);
        int len = distance(in_first, in_mid);
        MyIt pre_mid = next(pre_first, len);

        // 一定不要漏掉 new root
        TreeNode *root = new TreeNode(value);
        root->left = buildTree(next(pre_first), next(pre_mid), in_first, in_mid);
        root->right = buildTree(next(pre_mid), pre_last, next(in_mid), in_last);

        return root; 
    }
};
```
