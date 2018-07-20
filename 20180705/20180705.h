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
		//被除数不能为0
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
		//异或结果 + 与运算结果左移一位
		*/
	}

	int subtraction(int a, int b)
	{
		//加上被减数的相反数
		return add(a, negtive(b));
	}

	//取出符号位
	int getSign(int n)
	{
		return n >> 31;
	}

	//求n的相反数
	//~：按位取反
	//add：加法操作，末位加一
	int negtive(int n)
	{
		return add(~n, 1);
	}

	//求n的绝对值
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
		// 记录最终结果是正还是负
		isPositive = ((dividend < 0) && (divisor < 0)) || (dividend > 0) && (divisor > 0);
		// 将两个数都变成正数
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
