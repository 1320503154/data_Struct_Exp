class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(int n, int k, int startIndex)
    {

        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        // 剪枝优化单层搜索逻辑
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return result;
    }
};