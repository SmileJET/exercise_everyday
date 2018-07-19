#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace day_20180719
{

	class Solution
	{
	private:
		struct node {
			int num;
			struct node* pre;
			struct node* next;
		};
		typedef struct node node;
	public:
		void test()
		{
			vector<int> input1 = { 1, 2, 3, 4, 5 };
			node* tree1;
			create_tree(input1, &tree1);
			display_tree(tree1);
			solution(tree1, 2);
			display_tree(tree1);

			vector<int> input2 = { 0, 1, 2 };
			node* tree2;
			create_tree(input2, &tree2);
			display_tree(tree2);
			solution(tree2, 4);
			display_tree(tree2);
		}

		void create_tree(vector<int> input, node** tree)
		{
			*tree = (node*)malloc(sizeof(node));
			node*p, *q = NULL;
			p = *tree;
			p->pre = NULL;
			p->next = NULL;
			for (int i = 0; i < input.size(); i++)
			{
				q = (node*)malloc(sizeof(node));
				q->num = input[i];
				q->next = NULL;
				q->pre = p;
				p->next = q;
				p = p->next;
			}
			(*tree)->next->pre = q;
			q->next = (*tree)->next;
		}

		void display_tree(node * tree)
		{
			node* p = tree->next;
			while(true)
			{
				cout << p->num;
				p = p->next;
				if (tree->next != p) { cout << " -> "; }
				else 
				{ 
					cout << " -> NULL";
					break;
				}
			}
			cout << endl;
		}

		void solution(node * tree, int k)
		{
			node* head = tree->next, *head_pre = tree, *p;
			for (int i = 0; i < k; i++)
			{
				tree->next = tree->next->pre;
			}
		}

		void answer()
		{

		}


	};

}