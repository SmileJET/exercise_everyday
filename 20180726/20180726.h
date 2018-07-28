#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

namespace day_20180726
{
	class Solution
	{
	public:
		void test()
		{
			answer();
		}

		void answer()
		{
			cout << "answer : " << endl;
			int n = 4, k = 13;
			cout << "n :" << n << "\tk:" << k << "\t" << getPermutation(n, k).c_str() << endl;
		}

		string getPermutation(int n, int k) {
			string res;
			string num = "123456789";
			vector<int> f(n, 1);
			for (int i = 1; i < n; ++i)f[i] = f[i - 1] * i;
			--k;
			for (int i = n; i >= 1; --i) {
				int j = k / f[i - 1];
				k %= f[i - 1];
				res.push_back(num[j]);
				num.erase(j, 1);
			}
			return res;
		}
	};

}