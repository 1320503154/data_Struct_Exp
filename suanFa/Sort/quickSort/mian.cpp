#include <iostream>
#include <vector>

using namespace std;
// 交换数组中两个元素的位置
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 根据枢纽元素将数组划分为两部分
int partition(vector<int> &arr, int low, int high) // low = 0,high = size - 1;
{                                                  // size = 6,high = 5.
    int pivot = arr[high];                         // 选取最后一个元素作为枢纽元素
    int i = low - 1;                               // 初始化较小元素区的边界,i = -1;

    for (int j = low; j <= high - 1; j++) // j=low=0; hign-1目的就是不循环到最后一个元素,因为元素已经 被取了.
    {
        // 如果当前元素小于或等于枢纽元素，则将其放入较小元素区
        if (arr[j] <= pivot)
        {
            i++;                  // i = 0
            swap(arr[i], arr[j]); // 最开始就是较小元素区域,arr[0] = arr[5]
        }
    }

    // 将枢纽元素放入正确的位置，并返回其索引
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 快速排序算法
void quickSort(vector<int> &arr, int low, int high) // low = 0,high = size - 1;
{
    if (low < high)
    {
        // 在当前范围内选择枢纽元素，并将数组划分为两部分
        int pivotIndex = partition(arr, low, high);

        // 递归对划分后的两部分进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// 测试快速排序算法
int main()
{
    vector<int> numbers = {7, 2, 1, 6, 8, 5, 3, 4, 10, 9, 21};
    int size = numbers.size();

    cout << "Original array: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    quickSort(numbers, 0, size - 1);

    cout << "Sorted array: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}