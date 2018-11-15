#pragma once
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	// 数组中差为K的数对  leetcode 532
	int findPairs(vector<int>& nums, int k)
	{
		map<int, int> mp;
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int cur = nums[i];
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (abs(cur - nums[j]) == k)
				{
					int small = min(cur, nums[j]);
					if (mp.find(small) == mp.end())
					{
						cnt++;
						mp[small] = cur > nums[j] ? cur : nums[j];
					}
				}
			}
		}
		return cnt;
	}

	// 求函数调用次数   https://blog.csdn.net/a786150017/article/details/79689885
	int findTimes(int n)
	{


	}


	// https://blog.csdn.net/duxinyuhi/article/details/53710808
	int findQuestionCnt(int n, const std::vector<int>& vec)
	{


	}



	// http://group.jobbole.com/23591/
	/*
	有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。
	这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？
	输入描述:
	每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，
	且至少存在一个字符不是任何字符串的首字母。
	输出描述:
	输出一个数，表示最大和是多少。
	输入例子:
	2
	ABC
	BCA
	输出例子:
	1875

	根据所在位数做权重排序
	ABC = 100 x 10 x 1
	BCA = 100 x 10 x 1
	A = 101
	B = 110
	C = 11
	所以A取9，B取8，C取7
	得结果1875。
	一般来说权重最小的映射为0，因为0不能在首位，所以写程序的时候需要特殊处理0。
	*/
	int biggestSum()
	{

	}


	// https://blog.csdn.net/x_iya/article/details/79740854
	// 给函数传递一个正整数的列表alist和一个正整数T，假装它等于[1,3,6,4,2,7]，给出alist里所有相加等于T的元素的list，每个数只用一次。比如T=7，
	// 列表里3+4=7，7=7，1+6=7。你的函数就要返回[[3,4],[7],[1,6]]
	// 复杂度 n^2
	std::vector<std::vector<int> > findList_impl1(const std::vector<int>& vec, int sum)
	{
		std::vector<std::vector<int> > retVec;
		std::map<int, int> logMap;

		for (int i = 0; i < vec.size(); i++)
		{
			int cur = vec[i];
			std::vector<int> tempVec;

			if (sum == cur)
			{	
				if (logMap.find(0) == logMap.end())
				{
					tempVec.push_back(cur);
				}
			}

			for (int j=0; j<vec.size(); j++)
			{
				if (j == i) continue;
				if (vec[j] + cur == sum)
				{
					int key = min(cur, vec[j]);
					auto ite = logMap.find(key);
					if (ite == logMap.end())
					{
						tempVec.push_back(cur);
						tempVec.push_back(vec[j]);

						logMap[key] = max(cur, vec[j]);
					}
				}
			}

			if (!tempVec.empty())
				retVec.emplace_back(tempVec);
		}
		return retVec;
	}


	// 回溯法 + 递归
	std::vector<std::vector<int> > findList_impl2(const std::vector<int>& vec, int sum)
	{

	}

	// 第一题中限定了每个数只出现一次，第二题不用限制。就是可以1+1+1+1+…=7，也可以2+2+3=7。其实和第一题超级像，只要改一个返回值就好.
	std::vector<std::vector<int> > findList_impl3(const std::vector<int>& vec, int sum)
	{

	}


	// 用两个列表实现队列的push和pop功能。
	//class MyQueue
	//{
	//public:
	//	void push(int a)
	//	{
	//		vecA.push_back(a);
	//	}

	//	void pop()
	//	{
	//		if (vecB.empty())
	//		{
	//			if (!vecA.empty())
	//				vecB.assign(vecA.begin(), vecA.end());
	//			else
	//			{
	//				std::cout << "pop failed - no data" << std::endl;
	//				return;
	//			}
	//		}
	//		
	//		vecB.pop_back();
	//	}

	//private:
	//	std::vector<int> vecA;
	//	std::vector<int> vecB;
	//};

	// 判断一个字符串是否是另一个的子串
	const char* strstr_impl(const char* str, const char* sub)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			int tem = i;                    //tem保留主串中的起始判断下标位置 
			int j = 0;
			while (str[i++] == sub[j++])
			{
				if (sub[j] == '\0')
				{
					return &str[tem];
				}
			}
			i = tem;
		}
		return nullptr;
	}

	// 给定一个没有重复数字的序列，返回其所有可能的全排列。
	// https://leetcode-cn.com/problems/permutations/description/
	// https://www.cnblogs.com/huashanqingzhu/p/3569835.html

	void permute_helper(std::vector<int>& a, std::vector<int> flg, int idx, std::vector<int>& anss, int& cnt )
	{
		if (idx == a.size() - 1)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (flg[j] == 0)
				{
					anss[idx] = a[j];

					for (int k = 0; k < anss.size(); k++)
					{
						std::cout << anss[k] << " ";
					}
					std::cout << endl;
					cnt++;
					return;
				}
			}
		}
		else
		{
			for (int j=0; j<a.size(); j++)
			{
				if (flg[j] == 0)
				{
					anss[idx] = a[j];
					flg[j] = 1;

					permute_helper(a, flg, idx + 1, anss, cnt);

					flg[j] = 0;
				}
			}
		}
	}

	void permute(vector<int>& nums)
	{
		std::vector<int> flag(nums.size(), 0);
		std::vector<int> ans(nums.size(), 0);
		int count = 0;
		permute_helper(nums, flag, 0, ans, count);
		std::cout << count << std::endl;
	}

	/*
	有那么n个列表，每个列表有不确定个>=0的数，没有排序（列表大概长这个样子[3，0，9，11，2…..]），现在要每个列表里面选出一个元素，分别为a1，a2….an .
	使得满足 a1<=a2<=a3<=….<.an 的基础上a1+a2+。。。。。+an的值最大。
	先解释你的算法思想并且说出你算法的时间复杂度，然后写出时间负责度。（补充，这n个列表的位置是固定的，第一个列表选出来的元素就是a1，第二个就是n2，不用考虑先选哪一个列表）
	有了上一轮惨痛的体验，我就想安安稳稳的活着，用了一个最稳妥的方法，就是从an里选最大的，从an-1里选小于an而且最大的。在过程中可以判断一下是否可以提前结束就可以了。
	*/
	// O（n^2）
	int findMaxSumNList(const std::vector<std::vector<int>>& nums, int n)
	{
		assert(nums.size() == n);

		int sum = 0;
		int previousMax = INT_MAX;
		for (int i = n - 1; i >= 0; i--)
		{
			const std::vector<int>& vec = nums[i];
			if (!vec.empty())
			{
				int maxVal = INT_MIN;
				for (auto i : vec)
				{
					if (i < previousMax)
						maxVal = i > maxVal ? i : maxVal;
				}

				sum += maxVal;
				previousMax = maxVal;
			}
		}

		return sum;
	}

	/*
	第二题：有一条马路，马路上有很多树，树的高度不一。现在要统一剪树，剪到高度为h。意思就是，比h高的树都剪到h，比h低的树高度不变。
	所有的树剪掉的总长度为C。现在要使C>某个值的情况下(假设为MM)，使h最大。问怎么确定h。
	我用的二分法。初始min=0，max=最高的树，mid=（min+max）/2。在确定一个误差a，当误差小于某个数的时候就认为这个h是我们要的高度。
	然后他问我 如果误差是十的-6次方，时间复杂度是多少
	*/

	float findHeight(const std::vector<float>& vec, float C, float low, float high)
	{
		float h = (low + high) / 2;

		float sum = 0;
		for (auto i : vec)
		{
			if (i > h)
				sum += (i - h);
		}

		if (abs(C - sum) < 0.001f)
		{
			return h;
		}
		else
		{
			if (C > sum)
			{
				return findHeight(vec, C, low, h);
				
			}
			else if (C < sum)
			{
				return findHeight(vec, C, h, high);
			}
		}
	}

	/*
	循环有序列表：[7，7，8，9，1，2，5，6，7，7]，就是这个循环左移可以变成一个有序的列表。查找这个列表中是否有某个数，说出你的思路。
	我第一个方法是遍历。如果大于list[0]就从前向后遍历。如果小于list[0]就从后向前遍历，被鄙视了。
	第二个方法是二分法。如果要查找的数a小于list[mid]，那么这个数一定在list[:mid]。如果要查到的数大于list[mid],分两种情况，如果大于list[0]则在左边，
	如果小于，则在右边。
	*/
	int findElem(const std::vector<int>& vec, int n)
	{


	}



};