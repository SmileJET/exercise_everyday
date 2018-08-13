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

		}


	};

}