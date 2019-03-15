#pragma once
#include "BinaryTreeNode.h"
#define STACK_MAX_SIZE 50
#define QUEUE_MAX_SIZE 50
template <class T>
class BST
{
private:
	BinaryTreeNode<T> *root;
	bool isLeaf(BinaryTreeNode<T>*current)const;
	
public:
	BST();
	BST(BinaryTreeNode<T> *r);
	BinaryTreeNode<T> *getRoot();
	void setRoot(BinaryTreeNode<T> *current);
	BinaryTreeNode<T>* CreateTree(T *data, int n);
	bool isEmpty()const;
	BinaryTreeNode<T>* getMin(BinaryTreeNode<T>* current);
	BinaryTreeNode<T>* getMax(BinaryTreeNode<T>* current);
	BinaryTreeNode<T> *Find(BinaryTreeNode<T> *root, const T& key);
	void Insert(BinaryTreeNode<T>* &root, const T &key);
	void Delete(BinaryTreeNode<T>* &root, const T &key);
	void PreOrder(BinaryTreeNode<T>*root);
	void InOrder(BinaryTreeNode<T>*root);
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* current);
	void DeleteBinaryTree(BinaryTreeNode<T>* root);
	~BST();
};

