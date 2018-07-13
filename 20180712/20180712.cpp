
#include "stdafx.h"
#include "20180712.h"

using namespace day_20180712;

void Solution::test()
{
	vector<vector<int>> input = { { 0,0,1,1 },{ 1,0,1,0 },{ 1,1,0,0 } };
	solution(input);

	cout << "answer:" << endl;
	answer(input);
}

int Solution::solution(vector<vector<int>> input)
{
	cout << "input :" << endl;
	display_matrix(input);

	vector<vector<int>> row_tmp, col_tmp, pre, col_pre1, col_pre2;
	int cur_val, max_val = 0, max_val1, max_val2;

	pre = input;
	for (int i = 0; i < input.size(); i++)
	{
		row_tmp = pre;
		max_val1 = max_val;
		col_pre1 = row_tmp;
		cur_val = cal_mitrix(row_tmp);
		if (cur_val > max_val1)
		{
			max_val1 = cur_val;
			col_pre1 = row_tmp;
		}
		for (int j = 0; j < input[i].size(); j++)
		{
			col_tmp = col_pre1;
			move(col_tmp, false, j);
			cur_val = cal_mitrix(col_tmp);
			if (cur_val > max_val1)
			{
				max_val1 = cur_val;
				col_pre1 = col_tmp;
			}
		}

		move(row_tmp, true, i);

		max_val2 = max_val1;

		cur_val = cal_mitrix(row_tmp);
		if (cur_val > max_val2)
		{
			max_val2 = cur_val;
			col_pre2 = row_tmp;
		}
		col_pre2 = row_tmp;
		for (int j = 0; j < input[i].size(); j++)
		{
			col_tmp = col_pre2;
			move(col_tmp, false, j);
			cur_val = cal_mitrix(col_pre2);
			if (cur_val > max_val2)
			{
				max_val2 = cur_val;
				col_pre2 = col_tmp;
			}
		}
		if (max_val1 > max_val2)
		{
			pre = col_pre1;
			max_val = max_val1;
		}
		else
		{
			pre = col_pre2;
			max_val = max_val2;
		}
	}

	cout << "max:" << endl;
	display_matrix(pre);
	cout << "val:\t" << max_val << endl;

	return max_val;
}

void Solution::display_matrix(vector<vector<int>> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			cout << input[i][j] << "\t";
		}
		cout << endl;
	}
}

int Solution::cal_mitrix(vector<vector<int>> input)
{
	int sum = 0;
	for (int i = 0; i < input.size(); i++)
	{
		int base = 1;
		for (int j = input[i].size() - 1; j >= 0; j--)
		{
			sum += base * input[i][j];
			base *= 2;
		}
	}
	return sum;
}

/*
@input	input matrix
@is_row move row or col		false:col	true:row
@id		move rowid or colid
*/
void Solution::move(vector<vector<int>> &input, bool is_row, int id)
{
	if (is_row)
	{
		for (int i = 0; i < input[id].size(); i++)
		{
			input[id][i] = (input[id][i] + 1) % 2;
		}
	}
	else
	{
		for (int i = 0; i < input.size(); i++)
		{
			input[i][id] = (input[i][id] + 1) % 2;
		}
	}
}

// 答案
void Solution::answer(vector<vector<int>> A)
{
	cout << "res:" << matrixScore(A) << endl;
}

bool Solution::checkNeedTurn(vector<vector<int>> A, int i)
{
	bool retBoolean = false;
	int zeroCount = 0;

	for (int j = 0; j < A.size(); j++)
	{
		if (zeroCount > A.size() / 2)
		{
			retBoolean = true;
			return retBoolean;
		}
		if (A[j][i] == 0)
		{
			zeroCount++;
		}
	}
	if (zeroCount > A.size() / 2)
	{
		retBoolean = true;
	}
	return retBoolean;
}

int Solution::matrixScore(vector<vector<int>> A)
{
	int retData = 0;
	int count = A[0].size() - 1;

	// 先横向反转，然后再纵向反转
	for (int k = 0; k < A.size(); k++)
	{
		if (A[k][0] == 0)
		{
			for (int m = 0; m < A[0].size(); m++)
			{
				A[k][m] = (A[k][m] + 1) % 2;
			}
		}
	}

	// 竖向反转
	for (int i = 0; i < A[0].size(); i++)
	{
		if (!checkNeedTurn(A, i))
		{
			continue;
		}
		for (int j = 0; j < A.size(); j++)
		{
			A[j][i] = (A[j][i] + 1) % 2;
		}
	}

	retData = cal_mitrix(A);

	return retData;
}