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

		struct ListNode {
			int val;
			struct ListNode* next;
		};
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

			answer();
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

		void create_tree(vector<int> input, ListNode** tree)
		{
			*tree = (ListNode*)malloc(sizeof(ListNode));
			ListNode*p, *q = NULL;
			p = *tree;
			p->next = NULL;
			for (int i = 0; i < input.size(); i++)
			{
				q = (ListNode*)malloc(sizeof(ListNode));
				q->val = input[i];
				q->next = NULL;
				p->next = q;
				p = p->next;
			}
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

		void display_tree(ListNode* tree)
		{
			ListNode* p = tree->next;
			while (true)
			{
				cout << p->val;
				p = p->next;
				if (p != NULL) { cout << " -> "; }
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
			cout << "answer:" << endl;
			vector<int> input1 = { 1, 2, 3, 4, 5 };
			ListNode* tree1;
			create_tree(input1, &tree1);
			display_tree(tree1);
			rotateRight(tree1, 2);
			display_tree(tree1);

			vector<int> input2 = { 0, 1, 2 };
			ListNode* tree2;
			create_tree(input2, &tree2);
			display_tree(tree2);
			rotateRight(tree2, 4);
			display_tree(tree2);
		}

		void rotateRight(ListNode * head, int k)
		{
			if (k < 0)
			{
				return;
			}
			if (k == 0 || head == NULL || head->next == NULL)
			{
				return;
			}
			int size = this->size(head);
			k = k % size;
			k = size - k;
			ListNode* kNode = head->next;
			while (k > 1)
			{
				k--;
				kNode = kNode->next;
			}
			ListNode* lastNode = kNode;
			while (lastNode->next)// 找到最后一个节点
			{
				lastNode = lastNode->next;
			}

			lastNode->next = head->next;// 最后一个节点连接到头结点
			head->next = kNode->next;// 新的头结点是k+1节点
			kNode->next = NULL;// 第k个节点后断开
		}

		int size(ListNode* head)
		{
			ListNode* p = head->next;
			int size = 0;
			while (p)
			{
				p = p->next;
				size++;
			}
			return size;
		}
	};

}