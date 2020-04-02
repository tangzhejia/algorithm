#include <iostream>
using namespace std;

void merge(int a[], int start1, int end1, int start2, int end2) {
	int i = start1, j = start2;
	int n = (end1 - start1 + 1) + (end2 - start2 + 1);
	int temp[n];
	int k = 0;
	while (i <= end1 && j <= end2) {
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= end1)
		temp[k++] = a[i++];
	while (j <= end2)
		temp[k++] = a[j++];
	for (int i = 0; i < n; i++)
		a[start1 + i] = temp[i];
}

void MergeSort(int a[], int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;
		MergeSort(a, start, mid);
		MergeSort(a, mid + 1, end);
		merge(a, start, mid, mid + 1, end);
	}
}

int select(int a[], int start, int end, int k) {
	int n = end - start;
	if (n < 5) {
		MergeSort(a, start, end - 1);
		return a[start + k - 1];
	}

	int s = n / 5;
	int m[s];
	int i;
	for (i = 0; i < s; i++) {
		MergeSort(a, start + i * 5, start + i * 5 + 5 - 1);
		m[i] = a[start + i * 5 + 2];
	}
	MergeSort(m, 0, i - 1);
	int mid = m[i / 2];
	int a1[n];
	int a2[n];
	int a3[n];
	int num1 = 0, num2 = 0, num3 = 0;
	for (int i = start; i < end; i++) {
		if (a[i] < mid)
			a1[num1++] = a[i];
		else if (a[i] == mid)
			a2[num2++] = a[i];
		else
			a3[num3++] = a[i];
	}
	if (num1 >= k)
		return select(a1, 0, num1, k);
	if (num1 + num2 >= k)
		return mid;
	else
		return select(a3, 0, num3, k - num1 - num2);
}

int main() { 
	int n;
	cout << "输入数组个数：";
	cin >> n;
	int a[]={9,8,7,6,5,4,3,2,1,0,10,11,12,13,14,15,16,17,18,19,20};

	int k;
	cout << "输入所求第几小元素k：";
	cin >> k;
	
	cout << "第" << k << "小元素为：" << select(a, 0, n, k) << endl;
	return 0;
}










