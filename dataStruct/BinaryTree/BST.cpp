#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 定义二叉搜索树节点
struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// 插入节点到二叉搜索树
Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// 在二叉搜索树中查找给定的键值
Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// 删除二叉搜索树中的节点
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // 处理找到的节点
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// 中序遍历二叉搜索树（顺序输出键值）
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    // 插入几个节点
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "二叉搜索树中序遍历结果：";
    // 中序遍历能得到一个有序列表,因为左节点小于父节点,右节点大于父节点.左<中<右,恰好有序.
    inorder(root);
    cout << endl;

    // 查找节点
    int key = 0;
    cout << "你想查找的值:" << endl;
    cin >> key;
    Node *found = search(root, key);
    if (found)
        cout << key << " 已找到" << endl;
    else
        cout << key << " 未找到" << endl;

    // 删除节点
    int delKey = 30;
    root = deleteNode(root, delKey);
    cout << "删除节点 " << delKey << " 后的中序遍历结果：";
    inorder(root);
    cout << endl;

    return 0;
}