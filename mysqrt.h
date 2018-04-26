#ifndef MY_SQRT_H
#define MY_SQRT_H

#define MIN_ERROR 0.00000001

class Mysqrt
{
public:
	Mysqrt(int x): x_(x) {}

	// binary search
	double mysqrt_bs()
	{
		double begin = 1.0;
		double end = double(x_)/2.0 + 1;
		for (;;)
		{
			double mid = (begin + end) / 2;
			if (abs(mid * mid - x_) <= MIN_ERROR)
				return mid;
			else
			{
				if (mid * mid > x_)
					end = mid;
				else
					begin = mid;
			}
		}
	}

	// newton http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
	double mysqrt_newton()   
	{  
		int x = x_;
		if(x <= 0) return 0;

		double res, lastres;
		res = x;
		for (;;)
		{
			lastres = res;
			res = (res + x / res) / 2;
			if (abs(lastres - res) <= MIN_ERROR)
				break;
		}
		return res;  
	}

	// 卡马克-雷神之锤
	float InvSqrt()
	{  
		float x = static_cast<float>(x_);
		float xhalf = 0.5f * x;
		int i = *(int*)&x;
		i = 0x5f375a86 - (i>>1);
		x = *(float*)&i;
		x = x*(1.5f-xhalf*x*x);   
		x = x*(1.5f-xhalf*x*x);   
		x = x*(1.5f-xhalf*x*x);  

		return 1/x;
	}

private:
	int x_;
};


#endif