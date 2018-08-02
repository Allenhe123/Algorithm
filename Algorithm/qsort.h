#pragma once

// https://blog.csdn.net/tian779278804/article/details/51583430
// ����ָ�����β���м�ɨ�裨˫��ɨ�裩, ���ַ����������ڿ�����������

int partion(int a[], int l, int r)
{
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

void quickSort(int a[], int l, int r)
{
	if (l < r)
	{
		int k = partion(a, l, r);
		quickSort(a, l, k - 1);
		quickSort(a, k + 1, r);
	}
}
