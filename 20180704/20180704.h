#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace day_20180704
{

class Solution
{
public:
	void test()
	{
		cout << "test 1:" << solution(1).c_str() << endl;
		cout << "test 1:" << solution(218).c_str() << endl;
	}
	
	string solution(int input)
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
	
	// answer
	bool isPowerOf2(int num) {
		if (num <= 0)return false;
		return (num&(num - 1)) == 0;
	}
};

}
