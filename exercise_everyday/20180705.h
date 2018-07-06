#pragma once

// https://blog.csdn.net/sinat_35261315/article/details/72904945

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace day_20180705{

class Solution
{
public:

	void test()
	{
		cout << "10 / 3 = " << solution(10, 3) << endl;
		cout << "7 / (-3) = " << solution(7, -3) << endl;

		answer();
	}

	int solution(int32_t dividend, int32_t divisor)
	{
		//����������Ϊ0
		if (divisor == 0)
			throw std::runtime_error("Divided can't be zero...");

		bool isNegtive = false;
		if (getSign(dividend) ^ getSign(divisor))
			isNegtive = true;

		dividend = positive(dividend);
		divisor = positive(divisor);

		int res = 0;
		while (dividend >= divisor)
		{
			res = add(res, 1);
			dividend = subtraction(dividend, divisor);
		}

		return isNegtive == true ? negtive(res) : res;
	}

	int add(int a, int b)
	{
		return (b == 0) ? a : add(a ^ b, (a & b) << 1);
		/*
		if(b == 0)
		return a;
		else
		return add(a ^ b, (a & b) << 1);
		//����� + ������������һλ
		*/
	}

	int subtraction(int a, int b)
	{
		//���ϱ��������෴��
		return add(a, negtive(b));
	}

	//ȡ������λ
	int getSign(int n)
	{
		return n >> 31;
	}

	//��n���෴��
	//~����λȡ��
	//add���ӷ�������ĩλ��һ
	int negtive(int n)
	{
		return add(~n, 1);
	}

	//��n�ľ���ֵ
	int positive(int n)
	{
		return (getSign(n) & 1) ? negtive(n) : n;
	}

	void answer() {
		cout << "answer:" << endl;
		cout << "10 / 3 = " << divide(10, 3) << endl;
	}
	int divide(int dividend, int divisor) {
		long res = divideLong(dividend, divisor);
		if (res > INT_MAX)return INT_MAX;
		else if (res < INT_MIN) return INT_MIN;
		else return res;
	}
	long divideLong(long dividend, long divisor) {
		bool isPositive;
		// ��¼���ս���������Ǹ�
		isPositive = ((dividend < 0) && (divisor < 0)) || (dividend > 0) && (divisor > 0);
		// �����������������
		dividend = abs(dividend);
		divisor = abs(divisor);
		long count, tmp;
		long res = 0;
		while (dividend >= divisor) {
			count = 1;
			tmp = divisor;
			while (tmp <= dividend) {
				tmp <<= 1;
				count <<= 1;
			}
			res += count >> 1;
			dividend -= (tmp >> 1);
		}
		if (isPositive)return res;
		else return -res;
	}
};
}