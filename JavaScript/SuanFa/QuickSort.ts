const Partition = (a: number[], low: number, high: number): number => {
	let pivot: number = a[low]; //pivot:支点,中心
	//4 8 2 1 3 1 5,pivot=4.
	//挑选基准点,把小于基准点的放在左边.,大于基准点的放在右边.
	while (low < high) {
		while (low < high && a[high] >= pivot) {
			//当右边元素已经大于基准点时,不管,减少high指针.
			high--;
		}
		//结束循环时,找到了在pivot元素右边但是小于pivot元素的数组元素
		a[low] = a[high]; //放到pivot元素的左边,此时把4保存在了pivot变量中.最后放入left和right重合的位置即可.
		while (low < high && a[low] <= pivot) {
			//符合左边的元素小于pivot条件走low指针,
			low++;
		}
		a[high] = a[low]; //找到就把大于pivot的元素放到右边/
	}
	//此时循环进行完毕,low === high
	a[low] = pivot;
	return low;
};
const quickSort = (a: number[], low: number, high: number) => {
	// 1.确定参数和返回值
	// 2.确定递归的终止逻辑
	// 3.确定递归的单层搜索逻辑
	if (low >= high) {
		return;
	}
	let pivot: number = Partition(a, low, high); //分治法,得到中点的索引,递归解决左边的都小于pivot = arr[low]的元素和右边的元素.
	quickSort(a, low, pivot - 1);
	quickSort(a, pivot + 1, high);
};
const main = () => {
	let a: number[] = [4, 8, 2, 1, 3, 5, 9, 2, 3];
	console.log("排序前的a", a);
	quickSort(a, 0, a.length - 1);
	console.log("a数组排序后为:", a);
};
main();
