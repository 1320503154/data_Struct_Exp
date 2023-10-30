#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
    /* data */
    string name;
    int score;
};

int main()
{
    vector<Stu> objects;
    Stu a;
    a.name = "somedata";
    a.score = 18;
    objects.push_back(a);
    objects.push_back({"abcd", 90});
    for (auto it = objects.begin(); it != objects.end(); it++)
    {
        cout << it->name << " "; // 此处的it是一个指针
    }
}