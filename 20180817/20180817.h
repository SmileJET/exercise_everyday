#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180817
{

	class Solution
	{
	public:
		void test()
		{
			vector<int> nums = { 1, 1, 1, 1, 1 };
			int s = 3;
			cout << "res:" << solution(nums, s) << endl;;
		}

		int solution(vector<int> &nums, int &s)
		{
			int output = 0, max_val = pow(2, nums.size());
			int sign[2] = { 1, -1 };
			vector<int> vec;
			for (int i = 0; i < max_val; i++) {
				int tmp = 0, j = 0;
				to_binary(i, vec);
				for (; j < vec.size(); j++) {
					tmp += sign[vec[j]] * nums[j];
				}
				for (; j < nums.size(); j++) {
					tmp += nums[j];
				}
				if (tmp == s) { output += 1; }
			}
			
			return output;
		}
		
		void to_binary(int num, vector<int> &vec) {
			vec.clear();
			while (num) {
				vec.push_back(num % 2);
				num /= 2;
			}
		}

		void answer()
		{

		}

	};

}