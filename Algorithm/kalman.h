#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double frand()
{
	return 2 * ((rand() / (double)RAND_MAX) - 0.5);//�������(-1~1֮��)��rand()/RAND_MAXΪ0~1֮��
}

float kalmanFilter()
{
	float z_real = 0.56;                       // ʵ��ֵ��Ҫ������Ŀ�꣩
	float x_last = z_real + frand() * 0.03;    // ��ʼ����ֵ
	float p_last = 0.02;                       // ��ʼ����ֵ����, ̫С��Ӱ�������ٶ�
	float Q = 0.018;                           // ��˹��������
	float R = 0.542;                           // ���������Ӧ�����ľ���
	float kg = 0.0;                            // ����������                            
	float x_now;
	float p_cur;
	float p_now;
	float z_measure;                          // ÿһ�εĲ���ֵ, ��ϵͳ�������
	float summerror_kalman = 0;               // �����ۻ����
	float summerror_measure = 0;              // ����ֵ�ۻ����

	float x_cur = x_last;
	for (int i = 0; i < 1000; i++)
	{
		x_cur = x_last;          // ��һ������������ֵ
		p_cur = p_last + Q;      // ��һ������ֵ����������������ʵ�ʷ���

		// **���¿���������ϵ�����¹���ֵ�������¹���ֵ����Ӳ�������ı�ֵ�������������ܴ���Ȼ������ϵ����С�������¹���ֵʱ�����������ֵ��Ȩ�ؾ�Сһ��
		kg = p_cur / (p_cur + R);   // �Ѿ�+Q���� -- p_cur = p_last + Q

		// �µĲ���ֵ,ϵͳ�������
		z_measure = z_real + frand() * 0.03;

		// **�����µĹ���ֵ����x[i]=(1-kg)*x[i-1]+kg*z[i]���ɲ���ֵ����һ�ι���ֵ��ͬ������ι���ֵ����˭��һ���ɿ���������ϵ������������������ϵ������ÿһ�ֵ��·������
		x_now = x_cur + kg * (z_measure - x_cur);

		// **���¹���ֵ�Ĺ����ԭ����Ŀ��������ζ����
		p_now = (1 - kg) * p_cur;

		printf("��ʵֵ:%6.3f\n", z_real);
		printf("����ֵ:%6.3f [��ֵ������ֵ��:%.3f]\n", z_measure, fabs(z_real - z_measure));
		printf("������ֵ: %6.3f [��ֵ������ֵ��:%.3f]\n", x_now, fabs(z_real - x_now));
		printf("\n\n");
		summerror_kalman += fabs(z_real - x_now);      // ����������ۻ�
		summerror_measure += fabs(z_real - z_measure); // ��������ۻ�
		p_last = p_now;
		x_last = x_now;
	}

	printf("�����������ۻ�     :%f\n", summerror_measure);
	printf("���忨�����˲�����ۻ�:%f\n", summerror_kalman);
	printf("�����������ռ����(Խ��Խ�ÿ�):%d%%\n", 100 - (int)((summerror_kalman / summerror_measure) * 100));

	return x_now;
}

//void main()
//{
//	float ret = kalmanFilter();
//	printf("�������ֵΪ: %6.3f", ret);
//	getchar();
//}
