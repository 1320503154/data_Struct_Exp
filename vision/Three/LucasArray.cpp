#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Lucas(int num)
{
    if (num == 0)
    {
        return 2;
    }
    else if (num == 1)
    {
        return 1;
    }
    return Lucas(num - 1) + Lucas(num - 2);
}
int main()
{
    int N = 0;
    vector<int> arr;
    cin >> N;
    if (N == 1)
    {
        cout << "2";
        return 0;
    }
    while (N > 0)
    {
        arr.push_back(Lucas(N - 1));
        N--;
    }
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << ',';
    }
    cout << arr.back();
    return 0;
}