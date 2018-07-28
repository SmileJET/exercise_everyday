#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace day_20180727
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
			cout << "answer:" << endl;
			int target1 = 3;
			cout << "target : " << target1 << "\toutput : " << reachNumber(target1) << endl;
			int target2 = 2;
			cout << "target : " << target1 << "\toutput : " << reachNumber(target2) << endl;
		}

		int reachNumber(int target) {
			int t = abs(target), k = 0, s = 0;
			while (s < t) {
				k += 1;
				s += k;
			}
			int dt = s - t;
			if (dt % 2 == 0) {
				return k;
			} else {
				if (k % 2 == 0) {
					return k + 1;
				}
				else {
					return k + 2;
				}
			}
		}

	};

}