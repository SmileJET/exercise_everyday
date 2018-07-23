#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180723
{
	class Solution
	{
	public:
		void test()
		{
			string input1 = "tree";
			string input2 = "cccaaa";
			string input3 = "Aabb";
			cout << "input:" << input1.c_str() << "\toutput:" << solution(input1).c_str() << endl;
			cout << "input:" << input2.c_str() << "\toutput:" << solution(input2).c_str() << endl;
			cout << "input:" << input3.c_str() << "\toutput:" << solution(input3).c_str() << endl;
		}

		string solution(string input)
		{
			string output;
			vector<pair<char, int>> record;
			bool is_in = false;
			for (int i = 0; i < input.length(); i++)
			{
				for(int j = 0; j<record.size();j++)
				{
					is_in = false;
					if (record[j].first == input[i])
					{
						is_in = true;
						record[j].second++;
					}
				}
				if (!is_in)
				{
					record.push_back(pair<char, int>(input[i], 1));
				}
			}
			sort(record.begin(), record.end(), [](pair<char, int> &a, pair<char, int> &b) {return a.second > b.second; });
			for (int i = 0; i < record.size(); i++)
			{
				for (int j = 0; j < record[i].second; j++)
				{
					output += record[i].first;
				}
			}
			return output;
		}
		

		void answer()
		{
			
		}

	};

}