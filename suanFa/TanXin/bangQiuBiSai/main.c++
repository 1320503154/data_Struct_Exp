#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> sums;
        int sum = 0;
        for (const auto &op : operations)
        {
            int len = sums.size();
            int first = 0;
            int second = 0;
            int end = 0;
            int number = 0;
            switch (op[0]) // 此处取到的是容器内每一个元素的地址,[0]只是访问这个字符串地址的值,直接写op也行
            {
            case 'C':
                sum -= sums.back();
                sums.pop_back();
                break;
            case 'D':
                end = sums.back();
                sums.push_back(end * 2);
                sum += sums.back(); // sums.at(int pos)返回pos位置元素的引用
                break;
            case '+':
                first = sums.back();
                second = sums[len - 2];
                sums.push_back(first + second);
                sum += sums.back(); // 或者sums.back()访问尾元素
                break;

            default:
                number = stoi(op);
                sum += number;
                sums.push_back(stoi(op));
                break;
            }
        }
        return sum;
    }
};
int main()
{
    vector<string> ops = {"5", "2", "C", "D", "+"};

    Solution *solution = new Solution;
    int totalScore = solution->calPoints(ops);

    cout << "Total Score: " << totalScore << endl;

    delete solution;
    return 0;
}