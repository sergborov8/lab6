// TemplateTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include <iostream>

using namespace std;

template <class Tree>
class priority_queue
{
	Tree *tree;
	int length;
public:
	priority_queue(Tree n) : length(0)
	{
		tree = new Tree[n];
	}
	void get()
	{
		cout << tree[0] << endl;
	}
	void add(Tree value);
	void del();
	void print()
	{
		for (int i = 0; i < length; i++)
		{
			cout << tree[i] << " ";
		}
		cout << endl;
	}
	~priority_queue()
	{
		if (tree)
			delete[] tree;
	}
};

template <class Tree>
void priority_queue <Tree>::add(Tree value)
{
	int node_num = length;
	tree[node_num] = value;
	int parent_index = (node_num - 1) / 2;
	while (tree[parent_index] > value && node_num != 0)
	{
		tree[node_num] = tree[parent_index];
		tree[parent_index] = value;
		node_num = parent_index;
		parent_index = (node_num - 1) / 2;
	}
	length += 1;
	print();
}

template <class Tree>
void priority_queue <Tree>::del()
{
	int node_num = 0;
	int left = 1, right = 2, value = tree[length - 1];
	tree[node_num] = tree[length - 1];
	length--;
	while (node_num <= length - 1 && value > tree[left] && value > tree[right])
	{
		int index;
		if (tree[left] > tree[right])
			index = right;
		else
			index = left;
		tree[node_num] = tree[index];
		tree[index] = value;
		node_num = index;
		left = node_num * 2 + 1;
		right = node_num * 2 + 2;
	}
	print();
}

template <class Tree>
void Add(priority_queue <Tree> &pr)
{
	Tree value;
	cin >> value;
	pr.add(value);
}

int main()
{
	int n;
	string cmd;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество чисел: ";
	cin >> n;
	priority_queue <int> pr(n);
	//priority_queue pq(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			Add <int>(pr);
		}
	}
back:cin >> cmd;
	if (cmd == "del")
		pr.del();
	if (cmd == "get")
		pr.get();
	if (cmd == "exit")
		return 0;
	goto back;
	system("pause");
}