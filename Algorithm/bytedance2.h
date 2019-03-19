#pragma once

/*
给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：

区间中的最小数 * 区间所有数的和  最后程序输出经过计算后的最大值即可，不需要输出具体的区间。如给定序列[6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:

[6] = 6 * 6 = 36;
[2] = 2 * 2 = 4;
[1] = 1 * 1 = 1;
[6, 2] = 2 * 8 = 16;
[2, 1] = 1 * 3 = 3;
[6, 2, 1] = 1 * 9 = 9;
从上述计算可见选定区间[6] ，计算值为 36， 则程序输出为 36。

输入描述:
第一行输入数组序列长度n，第二行输入数组序列。
对于 50%的数据,  1 <= n <= 10000;
对于 100%的数据, 1 <= n <= 500000;
输出描述:
输出数组经过计算后的最大值。
输入例子1:
3
6 2 1
输出例子1:
36


具体思路为枚举每个点作为区间的最小值，然后利用单调栈求出区间的左右边界，在用前n项和来求区间的和。复杂度O(nlog(n))，
让我想起了求最长递增序列的O(nlogn)的求解过程，也是用的单调栈。

某个点作为最小值的时候 找左边第一个小于这个点的索引，找右边第一个小于这个点的索引，然后在这个区间去求

https://blog.csdn.net/qq_30578131/article/details/80740614
https://blog.csdn.net/txgANG/article/details/79800313

*/

#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

#define N 500007

int l[N], r[N], sum[N], a[N];

void bytedance2()
{
	int n;
	while (~scanf_s("%d", &n))
	{
		memset(sum, 0, sizeof(sum));
		a[0] = a[n + 1] = -1;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		stack<int>s;
		s.push(0);

		for (int i = 1; i <= n; i++)
		{
			int x;
			for (x = s.top(); a[x] >= a[i]; x = s.top())
			{
				s.pop();
			}
			l[i] = x + 1;
			s.push(i);
		}
		while (!s.empty())  s.pop();
		s.push(n + 1);

		for (int i = n; i >= 1; i--)
		{
			int x;
			for (x = s.top(); a[x] >= a[i]; x = s.top())
			{
				s.pop();
			}
			r[i] = x - 1;
			s.push(i);
		}

		int mx = 0;
		for (int i = 1; i <= n; i++)
		{
			mx = max(mx, a[i] * (sum[r[i]] - sum[l[i] - 1]));
		}
		printf("%d\n", mx);
	}
}
