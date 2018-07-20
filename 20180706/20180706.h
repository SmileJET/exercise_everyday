#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace day_20180706
{

	class Solution
	{
	public:
		
		void test()
		{
			int input1[] = { 10, 10, 10 };
			int input2[] = { 1, 2, 3, 5, 5, 6 };
			cout << "num:" << solution(input2, 6) << endl;
		}
		
		int solution(int input[], int size)
		{
			int tmp[1000], count = 0, pre = -1, sum = 0;
			bool is_repeat = false;
			for (int i = 0; i < size; i++)
			{
				if (pre == input[i]) { continue; }
				pre = input[i];
				for (int j = 0; j < count; j++)
				{
					if (tmp[j] == input[i])
					{
						is_repeat = true;
						break;
					}
				}
				if (!is_repeat)
				{
					tmp[count++] = input[i];
					is_repeat = false;
				}
			}
			for (int i = 0; i < count; i++)
			{
				sum += tmp[i] + 1;
			}
			return sum;
		}
	};

}
