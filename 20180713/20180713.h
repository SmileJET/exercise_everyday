#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180713
{

	class Solution
	{
	public:
		void test()
		{
			vector<int> input1 = { 1, 2, 2, 4 };
			vector<int> input2 = { 1, 2, 3, 4, 5, 3, 7, 8 };
			int* res;
			display(input1);
			res = solution(input1);
			cout << "result : " << res[0] << "\t" << res[1] << endl;
			display(input2);
			res = solution(input2);
			cout << "result : " << res[0] << "\t" << res[1] << endl;
			answer(input1);
			answer(input2);
		}

		int* solution(vector<int> input)
		{
			int res[] = { 0, 0 };
			for (int i = 0; i < input.size() - 1; i++)
			{
				if (input[i] == input[i + 1])
				{
					res[0] = input[i];
					res[1] = input[i] + 1;
					break;
				}
				if (input[i] + 1 != input[i + 1])
				{
					res[0] = input[i];
					res[1] = input[i + 1] - 1;
				}
			}
			return res;
		}

		void display(vector<int> & input)
		{
			for (int i = 0; i < input.size(); i++)
			{
				cout << input[i] << "\t";
			}
			cout << endl;
		}

		void answer(vector<int>& input)
		{
			cout << "answer:" << endl;
			display(input);
			vector<int> res = findRepeat(input);
			cout << "res:" << res[0] << "\t" << res[1] << endl;
		}

		vector<int> findRepeat (vector<int>& nums)
		{
			vector<int> res(2);
			vector<int> newnums(nums.size() + 1);
			for (int i = 0; i < nums.size(); i++)
			{
				newnums[nums[i]]++;
				if (newnums[nums[i]] == 2)res[0] = nums[i];//重复的数
			}
			//找缺少的那个数
			for (int i = 1; i <= nums.size(); i++)
			{
				if (newnums[i] == 0)
				{
					res[1] = i;
					break;
				}
			}
			return res;
		}
	};

}