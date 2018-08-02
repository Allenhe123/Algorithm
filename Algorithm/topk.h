#pragma once

// https://blog.csdn.net/tian779278804/article/details/51583430
// BFPTR算法

/*
在BFPTR算法中，仅仅是改变了快速排序Partion中的pivot值的选取，在快速排序中，我们始终选择第一个元

素或者最后一个元素作为pivot，而在BFPTR算法中，每次选择五分中位数的中位数作为pivot，这样做的目的

就是使得划分比较合理，从而避免了最坏情况的发生。算法步骤如下

（1）将输入数组的n个元素划分为n/5组，每组5个元素，且至多只有一个组由剩下的n%5个元素组成。

（2）寻找n/5个组中每一个组的中位数，首先对每组的元素进行插入排序，然后从排序过的序列中选出中位数。

（3）对于（2）中找出的n/5个中位数，递归进行步骤（1）和（2），直到只剩下一个数即为这n/5个元素

的中位数，找到中位数后并找到对应的下标p。

（4）进行Partion划分过程，Partion划分中的pivot元素下标为p。

（5）进行高低区判断即可。


本算法的最坏时间复杂度为O(n)，值得注意的是通过BFPTR算法将数组按第K小（大）的元素划分为两部分，而

这高低两部分不一定是有序的，通常我们也不需要求出顺序，而只需要求出前K大的或者前K小的。

另外注意一点，求第K大就是求第n-K+1小，这两者等价。TOP K问题在工程中有重要应用，所以很有必要掌握。
*/

#include <algorithm>


//插入排序  
void InsertSort(int a[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i - 1] > a[i])
		{
			int t = a[i];
			int j = i;
			while (j > l && a[j - 1] > t)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = t;
		}
	}
}

//寻找中位数的中位数  
int FindMid(int a[], int l, int r)
{
	if (l == r) return a[l];
	int i = 0;
	int n = 0;
	for (i = l; i < r - 5; i += 5)
	{
		InsertSort(a, i, i + 4);
		n = i - l;
		std::swap(a[l + n / 5], a[i + 2]);
	}

	//处理剩余元素  
	int num = r - i + 1;
	if (num > 0)
	{
		InsertSort(a, i, i + num - 1);
		n = i - l;
		std::swap(a[l + n / 5], a[i + num / 2]);
	}
	n /= 5;
	if (n == l) return a[l];
	return FindMid(a, l, l + n);
}

//寻找中位数的所在位置  
int FindId(int a[], int l, int r, int num)
{
	for (int i = l; i <= r; i++)
		if (a[i] == num)
			return i;
	return -1;
}

//进行划分过程  
int Partion(int a[], int l, int r, int p)
{
	std::swap(a[p], a[l]);
	int i = l;
	int j = r;
	int pivot = a[l];
	while (i < j)
	{
		while (a[j] >= pivot && i < j)
			j--;
		a[i] = a[j];
		while (a[i] <= pivot && i < j)
			i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	return i;
}

int BFPTR(int a[], int l, int r, int k)
{
	int num = FindMid(a, l, r);    //寻找中位数的中位数  
	int p = FindId(a, l, r, num);  //找到中位数的中位数对应的id  
	int i = Partion(a, l, r, p);

	int m = i - l + 1;
	if (m == k) return a[i];
	if (m > k)  return BFPTR(a, l, i - 1, k);
	return BFPTR(a, i + 1, r, k - m);
}
