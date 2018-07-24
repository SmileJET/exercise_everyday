#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

namespace day_20180724
{
	class Solution
	{
	public:
		void test()
		{
			string input1 = "owoztneoer";
			string input2 = "fviefuro";
			cout << "input:" << input1.c_str() << "\toutput:" << solution(input1).c_str() << endl;
			cout << "input:" << input2.c_str() << "\toutput:" << solution(input2).c_str() << endl;
		}

		string solution(string input)
		{
			int count[26] = { 0 };
			string output("");
			vector<string> words = { "zero", "one", "two", "three","four", "five", "six", "seven", "eight", "nine" };
			for (int i = 0; i < input.size(); i++) {
				count[input[i] - 'a']++;
			}
			
			for (int i = 0; i < words.size(); i++) {
				int tmp = count[words[i][0] - 'a'];
				for (int j = 1; j < words[i].size(); j++) {
					if (count[words[i][j] - 'a'] < tmp) {
						tmp = count[words[i][j] - 'a'];
					}
				}
				if (tmp != 0) {
					output.append(tmp, '0' + i);
					for (int j = 1; j < words[i].size(); j++) {
						count[words[i][j] - 'a'] -= tmp;
					}
				}
			}

			return output;
		}


		void answer()
		{

		}
	};

}