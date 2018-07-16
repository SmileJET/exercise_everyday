#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

namespace day_20180716
{

	class Solution
	{
	public:
		void test()
		{
			vector<string> dict = { "cat", "bat", "rat" };
			string input = "the cattle was rattled by the battery";
			cout << input.c_str() << endl;
			string res = solution(dict, input);
			cout << "result:" << res << endl;
		}

		string solution(vector<string> dict, string input)
		{
			stringstream res, word;
			// sort the dict
			sort(dict.begin(), dict.end());

			for (int i = 0;; i++)
			{
				if (i == input.length() - 1)
				{
					res << replace_word(dict, word.str());
					break;
				}
				if (input[i] == ' ')
				{
					res << replace_word(dict, word.str()) << " ";
					word.str("");
				}
				else
				{
					word << input[i];
				}
			}
			return res.str();
		}

		string replace_word(vector<string> dict, string word)
		{
			for (int i = 0; i < dict.size(); i++)
			{
				if (strncmp(dict[i].c_str(), word.c_str(), dict[i].length()) == 0)
				{
					return dict[i];
				}
			}
			return word;
		}

		void answer()
		{
		
		}

	};

}