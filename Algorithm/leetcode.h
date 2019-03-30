#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

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

	// 精确到小数点后n位
	std::string divideToN(int dividend, int divisor, int n)
	{
		bool diffSign = ((dividend ^divisor) >> 31);

		std::ostringstream ostreamRet;
		if (diffSign)
			ostreamRet << "-";

		dividend = dividend < 0 ? dividend * (-1) : dividend;
		divisor = divisor < 0 ? divisor * (-1) : divisor;

		int m = dividend;
		for (int i = 0; i < n + 1; i++)
		{
			int v = m / divisor;
			m = m % divisor;
			m *= 10;
			ostreamRet << v;
			if (i == 0)
				ostreamRet << ".";
		}

		return ostreamRet.str();
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

	/*
	给定一个n*m的矩阵A，A的每个元素Aij是16进制数。
	寻找一条从左上角到右下角的路径，每次只能向右或者向下移动，使得路径上所有数字之积在16进制下的后缀0最少。
	输入描述：
	第一行 n， m    n>=2, m<=1000
	接下来的n行，每行m个16进制数  0 <= Aij <= 10^9

	输出描述：
	第一行 最少后缀0的个数（十进制）
	第二行 路径方案。左上角开始 > 表示向右，v表示向下，如果由多种方案，输出字典序最小的方案。>的字典序小于v。

	示例：
	3 3
	3 2 8
	c 8 8
	2 a f

	输出 
	1
	>>vv

	思路：贪心算法+深度优先遍历+回溯
	
	*/

	int findPath(const std::vector<std::vector<int>>& input, std::vector<std::string>& path)
	{

	}


	/*
	给 n 个正整数 a_1,…,a_n， 将 n 个数顺序排成一列后分割成 m 段，每一段的分数被记为这段内所有数的和，该次分割的分数被记为 m 段分数的最大值。问所有分割方案中分割分数的最小值是多少？

	输入描述：
	第一行依次给出正整数 n, m。
	第二行依次给出n 个正整数 a1,...,an

	示例：

	输入
	5 3
	1 4 2 3 5
	输出
	5

	说明
	分割成 1 4 | 2 3 | 5 的时候三段的分数都为 5，得到分割分数的最小值。

	备注：
	对于所有的数据，有 m <= n <= 100000,0 <= ai

	思路

	将 n 个数划分为 n 段，分割分数即为 n 个正整数的最大值；
	将 n 个数划分为 1 段，分割分数即为 n 个正整数的和；
	若分为 m 段，则分割分数一定介于最大值与和之间。因此采用二分查找，每次取一个值对序列进行划分，若能划分出
	m 段，使得每段的和都小于这个数值，则满足划分，反之不满足，直至找到一个最小的满足划分的值为止。
	*/



	// leetcode 149 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
	// Definition for a point.
	 struct Point {
	     int x;
	     int y;
	     Point() : x(0), y(0) {}
	     Point(int a, int b) : x(a), y(b) {}
	 };
	
	 struct Slop
	 {
		 std::string slop;
		 int num;

		 Slop() : slop("0.0"), num(0) {}
		 Slop(const std::string& x, int y) : slop(x), num(y) {}
	 };


	 int maxPoints(vector<Point>& points)
	 {
		 if (points.empty()) return 0;

		 int maxnum = 0;
		 for (int i = 0; i < points.size(); i++)
		 {
			 int samenum = 0;
			 Point& p = points[i];
			 std::vector<Slop> tempVec;

			 for (int j = 0; j < points.size(); j++)
			 {
				 Point& q = points[j];

				 std::string s = "888888888.0";
				 if (p.x == q.x && p.y == q.y)
					 samenum++;
				 else if (p.x == q.x && p.y != q.y)
					 s = "999999999.0";
				 else
					 s = divideToN((q.y - p.y), (q.x - p.x), 20);

				 bool found = false;
				 int idx = 0;
				 for (idx = 0; idx < tempVec.size(); idx++)
				 {
					 if (s == tempVec[idx].slop)
					 {
						 found = true;
						 break;
					 }
				 }

				 if (found)
				 {
					 tempVec[idx].num++;
				 }
				 else
				 {
					 if (s == "888888888.0")
						 ;
					 else
						tempVec.emplace_back(Slop(s, 1));
				 }
			 }

			 int tempMax = 0;
			 for (auto sl : tempVec)
			 {
				 if (sl.num > tempMax)
				 {
					 tempMax = sl.num;
				 }
			 }
			 tempMax += samenum;

			 maxnum = maxnum < tempMax ? tempMax : maxnum;

		 }
		 return maxnum;
	 }



	 /*
	 给定一个包含n个整数的数组nums，判断nums中是否存在三个元素a，b，c，使得a+b+c=0。
	 找出所有满足条件且不重复的三元组。
	 例如：nums = {-1，0，1，2，-1，-4}
	 满足要求的三元组集合为：
	 [-1,0,1]
	 [-1,-1,2]
	 思路：对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。
	 这里我们可以先做个剪枝优化，就是当遍历到正数的时候就break，因为数组现在是有序的，如果第一个要fix的数是正数了，那么后面的数字
	 都是正数，永远不会出现和为0的情况。然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和前面的数字相等就跳过，因为我们不想把相同的
	 数字fix两次。对于遍历到的数，用0减去这个fix到的数得到target，然后只需要再找到两个数之和等于target即可。
	 我们用两个指针分别指向fix数字之后开始的数组的首尾两个数，如果两个数之和正好等于target，则将这2个数和fix的数一起放入结果中。
	 然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边的指针右移一位，使得指向的数字大一些。同理，若两数
	 之和大于target，则我们将右边那个指针左移一位，使得指向的数字减小一些。
	 */
	 std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
	 {
		 std::vector<std::vector<int>> res;
		 std::sort(nums.begin(), nums.end());
		 if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		 for (int k = 0; k < nums.size(); k++)
		 {
			 if (nums[k] > 0) break;
			 if (k > 0 && nums[k] == nums[k - 1]) continue;
			 int target = 0 - nums[k];
			 int i = k + 1;
			 int j = nums.size() - 1;
			 while (i < j)
			 {
				 if (nums[i] + nums[j] == target)
				 {
					 res.push_back({ nums[k], nums[i], nums[j] });
					 i++;
					 while (i < j && nums[i] == nums[i + 1]) i++;
					 while (i < j && nums[j] == nums[j - 1]) j--;
				 }
				 else if (nums[i] + nums[j] < target)
				 {
					 i++;
				 }
				 else
				 {
					 j--;
				 }
			 }
		 }
		 return res;
	 }

};