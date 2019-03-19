#pragma once

#include <string>
#include <vector>
#include <iostream>

/*
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ��
�ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣
���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
�������� :
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1 <= n <= 100������ʾС�����ϵĿ���ˮƿ����n = 0��ʾ�����������ĳ���Ӧ��������һ�С�
������� :
����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��
��������1 :
3
10
81
0
�������1 :
	1
	5
	40
*/

int func1(int n)
{
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;

	int x = n / 3;
	int y = n % 3;
	return func1(x + y) + x; // return func1(n - 2) + 1
}


/*
��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ������ü����������N��1��1000֮������������N��1000�������������ظ������֣�
ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣
����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ���(ͬһ��������������ܻ��ж������ݣ�ϣ���������ȷ����)��

Input Param
n               ����������ĸ���
inputArray      n�����������ɵ�����

Return Value
OutputArray    ����������������

A:
1.���Ԫ�ر�������vector�У����ȶ�vector�����Ԫ������Ȼ�����unique����ȥ�أ�unique(��ʼ������,��ֹ������)��
���ص���ȥ���Ժ�vector��û���ظ�Ԫ�ص���һ��λ�õĵ�������unique��ʵ��ԭ�������жϵ�ǰԪ���Ƿ������һ��Ԫ�أ�
������ھͽ���һ��Ԫ����ǰ���ǵ���ǰ��Ԫ�أ�����ִ����unique()�Ժ󷵻صĵ�������ʼ��vector.end()��Ԫ�ض���û������ġ�
#include <algorithm>
#include <vector>
uning namespace std;
vector<int> v;
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
2. ���뵽set��������ȡ����
3. �Լ�ʵ�� - λͼ
*/

void unique_sort(std::vector<int>& v)
{
	int vmax = *std::max_element(v.begin(), v.end());
	std::vector<int> vflag;
	vflag.resize(vmax + 1);
	memset(vflag.data(), 0, sizeof(int) * vflag.size());

	for (auto ite = v.begin(); ite != v.end(); ite++)
	{
		if (vflag[*ite] == 0)
			vflag[*ite] = 1;
		else
		{
			ite = v.erase(ite);
		}
	}

	sort(v.begin(), v.end());
}



/*
д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��
*/

std::string transfer(char* pinput)
{
	char* pTmp = pinput;
	if (*pTmp == '0' && (*(pTmp + 1) == 'x' || *(pTmp + 1) == 'X'))
		pTmp = pTmp + 2;

	unsigned long long number  = 0;
	char* plast = pTmp;
	while (*plast != '\0')
	{
		plast++;
	}
	plast--;

	int flag = 0;
	while (plast != pTmp)
	{
		number += pow(16, flag);
		flag++;
		plast--;
	}
	number += pow(16, flag);

	return std::to_string(number);
}
