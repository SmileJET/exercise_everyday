#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180809
{

	class Solution
	{
	public:
		void test()
		{
			vector<int> input_vec1 = {1, 4};
			int t1 = 2;
			cout << "res:" << solution(input_vec1, t1) << endl;
			vector<int> input_vec2 = { 1, 2 };
			int t2 = 2;
			cout << "res:" << solution(input_vec2, t2) << endl;
			vector<int> input_vec3 = { 3, 5, 9, 13, 19, 35, 44, 52, 68, 79 };
			int t3 = 10;
			cout << "res:" << solution(input_vec3, t3) << endl;
			answer();
		}

		int solution(vector<int> vec, int t)
		{
			if (vec.size() <= 0) {
				return 0;
			}
			int output = 0, start = vec[0], end = start + t;
			for (int i = 1; i < vec.size(); i++) {
				if (end >= vec[i]) {
					end = vec[i] + t;
				}
				else {
					output += end - start;
					start = vec[i];
					end = start + t;
				}
			}
			output += end - start;
			return output;
		}


		void answer()
		{
			cout << "answer:" << endl;
			vector<int> input_vec1 = { 1, 4 };
			int t1 = 2;
			cout << "res:" << findPoisonedDuration(input_vec1, t1) << endl;
			vector<int> input_vec2 = { 1, 2 };
			int t2 = 2;
			cout << "res:" << findPoisonedDuration(input_vec2, t2) << endl;
			vector<int> input_vec3 = { 3, 5, 9, 13, 19, 35, 44, 52, 68, 79 };
			int t3 = 10;
			cout << "res:" << findPoisonedDuration(input_vec3, t3) << endl;
		}

		int findPoisonedDuration(vector<int>& timeSeries, int duration) {
			int cnt = 0;
			if (timeSeries.size() == 0) {
				return cnt;
			}
			for (int i = 0; i < (int)timeSeries.size() - 1; i++) {
				for (int k = 0; k < duration; k++) {
					if ((timeSeries[i] + k) != timeSeries[i + 1]) {
						cnt++;
					}
					else {
						break;
					}
				}
			}
			return cnt + duration;
		}
	};

}