#pragma once

/*
����һ����������, ��Ҫ��ѡ��һ������, ʹ�ø����������������о������¼����ֵ����һ����

�����е���С�� * �����������ĺ�  ����������������������ֵ���ɣ�����Ҫ�����������䡣���������[6 2 1]�����������ʽ, �ɵõ����п���ѡ����������ļ���ֵ:

[6] = 6 * 6 = 36;
[2] = 2 * 2 = 4;
[1] = 1 * 1 = 1;
[6, 2] = 2 * 8 = 16;
[2, 1] = 1 * 3 = 3;
[6, 2, 1] = 1 * 9 = 9;
����������ɼ�ѡ������[6] ������ֵΪ 36�� ��������Ϊ 36��

��������:
��һ�������������г���n���ڶ��������������С�
���� 50%������,  1 <= n <= 10000;
���� 100%������, 1 <= n <= 500000;
�������:
������龭�����������ֵ��
��������1:
3
6 2 1
�������1:
36


����˼·Ϊö��ÿ������Ϊ�������Сֵ��Ȼ�����õ���ջ�����������ұ߽磬����ǰn�����������ĺ͡����Ӷ�O(nlog(n))��
��������������������е�O(nlogn)�������̣�Ҳ���õĵ���ջ��

ĳ������Ϊ��Сֵ��ʱ�� ����ߵ�һ��С�����������������ұߵ�һ��С��������������Ȼ�����������ȥ��

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
