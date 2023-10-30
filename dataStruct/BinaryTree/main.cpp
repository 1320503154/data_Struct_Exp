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