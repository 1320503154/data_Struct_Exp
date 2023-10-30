#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 二叉树的节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};
// 写一个二叉树的层序遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        if (root != NULL)
            q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }

public:
    // createTree
    TreeNode *createTree(vector<int> &v)
    {
        if (v.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(v[0]);
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (i < v.size() && v[i] != NULL)
            {
                node->left = new TreeNode(v[i]);
                q.push(node->left);
            }
            i++;
            if (i < v.size() && v[i] != NULL)
            {
                node->right = new TreeNode(v[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
// 写一个测试用例
int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = s.createTree(v);
    vector<vector<int>> res = s.levelOrder(root);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}