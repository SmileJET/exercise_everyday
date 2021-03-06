#pragma once
#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

namespace day_20180709
{

	class Solution
	{
	public:
		
		void test()
		{
			vector<vector<int>> input = { { 7, 0 },{ 4, 4 },{ 7, 1 },{ 5, 0 },{ 6, 1 },{ 5, 2 } };
			
			vector<vector<int>> res = solution(input);
			for (int i = 0; i < res.size(); i++)
			{
				cout << "i = " << i << "\t[0]:" << res[i][0] << "\t[1]:\t" << res[i][1] << endl;
			}

			cout << "answer:" << endl;
			answer();
		}

		vector<vector<int>> solution(vector<vector<int>> input)
		{
			vector<vector<int>> res;							// result vector
			int record[1100][2] = { 0 }, record_size = 0;		// find_table
			vector<int> tmp;									// temp vector

			srand((unsigned)time(NULL));
			int choose = 0, k = 0;
			bool is_repeat = false;
			for (int i = input.size(); i > 0; i--)
			{
				k = 0;
				choose = rand() % i;
				tmp = input[choose];
				is_repeat = false;
				int j = 0;
				for (; j < record_size; j++)
				{
					if (tmp[0]<=record[j][0])
					{
						k += record[j][1] + 1;
					}
					else if (tmp[0] == record[j][0])
					{
						is_repeat = true;
						k += record[j][1] + 1;
						record[j][1]++;
					}
				}
				if (!is_repeat) 
				{ 
					record[j][0] = tmp[0];
					record_size++;
				}
				tmp[1] = k;
				res.push_back(tmp);
				input.erase(input.begin() + choose);
			}

			return res;
		}

		void answer()
		{
			vector<pair<int, int>> input = { { 7, 0 },{ 4, 4 },{ 7, 1 },{ 5, 0 },{ 6, 1 },{ 5, 2 } };
			cout << "input:" << endl;
			display_pair(input);
			vector<pair<int, int>> res = reconstructQueue(input);
			cout << "result:" << endl;
			display_pair(res);
		}

		void display_pair(vector<pair<int, int>> input)
		{
			for (int i = 0; i < input.size(); i++)
			{
				cout << "first : " << input[i].first << "\tsecond : " << input[i].second << endl;
			}
		}

		vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>&people) {
			sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
				return a.first > b.first || (a.first == b.first && a.second < b.second);
			});
			vector<pair<int, int>> res(people.size());
			for (int i = 0; i < people.size(); i++)
			{
				res.insert(res.begin() + people[i].second, people[i]);
			}
			res.resize(people.size());
			return res;
		}
	};
}
