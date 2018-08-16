#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180816
{

	class Solution
	{
	private:
		typedef struct node{
			int val;
			struct node * next;
		}Node;
	public:
		void test()
		{
			vector<int> input_vec = { 1, 2, 3, 4 };
			Node* input;
			create_tree(input, input_vec);
			display_tree(input);
			solution(input);
			cout << "res:" << endl;
			display_tree(input);
		}

		void create_tree(Node* &head, vector<int> & vec) {
			head = (Node*)malloc(sizeof(Node));
			head->next = NULL;
			Node* p = head, *q;
			for (int i = 0; i < vec.size(); i++) {
				q = (Node*)malloc(sizeof(Node));
				q->val = vec[i];
				q->next = NULL;
				p->next = q;
				p = p->next;
			}
		}

		void display_tree(Node* head) {
			Node* p = head->next;
			while (p) {
				cout << p->val << " -> ";
				p = p->next;
			}
			cout << "NULL" << endl;
		}

		void solution(Node* &input)
		{
			Node* p = input, *q1 = NULL, *q2 = NULL;
			while (p) {
				if (p->next != NULL && p->next->next != NULL) {
					q1 = p->next;
					q2 = p->next->next;
					p->next = q2;
					q1->next = q2->next;
					q2->next = q1;
					p = q1;
				}
				else {
					p = p->next;
				}
			}
		}

		void answer()
		{

		}

	};

}