#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180712
{

	class Solution
	{
	public:
		void test()
		{
			vector<vector<int>> input = { { 0,0,1,1 },{ 1,0,1,0 },{ 1,1,0,0 } };
			solution(input);
		}

		int solution(vector<vector<int>> input)
		{
			cout << "input :" << endl;
			display_matrix(input);

			vector<vector<int>> row_tmp, col_tmp, pre, col_pre1, col_pre2;
			int cur_val, max_val = 0, max_val1, max_val2;

			pre = input;
			for (int i = 0; i < input.size(); i++)
			{
				row_tmp = pre;
				max_val1 = max_val;
				col_pre1 = row_tmp;
				cur_val = cal_mitrix(row_tmp);
				if (cur_val > max_val1)
				{
					max_val1 = cur_val;
					col_pre1 = row_tmp;
				}
				for (int j = 0; j < input[i].size(); j++)
				{
					col_tmp = col_pre1;
					move(col_tmp, false, j);
					cur_val = cal_mitrix(col_tmp);
					if (cur_val > max_val1)
					{
						max_val1 = cur_val;
						col_pre1 = col_tmp;
					}
				}

				move(row_tmp, true, i);

				max_val2 = max_val1;

				cur_val = cal_mitrix(row_tmp);
				if (cur_val > max_val2)
				{
					max_val2 = cur_val;
					col_pre2 = row_tmp;
				}
				col_pre2 = row_tmp;
				for (int j = 0; j < input[i].size(); j++)
				{
					col_tmp = col_pre2;
					move(col_tmp, false, j);
					cur_val = cal_mitrix(col_pre2);
					if (cur_val > max_val2)
					{
						max_val2 = cur_val;
						col_pre2 = col_tmp;
					}
				}
				if (max_val1 > max_val2)
				{
					pre = col_pre1;
					max_val = max_val1;
				}
				else
				{
					pre = col_pre2;
					max_val = max_val2;
				}
			}

			cout << "max:" << endl;
			display_matrix(pre);
			cout << "val:\t" << max_val << endl;

			return max_val;
		}

		void display_matrix(vector<vector<int>> input)
		{
			for (int i = 0; i < input.size(); i++)
			{
				for (int j = 0; j < input[i].size(); j++)
				{
					cout << input[i][j] << "\t";
				}
				cout << endl;
			}
		}

		int cal_mitrix(vector<vector<int>> input)
		{
			int sum = 0;
			for (int i = 0; i < input.size(); i++)
			{
				int base = 1;
				for (int j = input[i].size() - 1; j >= 0; j--)
				{
					sum += base * input[i][j];
					base *= 2;
				}
			}
			return sum;
		}

		/*
			@input	input matrix
			@is_row move row or col		false:col	true:row
			@id		move rowid or colid
		*/
		void move(vector<vector<int>> &input, bool is_row, int id)
		{
			if (is_row)
			{
				for (int i = 0; i < input[id].size(); i++)
				{
					input[id][i] = (input[id][i] + 1) % 2;
				}
			}
			else
			{
				for (int i = 0; i < input.size(); i++)
				{
					input[i][id] = (input[i][id] + 1) % 2;
				}
			}
		}

		void answer()
		{

		}

	};
}