#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180717
{

	class Solution
	{
	public:
		void test()
		{
			int input = 16, output;
			cout << "input:" << input << "\toutput:" << solution(input) << endl;
			input = 10;
			cout << "input:" << input << "\toutput:" << solution(input) << endl;
			input = 1;
			cout << "input:" << input << "\toutput:" << solution(input) << endl;
		}

		bool solution(int num)
		{
			vector<int> list;
			while (num)
			{
				list.push_back(num % 10);
				num /= 10;
			}
			sort(list.begin(), list.end());
			do
			{
				if (list[0] == 0) { continue; }
				int new_num = 0;
				for (int i = 0; i < list.size(); i++)
				{
					new_num = new_num * 10 + list[i];
				}
				cout << "new num:" << new_num << endl;
				if (is_power_of_2(new_num)) { return true; }
			} while (next_permutation(list.begin(), list.end()));
			
			return false;
		}

		bool is_power_of_2(int num)
		{
			if (num <= 0)return false;
			return (num&(num - 1)) == 0;
		}

		void answer()
		{
			
		}

		
	};

}