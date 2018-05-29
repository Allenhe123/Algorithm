#pragma once

// https://blog.csdn.net/tian779278804/article/details/51583430
// BFPTR�㷨

/*
��BFPTR�㷨�У������Ǹı��˿�������Partion�е�pivotֵ��ѡȡ���ڿ��������У�����ʼ��ѡ���һ��Ԫ

�ػ������һ��Ԫ����Ϊpivot������BFPTR�㷨�У�ÿ��ѡ�������λ������λ����Ϊpivot����������Ŀ��

����ʹ�û��ֱȽϺ����Ӷ������������ķ������㷨��������

��1�������������n��Ԫ�ػ���Ϊn/5�飬ÿ��5��Ԫ�أ�������ֻ��һ������ʣ�µ�n%5��Ԫ����ɡ�

��2��Ѱ��n/5������ÿһ�������λ�������ȶ�ÿ���Ԫ�ؽ��в�������Ȼ����������������ѡ����λ����

��3�����ڣ�2�����ҳ���n/5����λ�����ݹ���в��裨1���ͣ�2����ֱ��ֻʣ��һ������Ϊ��n/5��Ԫ��

����λ�����ҵ���λ�����ҵ���Ӧ���±�p��

��4������Partion���ֹ��̣�Partion�����е�pivotԪ���±�Ϊp��

��5�����иߵ����жϼ��ɡ�


���㷨���ʱ�临�Ӷ�ΪO(n)��ֵ��ע�����ͨ��BFPTR�㷨�����鰴��KС���󣩵�Ԫ�ػ���Ϊ�����֣���

��ߵ������ֲ�һ��������ģ�ͨ������Ҳ����Ҫ���˳�򣬶�ֻ��Ҫ���ǰK��Ļ���ǰKС�ġ�

����ע��һ�㣬���K��������n-K+1С�������ߵȼۡ�TOP K�����ڹ���������ҪӦ�ã����Ժ��б�Ҫ���ա�
*/

#include <algorithm>


//��������  
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

//Ѱ����λ������λ��  
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

	//����ʣ��Ԫ��  
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

//Ѱ����λ��������λ��  
int FindId(int a[], int l, int r, int num)
{
	for (int i = l; i <= r; i++)
		if (a[i] == num)
			return i;
	return -1;
}

//���л��ֹ���  
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
	int num = FindMid(a, l, r);    //Ѱ����λ������λ��  
	int p = FindId(a, l, r, num);  //�ҵ���λ������λ����Ӧ��id  
	int i = Partion(a, l, r, p);

	int m = i - l + 1;
	if (m == k) return a[i];
	if (m > k)  return BFPTR(a, l, i - 1, k);
	return BFPTR(a, i + 1, r, k - m);
}
