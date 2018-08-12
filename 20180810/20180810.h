#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180810
{

	class Solution
	{
	public:
		void test()
		{
			vector<int> input = { 4, 14, 2 };
			cout << "res:" << solution(input) << endl;
			vector<int> input1 = { 4, 142 };
			cout << "res:" << solution(input1) << endl;
			vector<int> input2 = { 4, 15, 136 };
			cout << "res:" << solution(input2) << endl;
			answer();
		}

		int solution(vector<int> input)
		{
			int output = 0;
			for (int i = 0; i < input.size() - 1; i++) {
				for (int j = i + 1; j < input.size(); j++) {
					int xor_val = input[i] ^ input[j];
					while (xor_val) {
						output += xor_val % 2;
						xor_val /= 2;
					}
				}
			}
			return output;
		}


		void answer()
		{
			vector<int> input = { 4, 14, 2 };
			cout << "res:" << totalHammingDistance(input) << endl;
			vector<int> input1 = { 4, 142 };
			cout << "res:" << totalHammingDistance(input1) << endl;
			vector<int> input2 = { 4, 15, 136 };
			cout << "res:" << totalHammingDistance(input2) << endl;
		}

		int totalHammingDistance(vector<int>& nums) {
			int cnt, ans = 0;
			for (int i = 0; i < 32; i++) {
				cnt = 0;
				for (int j = 0; j < nums.size(); j++) {
					if (nums[j] & 1) {
						cnt++;
					}
					nums[j] >>= 1;
				}
				ans += cnt * (nums.size() - cnt);
			}
			return ans;
		}
	};

}