#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double frand()
{
	return 2 * ((rand() / (double)RAND_MAX) - 0.5);//随机噪声(-1~1之间)：rand()/RAND_MAX为0~1之间
}

float kalmanFilter()
{
	float z_real = 0.56;                       // 实际值（要测量的目标）
	float x_last = z_real + frand() * 0.03;    // 初始估计值
	float p_last = 0.02;                       // 初始估计值方差, 太小会影响收敛速度
	float Q = 0.018;                           // 高斯噪声方差
	float R = 0.542;                           // 测量方差，反应测量的精度
	float kg = 0.0;                            // 卡尔曼增益                            
	float x_now;
	float p_cur;
	float p_now;
	float z_measure;                          // 每一次的测量值, 由系统随机生成
	float summerror_kalman = 0;               // 测量累积误差
	float summerror_measure = 0;              // 估计值累积误差

	float x_cur = x_last;
	for (int i = 0; i < 1000; i++)
	{
		x_cur = x_last;          // 上一个卡尔曼估计值
		p_cur = p_last + Q;      // 上一个估计值方差加上噪声方差，即实际方差

		// **更新卡尔曼增益系数，新估计值方差与新估计值方差加测量方差的比值。如果测量方差很大，显然卡尔曼系数变小，计算新估计值时，分配给测量值的权重就小一点
		kg = p_cur / (p_cur + R);   // 已经+Q处理 -- p_cur = p_last + Q

		// 新的测量值,系统随机生成
		z_measure = z_real + frand() * 0.03;

		// **更新新的估计值，即x[i]=(1-kg)*x[i-1]+kg*z[i]，由测量值和上一次估计值共同决定这次估计值，信谁多一点由卡尔曼增益系数决定，卡尔曼增益系数又由每一轮的新方差决定
		x_now = x_cur + kg * (z_measure - x_cur);

		// **更新估计值的估方差，原方差的卡尔曼信任度算得
		p_now = (1 - kg) * p_cur;

		printf("真实值:%6.3f\n", z_real);
		printf("测量值:%6.3f [差值（绝对值）:%.3f]\n", z_measure, fabs(z_real - z_measure));
		printf("卡尔曼值: %6.3f [差值（绝对值）:%.3f]\n", x_now, fabs(z_real - x_now));
		printf("\n\n");
		summerror_kalman += fabs(z_real - x_now);      // 卡尔曼误差累积
		summerror_measure += fabs(z_real - z_measure); // 测量误差累积
		p_last = p_now;
		x_last = x_now;
	}

	printf("总体测量误差累积     :%f\n", summerror_measure);
	printf("总体卡尔曼滤波误差累积:%f\n", summerror_kalman);
	printf("卡尔曼误差所占比例(越大越好咯):%d%%\n", 100 - (int)((summerror_kalman / summerror_measure) * 100));

	return x_now;
}

//void main()
//{
//	float ret = kalmanFilter();
//	printf("最终输出值为: %6.3f", ret);
//	getchar();
//}
