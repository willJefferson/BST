#pragma once
#include<stdio.h>
template <class T>
class BinaryTreeNode
{

private:
	T info;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

public:
	BinaryTreeNode();
	BinaryTreeNode(const T&ele);
	BinaryTreeNode(const T&ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
	BinaryTreeNode<T> &operator =(const BinaryTreeNode<T>*copy);
	T value() const;
	BinaryTreeNode<T> *leftchild() const;
	BinaryTreeNode<T> *rightchild() const;
	void setLeftchild(BinaryTreeNode<T>*);
	void setRightchild(BinaryTreeNode<T>*);
	void setValue(const T&val);
	bool isLeaf() const;
	~BinaryTreeNode();
};