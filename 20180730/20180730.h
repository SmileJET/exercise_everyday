#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_20180730
{

	class Solution
	{
	private:
		typedef struct node {
			int val;
			struct node * next;
		} node;
	public:
		void test()
		{
			vector<int> list = { 1, 4, 3, 2, 5, 2 };
			int x = 3;
			node* tree = (node*)malloc(sizeof(node));
			tree->next = NULL;
			node *p = tree, *q;
			for (int i = 0; i < list.size(); i++) {
				q = (node*)malloc(sizeof(node));
				q->next = NULL;
				q->val = list[i];
				p->next = q;
				p = p->next;
			}
			solution(tree, x);
			p = tree->next;
			while (p)
			{
				cout << p->val << " -> ";
				p = p->next;
			}
			cout << "NULL";
		}

		void solution(node *tree, int x)
		{
			node *head = (node*)malloc(sizeof(node)), *tail = (node*)malloc(sizeof(node));
			node *p = tree->next, *q1=head, *q2 = tail;
			head->next = NULL;
			tail->next = NULL;
			while (p) {
				if (p->val < x) {
					q1->next = p;
					p = p->next;
					q1 = q1->next;
					q1->next = NULL;
				}
				else {
					q2->next = p;
					p = p->next;
					q2 = q2->next;
					q2->next = NULL;
				}
			}
			tree->next = head->next;
			q1->next = tail->next;
		}

		
		void answer()
		{

		}


	};

}