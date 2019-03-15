#include "BinaryTreeNode.cpp"
#include "BST.cpp"
#include<iostream>
using namespace std;
//int num[100];

int main()
{
	/*
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	*/
	int n = 7;
	int num[7] = { 5,8,7,2,4,9,6 };
	BST<int> t;
	BinaryTreeNode<int> *root = t.CreateTree(num, n);
	t.Insert(root, 3);
	t.Delete(root, 5);
	t.PreOrder(root);
	cout << endl;
	t.InOrder(root);
	cout << endl;
	system("pause");
}