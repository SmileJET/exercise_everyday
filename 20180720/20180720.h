#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180720
{
	class Solution
	{
	public:
		void test()
		{
			vector<int> input = { 2, 0, 2, 1, 1, 0 };
			vector<int> output = solution(input);
			for (int i = 0; i < output.size(); i++)
			{
				cout << output[i] << "\t";
			}
		}


		vector<int> solution(vector<int> input)
		{
			qsort(input, 0, input.size() - 1);
			return input;
		}

		void qsort(vector<int>& input, int head, int tail)
		{
			int i = head, j = tail;
			if (head >= tail) { return; }
			int tmp = input[head];
			while (head < tail)
			{
				if (input[tail] <= tmp && head < tail)
				{
					input[head++] = input[tail];
					input[tail] = input[head];
				}
				if (input[head] >= tmp && head < tail)
				{
					input[tail--] = input[head];
					input[head] = input[tail];
				}
			}
			input[head] = tmp;
			qsort(input, i, head-1);
			qsort(input, head+1, j);
		}

		void answer()
		{
		
		}

	
	};

}