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
		void test();

		int solution(vector<vector<int>> input);

		void display_matrix(vector<vector<int>> input);

		int cal_mitrix(vector<vector<int>> input);

		/*
			@input	input matrix
			@is_row move row or col		false:col	true:row
			@id		move rowid or colid
		*/
		void move(vector<vector<int>> &input, bool is_row, int id);

		// ´ð°¸
		void answer(vector<vector<int>> A);

		bool checkNeedTurn(vector<vector<int>> A, int i);

		int matrixScore(vector<vector<int>> A);
	};
}