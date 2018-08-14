#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

namespace day_20180814
{

	class Solution
	{
	public:
		void test()
		{
			vector<int> input1 = {1, 1, 1, 2, 2, 3};
			int k1 = 2;
			vector<int> output1 = solution(input1, k1);
			cout << "res1:" << endl;
			for (int i = 0; i < output1.size(); i++) {
				cout << output1[i] << "\t";
			}
			cout << endl;

			vector<int> input2 = { 1 };
			int k2 = 1;
			vector<int> output2 = solution(input2, k2);
			cout << "res2:" << endl;
			for (int i = 0; i < output2.size(); i++) {
				cout << output2[i] << "\t";
			}
			cout << endl;
		}

		vector<int> solution(vector<int> &nums, int k)
		{
			if (nums.size() == 1) {
				return { nums[0] };
			}
			map<int, int> index;
			vector<pair<int, int>> bank;
			for (int i = 0; i < nums.size(); i++) {
				if (index.find(nums[i]) == index.end()) {
					index.insert(pair<int, int>(nums[i], bank.size()));
					bank.push_back(pair<int, int>(nums[i], 1));
				}
				else {
					bank[index[nums[i]]].second += 1;
				}
			}
			qsort(bank, 0, bank.size() - 1);
			vector<int> output;
			for (int i = 0; i < k; i++) {
				output.push_back(bank[i].first);
			}

			return output;
		}

		void qsort(vector < pair<int, int>> &nums, int low, int high) {
			if (low < high) {
				int q = _qsort(nums, low, high);
				qsort(nums, low, q - 1);
				qsort(nums, q + 1, high);
			}
		}

		int _qsort(vector<pair<int, int>> &nums, int low, int high) {
			int cur_index = high,i = low-1;
			pair<int, int> cur = nums[cur_index], temp;
			for (int j = low; j < high; j++) {
				if (nums[j].second > cur.second) {
					i++;
					temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}

			nums[high] = nums[i + 1];
			nums[i + 1] = cur;
			return i + 1;
			
		}

		void answer()
		{
			
		}

	};

}