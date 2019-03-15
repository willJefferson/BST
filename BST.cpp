#include "BST.h"

template<class T>
BinaryTreeNode<T>* BST<T>::getMin(BinaryTreeNode<T>* current)
{
	if (current->leftchild())
		return getMin(current->leftchild());
	else
	{
		BinaryTreeNode<T>*temp = current;
		current = current->rightchild();
		return temp;
	}
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BST<T>::getMax(BinaryTreeNode<T>* current)
{
	if (current)
	{
		while (current->rightchild())
			current = current->rightchild();
		return current;
	}
	return NULL;
}

template<class T>
BST<T>::BST()
{
	root = NULL;
}

template<class T>
BST<T>::BST(BinaryTreeNode<T>* r)
{
	root = r;
}

template<class T>
BinaryTreeNode<T>* BST<T>::getRoot()
{
	if (root)
		return root;
	return NULL;
}

template<class T>
void BST<T>::setRoot(BinaryTreeNode<T>* current)
{
	root = current;
}

template<class T>
BinaryTreeNode<T>* BST<T>::CreateTree(T *data, int n)
{
	BinaryTreeNode<T> *root = NULL;
	if (n == 0)
		return NULL;
	else
	{
		for (int i = 0; i < n; ++i)
			Insert(root, data[i]);
	}
	return root;
}

template<class T>
bool BST<T>::isEmpty() const
{
	return root == NULL;
}

template<class T>
BinaryTreeNode<T>* BST<T>::Find(BinaryTreeNode<T>* root, const T & key)
{
	if (root == NULL)
		return NULL;
	if (key == root->value())
		return root;
	else if (key < root->value())
		return Find(root->leftchild(), key);
	else
		return Find(root->rightchild(), key);
}

template<class T>
void BST<T>::Insert(BinaryTreeNode<T>* &root, const T &key)
{
	if (root == NULL)
	{
		root = new BinaryTreeNode<T>(key);
		return;
	}
	BinaryTreeNode<T>*temp = new BinaryTreeNode<T>(key);
	BinaryTreeNode<T>*s = root;
	while (s)
	{
		if (s->value() > key)
		{
			if (s->leftchild())
				s = s->leftchild();
			else
			{
				s->setLeftchild(temp);
				return;
			}
		}
		else if (s->value() < key)
		{
			if (s->rightchild())
				s = s->rightchild();
			else
			{
				s->setRightchild(temp);
				return;
			}
		}
		else
		{
			delete temp;
			return;
		}
			
	}
}

template<class T>
void BST<T>::Delete(BinaryTreeNode<T>* &root, const T &key)
{
	BinaryTreeNode<T>* pDel = Find(root, key);
	if (root == NULL||pDel==NULL)
		return;
	BinaryTreeNode<T>* t = root;
	BinaryTreeNode<T>* parent = Parent(root, pDel);
	if (pDel->leftchild() == NULL && pDel->rightchild() == NULL)//叶节点
	{
		if (root == pDel)//根节点
		{
			delete t;
			root = NULL;
			return;
		}
		if (parent->leftchild() == pDel)
			parent->setLeftchild(NULL);
		else
			parent->setRightchild(NULL);
		delete pDel;
		return;
	}
	else if (pDel->leftchild() != NULL && pDel->rightchild() == NULL)//右节点为空，直接左节点代替
	{
		if (root == pDel)
		{
			root = pDel->leftchild();
			delete pDel;
			return;
		}
		if (parent->leftchild() == pDel)
			parent->setLeftchild(pDel->leftchild());
		else
			parent->setRightchild(pDel->leftchild());
		delete pDel;
		return;
	}
	else if (pDel->leftchild()==NULL&&pDel->rightchild()!=NULL)//左节点为空，直接右节点代替
	{
		if (root == pDel)
		{
			root = pDel->rightchild();
			delete pDel;
			return;
		}
		if (parent->leftchild() == pDel)
			parent->setLeftchild(pDel->rightchild());
		else
			parent->setRightchild(pDel->rightchild());
		delete pDel;
		return;
	}
	else
	{
		BinaryTreeNode<T>* minRight = getMin(pDel->rightchild());
		pDel->setValue(minRight->value());
		parent = Parent(root, minRight);
		if (minRight == pDel->rightchild())
			parent->setRightchild(minRight->rightchild());
		else
			parent->setLeftchild(minRight->rightchild());
		delete minRight;
	}
}

template<class T>
void BST<T>::PreOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	std::cout << root->value() << ' ';
	PreOrder(root->leftchild());
	PreOrder(root->rightchild());
}

template<class T>
void BST<T>::InOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	InOrder(root->leftchild());
	std::cout << root->value() << ' ';
	InOrder(root->rightchild());
}

template<class T>
BinaryTreeNode<T>* BST<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *current)
{
	BinaryTreeNode<T> *temp = NULL;
	if (root == NULL)
		return NULL;
	if (current == root->leftchild() || current == root->rightchild())
		return root;
	if ((temp = Parent(root->leftchild(), current)) != NULL)
		return temp;
	if ((temp = Parent(root->rightchild(), current)) != NULL)
		return temp;
	return temp;
}


template<class T>
bool BST<T>::isLeaf(BinaryTreeNode<T>* current) const
{
	if (current->leftchild() && current->rightchild())
		return true;
	return false;
}
template<class T>
void BST<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	DeleteBinaryTree(root->leftchild());
	DeleteBinaryTree(root->rightchild());
	delete root;
}

template<class T>
BST<T>::~BST()
{
	DeleteBinaryTree(root);
}
