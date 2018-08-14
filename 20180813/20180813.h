#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180813
{

	class Solution
	{
	public:
		void test()
		{
			vector<vector<int>> input = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
			cout << "res:" << solution(input) << endl;
			answer();
		}

		int solution(vector<vector<int>> &input)
		{
			int *min_val = (int*)malloc(sizeof(int)*input.size());
			memset(min_val, 0, sizeof(int)*input.size());
			for (int i = 0; i < input.size(); i++) { min_val[input.size() - 1] += input[i][0]; }
			find_min(input, min_val, 1);
			return min_val[input.size()-1];
		}

		void find_min(vector<vector<int>> &input, int* min_val, int i) {
			if (i == input.size()-1) {
				int cur = 0;
				for (int j = 0; j < input.size()-1; j++) {
					cur += input[j][min_val[j]];
				}
				cur += input[input.size()-1][min_val[input.size()-2]] < input[input.size()-1][min_val[input.size()-2] + 1] ? 
							input[input.size()-1][min_val[input.size()-2]] : input[input.size()-1][min_val[input.size()-2] + 1];
				min_val[input.size() - 1] = min_val[input.size() - 1] < cur ? min_val[input.size() - 1] : cur;
				return;
			}
			min_val[i] = min_val[i-1]+0;
			find_min(input, min_val, i+1);
			min_val[i] = min_val[i-1]+1;
			find_min(input, min_val, i + 1);
		}


		void answer()
		{
			cout << "answer:" << endl;
			vector<vector<int>> input = { { 2 },{ 3, 4 },{ 6, 5, 7 },{ 4, 1, 8, 3 } };
			cout << "res:" << minimumTotal(input) << endl;
		}

		int minimumTotal(vector<vector<int>> &triangle) {
			if (triangle.size() == 0) { return 0; }
			vector<int> *prev = NULL;
			int prevLastIndex = 0;
			for (int j = 0; j < triangle.size(); j++) {
				// 如果用数组就反过来更新
				for (int i = 0; i < triangle[j].size(); i++) {
					if (prev == NULL) { break; }
					// 获取上一层最大的数值
					triangle[j][i] = triangle[j][i] + min(prev->at(i - 1 < 0 ? i : i - 1), prev->at(i > prevLastIndex ? prevLastIndex : i));
				}
				prev = &triangle[j];
				prevLastIndex = prev->size() - 1;
			}

			int result = INT_MAX;

			for (int i = 0; i < prev->size(); i++) {
				result = result < prev->at(i) ? result : prev->at(i);
			}

			return result;
		}

	};

}