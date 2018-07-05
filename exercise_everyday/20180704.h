#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace day_20180704
{

class Solution
{
public:
	void test();
	string solution(int);
	// answer
	bool isPowerOf2(int num) {
		if (num <= 0)return false;
		return (num&(num - 1)) == 0;
	}
};

}