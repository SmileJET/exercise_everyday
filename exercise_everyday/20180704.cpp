#include "stdafx.h"
#include "20180704.h"

using namespace day_20180704;

void Solution::test()
{
	cout << "test 1:" << solution(1).c_str() << endl;
	cout << "test 1:" << solution(218).c_str() << endl;
}

string Solution::solution(int input)
{
	if (input <= 0) { return "false"; }
	int end = input / 2;
	int cur = 1;
	for (int i = 0; i <= end; i++)
	{
		if (cur > input)
		{
			return "false";
		}
		else if (cur == input)
		{
			return "true";
		}
		cur *= 2;
	}
}