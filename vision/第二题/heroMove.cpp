#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 攻打距离为n米
// 每秒都可以更改档位
// 正整数每秒
// 最大一秒n米,最小一米.
// 有点动态规划的感觉了
// 计算共有多少种靠近时间.
int main()
{
    int n = 0;
    cin >> n;
    vector<int> dp(n, 0);
    // n=1,1;num=1
    // n=2,1+1,2;num=2
    // n=3,1+1+1,1+2,3;num=3
    // n=4,1+1+1+1,1+1+2,1+3,4,2+2;num=5
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}