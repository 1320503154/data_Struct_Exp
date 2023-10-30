let Partition = function (a, low, high) {
	let pivot = a[low];
	while (low < high) {
		while (low < high && a[high] >= pivot) {
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= pivot) {
			low++;
		}
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
};
let quickSort = function (a, low, high) {
	if (low >= high) {
		return;
	}
	let pivot = Partition(a, low, high);
	quickSort(a, low, pivot - 1);
	quickSort(a, pivot + 1, high);
};
let main = function () {
	let a = [4, 8, 2, 1, 3, 5, 9, 2, 3];
	console.log("排序前的a", a);
	quickSort(a, 0, a.length - 1);
	console.log("a数组排序后为:", a);
};
main();
