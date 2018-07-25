#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

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
			answer();
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
			cout << "answer:" << endl;
			string input1 = "owoztneoer";
			string input2 = "fviefuro";
			cout << "input:" << input1.c_str() << "\toutput:" << originalDigits(input1).c_str() << endl;
			cout << "input:" << input2.c_str() << "\toutput:" << originalDigits(input2).c_str() << endl;
		}

		string originalDigits(string s) {
			map<char, int> myMap{
				{'g', 8}, {'x',6},{'u',4},{'w',2},{'z',0},
			{'f',5},{'h',3},{'s',7},{'o',1},{'i',9}
			};
			vector<int> numbers(10, 0);
			string res;

			for (auto p : myMap) {
				numbers[p.second] = count(s.begin(), s.end(), p.first);
			}

			numbers[5] -= numbers[4];
			numbers[3] -= numbers[8];
			numbers[7] -= numbers[6];
			numbers[1] -= (numbers[0] + numbers[2] + numbers[4]);
			numbers[9] -= (numbers[5] + numbers[6] + numbers[8]);

			for (int i = 0; i < 10; i++) {
				while (numbers[i] > 0) {
					res += ('0' + i);
					numbers[i]--;
				}
			}

			return res;
		} 
	};

}