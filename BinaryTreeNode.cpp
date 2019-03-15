#include "BinaryTreeNode.h"
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	left = NULL;
	right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele)
{
	info = ele;
	left = NULL;
	right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r)
{
	info = ele;
	left = l;
	right = r;

}

template<class T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T>* copy)
{
	info = copy->info;
	left = copy->left;
	right = copy->right;
	// TODO: 在此处插入 return 语句
}

template<class T>
T BinaryTreeNode<T>::value()const
{
	return info;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::leftchild() const
{
	if (left != NULL)
		return left;
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::rightchild() const
{
	if (right != NULL)
		return right;
	return NULL;
}

template<class T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>*l)
{
	left = l;
}

template<class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>*r)
{
	right = r;
}

template<class T>
void BinaryTreeNode<T>::setValue(const T & val)
{
	info = val;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf() const
{
	if (left == NULL && right == NULL)
		return true;
	return false;
}

template<class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
}
